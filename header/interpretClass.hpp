//
//  test.cpp
//  temp
//
//  Created by Yonas Adamu on 12/11/20.
//

#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define ZODIACS_NUMBER 12
enum Zodiacs{AQUARIUS, PISCES, ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SAGGITARIUS, CAPRICORN};

class tallyScores{
private:
    int numAnswers = 0;
    int numQuestions = 0;
    std::vector<std::string> inputResponses;
    std::vector<std::string> answerLineation;
    int zodiacArray[ZODIACS_NUMBER] = {0};
    
    map<std::string, int> ZodiacMap = {
        {"AQUARIUS", 0},
        {"PISCES", 1},
        {"ARIES", 2},
        {"TAURUS", 3},
        {"GEMINI", 4},
        {"CANCER", 5},
        {"LEO", 6},
        {"VIRGO", 7},
        {"LIBRA", 8},
        {"SCORPIO", 9},
        {"SAGITTARIUS", 10},
        {"CAPRICORN", 11}
    };
    
public:
    tallyScores(){ };
    
    void importAnswers(string responseFile){
        ifstream inFile(responseFile);
        if(!inFile){
            cout<<"Error opening text file."<<endl;
            exit(0);
        }
        
        for (string line; getline(inFile, line); /**/) {
            if(!line.empty())
                inputResponses.push_back(line);
        }
        
        this->numQuestions = int(inputResponses.size());
        
        inFile.close();
    }
    
    void importLineation(string lineationFile, int numAnswers){
        this->numAnswers = numAnswers;
        
        ifstream inFile(lineationFile);
        if(!inFile){
            cout<<"Error opening text file."<<endl;
            exit(0);
        }
        
        for (string line; getline(inFile, line); /**/) {
            if(line.find(" : ")<line.length())
                answerLineation.push_back(line);
        }
        
        inFile.close();
    }
    void doScore(){
        for(int i = 0; i < numQuestions; i++){
            string temp2 = inputResponses.at(i);

            for(int j = 0; j < numAnswers; j++){
                string temp1 = answerLineation.at(i * numAnswers + j);
                

                if(temp1.find(temp2)<temp1.length()){
                    auto index = temp1.find_last_of(' ');
                    string last_word = temp1.substr(++index);

                    ++zodiacArray[ZodiacMap.find(last_word)->second];
                }
            }
        }
    }
    
    int getHighScore(){

        int max = 0;
        
        for(int i = 0; i < ZODIACS_NUMBER; i++){
            int temp = zodiacArray[i];
            if(max <= temp){
                max = temp;
            }
        }
        return max;

    }
};
