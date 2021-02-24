#pragma once

#include <typeindex>
#include <typeinfo>
#include <iostream>

#include "gtest/gtest.h"
#include "types.hpp"

template <typename T> const std::type_info & checkType(T & x) {
  return typeid(what_type_t<T>);
}

TEST(TypeTests, AliasTests) {
  static_assert(is_base_v<Base>);
  static_assert(is_base_v<A<MyType>>);
  static_assert(is_base_v<A<double>>);
  static_assert(is_base_v<B<MyType, MyType>>);
  static_assert(is_base_v<B<double, MyType>>);
  static_assert(is_base_v<B<MyType, double>>);
  static_assert(is_base_v<B<double, double>>);
  static_assert(is_A_v<A<MyType>>);
  static_assert(is_A_v<A<double>>);
  static_assert(is_B_v<B<MyType, MyType>>);
  static_assert(is_B_v<B<double, MyType>>);
  static_assert(is_B_v<B<MyType, double>>);
  static_assert(is_B_v<B<double, double>>);

  static_assert(!is_A_v<Base>);
  static_assert(!is_B_v<Base>);

  static_assert(!is_B_v<A<MyType>>);
  static_assert(!is_B_v<A<double>>);
  static_assert(!is_A_v<B<MyType, MyType>>);
  static_assert(!is_A_v<B<double, MyType>>);
  static_assert(!is_A_v<B<MyType, double>>);
  static_assert(!is_A_v<B<double, double>>);

  ASSERT_EQ(typeid(TypeInvalid), typeid(what_type_t<MyType>));
  ASSERT_EQ(typeid(double), typeid(what_type_t<double>));

  Z<MyType, MyType> z_mm;
  Z<double, MyType> z_dm;
  Z<MyType, double> z_md;
  Z<double, double> z_dd;
  Base base;
  A<MyType> A_m;
  A<double> A_d;
  B<MyType, MyType> B_mm;
  B<double, MyType> B_dm;
  B<MyType, double> B_md;
  B<double, double> B_dd;

  ASSERT_EQ(checkType(z_mm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(z_dm), typeid(double));
  ASSERT_EQ(checkType(z_md), typeid(TypeInvalid));
  ASSERT_EQ(checkType(z_dd), typeid(double));
  ASSERT_EQ(checkType(base), typeid(TypeInvalid));
  ASSERT_EQ(checkType(A_m), typeid(TypeInvalid));
  ASSERT_EQ(checkType(A_d), typeid(double));
  ASSERT_EQ(checkType(B_mm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(B_dm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(B_md), typeid(TypeInvalid));
  ASSERT_EQ(checkType(B_dd), typeid(double));

  A<Z<MyType, MyType>> Az_mm;
  A<Z<double, MyType>> Az_dm;
  A<Z<MyType, double>> Az_md;
  A<Z<double, double>> Az_dd;
  B<Z<MyType, MyType>, Z<MyType, MyType>> Bz_mmmm;
  B<Z<MyType, MyType>, Z<double, MyType>> Bz_mmdm;
  B<Z<MyType, MyType>, Z<MyType, double>> Bz_mmmd;
  B<Z<MyType, MyType>, Z<double, double>> Bz_mmdd;
  B<Z<double, MyType>, Z<MyType, MyType>> Bz_dmmm;
  B<Z<double, MyType>, Z<double, MyType>> Bz_dmdm;
  B<Z<double, MyType>, Z<MyType, double>> Bz_dmmd;
  B<Z<double, MyType>, Z<double, double>> Bz_dmdd;
  B<Z<MyType, double>, Z<MyType, MyType>> Bz_mdmm;
  B<Z<MyType, double>, Z<double, MyType>> Bz_mddm;
  B<Z<MyType, double>, Z<MyType, double>> Bz_mdmd;
  B<Z<MyType, double>, Z<double, double>> Bz_mddd;
  B<Z<double, double>, Z<MyType, MyType>> Bz_ddmm;
  B<Z<double, double>, Z<double, MyType>> Bz_dddm;
  B<Z<double, double>, Z<MyType, double>> Bz_ddmd;
  B<Z<double, double>, Z<double, double>> Bz_dddd;

  ASSERT_EQ(checkType(Az_mm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Az_dm), typeid(double));
  ASSERT_EQ(checkType(Az_md), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Az_dd), typeid(double));
  ASSERT_EQ(checkType(Bz_mmmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mmdm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mmmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mmdd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_dmmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_dmdm), typeid(double));
  ASSERT_EQ(checkType(Bz_dmmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_dmdd), typeid(double));
  ASSERT_EQ(checkType(Bz_mdmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mddm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mdmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_mddd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_ddmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_dddm), typeid(double));
  ASSERT_EQ(checkType(Bz_ddmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(Bz_dddd), typeid(double));

  DerivA<Z<MyType, MyType>> derivAz_mm;
  DerivA<Z<double, MyType>> derivAz_dm;
  DerivA<Z<MyType, double>> derivAz_md;
  DerivA<Z<double, double>> derivAz_dd;
  DerivB<Z<MyType, MyType>, Z<MyType, MyType>> derivBz_mmmm;
  DerivB<Z<MyType, MyType>, Z<double, MyType>> derivBz_mmdm;
  DerivB<Z<MyType, MyType>, Z<MyType, double>> derivBz_mmmd;
  DerivB<Z<MyType, MyType>, Z<double, double>> derivBz_mmdd;
  DerivB<Z<double, MyType>, Z<MyType, MyType>> derivBz_dmmm;
  DerivB<Z<double, MyType>, Z<double, MyType>> derivBz_dmdm;
  DerivB<Z<double, MyType>, Z<MyType, double>> derivBz_dmmd;
  DerivB<Z<double, MyType>, Z<double, double>> derivBz_dmdd;
  DerivB<Z<MyType, double>, Z<MyType, MyType>> derivBz_mdmm;
  DerivB<Z<MyType, double>, Z<double, MyType>> derivBz_mddm;
  DerivB<Z<MyType, double>, Z<MyType, double>> derivBz_mdmd;
  DerivB<Z<MyType, double>, Z<double, double>> derivBz_mddd;
  DerivB<Z<double, double>, Z<MyType, MyType>> derivBz_ddmm;
  DerivB<Z<double, double>, Z<double, MyType>> derivBz_dddm;
  DerivB<Z<double, double>, Z<MyType, double>> derivBz_ddmd;
  DerivB<Z<double, double>, Z<double, double>> derivBz_dddd;

  ASSERT_EQ(checkType(derivAz_mm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivAz_dm), typeid(double));
  ASSERT_EQ(checkType(derivAz_md), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivAz_dd), typeid(double));
  ASSERT_EQ(checkType(derivBz_mmmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mmdm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mmmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mmdd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_dmmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_dmdm), typeid(double));
  ASSERT_EQ(checkType(derivBz_dmmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_dmdd), typeid(double));
  ASSERT_EQ(checkType(derivBz_mdmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mddm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mdmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_mddd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_ddmm), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_dddm), typeid(double));
  ASSERT_EQ(checkType(derivBz_ddmd), typeid(TypeInvalid));
  ASSERT_EQ(checkType(derivBz_dddd), typeid(double));
}
