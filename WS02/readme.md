# Workshop #2: Dynamic Memory
* Version 0.9

In this workshop, you will use references to modify the content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate, reallocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;

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

# LAB (50%)

MortalKombat is a program that allows the user to add fighters to a competition and then beat them against each other in a deathmatch. The new Competitors will be added to a dynamic array of fighters. This array will increase in size to allocate the new fighter data. When the Fighter loses a match, he also loses his life. His info will be scratched out of the records and the array of fighters will decrease in size. After all the fights are completed, the program will list the information of the fighters that are still standing.

## Implementation 

A module called `Fighter` has been provided to you. This module will include two structs and your function prototypes. 
The Fighter struct is already provided to you. A fighter has an array of characters that saves his/her name and can contain a maximum of 50 characters. A fighter also has an integer that saves his power level.
You need to add the Competition struct and your function prototypes to the 'Fighter' module. The details are listed below.

### `Competition` struct

The competition struct includes a pointer to a fighter. This pointer will be used to allocate a dynamically allocated array of fighters who will join the competition.
The competition struct also includes an integer that will track the current number of fighters in the competition.

### Global Functions

Write a function called 'fighter':

- `void fighter(char* name)`: reads a fighter name from the keyboard and stores the read characters into the array received as a parameter. It is expected that a `Fighter` structure instance’s name will be passed in, so it may be given a value from user input.
  - First, the function will print `Enter Fighter Name:  ` using the `cout` object.
  - Then get the name of the user using the `cin` object into the `name` argument.

Write a function to overload the fighter function (remember that overloaded functions are functions with the same name, but different signature):

- `void fighter(int& power)`: reads a number from the keyboard and stores it into the parameter (consider what would happen if this was a plain `int` rather than a reference to an `int`). Similar to the previous function, the expected behaviour is that we pass in a `Fighter` structure instance’s power to this function so it may be given value from user input.

  - First, the function will print `Enter Fighter Power: ` using the `cout` object.
  - Then read a number from the keyboard using `cin` and save it in the `power` reference argument.

- `void display(const Fighter& myFighter)`: displays on the screen the content of the parameter in the following format:

  ```txt
  "Name: " [name] ", Power: " [Power]<Newline>
  ```
  
- `void display(const Competition& mycompetition)`: Uses the fighter display function to output the data of all the available fighters in the competition.
  
- `void addFighter(Competition& myCompetition)`: allows user to add fighters information to a Competition. This function implements the following pseudo-code:

   - Dynamically allocate a new Array of type Fighter in a Fighter pointer. (The size of the new Fighter Array should be one more than the size of the Competition fighters so the new fighter can be added.)
   - In a loop, copy the data from the competition fighters array (provided as the function parameter) to the new array of fighters. (*Note that since the new array is one element larger than the fighters array in the Competition, the last element of the new array will remain untouched*).
   - Prompt the user to enter the fighter information by displaying the following message `Information of the new fighter:<NEWLINE>`.
   - Use your `fighter` overloaded function to read the name and then the power of the new fighter into the last element of the new fighter array. 
   - Remove the fighters array of the Competition from memory (delete the fighters array in Competition object)
   - Set the fighters pointer in the Competition to the new fighters pointer.
   - Add one to the number of fighters in the Competition.
   - This completes adding a new fighter and the function ends

- `void removeFighter(Competition& mycompetition,const Fighter& loserFighter)`: allows the program to remove a fighter from a competition. This function implements the following pseudo code:

   - Dynamically allocate a new Array of type Fighter in a Fighter pointer. (The size of the new Fighter Array should be one less than the size of the Competition fighters so the loser fighter can be removed.)
   - Find the index of the `loserFighter` using the function `findFighter`. 
   - If the loserFighter is found in the Competition, in a loop with two indices (One for the new fighter array and one for the Competition fighter array), copy the data from the competition fighters array (provided as the function parameter) to the new array of fighters except for the loserFighter. This will remove the loser  (*Make sure the index of the new fighter array is increased in each repetition only if the current fighter index is not equal to the found index of the loserFighter in the Competition*).
   - reduce the number of fighters in the Competition by one
   - Remove the fighters array of the Competition from memory (delete the fighters array in Competition object)
   - Set the fighters pointer in the Competition to the new fighters pointer.
   - This completes removing a fighter and the function ends

- `int findFighter(const Competition& mycompetition,const Fighter& theFighter)`: returns the index of a desired fighter. It uses **theFighter** name as search criteria. If the fighter is not found, this function returns -1.
   - Define an integer to keep the found index and initially set it to -1
   - Start by looping through the fighters in the Competition.
   - Compare each fighter's name in the Competition with theFighter argument's name. If there is a match keep the found index and end the loop;
   - Return the found index (it will be -1 if no match were found) 

