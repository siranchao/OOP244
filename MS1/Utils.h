// Final Project Milestone 1 
// Utlils Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/7/2021             ms-1 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {

	void getChar(std::istream& istr); // throw away any separators which is not an int
	int getInt(std::istream& istr, int limit); // read and valid an integer from input

}
#endif // SDDS_UTILS_H__
