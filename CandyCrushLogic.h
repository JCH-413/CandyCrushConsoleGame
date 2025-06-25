#pragma once
void menu(int);
void options(int);
void mode(int);
void candyGrid(char[][11], int, int, int);
void move(char[][11], int, int, int);
void fillCandy(char[][11], int);
bool candyCrush(char[][11], int, int, int);
void swap(char[][11], int, int, int, int);
bool validMove(char[][11], int, int, int, int, int);
void blowCandy(char[][11], int);
void blowTheCandy(char[][11], int, int, int, int);
void shuffle(char[][11], int);
int needToShuffle(char[][11], int);
void newCandies(char[][11], int);
void dropDown(char[][11], int);
bool checkAbove(char[][11], int);
bool againBlowCandy(char[][11], int);
void scoreCal(char[][11], int, int&);
