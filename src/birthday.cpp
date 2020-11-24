#include "../header/birthday.hpp"

Birthday::Birthday() {
}

Birthday::Birthday(int m, int d, int y): month(m), date(d), year(y) {
}

void Birthday::set_month(int month) {
    this->month = month;
}

void Birthday::set_date(int date) {
    this->date = date;
}

void Birthday::set_year(int year) {
    this->year = year;
}

int Birthday::get_month() {
    return this->month;
}

int Birthday::get_date()  {
    return this->date;
}

int Birthday::get_year() {
    return this->year;
}


