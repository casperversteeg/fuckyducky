#include <typeindex>
#include <typeinfo>
#include <iostream>

#include "types.hpp"

#include "gtest/gtest.h"
#include "tests.hpp"

// I know it's a mess

int main(int argc, char ** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
