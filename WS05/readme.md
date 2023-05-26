# Workshop #5: Member and Helper operators
V 0.9 (due date moved one day back to give students a chance to celebrate thanksgiving day )
v 1.0 (DIY: corrected typeconversion test bug in tester program)
## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- overload binary member operators
- create and define type conversion operators
- create and define helper operators (without using the friendship of a C++ class)
- reuse member operators
- describe what you have learned in completing this workshop.

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1: A step-by-step guided workshop, worth 50% of the workshop's total mark that is due on ~~Thursday~~**Friday at 23:59:59** of the week of your scheduled lab.
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark. This part is due on ~~Sunday~~**Monday at 23:59:59** of the week of your scheduled lab.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.


If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# LAB (part 1) (50%)

Your task for part one of this workshop is to complete the code of a class that represents an **Egg Carton**. 

Develop your Egg Carton class in the **"EggCarton"** module provided in the workshop.

The **EggCarton** class encapsulates the size of the carton (i.e. the number of eggs it can hold), the number of eggs in the carton and whether the eggs are **jumbo** size or **regular**.
## constant values 
The following **constant** values are defined in the header file.
```C++
   const int RegularEggWieght = 50;
   const int JumboEggWieght = 75;
```
These wieghts are in Grams. (1000 Grams is one Kilo)

## the constructor
```C++
EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false)
```
The Egg Carton can be instantiated using its **size**, **number of eggs** and **if the eggs are jumbo size**. 

By default, the size of the carton is **6**, the number of eggs is **0**, and the eggs are **not jumbo size**. 

When created the following validation is done on the arguments of the constructor:
- **size** must be a coefficient of 6
- **size** must be between 6 and 36 (inclusively) 
- **the number of eggs** should be between 0 and the **size** of the Carton (inclusively) 

If the values do not match the above criteria, the Carton is considered broken and unusable. This is done by calling the **"setBroken()"** privte method that sets the **size** and number of eggs in the carton to **-1**.

## `ostream& display(std::ostream& ostr) const`
displays the Carton on the screen using the **ostr** argument and the following code snippet:
```C++
 // displays an Egg Carton
 int cartonWidth = m_size == 6 ? 3 : 6;
 for (int i = 0; i < m_size; i++) {
    cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
    if ((i + 1) % cartonWidth == 0) cout << endl;
 }
```
The Carton is displayed only if it is not broken (see `operator bool()` overload), otherwise the message: `"Broken Egg Carton!"<<endl` is displayed.

In the end, the **ostr** reference is returned. 

## `istream& read(std::istream& istr)`
Reads comma-separated values from **istr** to set the **attributes** of **the Egg Carton** and then returns the **istr** reference as follows:

- read a **character** from **istr**, if it is a lower-case `J` set the **jumbo flag** to **true**, otherwise set it to **false**
- **ignore** the next character.
- read an integer into the **size** of the Carton
- **ignore** the next character
- read another **integer** into **the number of eggs**
- perform the same validation on the attributes as the **constructor** and if it fails, set the Carton to broken and unusable. 

## Type Conversion Operator overloads
### Boolean conversion.
```C++
operator bool() const;
```
This **constant conversion** returns **true** if the **size** of the Carton is **greater than zero** (i.e. Returns true if the Carton is not broken) otherwise, it will return **false**.
### Integer conversion
```C++
operator int() const;
```
This **constant conversion** returns the **number of eggs** if the Carton is not broken (use boolean conversion) otherwise, it will return **-1**
### Double Conversion
```C++
operator double() const;
```
This **constant conversion** returns the **total weight** of the eggs using the **constant weight values** defined in the header file in **Kilos**.
```text
(noOfEggs x WeightOfOnEgg)/1000.0
```
If the Carton is broken this conversion returns **-1.0**.

## Unary Operator overloads:

### prefix `operator--` 
If the Carton is **not broken** and the **number of eggs** is more than **zero**, it will reduce it by one. 

