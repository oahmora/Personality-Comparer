#include "../header/questions.hpp"

TEST(QuizTest, Quiz) {
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
	int ansNum = 5;
	int qNum = 2;
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, ansNum);
	quiz->createQuiz();
	
	ASSERT_EQ(quiz->getQuestionsTotal(), qNum);
	
	for(int i = 0; i < qNum; i++){
		EXPECT_EQ(quiz->getQuestion(i), testQuestion.at(i));
		for(int j = 0; j < ansNum; j++){
			EXPECT_EQ(quiz->getAnswers(i, j), testAnswers.at(j + i*5));
		}
	}
}

TEST(QuestionTest, BasicQuestion){
	Question* question = new Question(0);
	question->createQuestion("This is question class test question 1");
	
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
	int ansNum = 5;
	
	for(int i = 0; i < ansNum; i++)
		question->createAnswer(testAnswers.at(i));
	
	EXPECT_EQ(question->getQuestion(), "This is question class test question 1");
	for(int j = 0; j < ansNum; j++){
			EXPECT_EQ(question->getAnswers(j), testAnswers.at(j));
	}
}

TEST(QuestionTest, LongQuestion){
	Question* question = new Question(0);
	question->createQuestion("!!\n!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	EXPECT_EQ(question->getQuestion(), "!!\n!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}

TEST(QuizTest, Questions100){
	vector<string> testQuestion(100, "0");
	vector<string> testAnswers(500, "5");
	
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	quiz->createQuiz();
	
	ASSERT_EQ(quiz->getQuestionsTotal(), 100);
}

TEST(QuestionTest, Empty){
	Question* question = new Question(0);
	question->createQuestion("");
	
	EXPECT_EQ(question->getQuestion(), "");
}

TEST(QuizTest, Answers100){
	int answerNumber = 100;
	vector<string> testQuestion(1, "0");
	vector<string> testAnswers(answerNumber, "5");
	
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, answerNumber);
	quiz->createQuiz();
	
	ASSERT_EQ(quiz->getNumAnswers(), 100);
}

TEST(QuizTest, ValidateInputsFail){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d"};
	
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 4);
	EXPECT_EQ(quiz->validateSize(), false);
}

TEST(QuizTest, ValidateInputsPass){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
	
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	EXPECT_EQ(quiz->validateSize(), true);
}

TEST(QuizTest, ValidateInputsBadnum){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
	
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 3);
	EXPECT_EQ(quiz->validateSize(), false);
}

TEST(QuizTest, TestResponses){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	quiz->createQuiz();
	
	quiz->recordResponse(0, 'a');
	quiz->recordResponse(1, 'b');
	
	EXPECT_EQ(quiz->getResponse(0), 'a');
	EXPECT_EQ(quiz->getResponse(1), 'b');
}

TEST(QuizTest, TestQuestionsGet){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
									
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	quiz->createQuiz();
	
	EXPECT_EQ(quiz->getQuestion(1), "This is test question 2.");
}

TEST(QuizTest, TestAnswersGet){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
									
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	quiz->createQuiz();
	
	EXPECT_EQ(quiz->getAnswers(0, 1), "b: answer b");
}

TEST(QuizTest, OutputTest){
	vector<string> testQuestion = {"This is test question 1.", "This is test question 2."};
	vector<string> testAnswers = {"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e",
									"a: answer a", "b: answer b", "c: answer c", "d: answer d", "e: answer e"};
									
	Quiz* quiz = new Quiz();
	quiz->importQuestionsVector(testQuestion, testAnswers, 5);
	quiz->createQuiz();
	
	EXPECT_EQ(quiz->getQuestion(0), "This is test question 1.");
	EXPECT_EQ(quiz->getQuestion(1), "This is test question 2.");
	EXPECT_EQ(quiz->getAnswers(0, 0), "a: answer a");
	EXPECT_EQ(quiz->getAnswers(0, 1), "b: answer b");
	EXPECT_EQ(quiz->getAnswers(0, 2), "c: answer c");
	EXPECT_EQ(quiz->getAnswers(0, 3), "d: answer d");
	EXPECT_EQ(quiz->getAnswers(0, 4), "e: answer e");
	EXPECT_EQ(quiz->getAnswers(1, 0), "a: answer a");
	EXPECT_EQ(quiz->getAnswers(1, 1), "b: answer b");
	EXPECT_EQ(quiz->getAnswers(1, 2), "c: answer c");
	EXPECT_EQ(quiz->getAnswers(1, 3), "d: answer d");
	EXPECT_EQ(quiz->getAnswers(1, 4), "e: answer e");
}
