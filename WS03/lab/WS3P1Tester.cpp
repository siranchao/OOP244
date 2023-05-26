// Workshop #3:
// Version: 0.9
// Date: 2021/09/26
// Author: Fardad Soleimanloo, Original Nargis Khan
// Description:
// This file tests the lab section of your workshop
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
using namespace sdds;
int noOfRecs(FILE* fptr);
void readBooks(Library& L, FILE* fptr);
int main() {
   FILE* fptr = fopen("books.csv", "r");
   Library b[4];
   Library L;
   int i;
   b[0].initialize("", 10);
   b[1].initialize(nullptr, 20);
   b[2].initialize("something", 0);
   b[3].initialize("something", -1);
   for (i = 0; i < 4; i++) {
      b[i].display();
      b[i].clear();
   }
   L.initialize("Seneca Newnham Library", noOfRecs(fptr));
   readBooks(L, fptr);
   L.display();
   L.display(true);
   L.display("The");
   L.display("ter");
   L.clear();
   fclose(fptr);
}
int noOfRecs(FILE* fptr) {
   int no = 0;
   int newline = 0;
   while ((newline = fgetc(fptr)) != EOF) {
      no += (newline == '\n');
   }
   rewind(fptr);
   return no;
}
void readBooks(Library& L, FILE* fptr) {
   int noOfRecs = ::noOfRecs(fptr);
   char book_title[51];
   int sku;
   int days;
   for (int i = 0; i < noOfRecs; i++) {
      fscanf(fptr, "%[^,],%d,%d\n", book_title, &sku, &days);
      L.addBook(book_title, sku, days);
   }
}




