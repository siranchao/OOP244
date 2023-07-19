// Final Project Milestone 4
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/26/2021             ms-4 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include "Publication.h"
namespace sdds {


	class Book : public Publication {
		char* m_author{};

	public:
		Book();
		//rule of three
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();

		//virtual function
		void setDefault();
		void set(int member_id);
		char type()const;

		//pure virtual function implement
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		bool conIO(std::ios& io)const;
		operator bool()const;

	};



}

#endif // !SDDS_BOOK_H__
