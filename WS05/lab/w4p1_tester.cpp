// Workshop #5:
// Version: 0.9
// Date: 2021/10/06
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include "EggCarton.h"
using namespace std;
using namespace sdds;
void IOTest();
void typeConversionTest();
void unaryOperatorTest();
void BinaryOperators();
int main() {
   IOTest();
   typeConversionTest();
   unaryOperatorTest();
   BinaryOperators();
   return 0;
}
void BinaryOperators() {
   EggCarton e1, e2(6, 4), e3(6, 5), bad(40);
   cout << endl << "Binary Member operator tests" << endl;
   cout << "e1: " << int(e1) << ", e2: " << int(e2) << ", e3: " << int(e3) << endl;
   e1 = e2 += e3;
   cout << "e1 = e2 += e3;" << endl;
   cout << "e1: " << int(e1) << ", e2: " << int(e2) << ", e3: " << int(e3) << endl;
   bad += e3;
   cout << "bad += e3;" << endl;
   cout << "bad: " << int(bad) << ", e3: " << int(e3) << endl;
   bad += e3;
   cout << "---------------------------------------------" << endl;
   e1 = 20;
   e2 = 2;
   cout << "e1 = 20; e2 = 2;" << endl;
   cout << "e1: " << int(e1) << ", e2: " << int(e2) << endl;
   e1 = 2;
   cout << "e1 = 2;" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "---------------------------------------------" << endl;
   e1 += 2;
   e2 += 1;
   e3 += 4;
   cout << "e1 += 1; e2 += 1; e3 += 4;" << endl;
   cout << "e1: " << int(e1) << ", e2: " << int(e2) << ", e3: " << int(e3) << endl;
   cout << "---------------------------------------------" << endl;
   e1 = EggCarton(6, 2, true);
   e2 = EggCarton(6, 3, false);
   e3 = EggCarton(18, 18, true);
   cout << "e1: " << int(e1) << ", e2: " << int(e2) << ", e3: " << int(e3) << endl;
   cout << "e1:" << endl << e1 << "e2:" << endl << e2 << "e3:" << endl <<e3 << endl;
   cout << "e1 is " << double(e1) << " kgs and e2 is " << double(e2) << " kgs therefore thier weights are " << (e1 == e2 ? "equal" : "different") << endl;
   cout << "e1 is " << double(e1) << " kgs and e3 is " << double(e3) << " kgs therefore thier weights are " << (e1 == e3 ? "equal" : "different") << endl;
   cout << "---------------------------------------------" << endl;
   cout << endl << "Binary non-member operator test" << endl;
   cout << "I have 5 eggs and there are " << int(e3) << " eggs in the Carton." << endl
      << "In total I have " << 5 + e3 << " eggs!" << endl;
}
void unaryOperatorTest() {
   EggCarton e1(6, 4), e2;
   cout << endl << "Unary operator tests" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "e2: " << int(e2) << endl;
   e2 = --e1;
   cout << "e2 = --e1;" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "e2: " << int(e2) << endl;
   cout << "--------------------------------" << endl;
   e2 = ++e1;
   cout << "e2 = ++e1;" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "e2: " << int(e2) << endl;
   cout << "--------------------------------" << endl;
   e2 = e1--;
   cout << "e2 = e1--;" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "e2: " << int(e2) << endl;
   cout << "--------------------------------" << endl;
   e2 = e1++;
   cout << "e2 = e1++;" << endl;
   cout << "e1: " << int(e1) << endl;
   cout << "e2: " << int(e2) << endl;
   cout << "End Unary operator tests" << endl;

}

