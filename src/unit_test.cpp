#include "gtest/gtest.h"

#include "../tests/date_test.hpp"
#include "../tests/createBirthday_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
