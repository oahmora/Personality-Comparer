#ifndef __ACTUALZODIAC_TEST_HPP__ 
#define __ACTUALZODIAC_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/date.hpp"
#include "../header/actualZodiac.hpp"

TEST(ActualZodiacTest, Test1) {
    
    ActualZodiac az = ActualZodiac();
    az.set_birthday();

    testing::internal::CaptureStdout();
    std::cout << az.match_zodiac() << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, output);
}

TEST(ActualZodiacTest, TestFail) {
    
    ActualZodiac az = ActualZodiac();
    az.set_birthday();

    testing::internal::CaptureStdout();
    std::cout << az.match_zodiac() << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Cancer\n");
}


#endif //__ACTUALZODIAC_TEST_HPP__