void typeConversionTest() {
   EggCarton eggs[] = {
      {},
      {36,20,true},
      {36,20,false},
      {42}
   };
   cout << endl << "Type Conversion operator tests" << endl;
   for (int i = 0; i < 4; i++) {
      cout.setf(ios::fixed);
      cout.precision(2);
      if (eggs[i]) {
         cout << int(eggs[i]) << " Eggs:" << endl;
         cout << double(eggs[i]) << " kgs" << endl << "---------------" << endl;
      }
      else {
         cout << "Bad or Broken Carton" << endl;
      }
   }
   cout << "END Type Conversion operator tests" << endl;
}
void IOTest() {
   cout << endl << "Operator <<, Operator >>, display and read test" << endl;
   EggCarton eggs[] = {
      {},
      {10},
      {10,5},
      {6,-1},
      {42,10},
      {36,37},
      {6,4,true},
      {6,4,false},
      {18,10,true},
      {18,10,false}
   };
   for (int i = 0; i < 10; i++) {
      cout << eggs[i] << "----------" << endl;
   }
   cout << "Enter the following valid values:" << endl << " j,24,20" << endl << ">";
   cin >> eggs[0];
   cout << eggs[0] << "----------" << endl;
   cout << "Enter the following valid values:" << endl << " r,24,20" << endl << ">";
   cin >> eggs[0];
   cout << eggs[0] << "----------" << endl;
   cout << "Enter the following invalid values:" << endl << " j,44,20" << endl << ">";
   cin >> eggs[0];
   cout << eggs[0] << "----------" << endl;
   cout << "Enter the following invalid values:" << endl << " j,24,40" << endl << ">";
   cin >> eggs[0];
   cout << eggs[0] << "----------" << endl;
   cout << "END Operator <<, Operator >>, display and read test" << endl;
}
/*
output

Operator <<, Operator >>, display and read test
~~~
~~~
----------
Broken Egg Carton!
----------
Broken Egg Carton!
----------
Broken Egg Carton!
----------
Broken Egg Carton!
----------
Broken Egg Carton!
----------
OOO
O~~
----------
ooo
o~~
----------
OOOOOO
OOOO~~
~~~~~~
----------
oooooo
oooo~~
~~~~~~
----------
Enter the following valid values:
 j,24,20
>j,24,20
OOOOOO
OOOOOO
OOOOOO
OO~~~~
----------
Enter the following valid values:
 r,24,20
>r,24,20
oooooo
oooooo
oooooo
oo~~~~
----------
Enter the following invalid values:
 j,44,20
>j,44,20
Broken Egg Carton!
----------
Enter the following invalid values:
 j,24,40
>j,24,40
Broken Egg Carton!
----------
END Operator <<, Operator >>, display and read test

Type Conversion operator tests
0 Eggs:
0.00 kgs
---------------
20 Eggs:
1.50 kgs
---------------
20 Eggs:
1.00 kgs
---------------
Bad or Broken Carton
END Type Conversion operator tests

Unary operator tests
e1: 4
e2: 0
e2 = --e1;
e1: 3
e2: 3
--------------------------------
e2 = ++e1;
e1: 4
e2: 4
--------------------------------
e2 = e1--;
e1: 3
e2: 4
--------------------------------
e2 = e1++;
e1: 4
e2: 3
End Unary operator tests

Binary Member operator tests
e1: 0, e2: 4, e3: 5
e1 = e2 += e3;
e1: 6, e2: 6, e3: 3
bad += e3;
bad: -1, e3: 3
---------------------------------------------
e1 = 20; e2 = 2;
e1: -1, e2: 2
e1 = 2;
e1: -1
---------------------------------------------
e1 += 1; e2 += 1; e3 += 4;
e1: -1, e2: 3, e3: -1
---------------------------------------------
e1: 2, e2: 3, e3: 18
e1:
OO~
~~~
e2:
ooo
~~~
e3:
OOOOOO
OOOOOO
OOOOOO

e1 is 0.15 kgs and e2 is 0.15 kgs therefore thier weights are equal
e1 is 0.15 kgs and e3 is 1.35 kgs therefore thier weights are different
---------------------------------------------

Binary non-member operator test
I have 5 eggs and there are 18 eggs in the Carton.
In total I have 23 eggs!


*/