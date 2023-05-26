#include <iostream>
#include <iomanip>
using namespace std;


struct Drink {
  char name[10];
  int volume;
  double price;
  int quantity;
};

const int MAXDRINKS = 5;

Drink machine[MAXDRINKS];

void loadDrinks();
void drinkMenu();
void displayDrink(const Drink* drink);
int chooseDrink();
bool updateDrink(int sel);
void clearBuffer();
bool confirm();

int main() {
  bool done = false;
  loadDrinks();
  cout << "Welcome to the Seneca Vending Machine" << endl << endl;
  while (!done) {
    drinkMenu();
    chooseDrink();
    cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
    done = !confirm();
    cout << endl;
  }
  drinkMenu();
  cout << "\nThank you and come again" << endl;
  return 0;
}

void loadDrinks() {
  machine[0] = Drink{"Coffee", 300, 1.50, 5};
  machine[1] = Drink{"Tea", 250, 1.25, 3};
  machine[2] = Drink{"Cola", 350, 2.50, 2};
  machine[3] = Drink{"Water", 500, 3.10, 15};
  machine[4] = Drink{"Beer", 350, 5.25, 0};
}

void drinkMenu() {
  cout << "-----------Available Drinks-----------" << endl;
  cout << left << setw(10) << "Drink" <<  setw(10) << "Volume"; 
  cout << setw(10) << "Price" << setw(10) << "Quantity" << endl;
  for (int i = 0; i < MAXDRINKS; ++i) {
    cout << i + 1 << ".";
    displayDrink(&machine[i]);
  }
}

void displayDrink(const Drink* drink) {
    cout << left << setw(10) << drink->name << setw(10) << drink->volume
      << setw(10) << drink->price << setw(10) << drink->quantity << endl;
}

int chooseDrink() {
  bool done = false;
  int sel= 0;
  cout << "Select a drink from the menu (1-" << MAXDRINKS << "): ";
  do {
    cin >> sel;
    clearBuffer();
    if (sel >= 1 && sel <= MAXDRINKS) {
      if (updateDrink(sel) == true)
        done = true;
      else
        cout << "Out of stock for that drink, try again: ";
    }
    else
      cout << "Selection was was invalid try again: ";
  } while (!done);
  return sel;
}

bool updateDrink(int sel) {
  bool res = false;
  if (machine[sel - 1].quantity > 0) {
    machine[sel - 1].quantity--;
    res = true;
  }
  return res;
}

bool confirm() {
  char choice = cin.get();
  clearBuffer();
  return choice == 'Y';
}

void clearBuffer() {
  while (cin.get() != '\n');
}
