#pragma once

template <template <class... V> class T, class U> struct is_template_base_of {
  static constexpr bool value = decltype(is_template_base_of::test(U()))::value;

private:
  template <class... V> static std::true_type test(T<V...>);
  static std::false_type test(...);
};

template <template <typename... V> typename T, typename U>
constexpr bool is_template_base_of_v = is_template_base_of<T, U>::value;

struct MyType {};

template <typename U, typename V> struct Z {};

struct Base {};
template <typename T> struct A : Base { using type = T; };
template <typename T> struct DerivA : A<T> {};
template <typename T, typename U> struct B : Base {
  using type = T;
  using type2 = U;
};
template <typename T, typename U> struct DerivB : B<T, U> {};

template <typename T> struct is_Z : std::false_type {};
template <typename U, typename V> struct is_Z<Z<U, V>> : std::true_type {};
template <typename T> struct is_base : std::false_type {};
template <> struct is_base<Base> : std::true_type {};
template <typename T> struct is_A : is_template_base_of<A, T> {};
template <typename T> struct is_B : is_template_base_of<B, T> {};
template <typename T> struct is_derivA : is_template_base_of<DerivA, T> {};
template <typename T> struct is_derivB : is_template_base_of<DerivB, T> {};

template <typename T>
constexpr bool is_base_v = is_base<std::common_type_t<T, Base>>::value;
template <typename T> constexpr bool is_A_v = is_A<T>::value;
template <typename T> constexpr bool is_B_v = is_B<T>::value;
template <typename T> constexpr bool is_derivA_v = is_derivA<T>::value;
template <typename T> constexpr bool is_derivB_v = is_derivB<T>::value;
template <typename T> constexpr bool is_Z_v = is_Z<T>::value;

struct TypeInvalid {};

template <> struct std::common_type<double, MyType> { using type = MyType; };
template <> struct std::common_type<MyType, double> { using type = MyType; };
template <> struct std::common_type<double, TypeInvalid> {
  using type = TypeInvalid;
};
template <> struct std::common_type<TypeInvalid, double> {
  using type = TypeInvalid;
};

template <typename T, class Enable = void> struct WhatType {
  using type =
      typename std::conditional_t<std::is_arithmetic_v<T>, T, TypeInvalid>;
};

template <typename T> struct WhatType<T, typename std::enable_if_t<is_A_v<T>>> {
  using type = typename WhatType<typename T::type>::type;
};

template <typename T> struct WhatType<T, typename std::enable_if_t<is_B_v<T>>> {
  using type = typename WhatType<
      std::common_type_t<typename WhatType<typename T::type>::type,
                         typename WhatType<typename T::type2>::type>>::type;
};

template <typename U, typename V> struct WhatType<Z<U, V>> {
  using type = typename WhatType<U>::type;
};

template <typename T> using what_type_t = typename WhatType<T>::type;
