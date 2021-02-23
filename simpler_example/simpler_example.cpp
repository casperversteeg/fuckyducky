#include <typeindex>
#include <typeinfo>
#include <iostream>
struct MyType {};
template <typename T>
struct Base {
  using type = T;
};
template <typename T>
struct Deriv : Base<T> {};
template <typename T>
struct Deriv2 : Base<T> {};
template <typename T>
struct is_base : std::false_type {};
template <typename T>
struct is_base<Base<T>> : std::true_type {};
template <typename T>
constexpr bool is_base_v = is_base<T>::value;
struct TypeInvalid {};
template <typename T>
struct WhatType {
  typedef typename std::conditional_t<std::is_arithmetic_v<T>, T, TypeInvalid>
      type;
};
template <typename T>
struct WhatType<Base<T>> {
  typedef typename WhatType<T>::type type;
};
// template <typename U>
template <typename T>
using what_type_t = typename WhatType<
    std::conditional_t<is_base_v<T>,
                       T,
                       std::common_type_t<Base<typename T::type>, T>>>::type;
template <typename T>
void printMyType(T & x) {
  std::cout << typeid(what_type_t<T>).name() << std::endl;
}
int main() {
  Base<MyType> base_m;
  Base<double> base_d;
  Deriv<MyType> deriv_m;
  Deriv<double> deriv_d;
  Deriv2<MyType> deriv2_m;
  Deriv2<double> deriv2_d;
  printMyType(base_m);
  printMyType(base_d);
  printMyType(deriv_m);
  printMyType(deriv_d);
  printMyType(deriv2_m);
  printMyType(deriv2_d);
  std::cout << std::boolalpha;
  std::cout << is_base_v<Base<double>> << std::endl;
  std::cout << is_base_v<Base<MyType>> << std::endl;
  std::cout << is_base_v<Deriv<MyType>> << std::endl;
  std::cout << is_base_v<Deriv<double>> << std::endl;
  std::cout << is_base_v<Deriv2<MyType>> << std::endl;
  std::cout << is_base_v<Deriv2<double>> << std::endl;
  return 0;
}
