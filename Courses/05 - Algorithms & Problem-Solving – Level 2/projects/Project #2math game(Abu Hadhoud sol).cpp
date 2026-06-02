#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOP = 5 };

struct stQuestion {

	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel QuestionsLevel;
	enOpType OpType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnsweResult = false;
};

struct stQuizz {
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionsLevel QuestionsLevel;
	enOpType OpType;
	short NumberOfCorrectAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

int RandomNumber(int From, int To) {
	return  rand() % (To - From + 1) + From;
}

int SimpleCalculator(int Number1, int Number2, enOpType OpType) {

	switch (OpType) {

		case Add:
			return Number1 + Number2;
		case Sub:
			return Number1 - Number2;
		case Mul:
			return Number1 * Number2;
		case Div:
			return Number1 / Number2;
		default:
			return Number1+ Number2;
	}

}



stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOpType OpType) {

	stQuestion Question;
	if (QuestionsLevel == enQuestionsLevel::Mix) {

		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOpType::MixOP) {

		OpType = (enOpType)RandomNumber(1, 4);
	}

	Question.OpType = OpType;

	switch (QuestionsLevel) {

	case Easy :
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
		Question.QuestionsLevel = QuestionsLevel;


		return Question;

	case Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
		Question.QuestionsLevel = QuestionsLevel;


		return Question;

	case Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
		Question.QuestionsLevel = QuestionsLevel;


		return Question;
	}


}


void GenerateQuizzQuestions(stQuizz& Quizz) {

	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

		Quizz.QuestionList[QuestionNumber] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
	}
}


short ReadHowManyQuestions() {
	short NumberOfQuestions;
	do {
		cout << "Please, enter How many questions do you want to answer ? ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

	return NumberOfQuestions;
}
enQuestionsLevel ReadQuestionsLevel() {

	short QuestionsLevel;
	do {

		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionsLevel;


	} while (QuestionsLevel < 1 || QuestionsLevel > 4);

	return (enQuestionsLevel)QuestionsLevel;
}
enOpType ReadOpType() {
	short OpType;
	do {
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] MixOP ? ";
		cin >> OpType;
		cout << "\n\n";
	} while (OpType < 1 || OpType > 5);

	return (enOpType)OpType;
}

int ReadPlayerAnswer() {
	int Answer;
	cin >> Answer;
	return Answer;
}

string GetOpTypeSymbol(enOpType OpType) {


	switch (OpType) {

	case enOpType::Add:
		return "+";
		break;

	case enOpType::Sub:
		return "-";
		break;

	case enOpType::Mul:
		return "*";
		break;

	case enOpType::Div:
		return "/";
		break;

	}

}
void PrintQuestionInfo(stQuizz Quizz, short QuestionNumber) {
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " " << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OpType) << endl;
	cout << "________\n";
}

void CorrectTheQuestionAnswer(stQuizz & Quizz, short QuestionNumber) {

	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
		Quizz.QuestionList[QuestionNumber].AnsweResult = false;
		Quizz.NumberOfWrongAnswers++;
		cout << "\a";
		system("color 4F");
		cout << "Wrong Result :(\n";
		cout << "The Right Result is :";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl << endl;
	}
	else {
		Quizz.QuestionList[QuestionNumber].AnsweResult = true;
		Quizz.NumberOfCorrectAnswers++;
		system("color 2F");
		cout << "Right Result :)\n\n";
		
	}
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {

	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

		PrintQuestionInfo(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);

	}

}

string GetFinalResultText(bool IsPass) {

	if (IsPass)
		return "PASS";
	else
		return "Fail";
	
}

string GetQuestionLevelText(enQuestionsLevel QuestionsLevel) {

	string arrQuestionsLevel[4] = { "Easy", "Med", "Hard" , "Mix" };
	return arrQuestionsLevel[QuestionsLevel - 1];

}

string GetOpTypeText(enOpType OpType) {
	string arrOp[5] = { "Add" , "Sub" , "Mul" , "Div", "MixOP" };
	return arrOp[OpType - 1];
}
void PrintQuizzResult(stQuizz Quizz) {
	cout << "__________________________________________\n\n";
	cout << "Final Result is " << GetFinalResultText(Quizz.IsPass) << endl;
	cout << "__________________________________________\n\n";
	cout << "Number of questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
	cout << "OpType             : " << GetOpTypeText(Quizz.OpType) << endl;
	cout << "Number Of Right Answers: " << Quizz.NumberOfCorrectAnswers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "__________________________________________\n\n";
}

void PlayMathGame() {

	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOpType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResult(Quizz);
}



void restartScreen() {

	system("cls");
	system("color 0F");
}


void StartGame() {
	char PlayAgain = 'Y';

	do {
		restartScreen();
		PlayMathGame();
		

		cout << "Do you want to play again? (Y/N) ?";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');



}

int main() {

	srand((unsigned)time(NULL));
	StartGame();
}