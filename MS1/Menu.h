// Final Project Milestone 1 
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/7/2021             ms-1 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {

	const int MAX_MENU_ITEMS = 20;
	class Menu;

	//// MenuItem Class:
	class MenuItem {
	private:
		char* m_item{};
		
		friend class Menu;
		MenuItem(const char* item = nullptr);
		~MenuItem();
		// disable copy constructor and assignment
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;

		void setName(const char* item);
		operator bool() const;
		operator const char* () const;
		std::ostream& display(std::ostream& ostr) const;
	};

	//// Menu Class:
	class Menu {
	public:
		Menu(const char* title = nullptr);
		~Menu();
		// disable copy constructor and assignment
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;

		int run() const;
		int operator~() const;
		Menu& operator<<(const char* menuItem);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		char* operator[](int index) const;
		std::ostream& displayTitle(std::ostream& ostr) const;
		std::ostream& displayMenu(std::ostream& ostr) const;

	private:
		MenuItem m_title;
		int m_numberOfItems;
		MenuItem* m_itemList[MAX_MENU_ITEMS]{};
	};

	// helper functions:
	std::ostream& operator<<(std::ostream& ostr, const Menu& ro);

}


#endif // !SDDS_MENU_H_
