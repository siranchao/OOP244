# Workshop #1: Modules
* Verison 1.0

In this workshop, you will deconstruct a monolithic program into multiple modules and incorporate the use of namespaces to organize the code in part 1. In part 2 you will enhance the program through the use of File reading.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:


- organize source code into modules, using header and implementation files;
- compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- describe to your instructor what you have learned in completing this workshop.


## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1: A step-by-step guided workshop, worth 50% of the workshop's total mark that is due on **Thursday at 23:59:59** of the week of your scheduled lab.
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark. This part is due on **Sunday at 23:59:59** of the week of your scheduled lab.  
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

# LAB (50%) Vending Machine

The Vending Machine is a program that despenses drinks via a text based menu. A user can choose from up to 5 drinks and can may multiple purchases (one drink at time). The following is an example execution of the program:


## Execution sample:
```Text
Welcome to the Seneca Vending Machine

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Coffee    300       1.5       5
2.Tea       250       1.25      3
3.Cola      350       2.5       2
4.Water     500       3.1       15
5.Beer      350       5.25      0
Select a drink from the menu (1-5): 0
Selection was was invalid try again: 5
Out of stock for that drink, try again: 1

Do you want to order another drink? (Y)es or (N)o: Y

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Coffee    300       1.5       4
2.Tea       250       1.25      3
3.Cola      350       2.5       2
4.Water     500       3.1       15
5.Beer      350       5.25      0
Select a drink from the menu (1-5): 2

Do you want to order another drink? (Y)es or (N)o: N

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Coffee    300       1.5       4
2.Tea       250       1.25      2
3.Cola      350       2.5       2
4.Water     500       3.1       15
5.Beer      350       5.25      0

Thank you and come again
```

## Step 1 - Test the Program

### On Visual Studio

- Open Visual studio 2019 and create an Empty C++ Windows Console Project:
![Empty Project](images/emptyproj.png)
- In VS, (if not open already) open Solution Explorer (click on View/Solution Explorer) and then add w1p1.cpp file to your project:
  - Right-click on “Source Files”
  - Select “Add/Existing Item”
  - Select **w1p1.cpp** from the file browser
  - Click on “Ok”
- Now you can run the program by selecting “Debug/Start Without Debugging” or pressing the “Ctr-F5” button.

### On Linux, in your Matrix account

- Connect to Seneca with [Global Protect VPN](https://inside.senecacollege.ca/its/services/vpn/studentvpn.html)
- Upload **w1p1.cpp** to your matrix account (Ideally to a designated directory for your workshop solutions). Then, enter the following command to compile the source file and create an executable called ws:

```bash
g++ w1p1.cpp -Wall -std=c++11 -o ws<ENTER>

-Wall: display all warnings
-std=c++11: compile using C++11 standards
-o ws:  name the executable ws
```

- Type the following to run and test the execution (use the same inputs as the execution example above):

```bash
ws<ENTER>
```

## Step 2 - Create the Modules

### On Windows, in Visual Studio (VS)

In the solution explorer add three new modules to the project:

- **drink**; A module to hold the Drink struct, a constant value representing a maximum number of Drinks and other Drink related functions
- **util**; A module that contains some utility functions related to processing user input
- **vendingmaching**; A module that will contain the main funciton and act as the entry point of the program

The **vendingmachine** module has an implementation file (.cpp) but no header file (.h). The **drink** and **util** module have both implemenation and header files

#### Header Files

Add **drink.h** and **util.h** to the "Header Files" directory (right click on “Header Files” and select “Add/New Item” and add a header file)

Make sure you add the compilation safeguards and also have all the C++ code in the last four modules in a namespace called **sdds**.

#### Compilation Header Guard

**compilation safeguards** refer to a technique to guard against multiple inclusion of header files. It does so by applying macros that check against a defined name:

```c++
#ifndef NAMESPACE_HEADERFILENAME_H // replace with relevant names
#define NAMESPACE_HEADERFILENAME_H

// Your header file content goes here

#endif
```

If the name isn’t yet defined, the #ifndef will allow the code to proceed onward to then define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.

Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).

Additionally, here is an **instructional video** showing how the compiler works and why you need these safeguards in all of your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.

