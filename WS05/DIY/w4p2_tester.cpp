// Workshop #5:
// Version: 1.0 (corrected typeconversion bug)
// Date: 2021/10/06
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include "Bus.h"
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
   Bus b1, b2(10, 7), b3(10, 8), bad(50);
   cout << endl << "Binary Member operator tests" << endl;
   cout << "b1: " << int(b1) << ", b2: " << int(b2) << ", b3: " << int(b3) << endl;
   b1 = b2 += b3;
   cout << "b1 = b2 += b3;" << endl;
   cout << "b1: " << int(b1) << ", b2: " << int(b2) << ", b3: " << int(b3) << endl;
   bad += b3;
   cout << "bad += b3;" << endl;
   cout << "bad: " << int(bad) << ", b3: " << int(b3) << endl;
   bad += b3;
   cout << "---------------------------------------------" << endl;
   b1 = 20;
   b2 = 2;
   cout << "b1 = 20; b2 = 2;" << endl;
   cout << "b1: " << int(b1) << ", b2: " << int(b2) << endl;
   b1 = 2;
   cout << "b1 = 2;" << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "---------------------------------------------" << endl;
   b1 += 2;
   b2 += 1;
   b3 += 4;
   cout << "b1 += 1; b2 += 1; b3 += 4;" << endl;
   cout << "b1: " << int(b1) << ", b2: " << int(b2) << ", b3: " << int(b3) << endl;
   cout << "---------------------------------------------" << endl;
   b1 = Bus(10, 5);
   b2 = Bus(10, 10);
   b3 = Bus(18, 10);
   cout << "b1: " << int(b1) << ", b2: " << int(b2) << ", b3: " << int(b3) << endl;
   cout << "b1:" << endl << b1 << "b2:" << endl << b2 << "b3:" << endl <<b3 << endl;
   cout << "b1 has " << int(b1) << " passengers and b2 is " << int(b2) << " passengers therefore thier head counts are " << (b1 == b2 ? "equal" : "different") << endl;
   cout << "b2 has " << int(b2) << " passengers and b3 is " << int(b3) << " passengers therefore thier head counts are " << (b2 == b3 ? "equal" : "different") << endl;
   cout << "---------------------------------------------" << endl;
   cout << endl << "Binary non-member operator test" << endl;
   cout << "There are 5 passengers at the bus stop and there are " << int(b3) << " passengers on the bus." << endl
      << "When the passengers get off the bus there will be " << 5 + b3 << " passengers at the bus stop!" << endl;
}
void unaryOperatorTest() {
   Bus b1(10,10), b2;
   cout << endl << "Unary operator tests" << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "b2: " << int(b2) << endl;
   cout << "--b1; --b2;" << endl;
   cout << (--b1 ? "Passenger removed!" : "Bus empty!") << endl;
   cout << (--b2 ? "Passenger removed!" : "Bus empty!") << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "b2: " << int(b2) << endl;
   cout << "--------------------------------" << endl;
   cout << "++b1; ++b1; --b2;" << endl;
   cout << (++b1 ? "Passenger added!" : "Bus full!") << endl;
   cout << (++b1 ? "Passenger added!" : "Bus full!") << endl;
   cout << (++b2 ? "Passenger added!" : "Bus full!") << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "b2: " << int(b2) << endl;
   cout << "--------------------------------" << endl;
   cout << "b1--; b2--; b2--;" << endl;
   cout << (b1-- ? "Passenger removed!" : "Bus empty!") << endl;
   cout << (b2-- ? "Passenger removed!" : "Bus empty!") << endl;
   cout << (b2-- ? "Passenger removed!" : "Bus empty!") << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "b2: " << int(b2) << endl;
   cout << "--------------------------------" << endl;
   cout << "b1++; b1++; b2++" << endl;
   cout << (b1++ ? "Passenger added!" : "Bus full!") << endl;
   cout << (b1++ ? "Passenger added!" : "Bus full!") << endl;
   cout << (b2++ ? "Passenger added!" : "Bus full!") << endl;
   cout << "b1: " << int(b1) << endl;
   cout << "b2: " << int(b2) << endl;
   cout << "--------------------------------" << endl;

}

