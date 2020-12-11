#include "gtest/gtest.h"

using namespace std;

#include "../tests/questions_test.hpp"

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
