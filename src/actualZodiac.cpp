#include <iostream>
#include <string>
#include <utility>

#include "../header/actualZodiac.hpp"
#include "../header/createBirthday.hpp"


ActualZodiac::ActualZodiac() {
    _birthday = new Date();
    init_zodiac_months();
    init_zodiac_signs();
}

void ActualZodiac::set_birthday() {
    CreateBirthday validate = CreateBirthday();
    validate.ask_birthday();
    _birthday = validate.get_birthday();
}

std::string ActualZodiac::match_zodiac() {
    auto it = _zodiac_months.begin();
    // if _birthday month and day falls in the range or current
    // zodiac_months, the break loop
    for (  ; it != _zodiac_months.end(); ++it) {
    if( (_birthday->get_month() == it->second.first.get_month() &&
       _birthday->get_day() >= it->second.first.get_day() ) ||
       (_birthday->get_month() == it->second.second.get_month() &&
        _birthday->get_day() < it->second.second.get_day() )) {
            break;
        }
    }
    // return the zodiac_sign at index it->first
    return std::string(_zodiac_signs.at(it->first));
}

void ActualZodiac::init_zodiac_months() {
    _zodiac_months[0] = std::make_pair(Date(3,21,0), Date(4,20,0));
    _zodiac_months[1] = std::make_pair(Date(4,20,0), Date(5,21,0));
    _zodiac_months[2] = std::make_pair(Date(5,21,0), Date(6,21,0));
    _zodiac_months[3] = std::make_pair(Date(6,21,0), Date(7,23,0));
    _zodiac_months[4] = std::make_pair(Date(7,23,0), Date(8,23,0));
    _zodiac_months[5] = std::make_pair(Date(8,23,0), Date(9,23,0));
    _zodiac_months[6] = std::make_pair(Date(9,23,0), Date(10,23,0));
    _zodiac_months[7] = std::make_pair(Date(10,23,0), Date(11,22,0));
    _zodiac_months[8] = std::make_pair(Date(11,23,0), Date(12,22,0));
    _zodiac_months[9] = std::make_pair(Date(12,22,0), Date(1,20,0));
    _zodiac_months[10] = std::make_pair(Date(1,20,0), Date(2,19,0));
    _zodiac_months[11] = std::make_pair(Date(2,19,0), Date(3,21,0));
}

void ActualZodiac::init_zodiac_signs() {
    _zodiac_signs[0] = "Aries";
    _zodiac_signs[1] = "Taurus";
    _zodiac_signs[2] = "Gemini";
    _zodiac_signs[3] = "Cancer";
    _zodiac_signs[4] = "Leo";
    _zodiac_signs[5] = "virgo";
    _zodiac_signs[6] = "Libra";
    _zodiac_signs[7] = "Scorpio";
    _zodiac_signs[8] = "Sagittarius";
    _zodiac_signs[9] = "Capricorn";
    _zodiac_signs[10] = "Aquarius";
    _zodiac_signs[11] = "Pisces";
}
