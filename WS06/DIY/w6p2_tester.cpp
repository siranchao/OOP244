// Workshop #6:
// Version: 0.9
// Date: 2021/10/17
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Book.h"
using namespace std;
using namespace sdds;
void hr(const char* title = nullptr);
void constructionTest();
Book readBook(ifstream& file);
void printbookRow(int ros, Book B);
void readAndRuleOfThreeTest();
int noOfRecs(const char* filename);
void header();

int main() {
   constructionTest();
   readAndRuleOfThreeTest();
   return 0;
}

void constructionTest() {
   Book B[]{
      {"","abc", 48, 6},
      {nullptr,"abc", 48, 6},
      {"abc", "", 48, 6},
      {"abc", nullptr, 48, 6},
      {"abc","abc", 0, 6},
      {"abc","abc", 48, 0},
      {"Huckleberry Finn","Mark Twain", NoOfBookCases,NoOfShelves},
      {"Huckleberry Finn","Mark Twain", NoOfBookCases + 1,NoOfShelves},
      {"Huckleberry Finn","Mark Twain",NoOfBookCases,NoOfShelves + 1}
   };
   hr("Constructor test");
   header();
   for (int i = 0; i < 8; cout << B[i++] << endl);
   hr("End Constructor test");
}


void readAndRuleOfThreeTest() {
   ifstream bookFile("books.csv");
   ofstream goodBooks("goodBooks.csv");
   Book B;
   int noOfRecs = ::noOfRecs("books.csv");
   int i;
   hr("Read and Rule of three");
   header();
   for (i = 0; i < noOfRecs; i++) {
      B = readBook(bookFile);
      printbookRow(i, B);
      if (bookFile) {
         B.write(goodBooks, false) << endl;
      }
      else {
         bookFile.clear();
      }
      bookFile.ignore(MaxAuthorLen + MaxTitleLen + 7, '\n');
   }
   goodBooks.close();
   bookFile.close();
   bookFile.open("goodBooks.csv");
   hr("+++ Good Books");
   header();
   for (i = 0; bookFile >> B; i++) {
      bookFile.ignore(MaxAuthorLen + MaxTitleLen + 7, '\n');
      printbookRow(i, B);
   }
   hr("End Read and Rule of three");
}

Book readBook(ifstream& file) {
   Book B;
   file >> B;
   return B;
}

void hr(const char* title) {
   int len = 0;
   if (title) cout << title << " ";
   while (title && *title++)len++;
   cout.width(78 - len + !title);
   cout.fill('-');
   cout << '-' << endl;
   cout.fill(' ');
}

int noOfRecs(const char* filename) {
   int num = 0;
   ifstream file(filename);
   while (file) num += (file.get() == '\n');
   return num;
}

void header() {
   cout << "Row: Book Title                              | Author(s)                | Loc" << endl
      << "---------------------------------------------+--------------------------+------" << endl;
}
void printbookRow(int row, Book B) {
   cout.width(3);
   cout.fill('0');
   cout.setf(ios::right);
   cout << (row + 1) << ": ";
   cout.fill(' ');
   cout.unsetf(ios::right);
   cout << B << endl;;
}


/*
Example of the output of a book row with a ruler to help for counting.
         1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
Huckleberry Finn                        | Mark Twain               | 7/132
The Alchemist                           | Paulo Coelho             | 1/025
The Great Gatsby                        | F. Scott Fitzgerald      | 1/033
*/