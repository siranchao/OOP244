// Workshop #3:
// Version: 0.9
// Date: 2021/09/26
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Bank.h"
using namespace std;
using namespace sdds;
int noOfRecs(FILE* fptr);
void readAccounts(Bank& L, FILE* fptr);
int main() {
   FILE* fptr = fopen("accounts.csv", "r");
   Bank b[4];
   Bank L;
   int i;
   b[0].initialize("", 10);
   b[1].initialize(nullptr, 20);
   b[2].initialize("something", 0);
   b[3].initialize("something", -1);
   for (i = 0; i < 4; i++) {
      b[i].display();
      b[i].clear();
   }
   L.initialize("Seneca Bank & Trust", noOfRecs(fptr));
   readAccounts(L, fptr);
   L.display();
   L.display(true);
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
void readAccounts(Bank& L, FILE* fptr) {
   int noOfRecs = ::noOfRecs(fptr);
   int accNo;
   double balance;
   int days;
   for (int i = 0; i < noOfRecs; i++) {
      fscanf(fptr, "%d,%lf,%d\n", &accNo, &balance, &days);
      L.addAccount(accNo, balance, days);
   }
}

/*output
Invalid Bank
Invalid Bank
Invalid Bank
Invalid Bank
----------------------------------------
>>> Seneca Bank & Trust <<<
----------------------------------------
Row Accnt No       Balance  Days Interest
--- ---------- ------------ ---- --------
1    97988775     852283.02  6
2    90837261    1776257.40  14
3    96925213     471948.98  56  20636.45
4    97687611     849206.85  47  31164.73
5    90251542     878439.19  9
6    99792020     432107.95  55  18556.96
7    99456993    1676602.38  52  68074.65
8    91668387    1980439.23  53  81957.63
9    97717004     853368.22  8
10   90862850    1264645.87  30
11   99493936      37329.10  58   1690.55
12   93182966    1742978.32  54  73491.61
13   94523817     161271.42  23
14   96829419     363081.73  43  12190.59
15   94222780     323362.90  21
-----------------------------------------
              Total interest:   307763.17

INTEREST ONLY LIST!
----------------------------------------
>>> Seneca Bank & Trust <<<
----------------------------------------
Row Accnt No       Balance  Days Interest
--- ---------- ------------ ---- --------
1    96925213     471948.98  56  20636.45
2    97687611     849206.85  47  31164.73
3    99792020     432107.95  55  18556.96
4    99456993    1676602.38  52  68074.65
5    91668387    1980439.23  53  81957.63
6    99493936      37329.10  58   1690.55
7    93182966    1742978.32  54  73491.61
8    96829419     363081.73  43  12190.59
-----------------------------------------
              Total interest:   307763.17

*/


