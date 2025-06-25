#include"CandyCrushLogic.h"
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void menu(int i)
{
	const int options = 5;
	char choose[options];
	for (int j = 0; j < options; ++j)
		if (j != i)
			choose[j] = ' ';
		else
			choose[j] = '<';
	system("cls");
	cout << "\t\t\t**** CANDY CRUSH ****" << endl << endl;
	cout << "\t\t\tMENU" << endl << endl;
	cout << "\t\t1. Play Game" << setw(4) << choose[0] << endl;
	cout << "\t\t2. Credits" << setw(4) << choose[1] << endl;
	cout << "\t\t3. Instructions" << setw(4) << choose[2] << endl;
	cout << "\t\t4. Score" << setw(4) << choose[3] << endl;
	cout << "\t\t5. End Game" << setw(4) << choose[4] << endl;
}

void mode(int i)
{
	const int options = 2;
	char choose[options]; 
	for (int j = 0; j < options; ++j)
		if (j != i)
			choose[j] = ' ';
		else
			choose[j] = '<';
	system("cls");
	cout << "\t\t\t***PLAY GAME***" << endl << endl;
	cout << endl;
	cout << "\n\t\tChoose Difficulty Level:" << endl << endl;
	cout << "\t\t\tEasy Mode" << setw(4) << choose[0] << endl;
	cout << "\t\t\tHard Mode" << setw(4) << choose[1] << endl;
}
void options(int opNum)
{
	if (opNum == 2) {
		cout << "\t\t\t***CREDITS***" << endl << endl;
		cout << "\t\t~ CANDY CRUSH\n\t\tMade By" << endl << endl;
		cout << "\t\t\tStudents of FAST NUCES CFD CAMPUS\n" << endl;
		cout << "\t\t\tJUNAID A. CHAUDHARY - 22F-3332" << endl;
		cout << "\t\t\tMUHAMMAD AHMED - 22F-3866" << endl;
		cout << "\n\t\tMay GOD help rich people. Amen :)" << endl << endl;
	}
	else if (opNum == 3) {
		cout << "\t\t\t***INSTRUCTIONS***" << endl << endl;
		cout << "\n\t1. You can move cursor with arrow keys" << endl;
		cout << "\n\t2. You can swap candies with (W for up, S for down, D for right and A for left)" << endl;
		cout << "\n\t3. Horizontal and Vertical (both) match gets 10 points." << endl;
		cout << "\n\t4. Diagonals (both) match gets 20 points." << endl;
		cout << "\n\t5. L shape (with 5 candies exactly at same positions) match gets 25 points." << endl;
		cout << "\n\t6. There is a total of 15 moves." << endl;
		cout << "\n\t7. For Easy Mode, the timer is set to 60 seconds with a 8 x 8 Grid." << endl;
		cout << "\n\t8. For Hard Mode, the timer is set to 40 seconds with a 10 x 10 Grid." << endl << endl;
	}
	else if (opNum == 4) {
		cout << "\t\t\t***SCORE***" << endl << endl;
	}
}

void candyGrid(char gridInput[][11], int gridSizeR, int gridSizeC, int mode)
{	
	cout << endl << endl;
	for (int i = 0; i <= gridSizeR; ++i) {
		cout << "\t";
		for (int j = 0; j <= gridSizeR * 2; ++j)
			cout << setw(4) << "-";
		cout << "\n\t";
		cout << setw(4);
		if (i == gridSizeR)
			break;
		for (int k = 0; k <= gridSizeC; ++k) {
			cout << "|" << setw(4);
			if (k != gridSizeC) {
				switch (gridInput[i][k]) {
				case '@':
					SetConsoleTextAttribute(color, 3);
					break;
				case '#':
					SetConsoleTextAttribute(color, 8);
					break;
				case '$':
					SetConsoleTextAttribute(color, 10);
					break;
				case '%':
					SetConsoleTextAttribute(color, 11);
					break;
				case '^':
					SetConsoleTextAttribute(color, 12);
					break;
				case '&':
					SetConsoleTextAttribute(color, 13);
					break;
				case '*':
					SetConsoleTextAttribute(color, 14);
					break;
				default:
					SetConsoleTextAttribute(color, 15);
					break;
				}
				cout << gridInput[i][k] << setw(4);
			}
			SetConsoleTextAttribute(color, 15);
		}
		cout << "\n";
	}
}

void move(char candyMove[][11], int mode, int Rindex, int Cindex)
{
	int n, m;
	if (mode == 0) n = m = 8;
	else n = m = 10;
	char temp = candyMove[Rindex][Cindex];
	candyMove[Rindex][Cindex] = 'X';
	candyGrid(candyMove, n, m, mode);
	candyMove[Rindex][Cindex] = temp;
}