In the end it returns the reference of the **current EggCarton object** (`*this`).
### prefix `operator++` 
If the Carton is **not broken** it will add one the **number of eggs**. If the **number of eggs** exceeds the **size** of the carton, the Carton will be considered **broken and unusable**.
In the end, return the reference of the **current EggCarton object** (`*this`).
### postfix `operator--`
**Creates a local copy** of the current EggCarton object (`*this`), calls the prefix `operator--` and returns the local copy **by value**.
### postfix `operator++`
**Creates a local copy** of the current EggCarton object (`*this`), calls the prefix `operator++` and returns the local copy **by value**.

## Binary Member Operators
### `EggCarton& operator=(int value)`
Sets the number of eggs to **the integer value** and If the **number of eggs** exceeds the **size**, it will set the Carton to **broken**. 
Returns a reference to the **current object** at the end.
### `EggCarton& operator+=(int value)`
Add **the value** to the **number of eggs** if the Carton is not broken. 
If the **number of eggs** exceeds the **size**, it will set the Carton to broken. 
Returns a reference to the current object at the end.
### `EggCarton& operator+=(EggCarton& right)`
If the Carton is not broken it will **move** the eggs from the **right** Carton to the empty spots of the **current Carton** as much as it can. If there is not enough space in the current Carton, the rest of the eggs are left in **the right one**. 

> For example, if the current Carton has 3 empty spots and there are 7 eggs in the right Carton after this operator runs, the current Carton will be full and the right Carton will have 4 eggs in it.

In the end, return a reference to the current object.

### `bool operator==(const EggCarton& right) const`
Return **true** if the **difference** between the **weight of the current** Carton and the **weight of the right** Carton is between -0.001  and 0.001 kilos otherwise, return **false**.

## Helper Binary Operator Overload
### `int operator+(int left, const EggCarton& right)`
If the right operand is not broken it will return the sum of **"left"** and number of eggs in the **"right"**. Otherwise, it will return the value of the **left** only.

### `ostream& operator<<(ostream& ostr, const EggCarton& right)`

displays the EggCarton and returns **ostr**;

### `istream& operator>>(istream& istr, EggCarton& right)`

Reads the specs from the console into the **right** Carton and returns **istr**.

## Tester program:

```C++
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

```

## Execution Sample
```text

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

```

## PART 1 Submission 
To test and demonstrate the execution of your program use the same data as shown in the output example.

### Files to Submit
<pre>
EggCarton.h
EggCarton.cpp
w4p1_tester.cpp
</pre>

### Submission Process:

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

## DIY (50%)
Your task for part two of this workshop is to create a class module to represent a **Bus**. 

Develop your module int files `Bus.h`  and `Bus.cpp`

The Bus class encapsulates **the number of seats** and **the number of passengers** in a **bus**.

## global constant value 
The **price of a bus ticket** is **$125.34** and will not change throughout the program. 

## the constructor
A **Bus** can be instantiated using the **number of seats** and the **number of passengers** on board. 

By default, a bus has **20 seats** and **no passengers**. 

When created the following validation is done on the arguments of the constructor:
- **number of seats** must be a coefficient of **2**
- **number of seats** must be between **10** and **40** (inclusively) 
- the **number of passengers** should be between **0** and the **number of seats**.

If the values do not match the above criteria, the bus is considered **out of service**. 

## Displaying a bus on the screen.
A **bus** can be drawn on the screen by getting **inserted** into the **cout** object and under the drawing, on a new line the **total fare for the bus**, based on the **number of passengers** and **price of one ticket** must be displayed. 

For example, a **Bus** with **12** seats and **7** passengers should be displayed as follows:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

If the Bus is not in service the following message should be displayed instead:
```text
Out of service!
```

Use the following function in your **display** routine as a **private member** of **Bus class** to draw the bus on the screen. 

