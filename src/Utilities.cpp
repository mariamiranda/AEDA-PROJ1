#include "Utilities.h"

string convertToLowerCase (string Word){ //Function to do a case-insensitive search

	for (unsigned int i = 0; i < Word.size(); i++){
		Word[i] = tolower(Word[i]);
	}
	return Word;
}

string convertToUpperCase (string Word){ //Function to do a case-insensitive search

	for (unsigned int i = 0; i < Word.size(); i++){
		Word[i] = toupper(Word[i]);
	}
	return Word;
}

void ClearScr()
{
	printf("\033[2J\033[1;1H"); //console cleaner
}

string inputString()
{
	string nomestring;
	//ClearScr();
	ws(cin); //ignorar espaço antes de introduzir nome
	getline(cin, nomestring);
	if (nomestring.length() > 40)
	{
		ClearScr();
		cout << "Please write only first and last name.";
		Sleep(800);
		return inputString();
	}
	return nomestring;
}

int Value()
{

	int out;
	string in;
	while(true) {

		getline(cin,in);
		stringstream ss(in); //covert input to a stream for conversion to int

		if(ss >> out && !(ss >> in)) return out;

		cin.clear();
		cerr << "\nInvalid input. Please try again.\n";
		Sleep(800);
	}
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO cci = {100, FALSE};

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

/*
vector <int> parsingInput(string line)
		{
	vector <int> IDs;
	stringstream stream(line);

	while (1) {
		int n;
		stream >> n;
		if (!stream)
			break;
		else
			IDs.push_back(n);
	}

	return IDs;

		}
*/

themes convertStringToTheme(string type)
{
	if (type == "ADVENTURE")
		return ADVENTURE;
	else if (type == "SPORT")
		return SPORT;
	else if (type == "COMIC")
		return COMIC;
	else if (type == "ROMANCE")
		return ROMANCE;
	else if (type == "MISTERY")
		return MISTERY;

}

string convertThemeToString(themes type)
{
	if (type == ADVENTURE)
		return "ADVENTURE";
	else if (type == SPORT)
		return "SPORT";
	else if (type == COMIC)
		return "COMIC";
	else if (type == ROMANCE)
		return "ROMANCE";
	else if (type == MISTERY)
		return "MISTERY";

}

WeekDay convertStringToWeekDay(string day)
{
	if (day == "SUNDAY")
		return SUNDAY;
	else if (day == "MONDAY")
		return MONDAY;
	else if (day == "TUESDAY")
		return TUESDAY;
	else if (day == "WEDNESDAY")
		return WEDNESDAY;
	else if (day == "THURSDAY")
		return THURSDAY;
	else if (day == "FRIDAY")
		return FRIDAY;
	else if (day == "SATURDAY")
		return SATURDAY;

}

string convertWeekDayToString (WeekDay day)
{
	if (day == SUNDAY)
		return "SUNDAY";
	else if (day == MONDAY)
		return "MONDAY";
	else if (day == TUESDAY)
		return "TUESDAY";
	else if (day == WEDNESDAY)
		return "WEDNESDAY";
	else if (day == THURSDAY)
		return "THURSDAY";
	else if (day == FRIDAY)
		return "FRIDAY";
	else if (day == SATURDAY)
		return "SATURDAY";

}

string convertIntToString(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

bool checkValidWeekDay(string day)
{
	if ((convertToUpperCase(day) != "SUNDAY") && (convertToUpperCase(day) != "MONDAY") &&  (convertToUpperCase(day) != "TUESDAY") && (convertToUpperCase(day) != "WEDNESDAY") && (convertToUpperCase(day) != "THURSDAY") && (convertToUpperCase(day) != "FRIDAY") && (convertToUpperCase(day) != "SATURDAY"))
		return false;
	else
		return true;
}

bool checkValidTheme(string type)
{

	if ((convertToUpperCase(type) != "ADVENTURE") && (convertToUpperCase(type) != "SPORT") && (convertToUpperCase(type) != "COMIC") &&  (convertToUpperCase(type) != "ROMANCE") && (convertToUpperCase(type) != "MISTERY"))
		return false;
	else
		return true;
}
