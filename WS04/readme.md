# Workshop #4: Constructors, Destructors and Current object
* Version 1.0 corrected the due day to Thursday!

In this workshop, you will use Constructors,  Destructor and references of the current object to simulate a Country with cities and their population.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor
- define a custom constructor with a different number of arguments
- define a Destructor to prevent a memory leak.
- use reference of the current object
- describe to your instructor what you have learned in completing this workshop

## Submission Policy

The workshop is divided into two coding parts; part 1, **LAB** and part 2, **DIY**  and one non-coding part:

- ***LAB*** (part 1): worth 50% of the workshop's total price, is due on **Thursday at 23:59:59** of the week of your scheduled lab.

> Please note that the LAB (part 1) section is **not to be started in your lab session**. You should start it on your own before the day of your lab and join the lab session to ask for help and correct your mistakes.

- ***DIY*** (part 2): worth 50% of the workshop's total price, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *DIY* part that do not contain the *reflection* are not considered valid submissions and are ignored.

- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have prices associated with it but can incur a **penalty of max 40% of the whole workshop's price** if your professor deems it insufficient (you make your prices from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the price for the entire workshop is 0%**.

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

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# LAB (50%) Country Population Record

Your task for this lab is to create a program that provides a class called **Country**. This class can be initiated by the country name and number of **cities**. The cities are added to the country by city name and number of population. Every city can hold a specific number for the population. If more people try to migrate, a **City** will discard the overflow population. A **Country** can add a new city and allow people to migrate there.  

The **Country** then can be displayed with the name of the cities and their population.

## Implementation 
Implement this program in two modules (i.e., classes): **Country** and **City**

## The City Class
Develop this class module in two files named **City.h** and **City.cpp**. 

First, define the following constant in the **City** header:
```C++
const int POPULATION = 20000; //max population of a city
```

The **City** class encapsulates a City using its name and its population using the following member variables (attributes) and member functions (methods):

#### Private member variables(attributes)
The class has the following private member variables:
```C++
    char m_cityName[31];// holds the city name up to 30 chars
    int m_population;//number of people. A city can have zero population.
```
#### Public member functions(methods)
A **City** can be created in two different ways:
###### No argument constructor (default)
```C++
    City();
```
By default a **City** is instantiated by setting all the member variables to default values. You can do this by setting the first character of **m_cityName** to an empty Cstring and  **m_population** to a value like **-1**.

###### Two argument constructor
```C++
    City(const char* name,int population);
```
A **City** can also be created by the city name and the number of population. 

If **name** is not nullptr and not empty also if **population** is greater than or equal to zero (a city can have 0 population) then it will set the received arguments to the corresponding member variables. Otherwise, set the values to a safe empty state.

```C++
void setEmpty();
```
Sets a **City** to a safe empty state by setting **m_cityName** to an empty string and **m_population** to **-1**.

```C++
void setCityName(const char* name);
```
If **name** is not nullptr then it will copy the Cstring pointed by the **name** argument into **m_cityName** attribute up to 30 characters. Otherwise, set it to an empty string.

```C+
void setPopulation(int population);
```
If the population value is less than the constant **POPULATION** then it will set **m_population** attribute to the value. Otherwise, it will set it  to **-1**

```C++
void addPopulation(int population);
```
This function will add the newly migrated population to a city up to the constant **POPULATION** limit. If the received value is less than **POPULATION** then it will add the value to that city. If after adding, **m_population** exceeds value of the constant  **POPULATION** then it will set the **m_population** to **POPULATION** instead, discarding the population overflow.

```C++
bool isEmpty()const;
```
Returns true if **m_cityName** is empty or the **m_population** is less than **0**. 

```C++
int getPeople()const;
```
Returns  **m_population**

```C++
void display()const;
```
1) If City object is valid<br/>
     a) prints "|" <br/>
     b) prints **m_cityName** in 30 spaces ,left justified.<br/>
     c) prints " | "<br/>
     d) prints **m_population** in 10 spaces, right justified.<br/>
     e) prints " | "<br/>
     f) new line<br/>
