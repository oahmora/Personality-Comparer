#ifndef _SCORE_HPP
#define _SCORE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

/*constant of number of lines to read*/
#define MAX_ANSWERS 12

using namespace std;


class Score{

	public:
		int calculateScore(const string & filename);
		int getTotalscore(int aScore, int bScore, int cScore, int dScore);
};

#endif //!_SCORE_HPP
