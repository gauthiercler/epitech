#ifndef CPP_RTYPE_CALLBACK_HPP
# define CPP_RTYPE_CALLBACK_HPP

#include <tuple>

template <typename T>
struct function_traits
	: public function_traits<decltype(&T::operator())>
{};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
{
	template <size_t i>
	using arg_t = std::tuple_element_t<i, std::tuple<Args...>>;
};

template <typename F>
auto getCallback(F f)
{
	return [](typename function_traits<F>::template arg_t<0> data) {
		auto& f = *static_cast<F*>(data->UserData);
		return f(data);
	};
}

#endif /* !CPP_RTYPE_CALLBACK_HPP*/
