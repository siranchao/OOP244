// Final Project Milestone 2
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-2 submission
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {

	// Constructor
	LibApp::LibApp(const char* mainTitle, const char* exitTitle): m_changed(false), m_mainMenu(mainTitle), m_exitMenu(exitTitle) {
		m_mainMenu << MAIN_1 << MAIN_2 << MAIN_3 << MAIN_4;
		m_exitMenu << EXIT_1 << EXIT_2;
		load();
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

	void LibApp::load()const {
		cout << "Loading Data" << endl;
	}
	void LibApp::save()const {
		cout << "Saving Data" << endl;
	}
	void LibApp::search()const {
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl << "Publication returned" << endl << endl;
		m_changed = true;
	}

	bool LibApp::confirm(const char* message)const {
		Menu confirmMenu(message);
		confirmMenu << "Yes";
		return confirmMenu.run() == 1 ? true : false;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		bool res = confirm("Add this publication to library?");
		if (res) {
			m_changed = true;
			cout << "Publication added" << endl << endl;
		}
		else {
			cout << endl;
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		bool res = confirm("Remove this publication from the library?");
		if (res) {
			m_changed = true;
			cout << "Publication removed" << endl << endl;
		}
		else {
			cout << endl;
		}
	}
	void LibApp::checkOutPub() {
		search();
		bool res = confirm("Check out publication?");
		if (res) {
			m_changed = true;
			cout << "Publication checked out" << endl << endl;
		}
		else {
			cout << endl;
		}
	}


   

}
