// Final Project Milestone 3
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-3 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {

	class Utils {
	public:
		Utils() = delete;

		static void getChar(std::istream& is, char ch); 
		static void getChar(std::istream& istr);
		static int getInt(std::istream& is, int min, int max, const char* message = nullptr); //read and valid an integer
		static void copyStr(char*& des, const char* src); //copy a string to des from src
		static char* readInput(std::istream& is, char delimeter = '\n'); //count numbers of characters in the istream

	};



}
#endif // SDDS_UTILS_H__