[Compilation Safeguards Video Explanation](https://www.youtube.com/watch?v=EGak2R7QdHo)

#### Implementation Files

Add **vendingmachine.cpp**, **drink.cpp**, and **util.cpp** to the “Source Files” directory (right click on “Source Files” and select “Add/New Item” and add a C++ file)

## Step 3 - The Main Module

### vendingmachine Module

**vendingmachine.cpp** should have the following include and namespace statements:

```c++
#include <iostream>
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;
```

This is the module that holds the **main function** place that after the above statements.

## Step 4 - Organize code in remaining Modules

Separate the remaining functions from **w1p1.cpp** into the modules as described below. Copy the body of the functions into the respective implementation files and the prototypes to the headers.

#### Guideline for creating modules (read before moving any code)
##### #includes
Avoid unnecessary random includes and only include a header file in a cpp file in which the header file functions are called or the header file definitions are used. <br />
Do not include a header file inside another header file unless it is absolutely necessary.

##### Global variables (file scope variables)
Global variable declarations must be in the CPP files to be kept invisible to other modules

##### Structure definitions
Structure definitions must be kept in the header file to be visible to all the modules using it.

##### Constant value declarations 
The Constant value declarations are to be added to the file they are used in; if they are used in a header file, they must be added to the header file otherwise they must be added to the CPP file they are used in.

##### Namespace
All your code (in header files and CPP files) must be surrounded by the **sdds** namespace except in the module holding the **main** function.<br />
The **main** module should use the **sdds** namespace (```using namespace sdds;```).<br />
> important: Never use the **using** statement in a header file.

### drink Module

This module contains the **Drink structure**

#### Functions
```bash
loadDrinks
drinkMenu
displayDrink
chooseDrink
updateDrink 
```

#### Constant Variables
```bash
MAXDRINKS
```

#### Global Variables 
```bash
Drink machine[MAXDRINKS]
```

#### Required Standard Libraries to include
```bash
iostream
iomanip
```

### util Module

#### Functions
```bash
clearBuffer
confirm
```

#### Required Standard Libraries to include
```bash
iostream
```

## Step 5 - Testing

#### Windows
To test that you have done this correctly, you can compile each module separately, by right-clicking on ***vendingmachine.cpp**, **drink.cpp** and **util.cpp** separately and select compile from the menu. If the compilation is successful, most likely you have done it correctly.

The equivalent of this on matrix is to add -c to the compile command:
```Bash
g++ File.cpp –Wall -std=c++11 –c<ENTER>
```
This example will only compile File.cpp and will not create an executable.

Now remove **w1p1.cpp** from the project. You can do this by right-clicking on the filename in solution explorer and selecting Remove in the menu (make sure you do not delete this file but only remove it).
Compile and run the project (as you did before in Step 1) and make sure everything works.
#### Matrix (Linux)
On Linux, in your matrix account, upload all the module files to your matrix account and compile the source code using the following command.

```Bash
g++ vendingmachine.cpp drink.cpp util.cpp -Wall -std=c++11 -o ws<ENTER>
```
Run the program like before with the execution sample and make sure that everything still works properly. 


## PART 1 Submission 

### Files to submit:  
```Text
vendingmachine.cpp
drink.h
drink.cpp
util.h
util.cpp
```


Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as the execution sample above and make sure that everything works properly.

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


# DIY (50%) Vending Machine with File Reading

In the DIY we'll be upgrading the vending machine so it will instead of loading a static set of drinks (refer to loadDrinks' implementation), it will instead read a file instead to populate the machine's drinks.

In order to accomplish one new mandatory function is required to be added to the **drink** module:

```c++
void loadDrinksFromFile(const char* filename)
```

The parameter is the file name from which we'll be reading the data from. 

The data will be presented in the supplied **drinks.txt** file which has this content/format:

```text
Juice 200 2.50 3 
Soup 350 2.25 2 
Milk 150 3.50 0
Soda 400 1.10 8
Wine 250 7.25 1
```

The fields in order represent the drink's:
- name
- volume
- price
- quantity

In order to implement this function the following steps are needed:
- Open the file for reading
- Reading each line of the file and setting the attributes of the drinks based on what's read. Consider looping from 0 till MAX_DRINKS and read one line at a time.
- Closing the file when done

It may be a good idea to review the [IPC144 Chapter](https://ict.senecacollege.ca/~ipc144/pages/content/files.html) on Files and the **stdio.h** library before approaching this portion of the workshop. Some functions of note are:

- fopen - to open a File stream
- fscanf - to read from a File stream in a formatted way
- fclose - to close a File stream

Once you have implemented this function edit the main to incorporate it:

```c++
int main() {
  bool done = false;
  //loadDrinks();
  loadDrinksFromFile("drinks.txt"); // for DIY
  cout << "Welcome to the Seneca Vending Machine" << endl << endl;
  ...
```

If you have implemented the function correctly then the following output should be achieved.

**Note**

In addition to the loadDrinksFromFile function, the DIY includes an empty module called **file** (file.h, file.cpp) which you may incorporate in the implementation of the DIY. As in the Part 1, it is generally a *good idea to modularize your code for future reuse*. 

Rather than have all of the functionality be stuffed in loadDrinksFromFile it could likely be split up more cleanly. If you decide to take this route use the **file** module to do so and include it in the **drink** module.

Follow all the module guidelines from *Part 1* for the **file** module as well (eg namespaces, header guards).

If you decide to not make use of the **file** module leave them empty but have them in your directory / project for submission purposes on **Matrix**.

## DIY Execution sample
```Text
Welcome to the Seneca Vending Machine

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Juice     200       2.5       3
2.Soup      350       2.25      2
3.Milk      150       3.5       0
4.Soda      400       1.1       8
5.Wine      250       7.25      1
Select a drink from the menu (1-5): 0
Selection was was invalid try again: 3
Out of stock for that drink, try again: 5

Do you want to order another drink? (Y)es or (N)o: Y

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Juice     200       2.5       3
2.Soup      350       2.25      2
3.Milk      150       3.5       0
4.Soda      400       1.1       8
5.Wine      250       7.25      0
Select a drink from the menu (1-5): 2

Do you want to order another drink? (Y)es or (N)o: N

-----------Available Drinks-----------
Drink     Volume    Price     Quantity
1.Juice     200       2.5       3
2.Soup      350       2.25      1
3.Milk      150       3.5       0
4.Soda      400       1.1       8
5.Wine      250       7.25      0

Thank you and come again
```


## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
### Files to submit:  
```Text
vendingmachine.cpp
drink.h
drink.cpp
util.h
util.cpp
file.h
file.cpp
```

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
