/* Final Project Milestone 5
Module: LibApp
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
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    // Constructor
    LibApp::LibApp(const char* fileName, const char* mainTitle, const char* exitTitle, const char* selectTitle) : m_ppaSize(0), m_lastRefNo(0), m_changed(false), m_mainMenu(mainTitle), m_exitMenu(exitTitle), m_selectMenu(selectTitle) {
        //initialize
        strcpy(m_fileName, fileName);
        load();
        //set up menu options
        m_mainMenu << MAIN_1 << MAIN_2 << MAIN_3 << MAIN_4;
        m_exitMenu << EXIT_1 << EXIT_2;
        m_selectMenu << SELECT_1 << SELECT_2;
    }

    LibApp::~LibApp() {
        for (int i = 0; i < m_ppaSize; i++) {
            delete m_pubPtrs[i];
            m_pubPtrs[i] = nullptr;
        }
    }

    // Run function
    void LibApp::run() {
        bool loop = true;
        do {
            switch (m_mainMenu.run()) {  //execute main menu
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                loop = exitMode();  //execute exit menu
                break;
            }
        } while (loop);
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    bool LibApp::exitMode()const {
        bool loop = false;
        if (m_changed) {
            switch (m_exitMenu.run()) {
            case 1:
                save();
                break;
            case 2:
                loop = true;
                break;
            case 0:
                loop = !confirm("This will discard all the changes are you sure?");
                break;
            }
        }
        cout << endl;
        return loop;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
        ifstream fistr(m_fileName);
        char type;
        int i;
        for (i = 0; fistr; i++) {
            fistr >> type;
            Utils::getChar(fistr, '\t');
            if (fistr) {
                if (type == 'P') 
                    m_pubPtrs[i] = new Publication;
                else if (type == 'B') 
                    m_pubPtrs[i] = new Book;
                if (m_pubPtrs[i]) {
                    fistr >> *m_pubPtrs[i];
                    m_ppaSize++;
                }
            }
        }
        m_lastRefNo = m_pubPtrs[m_ppaSize - 1]->getRef();
    }

    void LibApp::save()const {
        cout << "Saving Data" << endl;
        ofstream fostr(m_fileName);
        for (int i = 0; i < m_ppaSize; i++) {
            if (m_pubPtrs[i]->getRef() != 0) fostr << *m_pubPtrs[i] << endl;
        }
    }

    int LibApp::search(int mode)const {
        //create a pub Selector
        PublicationSelector selector("Select one of the following found matches:");
        //enter select menu
        int ref = 0;
        bool exit = false;
        char type{};
        char title[256]{};
        switch (m_selectMenu.run()) {
        case 1:
            type = 'B';
            break;
        case 2:
            type = 'P';
            break;
        case 0:
            exit = true;
            cout << "Aborted!" << endl << endl;
            break;
        }

        if (!exit) {
            //read an input title
            cout << "Publication Title: ";
            cin.getline(title, 256, '\n');

            //search ppa array by different modes AND insert results into selector
            if (mode == SEARCH_ALL) {
                for (int i = 0; i < m_ppaSize; i++) {
                    (m_pubPtrs[i]->getRef() != 0 && m_pubPtrs[i]->type() == type && *m_pubPtrs[i] == title) && selector << m_pubPtrs[i];
                }
            }
            else if (mode == SEARCH_ON_Loan) {
                for (int i = 0; i < m_ppaSize; i++) {
                    (m_pubPtrs[i]->onLoan() && m_pubPtrs[i]->getRef() != 0 && m_pubPtrs[i]->type() == type && *m_pubPtrs[i] == title) && selector << m_pubPtrs[i];
                }
            }
            else if (mode == SEARCH_AVAILABLE) {
                for (int i = 0; i < m_ppaSize; i++) {
                    (!m_pubPtrs[i]->onLoan() && m_pubPtrs[i]->getRef() != 0 && m_pubPtrs[i]->type() == type && *m_pubPtrs[i] == title) && selector << m_pubPtrs[i];
                }
            }

            //display selector data
            if (selector) {
                selector.sort();
                ref = selector.run();
                if (ref != 0) 
                    cout << *getPub(ref) << endl;
                else 
                    cout << "Aborted!" << endl << endl;
            }
            else {
                cout << "No matches found!" << endl << endl;
            }
        }
        return ref;
    }

    Publication* LibApp::getPub(int libRef)const {
        Publication* ptr{};
        for (int i = 0; i < m_ppaSize && !ptr; i++) {
            if (m_pubPtrs[i]->getRef() == libRef) ptr = m_pubPtrs[i];
        }
        return ptr;
    }

    bool LibApp::confirm(const char* message)const {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp::returnPub() {
        Date today;
        cout << "Return publication to the library" << endl;
        int ref = search(SEARCH_ON_Loan);
        if (ref != 0) {
            if (confirm("Return Publication?")) {
                int lateDays = today - getPub(ref)->checkoutDate();
                if (lateDays > SDDS_MAX_LOAN_DAYS) {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Please pay $" << ((double)lateDays - (double)SDDS_MAX_LOAN_DAYS) * 0.5 << " penalty for being " << (lateDays - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }
                getPub(ref)->set(0);
                m_changed = true;
                cout << "Publication returned" << endl << endl;
            }
            else {
                cout << "Aborted!" << endl << endl;
            }
        }
    }

    void LibApp::newPublication() {
        if (m_ppaSize == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl << endl;
        }
        else {
            cout << "Adding new publication to the library" << endl;
            Publication* newPub{};
            switch (m_selectMenu.run()) {
            case 1:
                newPub = new Book;
                break;
            case 2:
                newPub = new Publication;
                break;
            case 0:
                cout << "Aborted!" << endl << endl;
                newPub = nullptr;
                break;
            }
            // read data from console
            if (newPub) {
                cin >> *newPub;
                if (cin) {
                    if (confirm("Add this publication to the library?")) {
                        if ((*newPub)) {
                            //add a valid object into PPA
                            m_pubPtrs[m_ppaSize] = newPub;
                            m_pubPtrs[m_ppaSize]->setRef(++m_lastRefNo);
                            m_ppaSize++;
                            m_changed = true;
                            cout << "Publication added" << endl << endl;
                        }
                        else {
                            cout << "Failed to add publication!" << endl << endl;
                            delete newPub;
                        }
                    }
                    else {
                        delete newPub;
                        cout << "Aborted!" << endl << endl;
                    }
                }
                else {
                    delete newPub;
                    cin.ignore(1000, '\n');
                    cout << "Aborted!" << endl << endl;
                }
            }
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int ref = search(SEARCH_ALL);
        if (ref != 0) {
            if (confirm("Remove this publication from the library?")) {
                getPub(ref)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl << endl;
            }
            else {
                cout << "Aborted!" << endl << endl;
            }
        }
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int ref = search(SEARCH_AVAILABLE);
        int membership = 0;
        if (ref != 0) {
            if (confirm("Check out publication?")) {
                cout << "Enter Membership number: ";
                membership = Utils::getInt(cin, 10000, 99999, "Invalid membership number, try again: ");
                getPub(ref)->set(membership);
                m_changed = true;
                cout << "Publication checked out" << endl << endl;
            }
            else {
                cout << "Aborted!" << endl << endl;
            }
        }
    }


}