2) otherwise prints,  cout << "Invalid city" << endl;



## The Country Class
Develop this module in two files named **Country.h** and **Country.cpp**. Place your class definition in **Country.h** and your function definitions in **Country.cpp**. Create a class named **Country** and the class should have the following member variables (attributes) and member functions (method):
First, define the following constant in the **Country** header:
```
const int MAX_CITY = 20; //maximum number of cities
```
#### Private member variables(attributes)
The class should have the following private member variables:
```C++
    char* m_name;//points to a dynamically allocated Cstring holding the Country name
    int m_noOfCity;//size of the dynamically allocated array of cities
    City* m_city=nullptr;//pointer to the dynamically allocated array of cities
```
#### Public member functions(methods)
A **Country** can be created in two different ways:
###### No argument constructor (default)
```C++
    Country();
```
- By default, a **Country** is initiated by setting all the member variable values to default values. You can do this by setting **m_name**, **m_city** to nullptr and **m_noOfCity** to a recognizable value like **0**.

###### Three argument constructor
```C++
    Country(const char* name, int noOfCity,const City* cities);
```
 A **Country** can also be created by a name, the number of cities and adding a list of cities:
- First, it will set the attributes to default values (So if the   argument validation fails, the object will be in a safe empty state)
- Next, if all of the arguments are valid, it will set  **m_name** and **m_noOfCity** to the corresponding argument values. The number of cities cannot be more than **MAX_CITY** and less than zero. 
- Then dynamically allocate an array of cities pointed by **m_city** member variable. The length of this array will be **m_noOfCity**.
- Lastly, add all the cities to the dynamically allocated array of **m_city**.

```C++
void setName(const char* name);
```
Sets the name of the **Country**. First, it will delete the old resources of the **m_name**. Then if the incoming **name** is not nullptr and not empty it will allocate memory to the length of the name argument (+1 for null character) and copy the name into the newly allocated memory. Otherwise, it will deallocate the m_city array and set the object to the safe empty state.

```C++
Country& addCity(const City& c);
```
If the incoming City reference is not empty, this method will add the city to the **m_city** array of cities, otherwise, the function is exited and no action will be taken.

 To accommodate the new city you have to resize the memory of the **m_city**. 
- create a temporary pointer of type **City** and dynamically allocate an array of cities with the length of **m_noOfCity + 1**.
- then copy the existing values into temp.
- delete the resources of **m_city**
- add the new received city to the temp array and increase the value of **m_noOfCity**.
- assign the temp to **m_city**

In all cases when the function ends, return the current object.

```C++
Country& migrate(int people);
```
This function will receive the number of people who want to migrate to the list of cities **m_city**. It will loop through all the cities one by one. If a city`s population is less than the **POPULATION** constant value then this function will add the received people to that city. Otherwise, it will do nothing. lastly, return the current object.

```C++
void setEmpty();
```
Sets the **Country** object to an Empty State. Do this by setting the **m_name** and **m_city** to nullptr and **m_noOfCity** to **0**.

```C++
bool isEmpty()const;
```
Returns true if **m_name** is nullptr; 

```C++
~Country()
```
Deallocate the memory allocated by **m_name** and **m_city**. 

```C++
void display()const;
```
If the **Country** object is not empty this function will print the output in the following format: (For more details see the sample output)
- prints "Country Name: " 
- prints the name and then goes to new line
- prints "No of city: "
- printf the number of cities and  then goes to new line
- prints "City name" with width 32, left justified.
- prints "Population"
- goes to new line
- will loop through the **m_city** elements, printing each of them.
 
otherwise prints, cout<< "Invalid country object" << endl;


## Tester program:
```C++
// Workshop #4:
// Version: 0.9
// Date: 2021/05/01
// Author: Nargis Khan
// Description:
// This file tests the lab section of your workshop
// Revision: Fardad Soleimanloo
// Date: 2021/10/01
///////////////////////////////////////////////////
#include<iostream>
#include"City.h"
#include"Country.h"
using namespace std;
using namespace sdds;

