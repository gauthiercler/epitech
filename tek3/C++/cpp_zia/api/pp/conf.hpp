
#pragma once

#include <iostream>
#include <memory>
#include "../conf.h"
#include "visitor.hpp"

/**
 * Wrapper of zia::api::Conf header to simplify the using.
 */
namespace zia::apipp {

    class ConfElem;

    template<typename T, typename U>
    constexpr bool isThisType() {
        using decayed = std::decay_t<T>;
        return std::is_same_v<decayed, U>;
    };

    struct ConfMap {

        using Sptr = std::shared_ptr<ConfMap>;

        ConfMap() = default;
        ConfMap(ConfMap const&) = default;
        ConfMap(ConfMap&&) = default;

        ConfMap& operator=(ConfMap const&) = default;
        ConfMap& operator=(ConfMap&&) = default;


        std::map<std::string, std::shared_ptr<ConfElem> > elems;

        // Put in the .cpp file to allow proper destructor call.
        ~ConfMap();
    };

    struct ConfArray {
        using Sptr = std::shared_ptr<ConfArray>;

        ConfArray() = default;
        ConfArray(ConfArray const&) = default;
        ConfArray(ConfArray&&) = default;

        ConfArray& operator=(ConfArray const&) = default;
        ConfArray& operator=(ConfArray&&) = default;

        std::vector<std::shared_ptr<ConfElem> > elems;

        // Put in the .cpp file to allow proper destructor call.
        ~ConfArray();
    };

    class ConfElem {
    public:
        enum Type {
            Empty, // std::monostate
            Map, // ConfMap
            Array, // ConfArray
            String, // std::string
            Integer, // long long
            Double, // double
            Boolean // bool
        };

        class InvalidAccess : std::exception {
        };

    private:
        Type type;
        using Variant = std::variant<std::monostate, ConfMap::Sptr, ConfArray::Sptr, std::string, long long, double, bool>;

        Variant value;

        template<typename TElem>
        struct variant_helper
        {
			template<typename T = TElem, std::enable_if_t<std::is_same_v<T, std::monostate> >* = nullptr >
			static Type get_type() { return Empty; }

            template<typename T = TElem, std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<bool, T> >* = nullptr>
            static Type get_type() { return Integer; }

            template<typename T = TElem, std::enable_if_t<std::is_floating_point_v<T> > * = nullptr>
            static Type get_type() { return Double; }

            template<typename T = TElem, std::enable_if_t<std::is_same_v<std::string, T> > * = nullptr>
            static Type get_type() { return String; }

            template<typename T = TElem, std::enable_if_t<std::is_same_v<ConfArray, T> ||
                                                          std::is_same_v<ConfArray::Sptr, T> > * = nullptr>
            static Type get_type() { return Array; }

            template<typename T = TElem, std::enable_if_t<std::is_same_v<ConfMap, T> ||
                                                          std::is_same_v<ConfMap::Sptr, T> > * = nullptr>
            static Type get_type() { return Map; }

            template<typename T = TElem, std::enable_if_t<std::is_same_v<bool, T> >* = nullptr>
            static Type get_type() { return Boolean; }

			template<typename T, typename U = TElem, std::enable_if_t<std::is_same_v<U, std::monostate> >* = nullptr >
			static void set_value(T &&value, Variant& var) {
				var = std::monostate();
			}

            template<typename T, typename U = TElem, std::enable_if_t<std::is_integral_v<U> && !std::is_same_v<bool, U> >* = nullptr>
            static void set_value(T &&value, Variant &var) {
                var = static_cast<long long>(value);
            };

            template<typename T, typename U = TElem, std::enable_if_t<std::is_floating_point_v<U> > * = nullptr>
            static void set_value(T &&value, Variant &var) {
                var = static_cast<double>(value);
            };

            template<typename T, typename U = TElem, std::enable_if_t<std::is_same_v<std::string, U> > * = nullptr>
            static void set_value(T &&value, Variant &var)
            {
                var = std::forward<T>(value);
            };

            template<typename T, typename U = TElem, std::enable_if_t<std::is_same_v<ConfArray, U>
                                                          || std::is_same_v<ConfMap, U> > * = nullptr>
            static void set_value(T &&value, Variant &var) {
                var = std::make_shared<TElem>(std::forward<TElem>(value));
            };

            template<typename T, typename U = TElem, std::enable_if_t<std::is_same_v<bool, U> >* = nullptr>
            static void set_value(T &&value, Variant &var) {
                var = value;
            };

            template<typename T, typename U = TElem, std::enable_if_t<std::is_same_v<ConfArray::Sptr, U>
                                                          || std::is_same_v<ConfMap::Sptr, U> >* = nullptr>
            static void set_value(T const& value, Variant &var) {
                var = value;
            };
        };

    public:
        ConfElem() {
            type = Empty;
        }

        ConfElem(ConfElem const& r) = default;
        ConfElem(ConfElem&&) noexcept = default;