```C++
// draws a bus with 
// seat = number of seats
// psng = number of passengers
// on ostream
void drawBus(ostream& ostr, int seats, int psng) {
   int i, p;
   ostr.fill('_');
   ostr.width((seats / 2) * 3 + 4);
   ostr << "_";
   ostr << endl << "| ";
   for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
   ostr << "|_\\_" << endl;
   ostr << "| ";
   ostr.fill(' ');
   ostr.width(((seats / 2) * 3 - 14) / 2);
   ostr << " " << "Seneca College";
   ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
   ostr << " " << "    )" << endl;
   ostr << "`---OO";
   ostr.fill('-');
   ostr.width((seats / 2) * 3 - 5);
   ostr << "-" << "O---'" << endl;
}
```
> you may modify this code as long as the output is not changed.


## Reading the specs. of a bus form console:
The specifications of a bus can be **read** from the **console** by **extracting** a Bus object from **istream** (**cin**).

Extraction should be done as follows

- read an **integer** into the **number of seats**
- **ignore** the next character.
- read **an integer** into the **number of passengers**. 
- perform the same validation on the attributes as the constructor and if it fails, set the bus to **out of service**.

## Type Conversion Operator overloads
### Boolean conversion.
This read only conversion returns true if the number of seats is greater than zero. (i.e. Returns true if the bus is **in service**)
### Integer conversion
This read only conversion returns the number of passengers if the Bus is in service otherwise, it will return -1
### Double Conversion
This read only conversion returns the total fare of the bus for the trip using the number of passengers on the bus and the price of a ticket.

If the Bus is out of service this conversion returns **-1.0**.

## Unary Operator overloads:
### prefix `operator--` 
If the bus is out of service or empty, this operator returns false. Otherwise, it will reduce the number of passengers by one and returns true;

### prefix `operator++` 
If the bus is out of service or full, this operator returns false. Otherwise, it will increase the number of passengers by one and returns true;

### postfix `operator--`
Works exactly like the prefix operator--
### postfix `operator++`
Works exactly like the prefix opeator++

## Binary Member Operators
### Assigning A bus object to an integer value.

Sets the number of passengers of a bus by assigning it to the integer value and If the number of passengers exceeds the number of seats, the bus will be **out of service**.

Returns a reference to the current object at the end.
```C++
Bus B(12,0);
cout << (B = 7); 
```
will print the following:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

### Adding an integer to a Bus object using **+=** operator

Adds the integer value to the number of passengers if the bus is in service. 
If the number of passengers exceeds the number of seats, the bus will go **out of service**.

Returns a reference to the current object at the end.

```C++
Bus B(10,2);
cout << (B += 5); 
```
Will print the following:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

### Adding a bus object to another bus object using += operator.

If both busses are in service it will move the passengers from one bus (right) to another (left). If there is not enough seat in the left bus, the rest of the passengers remain in the right bus.

In the end, a reference to the left bus is returned.

```C++
  Bus A(10, 2);
  Bus B(20, 12);
  cout << A << B;
  cout << (A += B) << B;
```
Will print the following:
```text
___________________
| [2][ ][ ][ ][ ]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 250.68
__________________________________
| [2][2][2][2][2][2][ ][ ][ ][ ]|_\_
|         Seneca College            )
`---OO-------------------------O---'
Total Fare Price: 1504.08
___________________
| [2][2][2][2][2]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 1253.40
__________________________________
| [2][2][ ][ ][ ][ ][ ][ ][ ][ ]|_\_
|         Seneca College            )
`---OO-------------------------O---'
Total Fare Price: 501.36
```

### Comparing two buses using the **==** operator.

If both buses are in service and the numbers of passengers are the same, this operator returns true, otherwise, it will return false.

```C++
Bus A(10,5);
Bus B(20,5);
if (A == B) cout << "Same number of passnegers" << endl; 
```



## Helper Binary Operator Overload
### sum of an integer number (at left) and a bus (at right) 
If the bus is in service, this operation should return the sum of the number and the number of passengers on the bus. 
Otherwise, the integer number is returned as if the number of passengers on the bus was 0.

```C++
Bus A(10,5),B(5,50);
int I = 3 + A;  // I will be 8 
I = 10 + B; // I will be 10
```

## Tester Program

```C++
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
```

## Execution Sample
```text

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

```

### Reflection
Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.
Create a file named reflect.txt that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty. You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
To test and demonstrate the execution of your program use the same data as shown in the output example.

### Files to Submit
<pre>
Bus.h
Bus.cpp
w5p2_tester.cpp
</pre>

### Submission Process:

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


