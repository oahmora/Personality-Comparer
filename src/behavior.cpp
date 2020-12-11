#include <iostream>
#include <fstream>

#include "../header/behavior.hpp"

Behavior::Behavior():filename("") {
}

void Behavior::set_filename(std::string filename) {
    this->filename = filename;
}

std::string Behavior::get_filename() {
    return filename;
}

std::string Behavior::get_behavior(std::string str) {

    std::string temp("");
    if ( open_file(str) == true)  {
        temp = read_file();
        close_file();
    }

    return temp;
}

void Behavior::print_behavior(std::string behavior) {
    std::cout << behavior <<  std::endl;
}

// ---------------------------- UTILITY ----------------------------

bool Behavior::open_file(std::string filename) {

    fin.open(to_lower(filename));
    if(fin.fail()) {
        std::cout << filename << " did not open!\n";
        return false;
    }
    return true;
}

std::string Behavior::read_file() {
    std::string str;
    for( std::string line; getline( fin, line ); ){
        str += line + "\n";
    }
    return str;
}

void Behavior::close_file() {
    fin.close();
}

std::string Behavior::to_lower(std::string str) {
    std::string temp("");
    for(auto i : str)
        temp += std::tolower(i);

    return temp;
}
