#include <iostream>
#include <vector>
#include "Question.hpp"
#ifndef _SCORE_HPP
#define _SCORE_HPP
using namespace std;

class Score() {

private:
	int total_score;

public:

	void calculateScore(int);
	int getTotalscore();
};

#endif // _SCORE_HPP
