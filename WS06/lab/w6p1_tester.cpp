// Workshop #6:
// Version: 1.0
// Date: 2021/10/17
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// v1.0  1021/10/20
//      corrected the filename goodNumber.txt to
//      goodNumbers.csv
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Contact.h"
using namespace std;
using namespace sdds;

int noOfRecs(const char* filename);
void showFile(const char* filename);
Contact ReadPhoneFromFile(istream& istr);
void dataEntryTest();
void validationTest();


int main() {
   int i;
   int recs = noOfRecs("phoneNumbers.csv");
   Contact C{ "Gandalf The Grey",111,222,3 };
   ifstream phoneFile("phoneNumbers.csv");
   ofstream goodPhoneFile("goodNumbers.csv");
   validationTest();
   dataEntryTest();
   cout << endl << "Rule of three test ---------------------------------------------" << endl;
   for (i = 0; phoneFile && i < recs; i++) {
      C = ReadPhoneFromFile(phoneFile);
      cout << C << endl;
      if(phoneFile) goodPhoneFile << C << endl;
   }
   if (i == recs)
      cout << "All records were read successfuly!" << endl;
   else {
      cout << "Read " << i - 1 << " out of " << recs << " Records successfully" << endl;
      cout << "Record number " << i << " is invalid!" << endl;
   }
   showFile("goodNumbers.csv");
   return 0;
}

void validationTest() {
   int i;
   Contact C[]{
      {"Fred Soley", 416,491,50},
      {nullptr, 416,491,5050 },
      {"Fred Soley", 41,491,5050 },
      {"Fred Soley", 416,49,5050 },
      {"Fred Soley", 416,491,50500 },
      {"Fred Soley", 1000,491,5050 },
      {"Fred Soley", 416,1000,5050 },
      {"Fred Soley", 416,491,-1 },
   };
   cout << "Validation Test" << endl;
   for (i = 0; i < 8; cout << C[i++] << endl);
}

int noOfRecs(const char* filename) {
   int num = 0;
   ifstream file(filename);
   while (file) num += (file.get() == '\n');
   return num;
}

void showFile(const char* filename) {
   ifstream file(filename);
   char ch;
   cout << "Contents of " << filename << endl << "----------------------------------------------------------------" << endl;
   while (file.get(ch)) {
      cout << ch;
   }
}

void dataEntryTest() {
   Contact C{ "Gandalf The Grey",111,222,3 };
   cout << endl << "Data entry test." << endl;
   cout << "Enter the test data using copy and paste to save time:" << endl << endl;
   cout << "Enter the following:" << endl
      << ">Gandalf-(111) 222,3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,111222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,(111)222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,(111) 2223333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">,(111) 222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,(111) 222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Content:" << endl << C << endl;
}


Contact ReadPhoneFromFile(istream& istr) {
   Contact C;
   istr >> C;
   return C;
}

