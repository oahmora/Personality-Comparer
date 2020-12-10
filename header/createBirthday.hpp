#ifndef __CREATE_BIRTHDAY_HPP__
#define __CREATE_BIRTHDAY_HPP__

#include <iostream>
#include <map>
#include <vector>

#include "../header/date.hpp"

/**
 * @brief CreateBirthday a class that takes user input from console
 *        and creates a Date object that serves as user's birthday
 */
class CreateBirthday {
    public:
        
        // ----------------------- contructor -----------------------

        /**
         * @brief CreateBirthday creates an empty Date object and initializes
         *        the _days_N_months map to the total number of days in a month
         */
        CreateBirthday();

        // -----------------------------------------------------------

        /**
         * @brief ask_birthday gets a string as a birthday from command line
         *        parses string and constructs a Date object from string
         */
        void ask_birthday();

        /**
         * @brief get_birthday gets the Date created from user input
         * @return a pointer to the Date object created with user input
         */
        Date* get_birthday();
    
    private:
    
        /**
         * @brief _birthday a Date object which will hold user's birthday
         */
        Date* _birthday;

        /**
         * @brief  _days_N_months a map of <int, int> that maps a month with
         *         the maximum number of days it has
         */
        std::map<int,int> _days_N_months;

    
        // ----------------------- validation -----------------------
    
        /**
         * @brief  month_is_valid checks if month's value is between 1 & 12
         * @param  month value being checked to see if it is valid
         * @return true if value of month is between 1 & 12, false otherwise
         */
        bool month_is_valid(int month);

        /**
         * @brief  day_is_valid checks if day's value is between 1 & 31
         * @param  day value being checked to see if it is valid
         * @return true if value of day is between 1 & 31, false otherwise
         */
        bool day_is_valid(int day);

        /**
         * @brief  year_is_valid checks if year's value is between 1900
         *         & 2021
         * @param  year value being checked to see if it is valid
         * @return true if value of year is between 1900 & 2021,
         *         false otherwise
         */
        bool year_is_valid(int year);

        /**
         * @brief  month_and_day_is_valid checks if month's value and day's
         *         value go along (i.e if February 31 is valid or not)
         * @param  month a given month
         * @param  day a given day
         * @return true if a the value of day corresponds to real life day
         *         in a given month
         */
        bool month_and_day_is_valid(int month, int day);

        /**
         * @brief  contains_invalid_inputs: checks if a character other than 0-9
         *         or "/" appears in str
         * @param  str    string being inspected for invalid characters
         * @return true if str does contain invalid input characters,
         *         false otherwise
         */
        bool contains_invalid_inputs(std::string str);

        // ------------------- utility functions ---------------------
    
        /**
         * @brief  read_input prompts user to enter a birthday
         * @return the input string from user
         */
        std::string read_input();
    
        /**
         * @brief  remove_spaces removes any white space character from string
         * @param  str string being inspected for white spaces
         * @return the string without any white space characters
         */
        std::string remove_spaces(std::string str);
    
        /**
         * @brief  parse_input parses the string str to month, day and year
         * @param  str string containing potential month, day and year
         * @return a vector of strings containing month, day and year from
         *         the parsed string if str is a valid Date in the format
         *         dd/mm/yyyy, otherwise returns an empty vector of string
         */ 
        std::vector<std::string> parse_input(std::string str);

        /**
         * @brief issue_error issues an error message
         * @param m bool to identify error message for invalid month input
         * @param d bool to identify error message for invalid day input
         * @param y bool to identify error message for invalid year input
         * @param MD bool to identify error message for invalid day+month input
         * @param unknown bool to identify error message for unknown inputs
         */
        void issue_error(bool m, bool d, bool y, bool MD, bool unknown);
    
        /**
         * @brief init initializes a map of month and its corresponding
         *        number of days in real life
         */
        void init();

};

#endif //__CREATE_BIRTHDAY_HPP__
