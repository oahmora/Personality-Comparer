#include <iostream>
#include <string>

#include "../header/date.hpp"

Date::Date():month(0), day(0), year(0) {
}

Date::Date(int m, int d, int y):month(m), day(d), year(y) {
}

void Date::set_month(int month) {
    this->month = month;
}

void Date::set_day(int day) {
    this->day = day;
}

void Date::set_year(int year) {
    this->year = year;
}

int Date::get_month() {
    return this->month;
}

int Date::get_day()  {
    return this->day;
}

int Date::get_year() {
    return this->year;
}

std::string Date::to_string() {
    std::string date = "Date = [";
    date += std::to_string(get_month()) + "/";
    date += std::to_string(get_day()) + "/";
    date += std::to_string(get_year()) + "]";
    return date;
}

std::ostream& operator<< (std::ostream &outs, const Date &d) {
    outs << d.month << "/" << d.day << "/" << d.year; 
    return outs;
}
