#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>

class Date {

    public:

        // --------------------------- contructors ----------------------------

        /**
         * @brief Date constructs an empty Date object and sets month, day
         *        and year to zero
         */
        Date();

        /**
         * @brief  Date constructs a Date with the given values
         * @param  month the given month for Date
         * @param  day   the given day of the month for Date
         * @param  year  the given year for Date
         */
        Date(int month, int day, int year);

        // ------------------------- modifiers/settors ------------------------
        
        /**
         * @brief  set_month sets Date::month to the given value of month
         * @param  month the given month for Date
         */
        void set_month(int month);

        /**
         * @brief  set_day sets Date::day to the given value of day
         * @param  day the given day of the month for Date
         */
        void set_day(int day);

        /**
         * @brief  set_year sets Date::year to the given value of year
         * @param  year the given year for Date
         */
        void set_year(int year);

        // ------------------------- accessors/getters ------------------------
    
        /**
         * @brief  get_month gets Date::month
         * @return month of the Date
         */
        int get_month();

        /**
         * @brief  get_day gets the Date::day
         * @return day of the Date
         */
        int get_day();

        /**
         * @brief  get_year gets the Date::year
         * @return year of the Date
         */
        int get_year();

        /**
         * @brief  to_string prints the string "Date[" followed by
         *         Date::month, Date::day & Date::year onto the console
         *         in a similar fashion to Java's to_string method
         */
        std::string to_string();
    
        /**
         * @brief  std::ostream& operator<< converts the Date into a
         *         string and sends string to ostream object outs
         * @param  out ostream operator similar to cout
         * @param  b a brithday object
         * @return ostream out
         */
        friend std::ostream& operator<< (std::ostream &out, const Date &b);
    
    private:
        /**
         * @brief month the month for Date
         */
        int month;
        /**
         * @brief day the day for Date
         */
        int day;
        /**
         * @brief year the year for Date
         */
        int year;
};

#endif //__DATE_HPP__
