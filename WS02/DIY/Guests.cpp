#include <iostream>
using namespace std;

namespace sdds {
   void read(char* str, int len) {
      if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
      cin.getline(str, len);
   }
}