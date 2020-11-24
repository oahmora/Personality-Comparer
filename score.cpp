#include "Score.hpp"

Score::total_score(int){
	int score = 0;
}
void Score::calculateScore(int) {
	
	int counter = 0;
	char answer;
	int score = 0;
	do {
		switch (toupper(answer))
		{
		case 'A':
			score += 10;
			counter += 1;
			break;
		case 'B':
			score += 10;
			counter += 1;
			break;
		case 'C':
			score += 10;
			counter += 1;
			break;
		case 'D':
			score += 10;
			counter += 1;
			break;
		case 'E':
			score += 10;
			counter += 1;
			break;

	} while (counter == 10);
	
}

Score::getTotalscore() {
	// have to figure out what to put here
	// }