int main() {
	int i;
	
	City c1[]{
		City(), 
		City("",1000),
		City("Bad1", -1) };

	City c2[]{
		City("Lily",15000),
		City("Tulip",8000),
		City("Daisy",500) };

	City c3{"Rose",0};

	Country cu[]{
		Country(),
		Country(nullptr,5,c2),
		Country("Bad1", 0,c2),
		Country("Flower",3,c2)
	};
	
	cout << "Displaying invalid Country objects" << endl;
	for (i = 0; i < 3; i++) {
		cout << i + 1<<". ";
		cu[i].display();
	}
	cout << "------------------------------------------------------" << endl;

	cout << "Displaying valid Country object with valid cities" << endl;
		cu[3].display();	
	cout << "-------------------------------------------------------" << endl;

	cout << "Displaying invalid City objects" << endl;
	for (i = 0; i < 3; i++) {
		cout << i + 1 << ". ";
		c1[i].display();
	}
	cout << "------------------------------------------------------" << endl;

	cout << "Migrating 10K people to the Flower country cities"<<endl;
	cu[3].migrate(10000);
	cu[3].display();
	cout << "-------------------------------------------------------" << endl;

	cout << "Adding a new city to the country and migrating new people there" << endl;
	cu[3].addCity(c3);
	cu[3].migrate(8000);
	cu[3].display();
	return 0;
	}
```
## Execution sample:
```Text
Displaying invalid Country objects
1. Invalid country object
2. Invalid country object
3. Invalid country object
------------------------------------------------------
Displaying valid Country object with valid cities
Country Name: Flower
No of city: 3
City name                       Population
|Lily                           |      15000 |
|Tulip                          |       8000 |
|Daisy                          |        500 |
-------------------------------------------------------
Displaying invalid City objects
1. invalid city
2. invalid city
3. invalid city
------------------------------------------------------
Migrating 10K people to the Flower country cities
Country Name: Flower
No of city: 3
City name                       Population
|Lily                           |      20000 |
|Tulip                          |      18000 |
|Daisy                          |      10500 |
-------------------------------------------------------
Adding a new city to the country and migrating new people there
Country Name: Flower
No of city: 4
City name                       Population
|Lily                           |      20000 |
|Tulip                          |      20000 |
|Daisy                          |      18500 |
|Rose                           |       8000 |

```
## LAB Submission (part 1)

### Files to submit:  
```Text
Country.cpp
Country.h
City.cpp
City.h
CountryTester.cpp
```

Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca user-id
- replace **#** with the workshop number
- replace **??** with your subject code (2**00** or 2**44**)
```text
~profname.proflastname/submit 2??/w#/p1
```

and follow the instructions.

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

# DIY (50%) Book Chapters
>Except from the mandatory sections of DIY, all the other parts can be changed by students if they find it necessary as long as the program produces an output that exactly matches the required output. Please note that you can (and probably should) add more member functions to make the DIY part work.

Write a program that encapsulates a **Book** with its title and its **Chapter**s name with the pages in each chapter.  

## Chapter
A Chapter object should get instantiated using the name of the Chapter and the number of pages.  The name can be a maximum of 50 characters long and the pages of the chapters cannot be more than 200. If any of this information is not provided or if they are invalid, the object is created in an invalid state.

A Chapter is displayed as follows (if Valid):
- Name in 50 spaces, filled with dots '.', left-justified
- Number of pages in 3 spaces right-justified 
- Newline
  
If the chapter is invalid, it should just print: ```"invalid Chapter"``` and go to newline.

For example if the Chapter name is **Java** and it is **60** pages, it should print as follows:

```text
Java..............................................  60
```

## Book
A Book is created using its name, number of chapters and an array of Chapters ( with "number of chapters" elements).

The length of the name or the number of chapters is unknown.

The following are the public functions required for the Class Book.

```C++
bool isEmpty()const;
```
returns true if the Book is empty or invalid, otherwise, it returns false;
```C++
Book& addChapter(const char* chapter_name, int noOfPages);
```
Adds a Chapter to a Book only if the name and noOfPages are valid values (to create a Chapter with). 

```C++
void display()const;
```
Displays the Book as follows, if it is valid:
- prints "Book Name: " 
- prints the book name value
- NEWLINE
- prints "No of chapters: " 
- prints the number of chapters
- prints all the Chapters in individual lines
If the book is invalid it will print:
- otherwise, prints "Invalid book object";

## Note
> Make sure all the allocated memory is deleted when the object goes out of scope.

## Tester program:

```C++
// Workshop #4:
// Version: 0.9
// Date: 2021/05/01
// Author: Nargis Khan
// Description:
// This file tests the DIY section of your workshop
// Revision: Fardad Soleimanloo
// Date: 2021/10/01
///////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include"Chapter.h"
#include"Book.h"
using namespace std;
using namespace sdds;