void fillCandy(char candy[][11], int mode)
{
	int maxRow, maxCol, numOfCandies;
	bool foundSame;
	char temp[11][11];
	char candies[7] = { '@', '#', '$', '%', '^', '&', '*' };

	if (mode == 0) { maxRow = maxCol = 8; numOfCandies = 5; }
	else { maxRow = maxCol = 10; numOfCandies = 7; }
	
	srand(time(0));
	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			foundSame = false;
			do {
				int randIndex = rand() % numOfCandies; 
				temp[i][j] = candies[randIndex];
				if (temp[i][j] == temp[i - 1][j] || temp[i][j] == temp[i][j - 1] || 
					temp[i][j] == temp[i - 2][j - 2] || temp[i][j] == temp[i - 2][j + 2]) {
					foundSame = false;
					continue;
				}
				else {
					foundSame = true;
					candy[i][j] = temp[i][j];
				}
			} while (!foundSame);
		}
	}
}

void newCandies(char candy[][11], int mode)
{
	int maxRow, maxCol, numOfCandies;
	if (mode == 0) { maxRow = maxCol = 8; numOfCandies = 5; }
	else { maxRow = maxCol = 10; numOfCandies = 7; }
	char candies[7] = { '@', '#', '$', '%', '^', '&', '*' };

	srand(time(0));
	for(int i = 0; i < maxRow; ++i)
		for (int j = 0; j < maxCol; ++j) 
			if (candy[i][j] == ' ') {
				int randIndex = rand() % numOfCandies;
				candy[i][j] = candies[randIndex];
			}
}

void dropDown(char candy[][11], int mode) {
	int maxRow, maxCol;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	while (checkAbove(candy, mode)) 
		for (int i = 0; i < maxRow - 1; ++i) 
			for (int j = 0; j < maxCol; ++j) 
				if (candy[i + 1][j] == ' ') {
					candy[i + 1][j] = candy[i][j];
					candy[i][j] = ' ';
				}
}

bool checkAbove(char candy[][11], int mode) 
{
	int maxRow, maxCol;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	for (int i = 0; i < maxRow; ++i) 
		for (int j = 0; j < maxCol; ++j) 
			if (candy[i][j] == ' ') 
				for (int k = i; k >= 0; --k) 
					if (candy[k][j] != ' ')
						return true;
	return false;
}

int crushType;
bool candyCrush(char candy[][11], int Rindex, int Cindex, int mode)
{
	crushType = 0;
	int maxRow, maxCol;
	if (mode == 0)  maxRow = maxCol = 8; 
	else maxRow = maxCol = 10;

	if (maxRow - Rindex > 2) {		//check for down side consecutive candies
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex] && candy[Rindex][Cindex] == candy[Rindex + 2][Cindex]) {
			crushType = 1;
			return true;
		}
	}
	if (maxCol - Cindex > 2) {		//check for right side consecutive candies
		if (candy[Rindex][Cindex] == candy[Rindex][Cindex + 1] && candy[Rindex][Cindex] == candy[Rindex][Cindex + 2]) {
			crushType = 2;
			return true;
		}
	}
	if (maxRow - Rindex > 2 && maxCol - Cindex > 2) {	//check for diagonal up to down
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex + 1] && candy[Rindex][Cindex] == candy[Rindex + 2][Cindex + 2]) {
			crushType = 3;
			return true;
		}
	}
	if (maxRow - Rindex > 2 && Cindex > 1) {	//check for reverse diagnol up to down
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex - 1] && candy[Rindex][Cindex] == candy[Rindex + 2][Cindex - 2]) {
			crushType = 4;
			return true;
		}
	}
	if (Rindex > 1) {		//check for up side consecutive candies
		if (candy[Rindex][Cindex] == candy[Rindex - 1][Cindex] && candy[Rindex][Cindex] == candy[Rindex - 2][Cindex]) 
			return true;
	}
	if (Cindex > 1) {		//check for left side consecutive candies	
		if (candy[Rindex][Cindex] == candy[Rindex][Cindex - 1] && candy[Rindex][Cindex] == candy[Rindex][Cindex - 2]) 
			return true;
	}
	if (maxRow - Rindex > 1 && Rindex > 0) {	//check for one up and one down consecutive candies
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex] && candy[Rindex][Cindex] == candy[Rindex - 1][Cindex]) 
			return true;
		
	}
	if (maxCol - Cindex > 1 && Cindex > 0) {	//check for one left and one right consecutive candies	
		if (candy[Rindex][Cindex] == candy[Rindex][Cindex + 1] && candy[Rindex][Cindex] == candy[Rindex][Cindex - 1]) 		
			return true;
		
	}
	if (Rindex > 1 && Cindex > 1) {		//check for diagonal down to up
		if (candy[Rindex][Cindex] == candy[Rindex - 1][Cindex - 1] && candy[Rindex][Cindex] == candy[Rindex - 2][Cindex - 2]) 	
			return true;
		
	}
	if (maxRow - Rindex > 1 && Rindex > 0 && maxCol - Cindex > 1 && Cindex > 0) { //check for diagonal both up n down
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex + 1] && candy[Rindex][Cindex] == candy[Rindex - 1][Cindex - 1]) 
			return true;
		
	}
	if (Rindex > 1 && maxCol - Cindex > 2) {	//check for reverse diagnol down to up
		if (candy[Rindex][Cindex] == candy[Rindex - 1][Cindex + 1] && candy[Rindex][Cindex] == candy[Rindex - 2][Cindex + 2]) 	
			return true;
		
	}
	if (maxRow - Rindex > 1 && Rindex > 0 && maxCol - Cindex > 1 && Cindex > 0) {	 //check for reverse diagonal both up n down
		if (candy[Rindex][Cindex] == candy[Rindex + 1][Cindex - 1] && candy[Rindex][Cindex] == candy[Rindex - 1][Cindex + 1]) 
			return true;
		
	}
	return false;
}

