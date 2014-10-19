#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <algorithm>
#include <fstream>

using namespace std;

enum WeekDay {
	SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};


enum themes {
	ADVENTURE, SPORT, COMIC, ROMANCE, MISTERY
};


string inputString();
int Value();
void ClearScr();
void hideCursor();
string convertToLowerCase (string Word);
string convertToUpperCase (string Word);
vector <int> parsingInput(string line);
WeekDay convertStringToWeekDay(string day);
string convertWeekDayToString(WeekDay day);
themes convertStringToTheme(string type);
string convertThemeToString(themes type);
string convertIntToString(int number);
bool checkValidWeekDay(string day);
bool checkValidTheme(string type);
