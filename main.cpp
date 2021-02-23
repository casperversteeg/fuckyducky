#include <typeindex>
#include <typeinfo>
#include <iostream>

#include "types.hpp"

// I know it's a mess

template <typename T> void printMyType(T & x, const char * s) {
  std::cout << "Should be " << s << ", is " << typeid(what_type_t<T>).name()
            << std::endl;
}

int main(int argc, char ** argv) {
  // DerivA<Z<MyType, MyType>> derivAz_mm;
  // DerivA<Z<double, MyType>> derivAz_dm;
  // DerivA<Z<MyType, double>> derivAz_md;
  DerivA<Z<double, double>> derivAz_dd;
  // DerivB<Z<MyType, MyType>, Z<MyType, MyType>> derivBz_mmmm;
  // DerivB<Z<MyType, MyType>, Z<double, MyType>> derivBz_mmdm;
  // DerivB<Z<MyType, MyType>, Z<MyType, double>> derivBz_mmmd;
  // DerivB<Z<MyType, MyType>, Z<double, double>> derivBz_mmdd;
  // DerivB<Z<double, MyType>, Z<MyType, MyType>> derivBz_dmmm;
  // DerivB<Z<double, MyType>, Z<double, MyType>> derivBz_dmdm;
  // DerivB<Z<double, MyType>, Z<MyType, double>> derivBz_dmmd;
  // DerivB<Z<double, MyType>, Z<double, double>> derivBz_dmdd;
  // DerivB<Z<MyType, double>, Z<MyType, MyType>> derivBz_mdmm;
  // DerivB<Z<MyType, double>, Z<double, MyType>> derivBz_mddm;
  // DerivB<Z<MyType, double>, Z<MyType, double>> derivBz_mdmd;
  // DerivB<Z<MyType, double>, Z<double, double>> derivBz_mddd;
  // DerivB<Z<double, double>, Z<MyType, MyType>> derivBz_ddmm;
  // DerivB<Z<double, double>, Z<double, MyType>> derivBz_dddm;
  // DerivB<Z<double, double>, Z<MyType, double>> derivBz_ddmd;
  B<Z<double, double>, double> derivBz_dddd;
  printMyType(derivAz_dd, "double");
  printMyType(derivBz_dddd, "double");

  // Z<MyType, MyType> z_mm;
  // Z<double, MyType> z_dm;
  // Z<MyType, double> z_md;
  // Z<double, double> z_dd;
  // Base base;
  // A<MyType> A_m;
  // A<double> A_d;
  // DerivA<MyType> derivA_m;
  // DerivA<double> derivA_d;
  // B<MyType, MyType> B_mm;
  // B<double, MyType> B_dm;
  // B<MyType, double> B_md;
  // B<double, double> B_dd;
  // DerivB<MyType, MyType> derivB_mm;
  // DerivB<double, MyType> derivB_dm;
  // DerivB<MyType, double> derivB_md;
  // DerivB<double, double> derivB_dd;
  //
  // printMyType(z_mm, "TypeInvalid");
  // printMyType(z_dm, "double");
  // printMyType(z_md, "TypeInvalid");
  // printMyType(z_dd, "double");
  // printMyType(base, "TypeInvalid");
  // printMyType(A_m, "TypeInvalid");
  // printMyType(A_d, "double");
  // printMyType(B_mm, "TypeInvalid");
  // printMyType(B_dm, "TypeInvalid");
  // printMyType(B_md, "TypeInvalid");
  // printMyType(B_dd, "double");
  // printMyType(derivA_m, "TypeInvalid");
  // printMyType(derivA_d, "double");
  // printMyType(derivB_mm, "TypeInvalid");
  // printMyType(derivB_dm, "TypeInvalid");
  // printMyType(derivB_md, "TypeInvalid");
  // printMyType(derivB_dd, "double");

  return 0;
}
