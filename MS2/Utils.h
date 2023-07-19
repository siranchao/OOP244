// Final Project Milestone 2
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-2 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {

	class Utils {
	public:
		Utils() = delete;

		static void getChar(std::istream& is, char ch); //throw away any separators
		static int getInt(std::istream& is, int min, int max, const char* message = nullptr); //read and valid an integer
		static void copyStr(char*& des, const char* src); //copy a string to des from src
		static char* countInput(std::istream& is, char delimeter = '\n'); //count numbers of characters in the istream

	};



}
#endif // SDDS_UTILS_H__
