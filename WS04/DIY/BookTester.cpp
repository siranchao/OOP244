// Workshop #4:
// Version: 0.9
// Date: 2021/05/01
// Author: Nargis Khan
// Description:
// This file tests the DIY section of your workshop
// Revision: Fardad Soleimanloo
// Date: 2021/10/01
///////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include"Chapter.h"
#include"Book.h"
using namespace std;
using namespace sdds;

void displayBooks(const Book* b, int num);
void DMAtest(Book& B);
int main() {

   Chapter cp1[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80) ,
      Chapter()
   };


   Chapter cp2[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter("",100)
   };

   Chapter cp3[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter("Bad1", 0)
   };

   Chapter cp4[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter(nullptr, 40)
   };
   
   Chapter cp[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80)
   };

   Book bo[] = {
      Book(nullptr,3,cp),
      Book("Bad1", 0,cp),
      Book("Bad2", 4,cp1),
      Book("Bad3", 4,cp2),
      Book("Bad4", 4,cp3),
      Book("Bad5", 4,cp4),
      Book("Object Oriented Programming Languages", 3, cp)
   };

   cout << "Displaying invalid Book objects" << endl;
   cout << "-------------------------------------------------------" << endl;
   displayBooks(bo, 5);
   cout << "Displaying valid Book object with valid chapters" << endl;
   cout << "-------------------------------------------------------" << endl;
   displayBooks(&bo[6], 1);
   cout << "Adding a new Chapter to the Book" << endl;
   cout << "-------------------------------------------------------" << endl;
   bo[6].addChapter("Python", 100);
   bo[6].display();
   cout << "-------------------------------------------------------" << endl;
   cout << "Testing DMA" << endl;
   cout << "-------------------------------------------------------" << endl;
   cout << "Press enter to continue: ";
   cin.ignore();
   DMAtest(bo[6]);
   return 0;
}
void DMAtest(Book& B) {
   for (int i = 0; i < 2000; i++) B.addChapter("testing", i%202);
   B.display();
}
void displayBooks(const Book* b, int num) {
   int i;
   for (i = 0; i < num; i++) {
      b[i].display();
   }
   cout << "-------------------------------------------------------" << endl;
}

/*
Displaying invalid Book objects
-------------------------------------------------------
Invalid Book object
Invalid Book object
Invalid Book object
Invalid Book object
Invalid Book object
-------------------------------------------------------
Displaying valid Book object with valid chapters
-------------------------------------------------------
Book Name: Object Oriented Programming Languages
No of Chapters: 3
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
-------------------------------------------------------
Adding a new Chapter to the Book
-------------------------------------------------------
Book Name: Object Oriented Programming Languages
No of Chapters: 4
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
Python............................................ 100
Testing DMA
-------------------------------------------------------
Press enter to continue:
Book Name: Object Oriented Programming Languages
No of Chapters: 1985
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
Python............................................ 100
testing...........................................   1
testing...........................................   2
testing...........................................   3
testing...........................................   4
testing...........................................   5
testing...........................................   6
testing...........................................   7
testing...........................................   8
... any many more line will be printed

*/