#ifndef __BIRTHDAY_HPP__
#define __BIRTHDAY_HPP__


class Birthday {
    private:
        int month;
        int date;
        int year;

    public:

        // ---------------------------- Constructors ----------------------------
        Birthday();
        Birthday( int month, int date, int year);

        // ------------------------- modifiers/ settors -------------------------
        void set_month( int month );
        void set_date( int date );
        void set_year( int year );

        // ------------------------- accessors/ getters -------------------------
        int get_month();
        int get_date();
        int get_year();
};

#endif //__BIRTHDAY_HPP__