        ConfElem& operator=(ConfElem const&) = default;
        ConfElem& operator=(ConfElem&&) noexcept = default;

        ~ConfElem();

        /**
         * Constructors
         */

        template<typename T, std::enable_if_t<!isThisType<T, ConfElem>()> * = nullptr>
        ConfElem(T&& v) : type(variant_helper<std::decay_t<T>>::get_type()), value() {
            variant_helper<std::decay_t<T> >::set_value(std::forward<T>(v), value);
        }

        /**
         * Get the value stored in the std::variant.
         *
         * If a invalid T is passed, a error (C2338 on MSVC) will occur.
         * Don't worry. You surely typed "int" instead of "long long".
         *
         * @tparam T
         * @return
         */
        template<typename T>
        T get() const {
            try {
                return std::get<T>(value);
            } catch (std::bad_variant_access &) {
                throw InvalidAccess();
            }
        }

        ConfElem &get_at(const int index) {
            return (*this)[index];
        }

        const ConfElem &get_at(const int index) const {
            return (*this)[index];
        }

        ConfElem &get_at(const std::string &index) {
            return (*this)[index];
        }

        const ConfElem &get_at(const std::string &index) const {
            return (*this)[index];
        }

        /**
         * Set the value into the std::variant.
         *  
         * If a invalid T is passed, a error (LNK2019 on MSVC) will occur during the linking pass of the compilation.
         *
         * @tparam T
         */

        template<typename T>
        ConfElem &set(T && v) &
        {
            using decayed = std::decay_t<T>;
            type = variant_helper<decayed>::get_type();
            variant_helper<decayed>::set_value(std::forward<T>(v), value);
            return *this;
        }

        template<typename T>
        ConfElem &&set(T && v) &&
        {
            using decayed = std::decay_t<T>;
            type = variant_helper<decayed>::get_type();
            variant_helper<decayed>::set_value(std::forward<T>(v), value);
            return std::move(*this);
        }

