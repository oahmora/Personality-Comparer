#ifndef __CREATEBIRTHDAY_TESTS_HPP__
#define __CREATEBIRTHDAY_TESTS_HPP__


#include "gtest/gtest.h"
#include <iostream>

#include "../header/createBirthday.hpp"


TEST(CreateBirthdayTest, CreateBirthdayTest1) {
    CreateBirthday *_validate = new CreateBirthday();
    _validate->ask_birthday();

    std::string str ("Date = [");
    str += std::to_string(_validate->get_birthday()->get_month());
    str += "/" + std::to_string(_validate->get_birthday()->get_day());
    str += "/" + std::to_string(_validate->get_birthday()->get_year());
    str += "]";
 
    EXPECT_EQ(_validate->get_birthday()->to_string(),str);
} 

TEST(CreateBirthdayTest, CreateBirthdayTest2) {
    CreateBirthday *_validate = new CreateBirthday();
    _validate->ask_birthday();

    testing::internal::CaptureStdout();
    std::cout << *_validate->get_birthday();
    std::string output = testing::internal::GetCapturedStdout();
    
    std::string str ("");
    str += std::to_string(_validate->get_birthday()->get_month());
    str += "/" + std::to_string(_validate->get_birthday()->get_day());
    str += "/" + std::to_string(_validate->get_birthday()->get_year());
    EXPECT_EQ(output,str);
} 

#endif // __CREATEBIRTHDAY_TESTS_HPP__
