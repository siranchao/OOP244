// Final Project Milestone 2
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-2 submission
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Utils.h"

//#include <ctype.h>

using namespace std;
namespace sdds {
	void Utils::getChar(std::istream& is, char ch) {
		if (is.peek() == ch) is.get();
	}

	int Utils::getInt(std::istream& is, int min, int max, const char* message) {
		int res;
		bool flag = false;
		while (!flag) {
			is >> res;
			if (is && is.peek() == '\n') {
				if (res >= min && res <= max) {
					flag = true;
				}
				else {
					is.ignore(1000, '\n');
					cout << "Out of Range, try again: ";
				}
			}
			else {
				is.clear();
				is.ignore(1000, '\n');
				if (message) cout << message;
			}
		}
		return res;
	}

	void Utils::copyStr(char*& des, const char* src) {
		delete[] des;
		des = new char[strlen(src) + 1];
		strcpy(des, src);
	}

	char* Utils::readInput(std::istream& is, char delimeter) {
		const int bufferSize = 20;
		int bufferNo = 1;
		char* buffer = new char[bufferSize];
		char* str = buffer;
		bool done = false;
		do {
			is.getline(str, bufferSize, delimeter);
			if (!is) {
				bufferNo++;
				char* temp = new char[(bufferSize-1) * bufferNo + 1];
				strcpy(temp, buffer);
				delete[] buffer;
				buffer = temp;
				str = buffer + (bufferSize - 1) * (bufferNo - 1);
				is.clear();
			}
			else {
				done = true;
			}
		} while (!done);
		str = new char[strlen(buffer) + 1];
		strcpy(str, buffer);
		delete[] buffer;
		return str;
	}



}