# Workshop #6: Classes and resources, IO operators
* Version 1.0

In this workshop, you will implement a class with overloaded constructors. Then you will overload IO operators that will be used to read and write on the screen and files.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and implement multiple constructors
- define and implement the rule of three
- Read formatted data using `istream`
- Write formatted data using `ostream`
- Overload the extraction and insertion operators for I/O, using iostream 

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1: A step-by-step guided workshop, worth 50% of the workshop's total mark that is due on **Thursday at 23:59:59** of the week of your scheduled lab.
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark. This part is due on **Sunday at 23:59:59** of the week of your scheduled lab.  
- **reflection**: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
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


## Two functions we need to know about

Before we start part 1 of this workshop we need to introduce two member functions that are available in istream:
```C++
setstate(); 
peek();
```
- **setstate();** manually sets the status of the istream object to a desired state. In our case we will be calling `setstate` as follows to manually set any object of istream (like cin) to a **fail** state:
```C++
// Examples:
// assuming there is a funciton called readData as follows
istream& readData(istream& istr){
    type variable{};
    istr >> variable;
    if(/*logic for variable being invalid*/){
        istr.setstate(ios::failbit); // this manually sets istr to failure
                                     // if the variable is readable but not acceptable
    }
    return istr;
}
// Or:

int getAge(){
    int age{};
    cin >> age;
    if(age < 19){
        cin.setstate(ios::failbit); // this sets cin to fail if the age is bellow 19
    }
    return age;
}

void someLogic(){
    cout << "Enter your age: ";
    int age = getAge();
    if(cin.fail()){
       cout << "You are not old enough to consume alcoholic drinks in Ontario!" <<endl; 
       cin.clear();
    }
}

```

- **peek();**, it peeks and checks the next character without extracting it from the keyboard. With this function, you can check and see what is the next character before reading it. 
setting m_name to nullptr before constructor invocation 

```C++
// Example
char next;
int value;

cout <<"Enter a number: ";
next = cin.peek();
if(next < '0' || next >'9'){ // checking if the next character in keyboard is not a digit
    cout << "You did not enter a number!";
}
else{
    cin >> value;
}
cin.ignore(1000, '\n'); // flush the invalid value or everything after the number.
```

## Part 1 - lab (50%), The Contact class

Your task for this part of your workshop is to complete the implementation of the Contact class. This class encapsulates the phone contact information of a person using the following attributes:

```C++
   class Contact {
      char* m_name{}; // sets m_name to nullptr before any constructor invocation 
      int m_area;
      int m_exchangeCode;
      int m_number;
      public:
      ...
   };
```

- Full name (Dynamically allocated)
- A Phone number is kept in three separate parts; Area code, Exchange Code and Number. For example in the phone number `(416) 491-5050` **416** is the area code, **491** is the exchange code and **5050** is the number. 

### Validation
These values are validated (considered **valid**) as follows:
   - A Valid full name is a Cstring that is not null and not empty.
   - area code having exactly 3 digits (100 to 999, inclusive)
   - Exchange code having exactly 3 digits (100 to 999, inclusive)
   - Number being an integer between 0 and 9999 inclusive.
   
The Contact class is to validate and store the above information via initialization and data entry from istream.

Also, the Contact class must comply with the rule of three not to cause crash or memory leak (i.e. the implementation of copy constructor, copy assignment and destructor)

Although the name of the Contact is dynamically held, but thorough a constant value the maximum possible size for a name is set to be 55 characters:
```C+
   const int MaxNameLength = 55;
```

Finally, A Contact object should reveal its status (of being valid or invalid) via type conversion overload of the Boolean type (a true outcome means the object is valid and a false outcome means it is invalid).

To accomplish the above and have an organized and modular code, implement these private methods to help you with the implementation of the whole logic: (you can add more if you like to)

### Private Methods

