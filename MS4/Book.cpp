// Final Project Milestone 4
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/26/2021             ms-4 submission
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"
#include "Lib.h"
using namespace std;
namespace sdds {

	Book::Book() {
		//Empty
	}
	//Rule of three
	Book::Book(const Book& src) {
		operator=(src);
	}
	Book& Book::operator=(const Book& src) {
		if (this != &src && src) {	// if src is empty copy denied
			Publication::operator=(src);
			Utils::copyStr(m_author, src.m_author);
		}
		return *this;
	}
	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	//virtual function
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}
	char Book::type()const {
		return 'B';
	}
	void Book::setDefault() {
		delete[] m_author;
		m_author = nullptr;
		Publication::setDefault();
	}

	//pure virtual function implement
	ostream& Book::write(ostream& ostr)const {
		Publication::write(ostr);
		if (conIO(ostr)) {
			ostr << " ";
			ostr.setf(ios::left);
			if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) ostr << m_author[i];
			}
			else {
				ostr.width(SDDS_AUTHOR_WIDTH);
				ostr << m_author;
			}
			ostr << " |";
			ostr.unsetf(ios::left);
		}
		else {
			ostr << '\t' << m_author;
		}
		return ostr;
	}
	istream& Book::read(istream& istr) {
		char author[SDDS_AUTHIR_READ_LEN + 1];
		setDefault();
		Publication::read(istr);
		if (conIO(istr)) {
			Utils::getChar(istr, '\n');
			cout << "Author: ";
			istr.getline(author, SDDS_AUTHIR_READ_LEN + 1);
		}
		else {
			Utils::getChar(istr, '\t');
			istr.get(author, SDDS_AUTHIR_READ_LEN + 1);
		}

		if (istr) {
			Utils::copyStr(m_author, author);
		}
		else {
			setDefault();
		}
		return istr;
	}

	bool Book::conIO(std::ios& io)const {
		return Publication::conIO(io);
	}
	Book::operator bool()const {
		return (m_author && m_author[0] && Publication::operator bool());
	}




}