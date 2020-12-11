#include "Score.hpp"

int  calculateScore(const string& filename) {

	int aScore = 0, bScore = 0, cScore = 0, dScore = 0;
	char answers[MAX_ANSWERS][1];
	int count = 0;
	ifstream inFile;
	inFile.open(filename);

	if (inFile.good()) { 
	

		while (!inFile.eof() && (count < MAX_ANSWERS)) {
			inFile.getline(answers[count], 1);
			count++;
		}


		for(int i = 0; i < count; i++){

			if  (answers[i] == "a") {
				aScore += 10;
				
			}	

			if (answers[i] == "b") {
				bScore += 10;
				
			}

			if (answers[i] == "c") {
				cScore += 10;

			}

			if (answers[i] == "d") {
				dScore += 10;
				
			}
			
			
		}
		
	}

	inFile.close();
	
	}

	
int getTotalscore(int aScore, int bScore, int cScore, int dScore) {

	if (aScore > bScore && aScore > cScore && aScore > dScore)
		return aScore;
	if (bScore > aScore && bScore > cScore && bScore > dScore)
		return bScore;
	if (cScore > aScore && cScore > bScore && cScore > dScore)
		return cScore;
	if (dScore > aScore && dScore > bScore && dScore > cScore)
		return dScore;
	}
