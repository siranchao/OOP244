// Final Project Milestone 2
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-2 submission
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {

	const char MAIN_TITLE[] = "Seneca Library Application";
	const char MAIN_1[] = "Add New Publication";
	const char MAIN_2[] = "Remove Publication";
	const char MAIN_3[] = "Checkout publication from library";
	const char MAIN_4[] = "Return publication to library";
	const char EXIT_TITLE[] = "Changes have been made to the data, what would you like to do?";
	const char EXIT_1[] = "Save changes and exit";
	const char EXIT_2[] = "Cancel and go back to the main menu";

   class LibApp {
	   bool m_changed;  //default is false
	   Menu m_mainMenu; //the main menu
	   Menu m_exitMenu; //the exit menu
   
   private:
	   // simple outputs fns
	   void load()const;
	   void save()const;
	   void search()const;
	   void returnPub();

	   bool confirm(const char* message)const;
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
	   bool exitMode()const;

   public:
	   LibApp(const char* mainTitle = MAIN_TITLE, const char* exitTitle = EXIT_TITLE);
	   void run();

   };
	



}
#endif // !SDDS_LIBAPP_H



