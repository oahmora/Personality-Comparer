#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../header/createBirthday.hpp"


CreateBirthday::CreateBirthday() {
    _birthday = new Date();
    init();
}

void CreateBirthday::ask_birthday() {
    std::string input;
    std::vector<std::string> parsedInput;
    bool m = false, d = false, y(false), m_n_d = false, contains = true;
    
    while ( contains == true || m == false || d == false ||
                  y == false || m_n_d == false)
    {
        input = read_input();
        input = remove_spaces(input);
        contains = contains_invalid_inputs(input);
        if( contains ) {
            issue_error(true, true, true, true, false);
            continue;
        }

        parsedInput = parse_input(input);
        if( parsedInput.size() < 3 ) {
            issue_error(true, true, true, true, false);
            parsedInput.clear();
            continue;
        }

        m = month_is_valid(std::stoi(parsedInput[0]));
        d = day_is_valid(std::stoi(parsedInput[1]));
        y = year_is_valid(std::stoi(parsedInput[2]));
        
        if(m == false || d == false || y == false) {
            issue_error(m, d, y, true, true);
            parsedInput.clear();
            continue;
        }
        m_n_d = month_and_day_is_valid(std::stoi(parsedInput[0]),
                                       std::stoi(parsedInput[1]));
        if( m_n_d == false) {
            issue_error(true, true, true, false, true);
            parsedInput.clear();
        }
    }
    
    _birthday->set_month(std::stoi(parsedInput[0]));
    _birthday->set_day(std::stoi(parsedInput[1]));
    _birthday->set_year(std::stoi(parsedInput[2]));
}

Date* CreateBirthday::get_birthday() {
    return _birthday;
}

// ----------------------------- validation -------------------------------

bool CreateBirthday::month_is_valid(int month){
    return !(month < 1 || month > 12);
}

bool CreateBirthday::day_is_valid(int day){
    return !(day < 1 || day > 31);
}

bool CreateBirthday::year_is_valid(int year){
    return !(year < 1900 || year > 2022);
}

bool CreateBirthday::month_and_day_is_valid(int month, int day){
    std::map<int, int>::const_iterator pos = _days_N_months.find( month - 1 );
    return ! ( day > pos->second );
}

bool CreateBirthday::contains_invalid_inputs(std::string str) {
    const std::string LOOKUP = "0123456789/";
    for(unsigned int i = 0; i < str.length(); i++) {
        std::size_t found = LOOKUP.find(str[i]);
        // if str contains other character than LOOKUP, return true input
        if ( found == std::string::npos )
            return true;
    }
    return false;
}

// -------------------------- utility functions ----------------------------

std::string CreateBirthday::read_input() {
    std::string input("");
    while( input.length() < 8 ) {
        std::cout << "Please enter your birthday in mm/dd/yyyy format: ";
        std::getline (std::cin,input);
    }
    return input;
}

std::string CreateBirthday::remove_spaces(std::string str) {
    std::string temp("");
    for(unsigned int i = 0; i < str.size( ); i++) {
        if( str[i] != ' ' && str[i] != '\n')
            // skip coping input into temp if white space
            temp.append(str.substr(i, 1));
    }
    return temp;
}

std::vector<std::string> CreateBirthday::parse_input(std::string str) {
    std::vector<std::string> temp; // vector to hold parsed string
    int count = 0;
    std::size_t found = str.find_first_of("/");
    
    while (found!=std::string::npos) {
        count++;
        found = str.find_first_of("/", found + 1);
    }
    if(count != 2) // if there are not only 2 occurrence of '/'
        return temp;

    int first_pos = (int)str.find_first_of("/");    // second occurrence
    int last_pos = (int)str.find_last_of("/");      // second occurrence
    
    if ( first_pos + 1 != last_pos ) {
        temp.push_back(str.substr(0, first_pos));
        temp.push_back(str.substr(first_pos + 1, last_pos - first_pos - 1));
        temp.push_back(str.substr(last_pos + 1));
    }
    
    return temp;
}

void CreateBirthday::issue_error(bool m, bool d, bool y, bool MD, bool unknown) {
    if(m == false)
        std::cout << "Please enter a valid month between 1 and 12.\n";
    else if(d == false)
        std::cout << "Please enter a valid day between 1 and 31.\n";
    else if(y == false)
        std::cout << "Please enter a valid year between 1900 and 2021.\n";
    else if(MD == false)
        std::cout << "Please enter a valid combination of month and date.\n";
    else if(unknown == false)
        std::cout << "Unknown input.\n";
}

void CreateBirthday::init() {
    _days_N_months[0] = 31;
    _days_N_months[1] = 28;
    _days_N_months[2] = 31;
    _days_N_months[3] = 30;
    _days_N_months[4] = 29;
    _days_N_months[5] = 30;
    _days_N_months[6] = 31;
    _days_N_months[7] = 31;
    _days_N_months[8] = 30;
    _days_N_months[9] = 30;
    _days_N_months[10] = 30;
    _days_N_months[11] = 31;
}
