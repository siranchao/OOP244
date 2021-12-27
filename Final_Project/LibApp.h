/* Final Project Milestone 5
Module:	LibApp
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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
namespace sdds {

   class LibApp {
	   char m_fileName[256]{}; //file name
	   Publication* m_pubPtrs[SDDS_LIBRARY_CAPACITY]{}; //Public pointer array
	   int m_ppaSize; //PPA array size
	   int m_lastRefNo; //record the last ref number in the library
	   bool m_changed;  //default is false
	   Menu m_mainMenu; //the main menu
	   Menu m_exitMenu; //the exit menu
	   Menu m_selectMenu; //the choose type menu
   
   private:
	   void load();
	   void save()const;
	   int search(int mode = SEARCH_ALL)const;
	   Publication* getPub(int libRef)const;
	   void returnPub();
	   bool confirm(const char* message)const;
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
	   bool exitMode()const;

   public:
	   LibApp(const char* fileName, const char* mainTitle = MAIN_TITLE, const char* exitTitle = EXIT_TITLE, const char* selectTitle = SELECT_TITLE);
	   void run();
	   //rule of three
	   LibApp(const LibApp& src) = delete;
	   LibApp& operator=(const LibApp& src) = delete;
	   virtual ~LibApp();
   };
	

}
#endif // !SDDS_LIBAPP_H



