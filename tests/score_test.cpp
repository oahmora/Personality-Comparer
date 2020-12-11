#include <iostream>
#include "../header/score.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST(ScoreTest, calcTest) {
	Score* test = new Score();
	test.open(testanswers.txt);
	test->calculateScore();
	test->getTotalscore();
	test.close();
	EXPECT_EQ(output, 40);

}
TEST(ScoreTest, calcTest) {
	Score* test = new Score();
	test.open(testanswers.txt);
	test->calculateScore();
	test->getTotalscore();
	test.close();
	EXPECT_EQ(output, 60);

}

TEST(ScoreTest, calcTest) {
	Score* test = new Score();
	test.open(testanswers.txt);
	test->calculateScore();
	test->getTotalscore();
	test.close();
	EXPECT_EQ(output, 80);

}

TEST(ScoreTest, calcTest) {
	Score* test = new Score();
	test.open(testanswers.txt);
	test->calculateScore();
	test->getTotalscore();
	test.close();
	EXPECT_EQ(output, 100);

}

TEST(ScoreTest, calcTest) {
	Score* test = new Score();
	test.open(testanswers.txt);
	test->calculateScore();
	test->getTotalscore();
	test.close();
	EXPECT_EQ(output, 120);

}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
