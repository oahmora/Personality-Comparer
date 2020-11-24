#include "../header/validateBirthday.hpp"

#include <iostream>
#include <utility>
#include <string>
#include <vector>



ValidateBirthday::ValidateBirthday()
{
    init();
}

std::vector<std::string> ValidateBirthday::parse_input( std::string input)
{
    std::vector< std::string > temp;
    std::size_t found = input.find("/");
    if (found != std::string::npos)
        // store the month in the vector
        temp.push_back(input.substr(0, found));
    else
        return temp;

    int t = found;
    found = input.find("/", found+1);
        if (found != std::string::npos)
        // store the month in the vector
        temp.push_back(input.substr(t, found));
    else
        return temp;

    temp.push_back(input.substr(found, input.length()) );

    return temp;
}

void ValidateBirthday::ask_birthday()
{
    std::string prompt("please enter your birthday in mm/dd/yyyy format: ");
    std::string input;

    std::cout << prompt;
    std::cin >> input;
    std::cout << std::endl;

    // parse input string to month, day and year
    std::vector<std::string> parsedInput = parse_input(input);

    bool m =  month_is_valid( std::stoi(parsedInput[0]));
    bool d = date_is_valid( std::stoi(parsedInput[1]));
    bool y = year_is_valid( std::stoi(parsedInput[2]));
    bool month_date = date_and_month_is_valid( std::stoi(parsedInput[0]), std::stoi(parsedInput[1]));

    while ( m != false && d != false && y != false && month_date != false)
    {
        std::cout << prompt;
        std::cin >> input;
        std::cout << std::endl;

        parsedInput = parse_input(input);

        m =  month_is_valid( std::stoi(parsedInput[0]));
        d = date_is_valid( std::stoi(parsedInput[1]));
        y = year_is_valid( std::stoi(parsedInput[2]));
        month_date = date_and_month_is_valid( std::stoi(parsedInput[0]), std::stoi(parsedInput[1]));
    }

    _birthday = new Birthday( std::stoi(parsedInput[0]), std::stoi(parsedInput[0]) , std::stoi(parsedInput[0]));

}

bool ValidateBirthday::date_is_valid(int date)
{

    if (date < 1 && date > 31)
    {
        std::cout << "Invalid Day. Please enter date between 1 and 31: ";
        return false;
    }

    return true;
}

bool ValidateBirthday::month_is_valid(int month)
{

    if (month < 1 && month > 12)
    {
        std::cout << "Month is invalid. Please enter month between 1 and 12: ";
        return false;
    }
    return true;
}

bool ValidateBirthday::year_is_valid(int year)
{

    if (year < 1900 && year > 2022)
    {
        std::cout << "Year is invalid. Please enter year between 1900 and 2021: ";
        return false;
    }
    return true;
}

bool ValidateBirthday::date_and_month_is_valid(int month, int day)
{
    std::pair<int, int> temp = std::make_pair(month, day);

    if (_dates_N_months[month - 1] != temp)
    {
        std::cout << "Invalid combination of month and date"
                  << "Please enter a valid combo of month and date: ";
        return false;
    }
    return true;
}

void ValidateBirthday::init()
{
    _dates_N_months[0] = std::make_pair(1, 31);
    _dates_N_months[1] = std::make_pair(2, 28);
    _dates_N_months[2] = std::make_pair(3, 31);
    _dates_N_months[3] = std::make_pair(4, 30);
    _dates_N_months[4] = std::make_pair(5, 29);
    _dates_N_months[5] = std::make_pair(6, 30);
    _dates_N_months[6] = std::make_pair(7, 31);
    _dates_N_months[7] = std::make_pair(8, 31);
    _dates_N_months[8] = std::make_pair(9, 30);
    _dates_N_months[9] = std::make_pair(10, 30);
    _dates_N_months[10] = std::make_pair(11, 30);
    _dates_N_months[11] = std::make_pair(12, 31);
}


