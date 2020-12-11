#ifndef __BEHAVIOR_HPP__
#define __BEHAVIOR_HPP__

#include <fstream>
#include <iostream>

/**
 * @brief Behavior a class that reads a text file and returns the contents of
 *        the file as a string
 */
class Behavior {
    public:
        
        /**
         * @brief  constructs an empty Behavior object
         */
        Behavior();

        /**
         * @brief  set_filename sets the Behavior::filename to the given string
         * @param  filename name of the file which'll be opened for writing to
         *         the console
         */
        void set_filename(std::string filename);

        /**
         * @brief  get_filename gets the Behavior::filename
         * @return the Behavior::filename
         */
        std::string get_filename();
    
        /**
         * @brief  get_behavior reads the text from the file associated with
         *         string str and returns the read text from the file
         * @param  str the file name to be where a behavior is stored
         * @return the text read from file
         */
        std::string get_behavior(std::string str);
        
        /**
         * @brief  print_behavior prints the string behavior to the screen
         * @param  behavior the string to be printed to console
         */
        void print_behavior(std::string behavior);
    
    private:

        /**
         * @brief  filename the name of the file that'll be opened for writing
         */
        std::string filename;

        /**
         * @brief  fin fstream to read from a file
         */
        std::ifstream fin;

        /**
         * @brief  open_file opens the file associated with the string filname
         * @param  filename  the name of the file to be opened
         * @return true if the file exist and was opened for reading
         *         exits otherwise
         */
        bool open_file(std::string filename);
        
        /**
         * @brief   read_file reads the text from a file
         * @return  the text read from the file
         */
        std::string read_file();
        
        /**
         * @brief  closes the file previously opened for reading
         */
        void close_file();

        /**
         * @brief  to_lower converts string str to lower case
         * @param  str string to be converted to lower case
         * @return string whose characters are all lower case
         */
        std::string to_lower(std::string str);

};
#endif //__BEHAVIOR_HPP__