- `bool fight(const Fighter& f1,const Fighter& f2`: returns true if first fighter is stronger than the second one. returns false otherwise.

  
- `void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)`: Two fighters will compete and the loser will be removed from the competition. make sure to use your fight function to determine the loser and use the removeFighter to remove the fighter from the competition.

   - Announce who is fighting against whom in following format: <br />
   ```text
   "    " [name of f1] " will fight " [name of f2] "..."<NEWLINE>```
   ```
   - Then announce the winner
   ```text
   "    The winner => " 
   ```
   - using the overloaded fight function determine the winner
   - print the winner's name and remove the loser using `removeFighter` function



## Tester program (mainKombat): 
This module is fully provided. Do not change any of its code. Review it and make sure you understand how the functions that you have developed are being used.

## Execution sample:

```text
*********************************
Welcome to OOP244-Mortal Kombat
*********************************
Information of the new fighter:
Enter Fighter Name: Thor
Enter Fighter Power: 987
Information of the new fighter:
Enter Fighter Name: Oden
Enter Fighter Power: 995
Information of the new fighter:
Enter Fighter Name: Zeus
Enter Fighter Power: 998
Information of the new fighter:
Enter Fighter Name: Ares
Enter Fighter Power: 985
*********************************
List of fighters:
Name: Thor, Power: 987
Name: Oden, Power: 995
Name: Zeus, Power: 998
Name: Ares, Power: 985
*********************************
Let the fights begin:
*********************************
    Thor will fight Oden...
    The winner => Name: Oden, Power: 995
*********************************
List of fighters Still Standing:
Name: Oden, Power: 995
Name: Zeus, Power: 998
Name: Ares, Power: 985
*********************************
    Oden will fight Zeus...
    The winner => Name: Zeus, Power: 998
*********************************
List of fighters Still Standing:
Name: Zeus, Power: 998
Name: Ares, Power: 985
*********************************
    Zeus will fight Ares...
    The winner => Name: Zeus, Power: 998
*********************************
The winner of the competition is:
Name: Zeus, Power: 998

```

## PART 1 Submission 

### Files to submit:  
```Text
mainKombat.cpp<--- contains the main function, do not modify this.
Fighter.cpp
Fighter.h
```

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


# DIY (50%)  (Restaurant Guest List)
After the pandemic, to help with contact tracing each restaurant is responsible to write the name and phone number of all their guests.

Help to complete a program that receives the name and phone number of a restaurant, then stands by to receive guest names and numbers.

The number of guests is unknown and the guest list should be kept dynamically. 

At the end of the day to end the program, the user hits enter instead of entering the guest name. This should end the program and display all the guests visited that day. 

## Sample execution:
```text
Please enter the name of the restaurant: Seneca Cafe
Enter Phone Number [area] [number]: 416 4915050
Guest entry...
Enter guest information or Enter to exit:
Guest name: Fred Soley
Enter Phone Number [area] [number]: 416 1112222
Enter guest information or Enter to exit:
Guest name: Homer Simpson
Enter Phone Number [area] [number]: 541 2223333
Enter guest information or Enter to exit:
Guest name: Barney Gumble
Enter Phone Number [area] [number]: 541 3332222
Enter guest information or Enter to exit:
Guest name: Edna Krabappel
Enter Phone Number [area] [number]: 541 4443333
Enter guest information or Enter to exit:
Guest name:


Seneca Cafe, Phone Number: (416) 4915050
**********************************************
Guestlist and their contacts:
1- Fred Soley, (416) 1112222
2- Homer Simpson, (541) 2223333
3- Barney Gumble, (541) 3332221
4- Edna Krabappel, (541) 4443333
```

## Implementation 
This application is implemented in two modules:
- Main Module (provided)
- Guest Module (partially provided)

Your task is to complete the implementation of the Guest module to provide the functions needed in the Main module.

***You may freely use/copy any logic or code needed from the LAB section!***

### Structurs to be used:

```C++
   struct PhoneNumber {
      int m_number;
      int m_areacode;
   };

   struct Guest {
      char m_name[21];
      PhoneNumber m_phno;
   };

   struct GuestList {
      Guest* m_gst;  // Dynamically holds the list of guests.
      int m_noOfGuests;
   };
```

### Mandatory functions
```C++
   void read(char* str, int len);
```
Reads a CString into the ```str``` pointer up to **len** characters.

This function is already implemented and is provided in the Guest module

```C++
   void read(PhoneNumber& thePhoneNumber);
```
Prompts: `"Enter Phone Number [area] [number]: "` and then receives two integers from `cin` into the area code and number of **thePhoneNumber** reference.

```C++
   bool read(Guest& theGuest);
```
Prompts: `"Guest name: "` and then reads a CString into the name of **theGuest** reference. 
If the user enters a value, then it will read the phone number of **theGuest** and returns true, otherwise, if the CString for the name is empty after entry, the function returns false.

```C++
   void print(const PhoneNumber& thePhoneNumber);
```
Prints a phone number as follows:
- Open parenthesis `"("`
- phone area code
- close parenthesis and space `") "`
- phone number
- newline

```C++
   void print(const Guest& theGuest);
```
Prints the guest information as follows: 
- name
- comma and space `", "`
- phone number

```C++
   void print(const GuestList& theGuestList);
```
Prints all the guests in a list. It also adds a row number with a dash before each name.

```C++
   void addGuest(GuestList& theGuestList, const Guest& aGuest);
```
Adds **aGuest** to the dynamically allocated list of guests in **theGuestList**

## Tester program (guestList.cpp)
This module is fully provided. Do not change any of its code. Review it and make sure you understand how the functions that you have developed are being used.


## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
### Files to submit:  
```Text
guestList.cpp<--- contains the main function, do not modify this.
Guest.cpp
Guest.h
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
