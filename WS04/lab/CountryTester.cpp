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

/*
	
Displaying invalid Country objects
1. Invalid country object
2. Invalid country object
3. Invalid country object
------------------------------------------------------
Displaying valid Country object with valid cities
Country Name: Flower
No of city: 3
City name                Population
|Lily                 |      15000 |
|Tulip                |       8000 |
|Daisy                |        500 |
-------------------------------------------------------
Displaying invalid City objects
1. invalid city
2. invalid city
3. invalid city
------------------------------------------------------
Migrating 10K people to the Flower country cities
Country Name: Flower
No of city: 3
City name                Population
|Lily                 |      20000 |
|Tulip                |      18000 |
|Daisy                |      10500 |
-------------------------------------------------------
Adding a new city to the country and migrating new people there
Country Name: Flower
No of city: 4
City name                Population
|Lily                 |      20000 |
|Tulip                |      20000 |
|Daisy                |      18500 |
|Rose                 |       8000 |

*/