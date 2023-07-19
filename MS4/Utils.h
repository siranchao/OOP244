// Final Project Milestone 4
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/26/2021             ms-4 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {

	class Utils {
	public:
		Utils() = delete;

		static void getChar(std::istream& is, char ch); //extract a given char
		static void getChar(std::istream& is);	//if next char is digit set istr fail or extract it otherwise
		static int getInt(std::istream& is, int min, int max, const char* message = nullptr); //get a int with validation and error message

		static void copyStr(char*& des, const char* src); 
		static char* readInput(std::istream& is, char delimeter = '\n');
	};



}
#endif // SDDS_UTILS_H__

