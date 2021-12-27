/* Final Project Milestone 5
Module: Lib
Filename: .h
Author:	Siran Cao
Student ID: 159235209
Revision History
-----------------------------------------------------------
Version               Date                 Reason
1.0         	    11/30/2021           ms-5 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#ifndef SDDS_LIB_H__
#define SDDS_LIB_H__
namespace sdds {

    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 5000;
    //const int SDDS_LIBRARY_CAPACITY = 333;
    // Maximum number of publications the library can hold.
    const int SDDS_AUTHIR_READ_LEN = 255;

    const char MAIN_TITLE[] = "Seneca Library Application";
    const char MAIN_1[] = "Add New Publication";
    const char MAIN_2[] = "Remove Publication";
    const char MAIN_3[] = "Checkout publication from library";
    const char MAIN_4[] = "Return publication to library";
    const char EXIT_TITLE[] = "Changes have been made to the data, what would you like to do?";
    const char EXIT_1[] = "Save changes and exit";
    const char EXIT_2[] = "Cancel and go back to the main menu";
    const char SELECT_TITLE[] = "Choose the type of publication:";
    const char SELECT_1[] = "Book";
    const char SELECT_2[] = "Publication";

    const int SEARCH_ALL = 1;
    const int SEARCH_ON_Loan = 2;
    const int SEARCH_AVAILABLE = 3;

}

#endif // !SDDS_LIB_H__

