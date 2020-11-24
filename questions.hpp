include <fstream>
enum Zodiacs{AQUARIUS, PISCES, ARIES, TAUROS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SAGITTARIUS, CAPRICORN};
enum InputMethod{QUESTIONS, SCORING, MULTICHOICE};

class Question{
	private:
		int questionNumber;
		string question;
		vector<string> answers;
		char answer;
	public:
		Question(int qNum){
			vector<string> inputQuestions;
			vector<string> inputAnswers;
	
			inputFileVector("questions.txt", inputQuestions, QUESTIONS);
			inputFileVector("answers.txt", inputAnswers, QUESTIONS);
			createQuestion(inputQuestions[qNum]);
			for(int j = 0; j < 5; j++){
				createAnswer(inputAnswers[j + 5 * qNum]);
			}
		};
		
		void createQuestion(string q){
			question = q;
		}
		
		void createAnswer(string a){
			answers.push_back(a);
		}
		
		void printQuestion(){
			cout << question << endl;
			for(int i = 0; i < answers.size(); i++){
				cout << answers.at(i) << endl;
			}
			
			do{
				cin >> answer;
			}while(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd' && answer != 'e');
		}
		
		void inputFileVector(string filename, vector<string> & inputs, int method){
			ifstream inFile(filename);
			
			if(!inFile){
				cout<<"Error opening text file."<<endl;
				exit(0);
			}
			
			string input;
			switch(method){
				case QUESTIONS:
				case MULTICHOICE:
					for (string line; getline(inFile, line); /**/) {
						inputs.push_back(line);
					}
					break;
			}
			inFile.close();
		}
};
