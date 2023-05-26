// Workshop 10:
// Student.h
// 2021-11-19
// Version: 2.0 
// Author: Fardad Soleimanloo
// Revised by: Wail Mardini
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(double gpa)const;
   };
}
#endif // !SDDS_STUDENT_H_

