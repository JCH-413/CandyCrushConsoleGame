#include "../include/CandyCrushTimer.h"
#include<iostream>
#include<Windows.h>
using namespace std;
void timing(int mode)
{
	static int hour = 0, min = 0, sec = 0;
	if (mode == 0) sec = 60;
	else sec = 40;
	while (hour != 0 || min != 0 || sec != 0) {
		if (min == 0 && sec == 0) {
			hour--;
			min = 60;
		}
		if (sec == 0) {
			min--;
			sec = 60;
		}
		sec--;
		cout << "\n\t\t\t" << hour << ":" << min << ":" << sec << endl;
		Sleep(1000);
	}
}