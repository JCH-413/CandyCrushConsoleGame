#include<iostream>
#include<string>
#include<conio.h>
#include "../include/CandyCrushLogic.h"
#include "../include/CandyCrushTimer.h"
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77 

int main()
{
	//system("Color 3F");
	int c = 0, keyPos = 0, keyPosMode = 0;
	bool chooosedPlay = 0;
	do {
		c = 0;
		keyPos = 0;
		while (c != 75)
		{
			menu(keyPos);
			c = 0;

			switch (c = _getch()) {
			case KEY_UP:
				if (keyPos == 0)	//key up
					keyPos = 4;
				else
					--keyPos;
				break;
			case KEY_DOWN:
				if (keyPos == 4) // key down
					keyPos = 0;
				else
					++keyPos;
				break;
			case KEY_LEFT:
				system("cls");
				break;
			}
		}
		if (keyPos != 0 && keyPos != 4) {
			options(keyPos + 1);
			//cout << "Press any key to go back........" << endl; 
			system("pause");
			chooosedPlay = false;
		}
		else
			chooosedPlay = true;
		
	} while (!chooosedPlay);
	
	c = 0;
	if (keyPos == 0) {		//opens difficulty mode menu (easy OR hard mode) 
		while (c != 75)
		{
			mode(keyPosMode);
			c = 0;

			switch (c = _getch()) {
			case KEY_UP:
				if (keyPosMode == 0)	//key up
					keyPosMode = 1;
				else
					--keyPosMode;
				break;
			case KEY_DOWN:
				if (keyPosMode == 1) // key down
					keyPosMode = 0;
				else
					++keyPosMode;
				break;
			case KEY_LEFT:
				system("cls");
				break;
			}
		}
	}
	else {
		cout << "\t\t\t***END***" << endl << endl;
		cout << "\t\tGOOD BYE. <3" << endl;
		return 0;
	}

	const int n = 11, m = 11;
	char candy[n][m];
	string name;
	fillCandy(candy, keyPosMode);
	cout << endl << endl;
	cout << "\t\tEnter Name: ";
	getline(cin, name);
	cout <<"\t" << endl << endl;
	system("pause");
	system("cls");
	
	int i = 0, j = 0, cols, rows, score = 0, moves = 15;
	int Rind1 = 0, Cind1 = 0, Rind2 = 0, Cind2 = 0;
	if (keyPosMode == 0) cols = rows = 7;
	else cols = rows = 9; 
	char  tempSwap = ' ';
	bool isSweet = false, isValidMove = true;
	c = 0;
	while (moves > 0)
	{
		Rind1 =  Cind1 = Rind2 = Cind2 = 0;
		system("cls");
		cout << endl;
		cout << "\tPlayer: " << name << endl;
		cout << "\tMOVES: " << moves << endl;
		cout << "\tSCORE: " << score << endl;
		if (isSweet) cout << "\n\tSWEET !!!" << endl;
		if (!isValidMove) cout << "\n\tINVALID MOVE !!!" << endl;
		isSweet = false; isValidMove = true;
		move(candy, keyPosMode, i, j);
		cout << "\n\n\t\t\t'X' is your cursor.\n\t\t\tCandy Behind the cursor: " << candy[i][j];
		//timing(keyPosMode);	//will show the timing

		c = 0;
		switch (c = _getch()) {

		case KEY_UP:	if (i > 0) i--;		break;
		case KEY_DOWN:	if (i < rows) i++;	break;
		case KEY_LEFT:	if (j > 0) j--;		break;
		case KEY_RIGHT:	if (j < cols) j++;	break;

		case 'w': case 'W':
			if (i > 0) {
				Rind1 = i; Cind1 = j; Rind2 = i - 1; Cind2 = j;
			}
			break;

		case 's': case 'S':
			if (i < rows) {
				Rind1 = i; Cind1 = j; Rind2 = i + 1; Cind2 = j;
			}
			break;

		case 'a': case 'A':
			if (j > 0) {
				Rind1 = i; Cind1 = j; Rind2 = i; Cind2 = j - 1;
			}
			break;

		case 'd': case 'D':
			if (j < cols) {
				Rind1 = i; Cind1 = j; Rind2 = i; Cind2 = j + 1;
			}
			break;
		default:
			continue;
		}
		if (c == 'w' || c == 'W' || c == 's' || c == 'S' || c == 'a' || c == 'A' || c == 'd' || c == 'D') {
			if (validMove(candy, keyPosMode, Rind1, Cind1, Rind2, Cind2)) {
				swap(candy, Rind1, Cind1, Rind2, Cind2);
				do {
					blowCandy(candy, keyPosMode);
					scoreCal(candy, keyPosMode, score);
					dropDown(candy, keyPosMode);
					newCandies(candy, keyPosMode);
					shuffle(candy, keyPosMode); //if there is a need to shuffle it will do it otherwise not
				} while (againBlowCandy(candy, keyPosMode));
				isSweet = true;
				moves--;
			}
			else
				isValidMove = false;
		}
		cout << endl << endl;
	}
	cout << "\n\n\n\t\t\tGAME OVER!!!" << endl;
	cout << "\n\t\t\tYOUR SCORE: " << score;
	cout << endl << endl << endl;
	return 0;
}


