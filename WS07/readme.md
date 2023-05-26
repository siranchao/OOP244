# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that make up the hierarchical structure. The base or parent class will be a `VehicleBasic` that holds common attributes of a vehicle with an engine then the child class `Dumper` will be derived from the parent class. In addition to this hierarchy, we will define custom input/output operators for these classes.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- inherit a derived class from a base class
- shadow a base class member function with a derived class member function
- access a shadowed member function that is defined in a base class
- utilize custom input/output operators with these classes
- describe to your instructor what you have learned in completing this workshop



## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1: worth 100% of the workshop's total mark, is due on **Thursday at 23:59:59** of the week of your scheduled lab.
- Part 2 (reflection): non-coding part, is due on **Sunday at 23:59:59** of the week of your scheduled lab. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

**The code that is submitted late receives 0%.**  On Sunday at midnight the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Employee ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the price for the parts you got help for, and the person helping you will be clear of any wrongdoing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# lab (part 1) (100%)


## `VehicleBasic` Module

Design and code a class named `VehicleBasic` that holds information about a vehicle with an engine. Place your class definition in a header file named `VehicleBasic.h` and your function definitions in an implementation file named `VehicleBasic.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `VehicleBasic` Class

Design and code a class named `VehicleBasic` that holds information about a vehicle with an engine.


#### `VehicleBasic` Private Members

The class should be able to store the following data:

- a license plate number as a statically allocated array of characters of size 9.
- the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
- the year when the vehicle was built.

You can add any other private members to the class, as required by your design.



#### `VehicleBasic` Public Members

- a custom constructor that receives as parameters the license plate number and the year when the vehicle was built.  Set the location of the vehicle at `Factory`. Assume all data is valid.

- `void NewAddress(const char* address)`: moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
  ```txt
  |[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
  ```
  where
  - the license plate is a field of 8 characters aligned to the right
  - current address is a field of 20 characters aligned to the right
  - new address is a field of 20 characters aligned to left

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `VehicleBasic` into a stream and extract a `VehicleBasic` from a stream. These operators should call the `write`/`read` member functions in the class `VehicleBasic`.


## `Dumper` Module

Design and code a class named `Dumper` that holds information about a motor vehicle that can carry cargo. Place your class definition in a header file named `Dumper.h` and your function definitions in an implementation file named `Dumper.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Dumper` Class

Design and code a class named `Dumper` that holds information about the basic vehicle that can carry cargo.  **This class should inherit from `VehicleBasic` class.**


#### `Dumper` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the Dumper can carry.
- the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Dumper` Public Members

- a custom constructor that receives as parameters the license plate number, the year when the Dumper was built, the capacity of the Dumper and the current address.  Call the constructor from the base class and pass the license number and year to it.  Set the current cargo to 0 and move the Dumper to the address specified in the last parameter.

- `bool loaddCargo(double cargo)`: a mutator will verify if he can load the Cargo based on the cargo load weight specified as a parameter and the current cargo on the dumper and the capacity; ** all or none will be loaded **. ** If the current load has been changed, return `true`, otherwise, return `false`.

- `bool unloadCargo()`: a mutator that unloads current cargo (sets the attribute to 0).  If the current load has been changed, return `true`, otherwise, return `false`. ** the mutator will not do anything if the current cargo is 0 and thus return false **

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
  ```

- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  Capacity: [USER TYPES HERE]
  Cargo: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `Dumper` into a stream and extract a `Dumper` from a stream. These operators should call the `write`/`read` member functions in the class `Dumper`.

## `w7_main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.
```C++
// Workshop 7: Inheritance
// Version: 1.0
// Date: 2021-08-30
// Author: Wail Mardini
/////////////////////////////////////////////

#include<iostream>
#include "Dumper.h"
#include "Dumper.h" // intentional
#include "VehicleBasic.h"
#include "VehicleBasic.h" // intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(58);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(58);
	cout << "" << endl;
	cout.fill(oldFill);
}

void moveAndLoad(Dumper& aDumper, const char* destination, double cargo)
{
	aDumper.NewAddress(destination);
	if (aDumper.loaddCargo(cargo))
		cout << "\nCargo loaded!\n";
	else
		cout << "\nLoading cargo failed!\n";
	cout << "Status " <<aDumper << endl << endl;
}

void moveAndUnload(Dumper& aDumper, const char* destination)
{
	aDumper.NewAddress(destination);
	if (aDumper.unloadCargo())
		cout << "\nCargo unloaded!\n";
	else
		cout << "\nUnloading cargo failed!\n";
	cout << "Status " << aDumper << endl << endl;
}

int main()
{
	
		printHeader("Vehicle 1: Basic Vehicle");

		VehicleBasic aVehicle("abc-123", 2010);
		cout << aVehicle << endl << endl;

		aVehicle.NewAddress("Downtown Toronto");
		aVehicle.NewAddress("Mississauga");
		aVehicle.NewAddress("North York");

		cout << endl << aVehicle << endl << endl;

		printHeader("Vehicle 2: Read/Write");
		cin >> aVehicle;
		cout << endl << aVehicle << endl << endl;
	
		printHeader("Vehicle 3: Dumper");

		Dumper aDumper("T-1111", 2015, 5432, "Toronto HQ");
		cout << endl;

		moveAndLoad(aDumper, "Toronto Deposit", 2345);

		moveAndLoad(aDumper, "Ottawa", 123); 

		moveAndLoad(aDumper, "Montreal", 3456); 

		moveAndLoad(aDumper, "New York", 4567);

		moveAndUnload(aDumper, "New Jersey");

		moveAndUnload(aDumper, "Toronto");


		printHeader("Vehicle 4: Read/Write");
		cin >> aDumper;
		cout << endl << (VehicleBasic)aDumper;
		cout << endl << aDumper << endl << endl;
	
}


```


### Sample Output

```Text
----------------------------------------------------------
|> Vehicle 1: Basic Vehicle
----------------------------------------------------------
| 2010 | abc-123 | Factory

| abc-123| |             Factory ---> Downtown Toronto    |
| abc-123| |    Downtown Toronto ---> Mississauga         |
| abc-123| |         Mississauga ---> North York          |

| 2010 | abc-123 | North York

----------------------------------------------------------
|> Vehicle 2: Read/Write
----------------------------------------------------------
Built year: 2018
License plate: abc-123
Current location: Ottawa

| 2018 | abc-123 | Ottawa

----------------------------------------------------------
|> Vehicle 3: Dumper
----------------------------------------------------------
|  T-1111| |             Factory ---> Toronto HQ          |

|  T-1111| |          Toronto HQ ---> Toronto Deposit     |

Cargo loaded!
Status | 2015 | T-1111 | Toronto Deposit | 2345/5432

|  T-1111| |     Toronto Deposit ---> Ottawa              |

Cargo loaded!
Status | 2015 | T-1111 | Ottawa | 2468/5432

|  T-1111| |              Ottawa ---> Montreal            |

Loading cargo failed!
Status | 2015 | T-1111 | Montreal | 2468/5432

|  T-1111| |            Montreal ---> New York            |

Loading cargo failed!
Status | 2015 | T-1111 | New York | 2468/5432

|  T-1111| |            New York ---> New Jersey          |

Cargo unloaded!
Status | 2015 | T-1111 | New Jersey | 0/5432

|  T-1111| |          New Jersey ---> Toronto             |

Unloading cargo failed!
Status | 2015 | T-1111 | Toronto | 0/5432

----------------------------------------------------------
|> Vehicle 4: Read/Write
----------------------------------------------------------
Built year: 2020
License plate: dab-112
Current location: Montreal
Capacity: 7000
Cargo: 0

| 2020 | dab-112 | Montreal
| 2020 | dab-112 | Montreal | 0/7000
```


## PART 1 Submission
Use the data entry values of the "sample output" above when submitting your work.

Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

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




# PART2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Reflection Submission (part 2)


Upload the **reflect.txt** to your `matrix` account. 

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
