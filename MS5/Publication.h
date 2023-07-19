/* Final Project Milestone 5
Module:	Publication
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

#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include <iostream>
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"
namespace sdds {

	class Publication : public Streamable {
		char* m_title{};	// nullptr by default
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};	// empty string by default
		int m_membership;	// 0 by default, means available in the Lib
		int m_libRef;	// -1 by default, unique ID for each publication 
		Date m_date;	// set to current date by default

	public:
		Publication();
		// Rule of three
		Publication(const Publication& src);
		Publication& operator=(const Publication& src);
		virtual ~Publication();

		// Modifiers
		virtual void setDefault();	// set object to default state
		virtual void set(int member_id);	// Sets the membership to either zero or a five-digit integer
		void setRef(int value);				// Sets the libRef value
		void resetDate();					// Sets the date to the current date of the system.
		
		// Queries
		virtual char type()const;		// Returns 'P' to identify this object as "Publication object"
		bool onLoan()const;				// Returns true if the publication is checkout
		Date checkoutDate()const;		// Returns the date attribute
		bool operator==(const char* title)const;	// Check if the argument title appears in the title
		operator const char* ()const;	// Returns the title attribute
		int getRef()const;				// Returns the libRef value

		// Pure virtual function implement
		bool conIO(std::ios& io)const;
		operator bool()const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
	};
}

#endif // !SDDS_PUBLICATION_H