void typeConversionTest() {
   Bus bus[] = {
      {},
      {36,20},
      {42}
   };
   cout << endl << "Type Conversion operator tests" << endl;
   for (int i = 0; i < 3; i++) {
      cout.setf(ios::fixed);
      cout.precision(2);
      if (bus[i]) {
         cout << int(bus[i]) << " Passengers:" << endl;
         cout << double(bus[i]) << " Dollars total fare." << endl << "---------------" << endl;
      }
      else {
         cout << "This bus is out of service!" << endl;
      }
   }
   cout << "END Type Conversion operator tests" << endl;
}
void IOTest() {
   cout << endl << "Operator <<, Operator >>, display and read test" << endl;
   Bus bus[] = {
      {},
      {25},
      {20,25},
      {20,-1},
      {30,21}
   };
   for (int i = 0; i < 5; i++) {
      cout << bus[i] << "----------" << endl;
   }
   cout << "Enter the following valid values:" << endl << " 22,11" << endl << ">";
   cin >> bus[0];
   cout << bus[0] << "----------" << endl;
   cout << "Enter the following valid values:" << endl << " 24,0" << endl << ">";
   cin >> bus[0];
   cout << bus[0] << "----------" << endl;
   cout << "Enter the following invalid values:" << endl << " 44,20" << endl << ">";
   cin >> bus[0];
   cout << bus[0] << "----------" << endl;
   cout << "Enter the following invalid values:" << endl << " 24,25" << endl << ">";
   cin >> bus[0];
   cout << bus[0] << "----------" << endl;
   cout << "END Operator <<, Operator >>, display and read test" << endl;
}
/*
output


Operator <<, Operator >>, display and read test
__________________________________
| [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]|_\_
|         Seneca College            )
`---OO-------------------------O---'
Total Fare Price: 0.00
----------
Out of service!
----------
Out of service!
----------
Out of service!
----------
_________________________________________________
| [2][2][2][2][2][2][2][2][2][2][1][ ][ ][ ][ ]|_\_
|                Seneca College                    )
`---OO----------------------------------------O---'
Total Fare Price: 2632.14
----------
Enter the following valid values:
 22,11
>22,11
_____________________________________
| [2][2][2][2][2][1][ ][ ][ ][ ][ ]|_\_
|          Seneca College              )
`---OO----------------------------O---'
Total Fare Price: 1378.74
----------
Enter the following valid values:
 24,0
>24,0
________________________________________
| [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]|_\_
|            Seneca College               )
`---OO-------------------------------O---'
Total Fare Price: 0.00
----------
Enter the following invalid values:
 44,20
>44,20
Out of service!
----------
Enter the following invalid values:
 24,25
>24,25
Out of service!
----------
END Operator <<, Operator >>, display and read test

Type Conversion operator tests
0 Passengers:
0.00 Dollars total fare.
---------------
20 Passengers:
2506.80 Dollars total fare.
---------------
This bus is out of service!
END Type Conversion operator tests

Unary operator tests
b1: 10
b2: 0
--b1; --b2;
Passenger removed!
Bus empty!
b1: 9
b2: 0
--------------------------------
++b1; ++b1; --b2;
Passenger added!
Bus full!
Passenger added!
b1: 10
b2: 1
--------------------------------
b1--; b2--; b2--;
Passenger removed!
Passenger removed!
Bus empty!
b1: 9
b2: 0
--------------------------------
b1++; b1++; b2++
Passenger added!
Bus full!
Passenger added!
b1: 10
b2: 1
--------------------------------

Binary Member operator tests
b1: 0, b2: 7, b3: 8
b1 = b2 += b3;
b1: 10, b2: 10, b3: 5
bad += b3;
bad: -1, b3: 5
---------------------------------------------
b1 = 20; b2 = 2;
b1: -1, b2: 2
b1 = 2;
b1: -1
---------------------------------------------
b1 += 1; b2 += 1; b3 += 4;
b1: -1, b2: 3, b3: 9
---------------------------------------------
b1: 5, b2: 10, b3: 10
b1:
___________________
| [2][2][1][ ][ ]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 626.70
b2:
___________________
| [2][2][2][2][2]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 1253.40
b3:
_______________________________
| [2][2][2][2][2][ ][ ][ ][ ]|_\_
|       Seneca College           )
`---OO----------------------O---'
Total Fare Price: 1253.40

b1 has 5 passengers and b2 is 10 passengers therefore thier head counts are different
b2 has 10 passengers and b3 is 10 passengers therefore thier head counts are equal
---------------------------------------------

Binary non-member operator test
There are 5 passengers at the bus stop and there are 10 passengers on the bus.
When the passengers get off the bus there will be 15 passengers at the bus stop!


*/