void swap(char candy[][11], int Rind1, int Cind1, int Rind2, int Cind2)
{
	char tempSwap = candy[Rind1][Cind1];
	candy[Rind1][Cind1] = candy[Rind2][Cind2];
	candy[Rind2][Cind2] = tempSwap;
}

bool validMove(char candy[][11], int mode, int Rind1, int Cind1, int Rind2, int Cind2) 
{
	swap(candy, Rind1, Cind1, Rind2, Cind2);
	if (candyCrush(candy, Rind1, Cind1, mode) || candyCrush(candy, Rind2, Cind2, mode)) {
		swap(candy, Rind1, Cind1, Rind2, Cind2);
		return true;
	}
	else {
		swap(candy, Rind1, Cind1, Rind2, Cind2);
		return false;
	}
}

void blowCandy(char candy[][11], int mode)
{
	int maxRow, maxCol;
	int score = 0;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;

	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			if (candyCrush(candy, i, j, mode))
				blowTheCandy(candy, i, j, mode, crushType);
		}
	}
}

void blowTheCandy(char candy[][11], int Rind, int Cind, int mode, int type)
{
	char a = candy[Rind][Cind];
	int maxRow, maxCol;
	//static int score = 0;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	switch (type) {
	case 1:
		for (int i = Rind; i < maxRow && a == candy[i][Cind]; ++i) {	//vertical candy boom
			candy[i][Cind] = ' ';
		}
		break;
	case 2:
		for (int j = Cind; j < maxCol && a == candy[Rind][j]; ++j) { //horizontal candy boom
			candy[Rind][j] = ' ';
		} 
		break;
	case 3:
		for (int i = Rind, j = Cind; i < maxRow && j < maxCol && a == candy[i][j]; ++i, ++j) { //diagonal candy boom
			candy[i][j] = ' ';
		} 
		break;
	case 4: 
		for (int i = Rind, j = Cind; i < maxRow && j > 0 && a == candy[i][j]; ++i, --j) { //reverse diagonal candy boom
			candy[i][j] = ' ';
		} 
		break;
	}
}

void shuffle(char candy[][11], int mode)
{
	int maxRow, maxCol, check;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	check = needToShuffle(candy, mode);
	//do {
		if (check == maxRow * maxCol)
			fillCandy(candy, mode);
		//check = needToShuffle(candy, mode);
	//} while (check == maxRow * maxCol);
}

int needToShuffle(char candy[][11], int mode)
{
	int maxRow, maxCol, noSwapAvailable;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	noSwapAvailable = 0;
	for (int i = 0; i < maxRow; ++i)
		for (int j = 0; j < maxCol; ++j)
			if (!candyCrush(candy, i, j, mode))
				noSwapAvailable++;
	return noSwapAvailable;
}

bool againBlowCandy(char candy[][11], int mode)
{
	int maxRow, maxCol;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;

	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			if (candyCrush(candy, i, j, mode))
				return true;
		}
	}
	return false;
}

void scoreCal(char candy[][11], int mode, int& score)
{
	int maxRow, maxCol;
	int type = 0, count = 0;
	if (mode == 0)  maxRow = maxCol = 8;
	else maxRow = maxCol = 10;
	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			if (candy[i][j] == ' ') {
				for (int k = i + 1, count = 0; k < i + 3 && candy[k][j] == ' '; ++k, ++count)	//vertical
					if (count == 1)	
						score += 10;
				for (int k = j + 1, count = 0; k < j + 3 && candy[i][k] == ' '; ++k, ++count)	//horizontal
					if (count == 1)
						score += 10;
				for (int k = i + 1, l = j + 1, count = 0; k < i + 3 && l < j + 3 && candy[k][l] == ' '; ++k, ++l, ++count)	//diagonal
					if (count == 1)
						score += 20;
				for (int k = i + 1, l = j - 1; k < i + 3 && l < j - 3 && candy[k][l] == ' '; ++k, --l, ++count)	//reverse diagonal
					if (count == 1)
						score += 20;
			}
		}
	}
}