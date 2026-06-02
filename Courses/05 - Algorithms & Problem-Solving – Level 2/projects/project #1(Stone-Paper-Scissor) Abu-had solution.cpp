#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

enum enGameChoices {Stone =1, Paper =2, Scissor=3};
enum enWinner { Player = 1, Computer =2, Draw =3 };

struct stRoundInfo {
	short RoundNumber = 0;
	enGameChoices Player1Choice;
	enGameChoices ComputerChoice;
	enWinner Winner;
	string WinnerName;

};
struct stGameResults {
	short GameRounds = 0;
	short Player1WonTimes  =0;
	short ComputerWonTimes = 0;
	short DrawTimes =0;
	enWinner FinalWinner;
	string FinalWinnerName = "";
};


int RandomNumber(int From, int To) {
	return  rand() % (To - From + 1) + From;
}

short ReadNumberOfRounds() {

	short NumberOfRounds;
	do {
		cout << "How many Rounds from 1 to 10 you want to play? ";
		cin >> NumberOfRounds;

	} while (NumberOfRounds < 1 || NumberOfRounds >10);

	return NumberOfRounds;
}

enGameChoices ReadPlayerChoice() {
	short Playerchoice;
	cout << "\n\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
	cin >> Playerchoice;
	return enGameChoices(Playerchoice);
}
enGameChoices GetComputerChoice() {

	return (enGameChoices)RandomNumber(1, 3);
}

enWinner WhoWinTheRound(stRoundInfo RoundInfo){
	if (RoundInfo.ComputerChoice == RoundInfo.Player1Choice) {
		system("color 6F");
		return enWinner::Draw;
	}
		

	switch (RoundInfo.Player1Choice)
	{

	case enGameChoices::Stone:
		if (RoundInfo.ComputerChoice == enGameChoices::Paper) {
			cout << "\a";
			system("color 4F");
			return enWinner::Computer;
		}
		break;

	case enGameChoices::Paper:
		if (RoundInfo.ComputerChoice == enGameChoices::Scissor) {
			cout << "\a";
			system("color 4F");
			return enWinner::Computer;
		}
		break;


	case enGameChoices::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoices::Stone) {
			cout << "\a";
			system("color 4F");
			return enWinner::Computer;
		}
		break;
	}
	system("color 2F");
	return enWinner::Player;
		
}
enWinner WhoWinTheGame(short Player1WinTimes, short ComputerWinTimes) {

	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;

}


string WinnerName(enWinner Winner) {
	string arrWinner[3] = { "Player " , "Computer" , "No Winner"};
	return arrWinner[Winner - 1];
}
string ChoiceName(enGameChoices GameChoice) {
	string arrChoice[3] = { "Stone" , "Paper", "Scissor"};
	return arrChoice[GameChoice - 1];
}



string tabs(int number) {
	string t = "";

	for (int i = 0; i < number;i++) {

		t = t + "\t";
	}
	return t;
}
void PrintRoundResults(stRoundInfo RoundInfo) {
	cout << "\n______________Round [" << RoundInfo.RoundNumber  << "]___________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice)<< endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	cout << "__________________________________\n";

}
void ShowGameOverScreen() {
	cout << endl;
	cout << tabs(2) << "____________________________________________________________________\n\n";
	cout << tabs(5) << "+++ G a m e  O v e r +++\n\n";
	cout << tabs(2) << "____________________________________________________________________\n\n";
}
void PrintFinalResults(stGameResults GameResults) {
	cout << tabs(2) << "_________________________[Game Results]_____________________________\n";
	cout << tabs(2) << "Game Rounds        :" << GameResults.GameRounds << endl;
	cout << tabs(2) << "Player1 won times  :" << GameResults.Player1WonTimes << endl;
	cout << tabs(2) << "Computer won times :" << GameResults.ComputerWonTimes << endl;
	cout << tabs(2) << "Draw times         :" << GameResults.DrawTimes << endl;
	cout << tabs(2) << "Final Winner       :" << GameResults.FinalWinnerName << endl;
	cout << tabs(2) << "____________________________________________________________________\n";
}


stGameResults FillGameResults(short NumberOfRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) {
	stGameResults GameResults;

	GameResults.GameRounds = NumberOfRounds;
	GameResults.Player1WonTimes = Player1WinTimes;
	GameResults.ComputerWonTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.FinalWinner = WhoWinTheGame(Player1WinTimes,ComputerWinTimes);
	GameResults.FinalWinnerName = WinnerName(GameResults.FinalWinner);

	return GameResults;
}

stGameResults PlayGame(short NumberOfRounds) {

	stRoundInfo RoundInfo;
	short Player1WinTimes =0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short RoundNumber = 1; RoundNumber <= NumberOfRounds; RoundNumber++) {

		RoundInfo.RoundNumber = RoundNumber;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner:: Player)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++ ;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(NumberOfRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);


}


void restartScreen() {

	system("cls");
	system("color 0F");
}


void StartGame() {
	char PlayAgain = 'Y';

	do {
		restartScreen();
		stGameResults GameResults = PlayGame(ReadNumberOfRounds());
		ShowGameOverScreen();
		PrintFinalResults(GameResults);
		cout << "Do you want to play again? (Y/N) ?";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');



}

int main() {

	srand((unsigned)time(NULL));
	StartGame();
}