        /**
         * Push a ConfElem into the ConfArray value. The value is moved into the array.
         * 
         * @throw InvalidAccess if the value is not a ConfArray
         *
         * @tparam T
         * @param index
         * @param val
         * @return
         */
        ConfElem &push(ConfElem &&val) & {
            try {
                std::get<ConfArray::Sptr>(value)->elems.emplace_back( std::make_shared<ConfElem>(std::move(val) )) ;
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return *this;
        }

		/**
		* Push a ConfElem into the ConfArray value. The value is moved into the array.
		*
		* @throw InvalidAccess if the value is not a ConfArray
		*
		* @tparam T
		* @param index
		* @param val
		* @return
		*/
        ConfElem &&push(ConfElem &&val) && {
            try {
                std::get<ConfArray::Sptr>(value)->elems.emplace_back( std::make_shared<ConfElem>(std::move(val) )) ;
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return std::move(*this);
        }

        /**

   * Push a ConfElem into the ConfArray value.
   *
   * @throw InvalidAccess if the value is not a ConfArray
   *
   * @tparam T
   * @param index
   * @param val
   * @return
   */
        ConfElem &push(std::shared_ptr<ConfElem> const& val) & {
            try {
                std::get<ConfArray::Sptr>(value)->elems.emplace_back(val);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return *this;
        }

        ConfElem &&push(std::shared_ptr<ConfElem> const& val) && {
            try {
                std::get<ConfArray::Sptr>(value)->elems.emplace_back(val);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return std::move(*this);
        }

        /**
         * Insert a value into the ConfMap value.
         *
         * @throw InvalidAccess if the value is not a ConfMap.
         *
         * @param index
         * @param val
         * @return.
         */
        ConfElem &set_at(const std::string &index, ConfElem && val) & {
            try {
                std::get<ConfMap::Sptr>(value)->elems[index] = std::make_shared<ConfElem>(std::move(val));
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return *this;
        }

		/**
		* Insert a value into the ConfMap value. Value is moved into the map.
		*
		* @throw InvalidAccess if the value is not a ConfMap.
		*
		* @param index
		* @param val
		* @return
		*/
        ConfElem &&set_at(const std::string &index, ConfElem && val) && {
            try {
                std::get<ConfMap::Sptr>(value)->elems[index] = std::make_shared<ConfElem>(std::move(val));
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return std::move(*this);
        }

        ConfElem &set_at(const std::string &index, std::shared_ptr<ConfElem> const& val) & {
            try {
                std::get<ConfMap::Sptr>(value)->elems[index] = val;
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return *this;
        }

        ConfElem &&set_at(const std::string &index, std::shared_ptr<ConfElem> const& val) && {
            try {
                std::get<ConfMap::Sptr>(value)->elems[index] = val;
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
            return std::move(*this);
        }

        /**
         * Get the enum type of the variant value.
         *
         * @return
         */
        ConfElem::Type getType() const {
            return type;
        }

        /**
         * Access to an index of a ConfArray.
         *
         * @throw InvalidAccess if the value is not a ConfArray
         *
         * @param index
         * @return
         */
        ConfElem &operator[](const int index) {
            try {
                return *(std::get<ConfArray::Sptr>(value))->elems.at(index);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
        }

		/**
		* Access to an index of a constant ConfArray.
		*
		* @throw InvalidAccess if the value is not a ConfArray
		*
		* @param index
		* @return
		*/
        const ConfElem &operator[](const int index) const {
            try {
                return *(std::get<ConfArray::Sptr>(value))->elems.at(index);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
        }

        /**
         * Access to an index of a ConfMap.
         *
         * @throw InvalidAccess if the value is not a ConfMap
         *
         * @param index
         * @return
         */
        ConfElem &operator[](const std::string &index) {
            try {
                return *(std::get<ConfMap::Sptr>(value))->elems.at(index);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
        }

		/**
		* Access to an index of a ConfMap.
		*
		* @throw InvalidAccess if the value is not a ConfMap
		*
		* @param index
		* @return
		*/
        const ConfElem &operator[](const std::string &index) const {
            try {
                return *(std::get<ConfMap::Sptr>(value))->elems.at(index);
            } catch (std::exception &) {
//                std::cout << e.what() << std::endl;
                throw InvalidAccess();
            }
        }

        /**
         * Returns the inner variant object. (used for std::visit).
         * @return Variant type with std::monostate, long long, double, std::string,
         * boolean, ConfArray and ConfMap types.
         */
        const Variant &getValue() const {
            return value;
        }

        /**
         * Encapsulated std::visit call with a recursive visitor.
         * @tparam TReturn default return type is void, must be given explicitly otherwise.
         * @tparam TVisitors Every overload must be given. Either with functions of different arguments type,
         * or a function with a generic parameter, and type selection with if constexpr expressions.
         * @param visitors
         * @return TReturn
         */
        template<typename TReturn = void, typename ...TVisitors>
        decltype(auto) visit(TVisitors&& ...visitors) const {
            auto rec_visit = make_recursive_visitor<TReturn>(
                std::forward<TVisitors>(visitors)...
            );

            return std::visit(rec_visit, getValue());
        };

        /**
         * Convert a configuration object from the SZA api to SZA++ format.
         * @param conf Basic Configuration from wrapped API.
         * @return SZA++ Configuration object.
         */
		static ConfElem fromBasicConfig(const zia::api::Conf &conf) {
			auto jsonConfig = ConfElem(ConfMap());

			auto visitor = make_recursive_visitor<ConfElem>([](auto self, auto&& value) -> ConfElem {
                using T = std::decay_t<decltype(value)>;

				if constexpr (std::is_same_v<T, std::monostate>) {
					return ConfElem();
				}
				else if constexpr  (std::is_same_v<T, double> ||
					std::is_same_v<T, long long int> ||
					std::is_same_v<T, bool> ||
					std::is_same_v<T, std::string>)
				{
					return ConfElem(value);
				}
				else if constexpr (std::is_same_v<T, zia::api::ConfObject>) {
					auto currentElem = ConfElem(ConfMap());
					for (auto& v : value)
					{
						currentElem.set_at(v.first, self(v.second.v));
					}
					return currentElem;
				}
				else if constexpr (std::is_same_v<T, zia::api::ConfArray>) {
					auto currentElem = ConfElem(ConfArray());

					for (auto& v : value) {
						currentElem.push(self(v.v));
					}
					return currentElem;
				}
			});

			for (auto const& basicvalue : conf)
			{
				jsonConfig.set_at(basicvalue.first, std::visit(visitor, basicvalue.second.v));
			}
			return jsonConfig;
		}

        /**
         * Convert a configuration object from SZA++ format to a Conf object from the SZA Api.
         * Since the Conf type from SZA++ is a Variant and the one from SZA Api is a map with named values, when
         * a ConfElem is not a map element, a field "data" is added at the root to store the real data.
         * @return
         */
        zia::api::Conf toBasicConfig();
    };

    /**
     * Serialize a SZA++ Configuration for display/testing purposes.
     * @param os Output stream
     * @param conf
     * @return
     */
    std::ostream& operator<<(std::ostream& os, ConfElem const &conf);

    /**
     * Serialize a SZA Configuration for display/testing purposes.
     * @param os Output stream
     * @param conf An element of the configuration.
     * @return
     */
    std::ostream& operator<<(std::ostream& os, zia::api::Conf const &conf);

    /**
     * Alias for long long.
     *
     * @return
     */
    template<>
    inline int ConfElem::get<int>() const {
        return static_cast<int>(get<long long>());
    }

    /**
     * Alias for double.
     *
     * @return
     */
    template<>
    inline float ConfElem::get<float>() const {
        return static_cast<float>(get<double>());
    }

    using Conf = ConfElem;
}