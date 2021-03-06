/* Final Project Milestone 5
Module:	Streamable
Filename: .h
Author:	Siran Cao
Student ID:	159235209
Revision History
-----------------------------------------------------------
Version               Date                 Reason
1.0         	    12/02/2021           ms-5 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>
namespace sdds {

	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();

	};
	std::ostream& operator<<(std::ostream& os, const Streamable& src);
	std::istream& operator>>(std::istream& is, Streamable& src);

}

#endif // !SDDS_STREAMABLE_H__
