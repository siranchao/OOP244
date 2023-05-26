// Workshop 10:
// ReadWrite.h
// 2021-11-19
// Version: 2.0 
// Author: Fardad Soleimanloo
// Revised by: Wail Mardini
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class ReadWrite {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
      virtual ~ReadWrite() {
      }
   };
   std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
   std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_

