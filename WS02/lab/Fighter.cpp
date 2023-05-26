/*
Name: Siran Cao
email: scao34@myseneca.ca
ID: 159235209
Date: 09/23/2021
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fighter.h"

using namespace std;
namespace sdds {

	void fighter(char* name)
	{
		cout << "Enter Fighter Name: ";
		cin >> name; 
	}

	void fighter(int& power)
	{	
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void display(const Fighter& myFighter)
	{
		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;
	}

	void display(const Competition& mycompetition)
	{
		for (int i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}
	}

	void addFighter(Competition& mycompetition)
	{
		Fighter* tempFighters = nullptr;
		tempFighters = new Fighter[mycompetition.numfighters + 1];
		if (tempFighters != nullptr)
		{
			for (int i = 0; i < mycompetition.numfighters; i++)
			{
				tempFighters[i] = mycompetition.fighters[i];
			}
		}

		cout << "Information of the new fighter:" << endl;
		fighter(tempFighters[mycompetition.numfighters].name);
		fighter(tempFighters[mycompetition.numfighters].power);

		delete[] mycompetition.fighters;
		mycompetition.fighters = tempFighters;
		mycompetition.numfighters++;
	}

	void removeFighter(Competition& mycompetition, const Fighter& loserFighter)
	{
		Fighter* tempFighters = nullptr;
		tempFighters = new Fighter[mycompetition.numfighters - 1];
		int index = findFighter(mycompetition, loserFighter);

		if (tempFighters != nullptr)
		{
			if (index != -1)
			{
				for (int i = 0, j = 0; i < mycompetition.numfighters; i++, j++)
				{
					if (i != index) {
						tempFighters[j] = mycompetition.fighters[i];
					}
					else {
						tempFighters[j] = mycompetition.fighters[i + 1];
						i++;
					}
				}

				delete[] mycompetition.fighters;
				mycompetition.fighters = tempFighters;
				mycompetition.numfighters--;
			}
		}
	}

	int findFighter(const Competition& mycompetition, const Fighter& theFighter)
	{
		int index = -1;
		bool found = false;
		for (int i = 0; i < mycompetition.numfighters && found == false; i++)
		{
			if (strcmp(theFighter.name, mycompetition.fighters[i].name) == 0) {
				found = true;
				index = i;
			}
		}
		return index;
	}

	bool fight(const Fighter& f1, const Fighter& f2)
	{
		bool res;
		(f1.power > f2.power) ? res = true : res = false;
		return res;
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)
	{
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		if (fight(f1, f2) == true) {
			cout << "    The winner => Name: " << f1.name << ", Power: "<< f1.power << endl;
			removeFighter(mycompetition, f2);
		}
		else {
			cout << "    The winner => Name: " << f2.name << ", Power: " << f2.power << endl;
			removeFighter(mycompetition, f1);
		}
	}



}