#### bool validPhone(int areaCode, int exchangeCode, int number)const;
Returns true is the three parts of a phone number are valid. (see [Validation](#validation))

#### void setEmpty();
Sets the Contact object to a recognizable empty (invalid) state by setting **m_name** to nullptr;

#### void allocateAndCopy(const char* name);
- First is will free the memory pointed by **m_name** 
- allocates memory enough to store **name** Cstring
- copies the Cstring pointed by **name** into the newly allocated memory pointed by **m_name**

#### void extractChar(std::istream& istr, char ch)const;
- First, it will peek and see if the next character in the keyboard buffer is the same as the **ch** argument 
- If yes, it will read and remove it from the keyboard. (it throws it away!)
- If not, it will set the istream into a fail state.

#### ostream& printPhoneNumber(ostream& istr)const;
Inserts the three parts of the phone number into the **istr** object in following format:<br />
`(999) 999-0009`<br/>
and then returns the **istr** object reference
> Note: the last part (number) is right justified and padded with zeros in width of 4.

#### void set(const char* name, int areaCode, int exchangeCode, int number);
sets the object attributes to their values after validating the arguments and then safely allocating memory for the name.

- If the name and the three parts are valid (see [Validation](#validation)) `Use private functions`
    - Calls the **allocateAndCopy** function to set the name
    - Sets the three parts to their values
- If not, it deletes the memory pointed by **m_name** and sets the object to a safe empty state (**setEmpty()**)

#### Constructors. 
The Contact can either get created with no values (default constructor) into a safe empty state or using all four values. 

Use the **set** function for the latter case. 

> Note that since the **m_name** attribute is initialized in the class definition to be **nullptr**, there is no need to worry about setting it to **nullptr** before calling the set function.

### Rule of three
#### Copy Constructor
`Contact(const Contact& cnt);`<br />
- if the **cnt** object is valid it will set the values of the current object to the those of the incoming argument (**cnt**).

#### Copy Assignment operator overload
`Contact& operator=(const Contact& cnt);`<br />
- First, it will make sure that this is not a "self copy" by comparing the address of the current object and the address of the incoming argument.
- If it is not a self copy this function works exactly like the copy constructor
- If it is a self copy don't perform any action 
At the end return the reference of the current object.

#### Destructor
deletes the memory pointed by **m_name**.

### Boolean type conversion operator
Returns true if **m_name** is not null, else it will return false;=

### ostream& print(ostream& ostr, bool toFile = true) const;
If the current object is in a valid state it inserts the values of the Contact information in two different formats based on the value of the **toFile** argument:
- if **toFile** is true, prints the data in comma separated format:<br />
    - prints the name
    - print comma
    - print the phone number using the private function
- if **toFile** is false prints the data in the following format:
    - In 50 characters, left justified and padded with dots ('.')
    - prints the name
    - print the phone number using the private function
- At the end it returns the **ostr** reference

### istream& read(istream& istr);
Reads the Contact information in followng format:
- name
- comma
- (
- area code
- )
- space
- exchange code
- dash ('-')
- number

Example: `Luke Skywalker,(647) 555-9475`

#### read implementation

In local variables read each part and if data is invalid set the **istr** to failure:
- using istream::get() read the name up to **MaxNameLength** or a comma (do not extract comma)
- extract a comma. (using **extractChar** private function)
- extract an open parentheses **'('** character (using **extractChar** private function)
- extract the area code into a local variable (istr >> value;)
- extract a close parentheses **')'** (using **extractChar** private function)
- extract a space character (using **extractChar** private function)
- extract the exchange code into a local variable
- extract a dash character **'-'** (using **extractChar** private function)
- extract the number into a local variable
- extract a new line character **'\n'** (using **extractChar** private function)
- if **istr** is not in a failure state
    - all data were read successfully, use the **set** private function to set values of the object to read value
- if **istr** is in a failure state, don't do anything a leave the Contact to its original values. 
- at the end return the **istr** reference

### insertion operator overload
`ostream& operator<<(ostream& ostr, const Contact& cnt);`<br />
if **cnt** is valid it will print it using the **print** function on the screen and not on File, (i.e. onFile is false). Otherwise it will print `"Invalid Phone Record"`.

In the end, it will return the **ostr** reference.

### extraction operator overload
`istream& operator>>(istream& istr, Contact& cnt)`<br />
returns the **read** method of the **cnt** argument.

## the tester program
```C++
// Workshop #6:
// Version: 0.9
// Date: 2021/10/17
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
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
   ofstream goodPhoneFile("goodNumbers.txt");
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
      cout << "Read " << i - 1 << " out of " << recs << " Records successfuly" << endl;
      cout << "Record number " << i << " is invalid!" << endl;
   }
   showFile("goodNumbers.txt");
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
   cout << "Contact Conent:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,111222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Conent:" << endl << C << endl;
   
   cout << "Enter the following:" << endl
      << ">Gandalf,(111)222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Conent:" << endl << C << endl;
   
   cout << "Enter the following:" << endl
      << ">Gandalf,(111) 2223333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Conent:" << endl << C << endl;
   
   cout << "Enter the following:" << endl
      << ">,(111) 222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Conent:" << endl << C << endl;

   cout << "Enter the following:" << endl
      << ">Gandalf,(111) 222-3333" << endl << ">";
   cin >> C;
   if (!cin) {
      cout << "Invalid Contact information" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
   }
   cout << "Contact Conent:" << endl << C << endl;
}


Contact ReadPhoneFromFile(istream& istr) {
   Contact C;
   istr >> C;
   return C;
}


```
## Tester output
```text
Validation Test
Fred Soley........................................(416) 491-0050
Invalid Phone Record
Invalid Phone Record
Invalid Phone Record
Invalid Phone Record
Invalid Phone Record
Invalid Phone Record
Invalid Phone Record

Data entry test.
Enter the test data using copy and paste to save time:

Enter the following:
>Gandalf-(111) 222,3333
>Gandalf-(111) 222,3333
Invalid Contact information
Contact Content:
Gandalf The Grey..................................(111) 222-0003
Enter the following:
>Gandalf,111222-3333
>Gandalf,111222-3333
Invalid Contact information
Contact Content:
Gandalf The Grey..................................(111) 222-0003
Enter the following:
>Gandalf,(111)222-3333
>Gandalf,(111)222-3333
Invalid Contact information
Contact Content:
Gandalf The Grey..................................(111) 222-0003
Enter the following:
>Gandalf,(111) 2223333
>Gandalf,(111) 2223333
Invalid Contact information
Contact Content:
Gandalf The Grey..................................(111) 222-0003
Enter the following:
>,(111) 222-3333
>,(111) 222-3333
Invalid Contact information
Contact Content:
Gandalf The Grey..................................(111) 222-0003
Enter the following:
>Gandalf,(111) 222-3333
>Gandalf,(111) 222-3333
Contact Content:
Gandalf...........................................(111) 222-3333

Rule of three test ---------------------------------------------
Jango Fett........................................(416) 555-8015
Padme Amidala.....................................(905) 555-9325
Q'ira.............................................(301) 555-3317
Firmus Piett......................................(705) 555-2063
Wedge Antilles....................................(647) 555-0495
Mon Mothma........................................(289) 555-6015
Count Dooku.......................................(416) 555-9903
Nien Nunb.........................................(905) 555-9141
Ponda Baba........................................(301) 555-4136
Max Rebo..........................................(705) 555-5202
Salacious B. Crumb................................(647) 555-6071
Enfys Nest........................................(289) 555-4382
Figrin D'an and the Modal Nodes...................(416) 555-5310
Wicket W. Warrick.................................(905) 555-7088
Poe Dameron.......................................(301) 555-7736
Qui-Gon Jinn......................................(705) 555-6073
Bib Fortuna.......................................(647) 555-4729
Finn..............................................(289) 555-9090
Kylo Ren..........................................(416) 555-3082
Chirrut Imwe......................................(905) 555-3874
Mace Windu........................................(301) 555-1845
Chewbacca.........................................(705) 555-3166
Jabba the Hut.....................................(647) 555-8392
Greedo............................................(289) 555-5763
Lando Calrissian..................................(416) 555-6912
Darth Maul........................................(905) 555-8201
Obi-Wan Kenobi....................................(301) 555-3858
Rey...............................................(705) 555-7583
Luke Skywalker....................................(647) 555-9475
Princess Leia.....................................(289) 555-7976
Yoda..............................................(416) 555-5461
Boba Fett.........................................(905) 555-9868
Darth Vader.......................................(301) 555-0086
Han Solo..........................................(705) 555-8107
Invalid Phone Record
Read 34 out of 36 Records successfully
Record number 35 is invalid!
Contents of goodNumbers.txt
----------------------------------------------------------------
Jango Fett........................................(416) 555-8015
Padme Amidala.....................................(905) 555-9325
Q'ira.............................................(301) 555-3317
Firmus Piett......................................(705) 555-2063
Wedge Antilles....................................(647) 555-0495
Mon Mothma........................................(289) 555-6015
Count Dooku.......................................(416) 555-9903
Nien Nunb.........................................(905) 555-9141
Ponda Baba........................................(301) 555-4136
Max Rebo..........................................(705) 555-5202
Salacious B. Crumb................................(647) 555-6071
Enfys Nest........................................(289) 555-4382
Figrin D'an and the Modal Nodes...................(416) 555-5310
Wicket W. Warrick.................................(905) 555-7088
Poe Dameron.......................................(301) 555-7736
Qui-Gon Jinn......................................(705) 555-6073
Bib Fortuna.......................................(647) 555-4729
Finn..............................................(289) 555-9090
Kylo Ren..........................................(416) 555-3082
Chirrut Imwe......................................(905) 555-3874
Mace Windu........................................(301) 555-1845
Chewbacca.........................................(705) 555-3166
Jabba the Hut.....................................(647) 555-8392
Greedo............................................(289) 555-5763
Lando Calrissian..................................(416) 555-6912
Darth Maul........................................(905) 555-8201
Obi-Wan Kenobi....................................(301) 555-3858
Rey...............................................(705) 555-7583
Luke Skywalker....................................(647) 555-9475
Princess Leia.....................................(289) 555-7976
Yoda..............................................(416) 555-5461
Boba Fett.........................................(905) 555-9868
Darth Vader.......................................(301) 555-0086
Han Solo..........................................(705) 555-8107
```
### Files to Submit
<pre>
Contact.cpp          
Contact.h           
phoneNumbers.csv
w6p1_tester.cpp
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

# Part 2 - DIY (50%)  The Book class

Your task for this part of your workshop is to complete the implementation of the Book class. The Book class is used to keep track of the location of a book in a library. This class encapsulates a book with respect to its title, author, shelf and bookcase number.

> It is strongly recommended to use what you have learnt in part 1 of this workshop. You are free to use the code or logic of part 1 with no citation.

- Book title is a Cstring (Dynamically allocated); the maximum possible name length should be kept in constant integer (global variable) and set to 40 characters
- Author name is a Cstring(Dynamically allocated); the maximum possible title length should be kept in constant integer (global variable) and set to 25 characters
- Bookcase number; the maximum valid value for bookcase number should be kept in constant integer (global variable) and set to 132 characters
- Shelf number; the maximum valid value for a shelf number should be kept in constant integer (global variable) and set to 7 characters

Based on the maximum valid values of bookcases and shelves, the library in this program has 132 bookcases and each bookcase has 7 shelves

### Validation
The attributes of the book class are validated (considered **valid**) as follows:
   - A valid book title and author name is not null and not empty
   - Bookcase number can be between 1 and the number of bookcases in the library inclusive.
   - Shelf number can be between 1 and the number of bookcase shelves in the library inclusive.

#### The mandatory constant integer global values
- `NoOfBookCases` set to 132
- `NoOfShelves` set to 7
- `MaxTitleLen` set to 40
- `MaxAuthorLen` set to 25

The Book class should validate and store the member variables (attributes) via initialization and data entry from istream.

Also, the Book class must comply with the rule of three not to cause a crash or memory leak.

Although the title and the author of the Book are dynamically held, note that the maximum amount of memory allocated is dictated by the constant values described in the [Validation](#validation) section. If any attempt is made to hold Cstring values longer than the maximum limit, the action should fail, rendering the object into an invalid safe empty state.

Finally, A Book object should reveal its status (of being valid or invalid) via a type conversion overload of the Boolean type (a true outcome means the object is valid and a false outcome means it is invalid).


### Mandatory Member functions and constructors

#### Default constructor 
Sets the Book to an empty invalid state.

#### Four argument constructor 
Sets the object attributes in the following order: title, author, bookcase number and shelf number

#### Rule of three
Implement all that is needed to follow **the rule of three**.

####  ostream& write(ostream& ostr, bool onScreen = true)const;
This member function outputs the Book object (if the object is valid) in two different formats based on the **onScreen** flag.

> The output samples assume the book name is "The Alchemist" by "Paulo Coelho" held in bookcase number 25, shelf number 1

##### onScreen == true
prints the book as follows:
```text
The Alchemist                           | Paulo Coelho             | 1/025
```
if the object is invalid it should print:
```text
Invalid Book Record ................... | ........................ | .....
```
##### onScreen == false
prints the book as follows:
```text
The Alchemist,Paulo Coelho,1/25
```
if the object is invalid it should print:
```text
Invalid Book Record
```

#### insertion and extraction operator overloads
#### insertion operator overload
Overload the insertion operator so the Book can be printed by an ostream object like cout.
```C++
Book B;
cout << B << endl;
```
The printing format and rules should be identical to the Book::write member function

#### extraction operator overload
Overload the extraction operator so the Book information can be read by an istream object like cin.
The book is always received using comma separated format:
```text
The Alchemist,Paulo Coelho,1/25
```
If the Cstring values are too long or empty, if any of the delimiters (like comma ',' and slash '/') are missing or misplaced, or if the integer values are out of bound, the istream object should be manually set into a fail state via the function call:`setstate(ios::failbit)`. 
> hint: The first two Cstrings are read using getline with (**','**) as the delimiter.
```C++
Book B;
cout << "Please enter book information: ";
cin >> B;
cout << "Thanks, you entered:" << endl << B <<endl;
```
Output:
```text
Please enter book information: The Alchemist,Paulo Coelho,1/25
Thanks, you entered:
The Alchemist                           | Paulo Coelho             | 1/025
```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 - DIY Submission 
### Files to submit:  
```Text
Book.cpp
Book.h
books.csv
w6p2_tester.cpp
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


### Tester program:
```C++
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
   int noOfReads = 0;
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
```
### The input data file, "books.csv"
```text
Harry Potter and the Chamber of Secrets,J. K. Rowling,2/56
Harry Potter and the Prisoner of Azkaban,J. K. Rowling,4/126
Harry Potter and the Goblet of Fire,J. K. Rowling,4/107
Harry Potter and the Order of the Phoenix,J. K. Rowling,4/100
Harry Potter and the Half-Blood Prince,J. K. Rowling,4/61
Harry Potter and the Deathly Hallows,J. K. Rowling,6/80
The Alchemist,Paulo Coelho,1/25
The Catcher in the Rye,J. D. Salinger,3/121
The Bridges of Madison County,Robert James Waller,6/21
Ben-Hur: A Tale of the Christ,Lew Wallace,5/132
You Can Heal Your Life,Louise Hay,1/16
One Hundred Years of Solitude,Gabriel Garca Mrquez,3/86
Lolita,Vladimir Nabokov,6/127
Heidi,Johanna Spyri,5/54
The Common Sense Book of Baby and Child Care,Benjamin Spock,3/104
Anne of Green Gables,Lucy Maud Montgomery,6/10
Black Beauty,Anna Sewell,2/73
The Name of the Rose,Umberto Eco,5/123
The Eagle Has Landed,Jack Higgins,6/129
Watership Down,Richard Adams,5/122
The Hite Report,Shere Hite,3/126
Charlotte's Web,E. B. White; illustrated byGarth Williams,2/130
The Tale of Peter Rabbit,Beatrix Potter,6/78
Jonathan Livingston Seagull,Richard Bach,6/102
The Very Hungry Caterpillar,Eric Carle,2/116
A Message to Garcia,Elbert Hubbard,3/118
To Kill a Mockingbird,Harper Lee,5/32
Flowers in the Attic,V. C. Andrews,7/73
Cosmos,Carl Sagan,1/30
Sophie's World,Jostein Gaarder,5/49
Angels & Demons,Dan Brown,4/69
Kane and Abel,Jeffrey Archer,4/121
How the Steel Was Tempered,Nikolai Ostrovsky,6/60
War and Peace,Leo Tolstoy,3/64
The Diary of Anne Frank,Anne Frank,4/99
Your Erroneous Zones,Wayne Dyer,7/55
The Thorn Birds,Colleen McCullough,2/20
The Purpose Driven Life,Rick Warren,1/97
The Kite Runner,Khaled Hosseini,6/7
Valley of the Dolls,Jacqueline Susann,3/28
The Great Gatsby,F. Scott Fitzgerald,1/33
Gone with the Wind,Margaret Mitchell,2/5
Rebecca,Daphne du Maurier,6/64
Nineteen Eighty-Four,George Orwell,1/20
The Revolt of Mamie Stover,William Bradford Huie,2/75
The Girl with the Dragon Tattoo,Stieg Larsson,2/44
The Lost Symbol,Dan Brown,4/62
The Hunger Games,Suzanne Collins,7/100
James and the Giant Peach,Roald Dahl,6/99
The Young Guard,Alexander Alexandrovich Fadeyev,2/28
Who Moved My Cheese?,Spencer Johnson,6/48
A Brief History of Time,Stephen Hawking,4/86
Paul et Virginie,Jacques-Henri Bernardin de Saint-Pierre,6/49
Lust for Life,Irving Stone,3/46
The Wind in the Willows,Kenneth Grahame,3/92
The Happy Hooker: My Own Story,Xaviera Hollander,6/90
Jaws,Peter Benchley,6/20
Love You Forever,Robert Munsch,6/66
The Women's Room,Marilyn French,5/16
What to Expect When You're Expecting,Arlene EisenbergandHeidi Murkoff,2/72
Adventures of Huckleberry Finn,Mark Twain,3/114
The Secret Diary of Adrian Mole- Aged 13 3/4,Sue Townsend,1/56
Pride and Prejudice,Jane Austen,5/21
Kon-Tiki: Across the Pacific in a Raft,Thor Heyerdahl,4/27
The Good Soldier Svejk,Jaroslav Haek,7/90
Where the Wild Things Are,Maurice Sendak,6/19
The Power of Positive Thinking,Norman Vincent Peale,2/8
The Secret,Rhonda Byrne,2/40
Fear of Flying,Erica Jong,5/12
Dune,Frank Herbert,3/83
Charlie and the Chocolate Factory,Roald Dahl,2/20
The Naked Ape,Desmond Morris,5/36
Totto-chan- the Little Girl at the Window,Tetsuko Kuroyanagi,6/56
Matilda,Roald Dahl,6/55
The Total Woman,Marabel Morgan,3/94
Knowledge-value Revolution,Taichi Sakaiya,6/27
Problems in China's Socialist Economy,Xue Muqiao,6/60
What Color Is Your Parachute?,Richard Nelson Bolles,5/130
The Dukan Diet,Pierre Dukan,1/115
The Joy of Sex,Alex Comfort,5/0
The Gospel According to Peanuts,Robert L. Short,7/53
Life of Pi,Yann Martel,2/37
The Giver,Lois Lowry,5/64
The Front Runner,Patricia Nell Warren,2/119
The Goal,Eliyahu M. Goldratt,0/64
Fahrenheit 451,Ray Bradbury,2/108
Angela's Ashes,Frank McCourt,1/78
The Story of My Experiments with Truth,Mohandas Karamchand Gandhi,2/77
Bridget Jones's Diary,Helen Fielding,5/75
Harry Potter,J. K. Rowling,1/45
Goosebumps,R. L. Stine,2/188
Perry Mason,Erle Stanley Gardner,7/5
Berenstain Bears,Stan and Jan Berenstain,5/93
Choose Your Own Adventure,Various authors,4/8
Diary of a Wimpy Kid,Jeff Kinney,2/41
Sweet Valley High,Francine Pascaland ghostwriters,5/40
Noddy,Enid Blyton,4/97
Nancy Drew,Various authors asCarolyn Keene,1/58
The Railway Series,Rev. W. Awdry-Christopher Awdry,4/21
San-Antonio,Frdric Dard,5/73
Robert Langdon,Dan Brown,4/19
The Baby-sitters Club,Ann Martin,5/2
Twilight,Stephenie Meyer,4/25
Star Wars,Various authors,2/113
Little Critter,Mercer Mayer,3/115
Peter Rabbit,Beatrix Potter,5/36
Fifty Shades,E. L. James,3/63
American Girl,Various authors,5/20
Geronimo Stilton,Elisabetta Damiand ghostwriters,10/100
Chicken Soup for the Soul,Jack Canfield-Mark Victor Hansen,1/79
Clifford the Big Red Dog,Norman Bridwell,5/108
Frank Merriwell,Gilbert Patten,2/77
Dirk Pitt,Clive Cussler,6/30
Musashi,Eiji Yoshikawa,5/81
The Chronicles of Narnia,C. S. Lewis,4/100
Mr. Men,Roger Hargreaves-Adam Hargreaves,6/97
The Hunger Games trilogy,Suzanne Collins,5/51
James Bond,Ian Fleming,3/71
Martine,Gilbert Delahaye-Marcel Marlier,1/108
Millennium,Stieg Larsson-David Lagercrantz,4/26
A Song of Ice and Fire,George R. R. Martin,2/121
Discworld,Terry Pratchett,6/39
Nijntje,Dick Bruna,6/7
Alex Cross,James Patterson,2/96
Anpanman,Takashi Yanase,3-51
Captain Underpants,Dav Pilkey,1/72
Fear Street,R. L. Stine,3/78
Pippi Longstocking,Astrid Lindgren,7/22
The Vampire Chronicles,Anne Rice,3/30
The Wheel of Time,Robert Jordan-Brandon Sanderson,7/82
OSS 117,Jean Bruce,3/20
Winnie-the-Pooh,A. A. Milne; illustrated byE. H. Shepard,3/59
Magic Tree House series,Mary Pope Osborne,4/96
Left Behind,Tim LaHaye-Jerry B. Jenkins,1/57
A Series of Unfortunate Events,Lemony SnicketakaDaniel Handler,2/31
Little House on the Prairie,Laura Ingalls Wilder,3/114
Jack Reacher,Lee Child,5/118
The Magic School Bus,Joanna Cole- illustrated byBruce Degen,2/89
Where's Wally?,Martin Handford,7/15
Men Are from Mars- Women Are from Venus,John Gray,3/20
The Hardy Boys,Various authors asFranklin W. Dixon,3/79
The Bobbsey Twins,Various authors asLaura Lee Hope,2/114
Tarzan,Edgar Rice Burroughs,3/93

```

### Output
```text
Constructor test --------------------------------------------------------------
Row: Book Title                              | Author(s)                | Loc
---------------------------------------------+--------------------------+------
Invalid Book Record ................... | ........................ | .....
Invalid Book Record ................... | ........................ | .....
Invalid Book Record ................... | ........................ | .....
Invalid Book Record ................... | ........................ | .....
Invalid Book Record ................... | ........................ | .....
Invalid Book Record ................... | ........................ | .....
Huckleberry Finn                        | Mark Twain               | 7/132
Invalid Book Record ................... | ........................ | .....
End Constructor test ----------------------------------------------------------
Read and Rule of three --------------------------------------------------------
Row: Book Title                              | Author(s)                | Loc
---------------------------------------------+--------------------------+------
001: Harry Potter and the Chamber of Secrets | J. K. Rowling            | 2/056
002: Harry Potter and the Prisoner of Azkaban| J. K. Rowling            | 4/126
003: Harry Potter and the Goblet of Fire     | J. K. Rowling            | 4/107
004: Invalid Book Record ................... | ........................ | .....
005: Harry Potter and the Half-Blood Prince  | J. K. Rowling            | 4/061
006: Harry Potter and the Deathly Hallows    | J. K. Rowling            | 6/080
007: The Alchemist                           | Paulo Coelho             | 1/025
008: The Catcher in the Rye                  | J. D. Salinger           | 3/121
009: The Bridges of Madison County           | Robert James Waller      | 6/021
010: Ben-Hur: A Tale of the Christ           | Lew Wallace              | 5/132
011: You Can Heal Your Life                  | Louise Hay               | 1/016
012: One Hundred Years of Solitude           | Gabriel Garca Mrquez     | 3/086
013: Lolita                                  | Vladimir Nabokov         | 6/127
014: Heidi                                   | Johanna Spyri            | 5/054
015: Invalid Book Record ................... | ........................ | .....
016: Anne of Green Gables                    | Lucy Maud Montgomery     | 6/010
017: Black Beauty                            | Anna Sewell              | 2/073
018: The Name of the Rose                    | Umberto Eco              | 5/123
019: The Eagle Has Landed                    | Jack Higgins             | 6/129
020: Watership Down                          | Richard Adams            | 5/122
021: The Hite Report                         | Shere Hite               | 3/126
022: Invalid Book Record ................... | ........................ | .....
023: The Tale of Peter Rabbit                | Beatrix Potter           | 6/078
024: Jonathan Livingston Seagull             | Richard Bach             | 6/102
025: The Very Hungry Caterpillar             | Eric Carle               | 2/116
026: A Message to Garcia                     | Elbert Hubbard           | 3/118
027: To Kill a Mockingbird                   | Harper Lee               | 5/032
028: Flowers in the Attic                    | V. C. Andrews            | 7/073
029: Cosmos                                  | Carl Sagan               | 1/030
030: Sophie's World                          | Jostein Gaarder          | 5/049
031: Angels & Demons                         | Dan Brown                | 4/069
032: Kane and Abel                           | Jeffrey Archer           | 4/121
033: How the Steel Was Tempered              | Nikolai Ostrovsky        | 6/060
034: War and Peace                           | Leo Tolstoy              | 3/064
035: The Diary of Anne Frank                 | Anne Frank               | 4/099
036: Your Erroneous Zones                    | Wayne Dyer               | 7/055
037: The Thorn Birds                         | Colleen McCullough       | 2/020
038: The Purpose Driven Life                 | Rick Warren              | 1/097
039: The Kite Runner                         | Khaled Hosseini          | 6/007
040: Valley of the Dolls                     | Jacqueline Susann        | 3/028
041: The Great Gatsby                        | F. Scott Fitzgerald      | 1/033
042: Gone with the Wind                      | Margaret Mitchell        | 2/005
043: Rebecca                                 | Daphne du Maurier        | 6/064
044: Nineteen Eighty-Four                    | George Orwell            | 1/020
045: The Revolt of Mamie Stover              | William Bradford Huie    | 2/075
046: The Girl with the Dragon Tattoo         | Stieg Larsson            | 2/044
047: The Lost Symbol                         | Dan Brown                | 4/062
048: The Hunger Games                        | Suzanne Collins          | 7/100
049: James and the Giant Peach               | Roald Dahl               | 6/099
050: Invalid Book Record ................... | ........................ | .....
051: Who Moved My Cheese?                    | Spencer Johnson          | 6/048
052: A Brief History of Time                 | Stephen Hawking          | 4/086
053: Invalid Book Record ................... | ........................ | .....
054: Lust for Life                           | Irving Stone             | 3/046
055: The Wind in the Willows                 | Kenneth Grahame          | 3/092
056: The Happy Hooker: My Own Story          | Xaviera Hollander        | 6/090
057: Jaws                                    | Peter Benchley           | 6/020
058: Love You Forever                        | Robert Munsch            | 6/066
059: The Women's Room                        | Marilyn French           | 5/016
060: Invalid Book Record ................... | ........................ | .....
061: Adventures of Huckleberry Finn          | Mark Twain               | 3/114
062: Invalid Book Record ................... | ........................ | .....
063: Pride and Prejudice                     | Jane Austen              | 5/021
064: Kon-Tiki: Across the Pacific in a Raft  | Thor Heyerdahl           | 4/027
065: The Good Soldier Svejk                  | Jaroslav Haek            | 7/090
066: Where the Wild Things Are               | Maurice Sendak           | 6/019
067: The Power of Positive Thinking          | Norman Vincent Peale     | 2/008
068: The Secret                              | Rhonda Byrne             | 2/040
069: Fear of Flying                          | Erica Jong               | 5/012
070: Dune                                    | Frank Herbert            | 3/083
071: Charlie and the Chocolate Factory       | Roald Dahl               | 2/020
072: The Naked Ape                           | Desmond Morris           | 5/036
073: Invalid Book Record ................... | ........................ | .....
074: Matilda                                 | Roald Dahl               | 6/055
075: The Total Woman                         | Marabel Morgan           | 3/094
076: Knowledge-value Revolution              | Taichi Sakaiya           | 6/027
077: Problems in China's Socialist Economy   | Xue Muqiao               | 6/060
078: What Color Is Your Parachute?           | Richard Nelson Bolles    | 5/130
079: The Dukan Diet                          | Pierre Dukan             | 1/115
080: Invalid Book Record ................... | ........................ | .....
081: The Gospel According to Peanuts         | Robert L. Short          | 7/053
082: Life of Pi                              | Yann Martel              | 2/037
083: The Giver                               | Lois Lowry               | 5/064
084: The Front Runner                        | Patricia Nell Warren     | 2/119
085: Invalid Book Record ................... | ........................ | .....
086: Fahrenheit 451                          | Ray Bradbury             | 2/108
087: Angela's Ashes                          | Frank McCourt            | 1/078
088: Invalid Book Record ................... | ........................ | .....
089: Bridget Jones's Diary                   | Helen Fielding           | 5/075
090: Harry Potter                            | J. K. Rowling            | 1/045
091: Invalid Book Record ................... | ........................ | .....
092: Perry Mason                             | Erle Stanley Gardner     | 7/005
093: Berenstain Bears                        | Stan and Jan Berenstain  | 5/093
094: Choose Your Own Adventure               | Various authors          | 4/008
095: Diary of a Wimpy Kid                    | Jeff Kinney              | 2/041
096: Invalid Book Record ................... | ........................ | .....
097: Noddy                                   | Enid Blyton              | 4/097
098: Invalid Book Record ................... | ........................ | .....
099: Invalid Book Record ................... | ........................ | .....
100: San-Antonio                             | Frdric Dard              | 5/073
101: Robert Langdon                          | Dan Brown                | 4/019
102: The Baby-sitters Club                   | Ann Martin               | 5/002
103: Twilight                                | Stephenie Meyer          | 4/025
104: Star Wars                               | Various authors          | 2/113
105: Little Critter                          | Mercer Mayer             | 3/115
106: Peter Rabbit                            | Beatrix Potter           | 5/036
107: Fifty Shades                            | E. L. James              | 3/063
108: American Girl                           | Various authors          | 5/020
109: Invalid Book Record ................... | ........................ | .....
110: Invalid Book Record ................... | ........................ | .....
111: Clifford the Big Red Dog                | Norman Bridwell          | 5/108
112: Frank Merriwell                         | Gilbert Patten           | 2/077
113: Dirk Pitt                               | Clive Cussler            | 6/030
114: Musashi                                 | Eiji Yoshikawa           | 5/081
115: The Chronicles of Narnia                | C. S. Lewis              | 4/100
116: Invalid Book Record ................... | ........................ | .....
117: The Hunger Games trilogy                | Suzanne Collins          | 5/051
118: James Bond                              | Ian Fleming              | 3/071
119: Invalid Book Record ................... | ........................ | .....
120: Invalid Book Record ................... | ........................ | .....
121: A Song of Ice and Fire                  | George R. R. Martin      | 2/121
122: Discworld                               | Terry Pratchett          | 6/039
123: Nijntje                                 | Dick Bruna               | 6/007
124: Alex Cross                              | James Patterson          | 2/096
125: Invalid Book Record ................... | ........................ | .....
126: Captain Underpants                      | Dav Pilkey               | 1/072
127: Fear Street                             | R. L. Stine              | 3/078
128: Pippi Longstocking                      | Astrid Lindgren          | 7/022
129: The Vampire Chronicles                  | Anne Rice                | 3/030
130: Invalid Book Record ................... | ........................ | .....
131: OSS 117                                 | Jean Bruce               | 3/020
132: Invalid Book Record ................... | ........................ | .....
133: Magic Tree House series                 | Mary Pope Osborne        | 4/096
134: Invalid Book Record ................... | ........................ | .....
135: Invalid Book Record ................... | ........................ | .....
136: Little House on the Prairie             | Laura Ingalls Wilder     | 3/114
137: Jack Reacher                            | Lee Child                | 5/118
138: Invalid Book Record ................... | ........................ | .....
139: Where's Wally?                          | Martin Handford          | 7/015
140: Men Are from Mars- Women Are from Venus | John Gray                | 3/020
141: Invalid Book Record ................... | ........................ | .....
142: Invalid Book Record ................... | ........................ | .....
143: Tarzan                                  | Edgar Rice Burroughs     | 3/093
+++ Good Books ----------------------------------------------------------------
Row: Book Title                              | Author(s)                | Loc
---------------------------------------------+--------------------------+------
001: Harry Potter and the Chamber of Secrets | J. K. Rowling            | 2/056
002: Harry Potter and the Prisoner of Azkaban| J. K. Rowling            | 4/126
003: Harry Potter and the Goblet of Fire     | J. K. Rowling            | 4/107
004: Harry Potter and the Half-Blood Prince  | J. K. Rowling            | 4/061
005: Harry Potter and the Deathly Hallows    | J. K. Rowling            | 6/080
006: The Alchemist                           | Paulo Coelho             | 1/025
007: The Catcher in the Rye                  | J. D. Salinger           | 3/121
008: The Bridges of Madison County           | Robert James Waller      | 6/021
009: Ben-Hur: A Tale of the Christ           | Lew Wallace              | 5/132
010: You Can Heal Your Life                  | Louise Hay               | 1/016
011: One Hundred Years of Solitude           | Gabriel Garca Mrquez     | 3/086
012: Lolita                                  | Vladimir Nabokov         | 6/127
013: Heidi                                   | Johanna Spyri            | 5/054
014: Anne of Green Gables                    | Lucy Maud Montgomery     | 6/010
015: Black Beauty                            | Anna Sewell              | 2/073
016: The Name of the Rose                    | Umberto Eco              | 5/123
017: The Eagle Has Landed                    | Jack Higgins             | 6/129
018: Watership Down                          | Richard Adams            | 5/122
019: The Hite Report                         | Shere Hite               | 3/126
020: The Tale of Peter Rabbit                | Beatrix Potter           | 6/078
021: Jonathan Livingston Seagull             | Richard Bach             | 6/102
022: The Very Hungry Caterpillar             | Eric Carle               | 2/116
023: A Message to Garcia                     | Elbert Hubbard           | 3/118
024: To Kill a Mockingbird                   | Harper Lee               | 5/032
025: Flowers in the Attic                    | V. C. Andrews            | 7/073
026: Cosmos                                  | Carl Sagan               | 1/030
027: Sophie's World                          | Jostein Gaarder          | 5/049
028: Angels & Demons                         | Dan Brown                | 4/069
029: Kane and Abel                           | Jeffrey Archer           | 4/121
030: How the Steel Was Tempered              | Nikolai Ostrovsky        | 6/060
031: War and Peace                           | Leo Tolstoy              | 3/064
032: The Diary of Anne Frank                 | Anne Frank               | 4/099
033: Your Erroneous Zones                    | Wayne Dyer               | 7/055
034: The Thorn Birds                         | Colleen McCullough       | 2/020
035: The Purpose Driven Life                 | Rick Warren              | 1/097
036: The Kite Runner                         | Khaled Hosseini          | 6/007
037: Valley of the Dolls                     | Jacqueline Susann        | 3/028
038: The Great Gatsby                        | F. Scott Fitzgerald      | 1/033
039: Gone with the Wind                      | Margaret Mitchell        | 2/005
040: Rebecca                                 | Daphne du Maurier        | 6/064
041: Nineteen Eighty-Four                    | George Orwell            | 1/020
042: The Revolt of Mamie Stover              | William Bradford Huie    | 2/075
043: The Girl with the Dragon Tattoo         | Stieg Larsson            | 2/044
044: The Lost Symbol                         | Dan Brown                | 4/062
045: The Hunger Games                        | Suzanne Collins          | 7/100
046: James and the Giant Peach               | Roald Dahl               | 6/099
047: Who Moved My Cheese?                    | Spencer Johnson          | 6/048
048: A Brief History of Time                 | Stephen Hawking          | 4/086
049: Lust for Life                           | Irving Stone             | 3/046
050: The Wind in the Willows                 | Kenneth Grahame          | 3/092
051: The Happy Hooker: My Own Story          | Xaviera Hollander        | 6/090
052: Jaws                                    | Peter Benchley           | 6/020
053: Love You Forever                        | Robert Munsch            | 6/066
054: The Women's Room                        | Marilyn French           | 5/016
055: Adventures of Huckleberry Finn          | Mark Twain               | 3/114
056: Pride and Prejudice                     | Jane Austen              | 5/021
057: Kon-Tiki: Across the Pacific in a Raft  | Thor Heyerdahl           | 4/027
058: The Good Soldier Svejk                  | Jaroslav Haek            | 7/090
059: Where the Wild Things Are               | Maurice Sendak           | 6/019
060: The Power of Positive Thinking          | Norman Vincent Peale     | 2/008
061: The Secret                              | Rhonda Byrne             | 2/040
062: Fear of Flying                          | Erica Jong               | 5/012
063: Dune                                    | Frank Herbert            | 3/083
064: Charlie and the Chocolate Factory       | Roald Dahl               | 2/020
065: The Naked Ape                           | Desmond Morris           | 5/036
066: Matilda                                 | Roald Dahl               | 6/055
067: The Total Woman                         | Marabel Morgan           | 3/094
068: Knowledge-value Revolution              | Taichi Sakaiya           | 6/027
069: Problems in China's Socialist Economy   | Xue Muqiao               | 6/060
070: What Color Is Your Parachute?           | Richard Nelson Bolles    | 5/130
071: The Dukan Diet                          | Pierre Dukan             | 1/115
072: The Gospel According to Peanuts         | Robert L. Short          | 7/053
073: Life of Pi                              | Yann Martel              | 2/037
074: The Giver                               | Lois Lowry               | 5/064
075: The Front Runner                        | Patricia Nell Warren     | 2/119
076: Fahrenheit 451                          | Ray Bradbury             | 2/108
077: Angela's Ashes                          | Frank McCourt            | 1/078
078: Bridget Jones's Diary                   | Helen Fielding           | 5/075
079: Harry Potter                            | J. K. Rowling            | 1/045
080: Perry Mason                             | Erle Stanley Gardner     | 7/005
081: Berenstain Bears                        | Stan and Jan Berenstain  | 5/093
082: Choose Your Own Adventure               | Various authors          | 4/008
083: Diary of a Wimpy Kid                    | Jeff Kinney              | 2/041
084: Noddy                                   | Enid Blyton              | 4/097
085: San-Antonio                             | Frdric Dard              | 5/073
086: Robert Langdon                          | Dan Brown                | 4/019
087: The Baby-sitters Club                   | Ann Martin               | 5/002
088: Twilight                                | Stephenie Meyer          | 4/025
089: Star Wars                               | Various authors          | 2/113
090: Little Critter                          | Mercer Mayer             | 3/115
091: Peter Rabbit                            | Beatrix Potter           | 5/036
092: Fifty Shades                            | E. L. James              | 3/063
093: American Girl                           | Various authors          | 5/020
094: Clifford the Big Red Dog                | Norman Bridwell          | 5/108
095: Frank Merriwell                         | Gilbert Patten           | 2/077
096: Dirk Pitt                               | Clive Cussler            | 6/030
097: Musashi                                 | Eiji Yoshikawa           | 5/081
098: The Chronicles of Narnia                | C. S. Lewis              | 4/100
099: The Hunger Games trilogy                | Suzanne Collins          | 5/051
100: James Bond                              | Ian Fleming              | 3/071
101: A Song of Ice and Fire                  | George R. R. Martin      | 2/121
102: Discworld                               | Terry Pratchett          | 6/039
103: Nijntje                                 | Dick Bruna               | 6/007
104: Alex Cross                              | James Patterson          | 2/096
105: Captain Underpants                      | Dav Pilkey               | 1/072
106: Fear Street                             | R. L. Stine              | 3/078
107: Pippi Longstocking                      | Astrid Lindgren          | 7/022
108: The Vampire Chronicles                  | Anne Rice                | 3/030
109: OSS 117                                 | Jean Bruce               | 3/020
110: Magic Tree House series                 | Mary Pope Osborne        | 4/096
111: Little House on the Prairie             | Laura Ingalls Wilder     | 3/114
112: Jack Reacher                            | Lee Child                | 5/118
113: Where's Wally?                          | Martin Handford          | 7/015
114: Men Are from Mars- Women Are from Venus | John Gray                | 3/020
115: Tarzan                                  | Edgar Rice Burroughs     | 3/093
End Read and Rule of three ----------------------------------------------------
```


