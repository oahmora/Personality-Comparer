#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <limits>

#include "header/questions.hpp"
#include "header/actualZodiac.hpp"
#include "header/behavior.hpp"


const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[1m\033[34m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

using namespace std;

std::string get_actualZodiac() {
	
    ActualZodiac az = ActualZodiac();
    az.set_birthday();
    return  az.match_zodiac();
}

void output_behavior(std::string str) {
    str = "resources/" + str + ".txt";
    Behavior b = Behavior();
    std::string bvor = b.get_behavior(str);
    std::cout << green ;
    b.print_behavior(bvor);
    std::cout << reset;
} 
    
int main(){
	int numAnswers = 4;
	
	Quiz* quiz = new Quiz();
	quiz->importText("questions.txt", numAnswers);

	//validate input file
	if(quiz->validateSize()==false){
		cout<<"Invalid import. Exiting."<<endl;
		exit(0);
	}
	cout<<"Input file validated. Proceeding with quiz."<<endl;

	cout << "Astrological Divergence: Truest Zodiac" <<endl;
	cout << "Does your personality actualy match your zodiac?"<<endl;
	cout << "The goal of this program is to test your personality and compare it with your birthday zodiac sign."<<endl;
	cout << "Beginning quiz." <<endl;

	char response;
	quiz->createQuiz();
	//quiz->doQuiz();
	
	for(int i = 0; i < quiz->getQuestionsTotal(); i++){
		cout << "Question " << i + 1 << "!" << endl
			 << quiz->getQuestion(i) << endl;
		for(int j = 0; j < quiz->getNumAnswers(); j++){
			cout << quiz->getAnswers(i, j) << endl;
		}
		
		do{
				cin >> response;
		}while(!quiz->recordResponse(i, response));
	}

	cout << endl;
	quiz->outputAnswerFile();
	
	// clear buffer so that no previous input affects actualZodiac inputs	
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	// call create_actualZodiac 
	std::string actualZodiac = get_actualZodiac();
		
	std::cout << "Based on your birthday, your zodiac sign is: " << green
		  << actualZodiac << reset << std::endl;

	std::cout << "Would you like to see discriptions of your zodiac?\n";
	std::cout << "Enter " << cyan << "Y/y" << reset << " for yes: any other key for no: " ;
	std::cout << magenta; 
	char input ; 
	cin >> input; 
	std::cout << reset;

	if(input == 'y' || input == 'Y') {
	    output_behavior(actualZodiac);
	}
	else 
	    std::cout << "Good bye!\n" << std::endl;
}

