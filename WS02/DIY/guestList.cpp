// Workshop 2:
// Version: 0.9
// Date: 2021/09/17
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Guests.h"
using namespace std;
using namespace sdds;

int main() {
   bool done = false;
   char resturantName[51];
   Guest gst = { "", {0,0} };
   GuestList gl = { nullptr, 0 };
   PhoneNumber phno;
   cout << "Please enter the name of the restaurant: ";
   read(resturantName, 50);
   read(phno);
   cout << "Guest entry..." << endl;
   while (!done) {
      cout << "Enter guest information or Enter to exit:" << endl;
      if (read(gst)) {
         addGuest(gl, gst);
      }
      else {
         done = true;
      }
   }
   cout << endl << endl << resturantName << ", Phone Number: ";
   print(phno);
   cout << "**********************************************" << endl;
   cout << "Guestlist and their contacts: " << endl;
   print(gl);
   delete[] gl.m_gst;
}