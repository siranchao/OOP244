/* Final Project Milestone 5
Module:	Book
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

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
namespace sdds {

	class Book : public Publication {
		char* m_author{};

	public:
		Book();
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();

		//virtual function implements
		void setDefault();
		void set(int member_id);
		char type()const;

		//pure virtual function implements
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		bool conIO(std::ios& io)const;
		operator bool()const;

	};



}

#endif // !SDDS_BOOK_H__
