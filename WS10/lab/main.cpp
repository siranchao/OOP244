// Workshop 10:
// Version: 2.0
// 2021-11-19
// Author: Fardad Soleimanloo
// Revised by: Wail Mardini
// // Description:
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
/////////////////////////////////////////////
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;

int main()
{
    Car C[7] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"),
                 Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"),
                 Car("GVDEFG", "Tesla Model X") };
    Student S[6] = { Student(23456, "Lisa Simpson",4.0),Student(45678, "Ralph Wiggum",2.1), Student(56789, "Milhouse Van Houten",4.0),
                 Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz",3.0),Student(12345, "Bart Simpson",1.5) };
    Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56,111), Employee(122345, "Mindy Simmons", 65432.44,222),
                 Employee(435678, "Lenny Leonard", 43213.22,111), Employee(546789, "Waylon Smithers", 654321.55,333),
                 Employee(657890, "Frank Grimes", 34567.88,333), Employee(364567, "Homer Simpson", 55432.11,111) };

    //these collections will hold the results of the searches
    Collection<Car> Cres1;
    Collection<Car> Cres2;
    Collection<Student> Sres;
    Collection<Employee>Eres;

    // Call the  listArrayElements to list all cars in the array C, Title: "All the cars:", size is 7
    listArrayElements(......................);
    cout << "Searching for Tesla cars: " << endl;

    // Call the search function to search the array C 
    // and store the matches in Cres1 passing "a" as the key argument
    if (search(......................))
    {
        cout << Cres1.size() << " match" << (Cres1.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres1.size(); i++)
        {
            cout << (i + 1) << ": " << Cres1[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    // Call the search function to search the array C 
    // and store the matches in Cres2 passing "b" as the key argument
    if (search(......................))
    {
        cout << Cres2.size() << " match" << (Cres2.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres1.size(); i++)
        {
            cout << (i + 1) << ": " << Cres1[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    //call the function sizeCheck and pass the resulted collections from the previous two searches
    // print "Collection 1 got more results!!", "Collection 2 got more results!!" or "equal results"
    if (sizeCheck(......................))
        cout << "Collection 1 got more results!!" << endl;
    else
        cout << "Collection 1 got less than or equal collection 2 results!!" << endl;

    cout << endl;

    // Call the  listArrayElements to list all the students, Title: "All students:"
    listArrayElements(......................);

    cout << "Searching for students with 4.0 Gpa:" << endl;
    // Call the search function to search the array S 
    // and store the matches in Sres passing 4.0 as the key argument
    if (search(......................))
    {
        cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Sres.size(); i++)
        {
            cout << (i + 1) << ": " << Sres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    // Call the  listArrayElements to list all the employees, Title: "All employees:"
    listArrayElements(......................);

    cout << "Searching for employees who share office number 111:" << endl;
    // Call the search function to search the array E 
    // and store the matches in Eres passing 111 as the key argument
    if (search(......................))
    {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++)
        {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    cout << "Searching for employees who share office number 555:" << endl;
    // Call the search function to search the array E 
    // and store the matches in Eres passing 555 as the key argument
    if (search(......................))
    {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++)
        {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    int a[]{ 10,20,30,40,50,60 };

    // Call the  listArrayElements to list all the integers in the array a
    // Title: "INTEGERS"
    listArrayElements(......................);
    return 0;
}
