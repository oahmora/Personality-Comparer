#ifndef __DATE_TEST_HPP__
#define __DATE_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/date.hpp"

TEST(DateTest, DateDefaultConstructor) {
    Date* birthday = new Date();
    birthday->set_month(02);
    birthday->set_day(12);
    birthday->set_year(2000);
    
    EXPECT_EQ(birthday->get_month(), 2);
    EXPECT_EQ(birthday->get_day(), 12);
    EXPECT_EQ(birthday->get_year(), 2000);
}

TEST(DateTest, DateConstructor) {
    Date* birthday = new Date(02, 12, 2000);

    EXPECT_EQ(birthday->get_month(), 2);
    EXPECT_EQ(birthday->get_day(), 12);
    EXPECT_EQ(birthday->get_year(), 2000);
}

TEST(DateTest, DateToString1) {
    Date* birthday = new Date();
    birthday->set_month(02);
    birthday->set_day(12);
    birthday->set_year(2000);

    EXPECT_EQ(birthday->to_string(), "Date = [2/12/2000]");
}

TEST(DateTest, DateToString2) {
    Date* birthday = new Date(02, 12, 1920);
    EXPECT_EQ(birthday->to_string(), "Date = [2/12/1920]");
}


TEST(DateTest, DateString1) {
    Date* birthday = new Date();
    birthday->set_month(02);
    birthday->set_day(12);
    birthday->set_year(2000);

    testing::internal::CaptureStdout();
    std::cout << *birthday ;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2/12/2000");
}

TEST(DateTest, DateString2) {
    Date* birthday = new Date(02, 12, 2000);

    testing::internal::CaptureStdout();
    std::cout << *birthday ;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2/12/2000");
}

TEST(DateTest, DateAll) {
    Date birthday = Date(02, 12, 2000);
    EXPECT_EQ(birthday.get_month(), 2);
    EXPECT_EQ(birthday.get_day(), 12);
    EXPECT_EQ(birthday.get_year(), 2000);

    testing::internal::CaptureStdout();
    std::cout << birthday ;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2/12/2000");
}

#endif //__DATE_TEST_HPP__
