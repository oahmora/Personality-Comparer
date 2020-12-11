#ifndef __BEHAVIOR_TEST_HPP__
#define __BEHAVIOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/actualZodiac.hpp"
#include "../header/behavior.hpp"


TEST(BehaviorTest, Test1) {
    Behavior b = Behavior();
    std::string bvor = b.get_behavior( "resources/capricorn.txt");

    testing::internal::CaptureStdout();
    b.print_behavior(bvor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, bvor + "\n");

}

TEST(BehaviorTest, Test2) {
    Behavior b = Behavior();
    std::string bvor = b.get_behavior( "resources/aquarius.txt");

    testing::internal::CaptureStdout();
    b.print_behavior(bvor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, bvor + "\n");
}

TEST(BehaviorTest, TestVisitorPattern1) {
    ActualZodiac az = ActualZodiac();
    az.set_birthday();

    Behavior b = Behavior();
    az.acceptVisitor(&b);

    std::string str = b.get_filename();
    str = "resources/" + str +".txt";
    std::string bvor = b.get_behavior(str);

    testing::internal::CaptureStdout();
    b.print_behavior(bvor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, bvor + "\n");
}

TEST(BehaviorTest, TestVisitorPatternFail) {
    ActualZodiac az = ActualZodiac();
    Behavior b = Behavior();
    az.acceptVisitor(&b);

    std::string str = b.get_filename();
    str = "resources/" + str +".txt";

    std::string bvor = b.get_behavior(str);

    testing::internal::CaptureStdout();
    b.print_behavior(bvor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, bvor + "\n");
}

#endif //__BEHAVIOR_TEST_HPP__
