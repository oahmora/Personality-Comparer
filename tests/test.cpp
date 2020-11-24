#include <iostream>
#include <utility>
#include <tuple>

#include "../src/birthday.cpp"
#include "../src/validateBirthday.cpp"


void testValdiation( ) {

    ValidateBirthday* _validate = nullptr;

    _validate->ask_birthday( );

}


void testBirthday( ) {
    
    Birthday birthday;

    birthday.set_month( 7 );
    birthday.set_date( 07 );
    birthday.set_year( 1990 );

    std::cout << birthday.get_month() << " / " 
              << birthday.get_date() << " / " 
              << birthday.get_year() << std::endl;

}

int main ( )
{

    testValdiation();

}



