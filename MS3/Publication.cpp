// Final Project Milestone 3
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-3 submission
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Utils.h"
using namespace std;
namespace sdds {

	Publication::Publication() {
		setDefault();
	}

	// Rule of three
	Publication::Publication(const Publication& src) {
		if (src) {
			Utils::copyStr(m_title, src.m_title);
			strcpy(m_shelfId, src.m_shelfId);
			m_membership = src.m_membership;
			m_libRef = src.m_libRef;
			m_date = src.m_date;
		}
		else {
			setDefault();
		}
	}
	Publication& Publication::operator=(const Publication& src) {
		if (this != &src && src) {
			Utils::copyStr(m_title, src.m_title);
			strcpy(m_shelfId, src.m_shelfId);
			m_membership = src.m_membership;
			m_libRef = src.m_libRef;
			m_date = src.m_date;
		}
		return *this;
	}
	Publication::~Publication() {
		delete[] m_title;
	}

	void Publication::setDefault() {
		delete[] m_title;
		m_title = nullptr;
		//strcpy(m_shelfId, "");
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}

	// Modifiers
	void Publication::set(int member_id) {
		if (member_id == 0) {
			m_membership = member_id;
		}
		else {
			if (member_id >= 10000 && member_id <= 99999) m_membership = member_id;
		}
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date.setToToday();
	}
	// Queries
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return m_membership != 0 ? true : false;
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title) != nullptr ? true : false;
	}
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}
	// Pure virtual function implement
	bool Publication::conIO(ios& io)const {
		return (&io == &cin || &io == &cout) ? true : false;
	}

	ostream& Publication::write(ostream& os)const {
		if (conIO(os)) {
			os.setf(ios::left);
			os << "| " << m_shelfId << " | ";
			os.width(SDDS_TITLE_WIDTH);
			os.fill('.');
			os << m_title;
			os.unsetf(ios::left);
			os.fill(' ');
			os << " | ";
			if (m_membership != 0) os << m_membership;
			else os << " N/A ";
			os << " | " << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr) {
		setDefault();
		char shelfId[SDDS_SHELF_ID_LEN + 1];
		char* title{};
		Date temp;
		int libRef = 0;
		int membership = 0;
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
			if (strlen(shelfId) < SDDS_SHELF_ID_LEN) istr.setstate(ios::failbit);
			cout << "Title: ";
			title = Utils::readInput(istr);
			cout << "Date: ";
			temp.read(istr);
		}
		else {
			istr >> libRef;
			Utils::getChar(istr, '\t');
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			Utils::getChar(istr, '\t');
			title = Utils::readInput(istr, '\t');
			Utils::getChar(istr, '\t');
			istr >> membership;
			Utils::getChar(istr, '\t');
			temp.read(istr);
		}
		if (!temp) istr.setstate(ios::failbit);
		if (istr) {
			Utils::copyStr(m_title, title);
			strcpy(m_shelfId, shelfId);
			set(membership);
			setRef(libRef);
			m_date = temp;
		}
		delete[] title;
		return istr;
	}

	Publication::operator bool()const {
		return (m_title && m_title[0] != '\0' && m_shelfId[0] != '\0') ? true : false;
	}
	

}