void displayBooks(const Book* b, int num);
void DMAtest(Book& B);
int main() {

   Chapter cp1[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80) ,
      Chapter()
   };


   Chapter cp2[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter("",100)
   };

   Chapter cp3[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter("Bad1", 0)
   };

   Chapter cp4[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80),
      Chapter(nullptr, 40)
   };
   
   Chapter cp[] = {
      Chapter("C++",75),
      Chapter("Java",60),
      Chapter("JavaScript",80)
   };

   Book bo[] = {
      Book(nullptr,3,cp),
      Book("Bad1", 0,cp),
      Book("Bad2", 4,cp1),
      Book("Bad3", 4,cp2),
      Book("Bad4", 4,cp3),
      Book("Bad5", 4,cp4),
      Book("Object Oriented Programming Languages", 3, cp)
   };

   cout << "Displaying invalid Book objects" << endl;
   cout << "-------------------------------------------------------" << endl;
   displayBooks(bo, 5);
   cout << "Displaying valid Book object with valid chapters" << endl;
   cout << "-------------------------------------------------------" << endl;
   displayBooks(&bo[6], 1);
   cout << "Adding a new Chapter to the Book" << endl;
   cout << "-------------------------------------------------------" << endl;
   bo[6].addChapter("Python", 100);
   bo[6].display();
   cout << "-------------------------------------------------------" << endl;
   cout << "Testing DMA" << endl;
   cout << "-------------------------------------------------------" << endl;
   cout << "Press enter to continue: ";
   cin.ignore();
   DMAtest(bo[6]);
   return 0;
}
void DMAtest(Book& B) {
   for (int i = 0; i < 2000; i++) B.addChapter("testing", i%202);
   B.display();
}
void displayBooks(const Book* b, int num) {
   int i;
   for (i = 0; i < num; i++) {
      b[i].display();
   }
   cout << "-------------------------------------------------------" << endl;
}
```
## The output:
```text
Displaying invalid Book objects
-------------------------------------------------------
Invalid Book object
Invalid Book object
Invalid Book object
Invalid Book object
Invalid Book object
-------------------------------------------------------
Displaying valid Book object with valid chapters
-------------------------------------------------------
Book Name: Object Oriented Programming Languages
No of Chapters: 3
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
-------------------------------------------------------
Adding a new Chapter to the Book
-------------------------------------------------------
Book Name: Object Oriented Programming Languages
No of Chapters: 4
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
Python............................................ 100
-------------------------------------------------------
Testing DMA
-------------------------------------------------------
Press enter to continue:
Book Name: Object Oriented Programming Languages
No of Chapters: 1985
Chapter name                                       Pages
C++...............................................  75
Java..............................................  60
JavaScript........................................  80
Python............................................ 100
testing...........................................   1
testing...........................................   2
testing...........................................   3
testing...........................................   4
testing...........................................   5
testing...........................................   6
testing...........................................   7
testing...........................................   8
... any many more lines will be printed

```
## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
### Files to submit:  
```Text
Book.h
Book.cpp
Chapter.h
Chapter.cpp
BookTester.cpp
```

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca user-id
- replace **#** with the workshop number
- replace **??** with your subject code (2**00** or 2**44**)
```text
~profname.proflastname/submit 2??/w#/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
