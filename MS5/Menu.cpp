/* Final Project Milestone 5
Module: Menu
Filename: .cpp
Author:	Siran Cao
Student ID: 159235209
Revision History
-----------------------------------------------------------
Version               Date                 Reason
1.0         	    12/02/2021           ms-5 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    //// MenuItem Class:
    MenuItem::MenuItem(const char* item) {
        setName(item);
    }
    MenuItem::~MenuItem() {
        delete[] m_item;
    }

    void MenuItem::setName(const char* item) {
        if (item != nullptr) {
            Utils::copyStr(m_item, item);
        }
    }

    MenuItem::operator bool() const {
        return !(m_item == nullptr);
    }
    MenuItem::operator const char* () const {
        return m_item;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (*this) ostr << m_item;
        return ostr;
    }

    //// Menu Class:
    Menu::Menu(const char* title) : m_title(title), m_numberOfItems(0) {
    }

    Menu::~Menu() {
        for (int i = 0; i < m_numberOfItems; i++) {
            delete m_itemList[i];
        }
    }

    std::ostream& Menu::displayTitle(std::ostream& ostr) const {
        return m_title.display(ostr);
    }

    std::ostream& Menu::displayMenu(std::ostream& ostr) const {
        if (m_title) {
            displayTitle(ostr);
            ostr << endl;
        }
        for (int i = 0; i < m_numberOfItems; i++) {
            ostr.setf(ios::right);
            ostr.width(2);
            ostr << i + 1 << "- ";
            m_itemList[i]->display(ostr);
            ostr << endl;
        }
        ostr << " 0- Exit" << endl;
        ostr << "> ";
        ostr.unsetf(ios::right);
        return ostr;
    }

    unsigned int Menu::run() const {
        displayMenu(cout);
        return Utils::getInt(cin, 0, m_numberOfItems, "Invalid integer, please try again: ");
    }
    int Menu::operator~() const {
        displayMenu(cout);
        return Utils::getInt(cin, 0, m_numberOfItems, "Invalid integer, please try again: ");
    }

    Menu& Menu::operator<<(const char* menuItem) {
        if (m_numberOfItems < MAX_MENU_ITEMS) {
            m_itemList[m_numberOfItems] = new MenuItem(menuItem);
            m_numberOfItems++;
        }
        return *this;
    }

    Menu::operator int() const {
        return m_numberOfItems;
    }
    Menu::operator unsigned int() const {
        return m_numberOfItems;
    }
    Menu::operator bool() const {
        return (m_numberOfItems > 0);
    }
    char* Menu::operator[](int index) const {
        int pos = index < 0 ? (-index % m_numberOfItems) : (index % m_numberOfItems);
        return m_itemList[pos]->m_item;
    }

    std::ostream& operator<<(std::ostream& ostr, const Menu& ro) {
        return ro.displayTitle(ostr);
    }

}