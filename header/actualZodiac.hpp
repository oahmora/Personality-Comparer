#ifndef __ACTUAL_ZODIAC_HPP__
#define __ACTUAL_ZODIAC_HPP__

#include <iostream>
#include <map>

#include "../header/date.hpp"

/**
 * @brief ActualZodiac a class that interprets users birthday and forms the
 *        their zodiac signs based on actual zodiac sign interpretation
 */
class ActualZodiac {

    public:
    
        /**
         * @brief ActualZodiac instantiates the CreateBirthday class and
         *        a Date class
         */
        ActualZodiac();
    
        /**
         * @brief calls the CreateBirthday::ask_birthday() method to take
         *        user input and copies the birthday input onto _birthday
         */
        void set_birthday();
    
        /**
         * @brief  match_zodiac finds the index of _zodiac_months on which the
         *         user's Date of birth falls in the same range as the
         *         _zodiac_months Date and returns the string from _zodiac_signs
         *         at index which describes the user's zodiac sign
         * @return a string from _zodiac_signs on which the user birthday
         *         falls on
         */
        std::string match_zodiac();
    
    private:
    
        /**
         * @brief _birthday a Date object which will hold users birthday
         */
        Date* _birthday;
    
        /**
         * @brief _zodiac_months a map of pair of Date that will hold the
         *        date and month range on which each zodiac sign falls
         */
        std::map<int, std::pair<Date,Date> > _zodiac_months;
    
        /**
         * @brief _zodiac_signs a map of strings of the different zodiac sign
         *        names
         */
        std::map<int, std::string> _zodiac_signs;
    
        // ---------------------------- UTILITY ----------------------------
    
        /**
         * @brief init_zodiac_signs initializes map of ints and strings
         *        corresponding with the 12 zodiac signs and thier names
         */
        void init_zodiac_signs();

        /**
         * @brief init_zodiac_months initializes a map of ints and pair of
         *        Date in accordance with the 12 zodiac signs and the
         *        time ranges each falls on
         */
        void init_zodiac_months();
};

#endif //__ACTUAL_ZODIAC_HPP__
