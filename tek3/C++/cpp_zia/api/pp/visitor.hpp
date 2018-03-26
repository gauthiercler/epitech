
#pragma once
/// Y-Combinator to allow infinite-recursion with lambdas.
/// The lambda passed as parameter must take an `auto` as first parameter, which is the current
/// function called. It allows recursion in lambdas sinc lambdas cannot be self-referenced in their scope.
template<typename F>
struct fix {
public:
    constexpr fix(F function) : _function(function) {}
    fix(fix const&) = default;
    fix(fix&&) = default;

    template<typename ...Args>
    constexpr decltype(auto) operator()(Args&& ...args) {
        return _function(*this, std::forward<Args>(args)...);
    }
private:
    F _function;
};

namespace detail {

    template <typename... lambda_ts>
    struct composer_t;

    template <typename lambda_t>
    struct composer_t<lambda_t> : lambda_t {
        composer_t(const lambda_t& lambda) : lambda_t{ lambda } { }
        composer_t(lambda_t&& lambda) : lambda_t{ std::move(lambda) } { }

        using lambda_t::operator();
    };

    template <typename lambda_t, typename... more_lambda_ts>
    struct composer_t<lambda_t, more_lambda_ts...> : lambda_t, composer_t<more_lambda_ts...> {
        using super_t = composer_t<more_lambda_ts...>;

        template <typename... lambda_ts>
        composer_t(const lambda_t& lambda, lambda_ts&&... more_lambdas) : lambda_t{ lambda }, super_t{ std::forward<lambda_ts>(more_lambdas)... } { }
        template <typename... lambda_ts>
        composer_t(lambda_t&& lambda, lambda_ts&&... more_lambdas) : lambda_t{ std::move(lambda) }, super_t{ std::forward<lambda_ts>(more_lambdas)... } { }

        using lambda_t::operator();
        using super_t::operator();
    };

    template <typename... lambda_ts>
    auto compose(lambda_ts&&... lambdas) {
        return detail::composer_t<std::decay_t<lambda_ts>...>{std::forward<lambda_ts>(lambdas)...};
    }
} // namespace detail


/// Doesn't work on MSVC since it doesn't support
/// parameter-pack expansion for using-declarations yet.
/*
* template<typename ...Ts>
* struct overloaded : Ts... {
*    using overloaded<Ts>::operator()...;
* };
*
* template<typename ...Ts>
* overloaded(Ts...) -> overloaded<Ts...>;
*/

template<typename TVisitor, typename TVariant>
constexpr auto recursive_visit(TVisitor&& visitor, TVariant&& variant) {
    return std::visit(
        std::forward<TVisitor>(visitor),
        std::forward<TVariant>(variant)
    );
};

/**
 * Used to make a recusive visitor to give to std::visit.
 * Function passed as parameter must have an 'auto' as first parameter
 * to take the visitor object which is used to continue recursion.
 * @tparam TReturn Return type of visitors object given as parameter.
 * The return type must be explicit since the selfRecursion cannot deduct self return type.
 * @tparam TVisitors Callable objects taking as parameter a generic function type
 * and as second parameter one of the types stored in the variant visited.
 */
template<typename TReturn, typename ...TVisitors>
constexpr auto make_recursive_visitor(TVisitors&& ...visitors) {
	auto selfRecursion = [&visitors...](auto self, auto&& arg)->TReturn {

		return detail::compose ( std::forward<TVisitors>(visitors)... ) (
			[&self](auto&& v)
            {
                return recursive_visit(self, v);
            },
            std::forward<decltype(arg)>(arg)
        );
    };
    return fix<decltype(selfRecursion)>(selfRecursion);
}