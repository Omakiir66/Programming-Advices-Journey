
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
			cout << setw(3) << numbers[i][j] << "\t";
		}
		cout << endl;
	}

}


int RowSum(int numbers[3][3], short RowNumber, short Cols) {
	int sum = 0;
	for (int i = 0;i < Cols;i++) {

		sum += numbers[RowNumber][i];
	}
	return sum;

}

void PrintSumOfEachRow(int numbers[3][3], short Rows, short Cols) {

	for (int i = 0;i < Rows;i++) {

		cout << "Row " << i + 1 << " Sum = " << RowSum(numbers,i,Cols) << endl;
	}
	
}
int main() {
	srand((unsigned)time(NULL));
	int numbers[3][3];
	
	FillMatrix(numbers, 3, 3);
	cout << "The following is a 3x3 random matrix:\n";
	PrintRandomMatrix(numbers, 3, 3);

	cout << "\nThe following are the sum of each row in the matrix:\n";
	PrintSumOfEachRow(numbers, 3, 3);
	
}
