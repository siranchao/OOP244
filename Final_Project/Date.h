/* Final Project Milestone 5
Module: Date
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

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        bool validate();             // validates the date setting error code and return the result true if valid
        void errCode(int);           // sets the error code
        int systemYear()const;       // returns the current system year
        bool bad()const;             // return true if
        int mdays()const;            // returns the number of days in current month

    public:
        Date();                      // creates a date with current date
        Date(int year, int mon, int day); // create a date with assigned values, validates and sets error code accordingly
        void setToToday();              // sets the date to the current date (system date)
        int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
        int errCode()const;         // returns the error code or zero if date is valid
        const char* dateStatus()const;  // returns a string corresponding the current status of the date
        int currentYear()const;         // returns the m_CUR_YEAR value;

        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout)const;
        operator bool()const;


    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    bool operator==(const Date& lo, const Date& ro);
    bool operator!=(const Date& lo, const Date& ro);
    bool operator>=(const Date& lo, const Date& ro);
    bool operator<=(const Date& lo, const Date& ro);
    bool operator<(const Date& lo, const Date& ro);
    bool operator>(const Date& lo, const Date& ro);
    int operator-(const Date& lo, const Date& ro);

    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;

}
#endif
