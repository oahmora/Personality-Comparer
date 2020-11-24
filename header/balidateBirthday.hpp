#ifndef __VALIDATE_BIRTHDAY_HPP__
#define __VALIDATE_BIRTHDAY_HPP__

#include <iostream>
#include <map>
#include <utility>

#include "../header/birthday.hpp"


class ValidateBirthday {
    private:
        Birthday* _birthday;

        std::map< int, std::pair<int, int> > _dates_N_months;


        // validation
        bool month_is_valid(int month);
        bool date_is_valid(int day);
        bool year_is_valid(int year);

        bool date_and_month_is_valid(int month, int day);

        // initialize _dates to map a month with how many days it have.
        void init( );
        // parse input string to dates, months and years
        std::vector<std::string> parse_input( std::string input );

    public:
        
        // Constructors
        ValidateBirthday();
        void ask_birthday();
};

#endif //__VALIDATE_BIRTHDAY_HPP__

