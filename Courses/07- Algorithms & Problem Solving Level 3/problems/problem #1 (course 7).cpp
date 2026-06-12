
#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	return  rand() % (To - From + 1) + From;
}
void FillMatrix(int numbers[3][3], short Rows, short Cols) {

	for (int i = 0;i < Rows;i++) {

		for (int j = 0;j < Cols;j++) {
			numbers[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintRandomMatrix(int numbers[3][3], short Rows, short Cols) {
	
	for (int i = 0;i < Rows;i++) {

		for (int j = 0;j < Cols;j++) {
			cout <<setw(3) << numbers[i][j] <<"\t";
		}
		cout << endl;
	}

}
int main() {
	srand((unsigned)time(NULL));
	int numbers [3][3];
	FillMatrix(numbers, 3,3);

	cout << "The following is a 3x3 random matrix:\n";
	PrintRandomMatrix(numbers,3,3);
}
