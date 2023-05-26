// Workshop 8: 
// Version: 1.0
// Date: 2021/6/03
// Author: Wail Mardini
// Description:
// This file tests the part 1 section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "baseShape.h"
#include "rectangleLabel.h"
#include "lineLabel.h"
using namespace sdds;
using namespace std;
int main() {
   cout << "Nothing should be printed between these two lines" << endl;
   cout << "------------------------------------" << endl;
   lineLabel BadOne;
   rectangleLabel BadRectangle("Bad one", 1, 1);
   cout << BadOne << BadRectangle; // this should not print anything
   cout << "------------------------------------" << endl;
   lineLabel* L = new lineLabel("Separator", 50);
   rectangleLabel* R = new rectangleLabel("Container", 20, 5);
   baseShape* S[2] = { L, R };
   cout << "\nTwo simple shapes should be printed here \n(Separator label with line of width 50 and then Container label with width 20 and leading spaces 5):\n\n";
   cout << *L << endl<<endl;
   cout << *R << endl;
   cout << "\n\nTo test creating a line shape, enter the following:\n>lineLabel two,40<ETNER>\n>";
   cin >> *L;
   cout << "The following outputs should be the same" << endl;
   cout << "The correct output:" << endl;
   cout << "lineLabel two\n========================================" << endl;
   cout << "Your output:" << endl;
   cout << *L << endl;
   cout << "\nTo test creating a rectangle shape, enter the following:\n>A 55 frame with 4 space to be printed on screen,55,4<ETNER>\n>";
   cin >> *R;
   cout << "The following outputs should be the same" << endl;
   cout << "The correct output:" << endl;
   cout << "+-----------------------------------------------------+\n"
           "|    A 55 frame with 4 spaces to be printed on screen |\n"
           "+-----------------------------------------------------+" << endl;
   cout << "Your output:" << endl;
   cout << *R << endl;
   cout << "printing lineLabel and rectangleLabel using Shape pointers: " << endl;
   cout << *S[0] << endl << *S[1] << endl;
   delete S[0];
   delete S[1];
   cout << "Reading the data from a file" << endl;
   ifstream file("ws8data.csv");
   baseShape* sptr;
   char type;
   while (file) {
      sptr = nullptr;
      type = 'x';
      file.get(type);
      file.ignore();
      if (type == 'L') {
         sptr = new lineLabel;
      }
      else if(type == 'R') {
         sptr = new rectangleLabel;
      }
      if (sptr) {
         file >> *sptr;
         cout << *sptr << endl;
         delete sptr;
      }
   }
   return 0;
}