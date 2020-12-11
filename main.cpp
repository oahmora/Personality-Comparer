#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

#include "header/questions.hpp"

using namespace std;
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
}
