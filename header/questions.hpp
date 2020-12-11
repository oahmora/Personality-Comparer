#include <fstream>
enum Zodiacs{AQUARIUS, PISCES, ARIES, TAUROS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SAGITTARIUS, CAPRICORN};

using namespace std;

class Question{
	private:
		int questionNumber;
		string question;
		vector<string> answers;
		char response;
	public:
		Question(int questionNumber){
			this->questionNumber = questionNumber;
		};
		
		void createQuestion(string question){
			this->question = question;
		}
		
		void createAnswer(string answer){
			this->answers.push_back(answer);
		}

		void inputResponse(char response){
			this->response = response;
		}
		
		char getResponse(){
			return this->response;
		}
		
		string getQuestion(){
			return this->question;
		}
		
		string getAnswers(int j){
			return this->answers.at(j);
		}
};

class Quiz{
	private:
		int questionsTotal = 0;
		vector<Question*> questions;
		int numAnswers = 0;
		vector<string> inputQuestions;
		vector<string> inputAnswers;
	
	public:
		Quiz(){};
		
		void importText(string questionsFile, int numAnswers){
			this->numAnswers = numAnswers;
			ifstream inFile(questionsFile);
			if(!inFile){
				cout<<"Error opening text file."<<endl;
				exit(0);
			}
			
			for (string line; getline(inFile, line); /**/) {
				if(line.find(" : ")<line.length()){
					this->inputAnswers.push_back(line);
				}
				else
					this->inputQuestions.push_back(line);
			}
			
			inFile.close();
		}

		void importQuestionsVector(vector<string> q, vector<string> a, int numAnswers){
			this->numAnswers = numAnswers;
			this->inputQuestions = q;
			this->inputAnswers = a;
		}
		
		bool validateSize(){
			return inputQuestions.size() * numAnswers == inputAnswers.size();
		}
		
		void createQuiz(){
			for(int i = 0; i < inputQuestions.size(); i++){
				questions.push_back(new Question(i));
				questions.at(i)->createQuestion(inputQuestions.at(i));
				for(int j = 0; j < numAnswers; j++){
					questions.at(i)->createAnswer(inputAnswers.at(j + (numAnswers) * i));
				}
				this->questionsTotal++;
			}
		}

		char getResponse(int i){
			return this->questions.at(i)->getResponse();
		}
		
		int getQuestionsTotal(){
			return this->questionsTotal;
		}
		
		string getQuestion(int i){
			return this->questions.at(i)->getQuestion();
		}
		
		int getNumAnswers(){
			return this->numAnswers;
		}
		
		string getAnswers(int i, int j){
			return this->questions.at(i)->getAnswers(j);
		}
		
		bool recordResponse(int questionNum, char answer){
			if(answer < 'a' || answer > 'a' + numAnswers - 1){
				return false;
			}
			
			questions.at(questionNum)->inputResponse(answer);
			return true;
		}
		
		void outputAnswerFile(){
			ofstream file("answers.txt");
			
			for(int i = 0; i < questionsTotal; i++){
				file << questions.at(i)->getResponse() << endl;
			}
			
			file.close();
		}
};
