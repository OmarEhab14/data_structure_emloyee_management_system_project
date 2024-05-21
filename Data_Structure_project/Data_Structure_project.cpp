#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cstdio>
using namespace std;

class Date {
private:
	int month;
	int day;
	int year;
	int checkDay(int) const;
public:
	static const int monthsPerYear = 12;
	Date(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void print() const;
};
class Node;
class employee {
private:
	static int nextId;
	int id;
	string name;
	double salary;
	Date* dateOfJoining;
	bool is_Working = true;
public:

	employee(int, string, double, int, int, int);
	void setId(int);
	void setName(string);
	void setSalary(double);
	void setDateOfJoining(int, int, int);
	int getId();
	string getName();
	double getSalary();
	Date* getDateOfJoining();
};

class Node {
public:
	employee* employee;
	Node* next;
};

class App {
private:
	Node* Head;
	Node* unemployedHead;
public:
	App();
	void introduction();
	void Login();
	void Admin_Login();
	void User_Login();
	void Admin_Control_Panel();
	void User_Control_Panel();
	void insert_employee();
	void update_employee();
	void delete_employee();
	void search();
	void display();
	void generate_report();
};

int main()
{
	App* app = new App();
	app->introduction();

	return 0;
}



int employee::nextId = 1;
employee::employee(int id = nextId++, string name = " ", double salary = 0.0, int month = 1, int day = 1, int year = 2004)
	: id(id), name(name), salary(salary), dateOfJoining(new Date(month, day, year)) {
	//Head = NULL;
	//setDateOfJoining(month, day, year);
}
void employee::setId(int id) {
	this->id = id;
}
void employee::setName(string name) {
	this->name = name;
}
void employee::setSalary(double salary) {
	this->salary = salary;
}
void employee::setDateOfJoining(int month, int day, int year) {
	this->dateOfJoining = new Date(month, day, year);
}
int employee::getId() {
	return id;
}
string employee::getName() {
	return name;
}
double employee::getSalary() {
	return salary;
}
Date* employee::getDateOfJoining() {
	return dateOfJoining;
}


Date::Date(int mn = 1, int dy = 1, int yr = 2004) {
	try {
		setMonth(mn);
		setDay(dy);
		setYear(yr);
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
		setMonth(1);
		setDay(1);
		setYear(2004);
	}
}
int Date::checkDay(int dy) const {
	static const int daysPerMonth[monthsPerYear + 1] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	try {
		if (dy > 0 && dy <= daysPerMonth[month])
			return dy;
		//check for leap year
		if (month == 2 && dy == 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return dy;
		throw invalid_argument("Invalid day for current month and year");
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Date::setMonth(int mn) {
	try {
		if (mn > 0 && mn <= monthsPerYear)
			month = mn;
		else
			throw invalid_argument("month must be 1-12");
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Date::setDay(int dy) {
	day = checkDay(dy);
}
void Date::setYear(int yr) {
	try {
		if (yr > 0)
			year = yr;
		else
			throw invalid_argument("Year must be positive number");
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}
int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
int Date::getYear() const {
	return year;
}
void Date::print() const {
	cout << month << "/" << day << "/" << year << endl;
}

App::App() {
	Head = NULL;
	unemployedHead = NULL;
}
void App::introduction() {
	system("cls");
	cout << "Welcome to our app" << endl;
	_getch();
	Login();
}
void App::Login() {
	bool p = false;
	while (!p) {
		p = true;
		system("cls");
		int option;
		cout << "Who are you?" << endl;
		cout << "1.Admin.\t\t\t2.User.\t\t\t3.Back." << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			Admin_Login();
			break;
		case 2:
			User_Login();
			break;
		case 3:
			introduction();
			break;
		default:
			cout << "INVALID CHOICE...PLEASE TRY AGAIN." << endl;
			p = false;
			_getch();
			break;
		}
	}
}
void App::Admin_Login() {
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		for (int i = 0; i < 5; i++) {
			password += _getch();
			cout << "*";
		}
		if (username == "admin" && password == "admin") {
			cout << "\nCongratulations!...LOGIN SUCCESS!" << endl;
			tryAgain = false;
			cout << "\nLOADING";
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				cout << ".";
			}
			Admin_Control_Panel();
		}
		else {
			cout << "\nWRONG USERNAME OR PASSWORD...PLEASE TRY AGAIN." << endl;
			int option;
			cout << "1.Try again.\t\t\t2.Back." << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				tryAgain = true;
				break;
			case 2:
				Login();
				break;
			default:
				cout << "Invalid option";
				break;
			}
		}
	}
}
void App::User_Login() {
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		for (int i = 0; i < 5; i++) {
			password += _getch();
			cout << "*";
		}
		if (username == "admin" && password == "admin") {
			cout << "\nCongratulations!...LOGIN SUCCESS!" << endl;
			tryAgain = false;
			cout << "\nLOADING";
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				cout << ".";
			}
			Admin_Control_Panel();
		}
		else {
			cout << "\nWRONG USERNAME OR PASSWORD...PLEASE TRY AGAIN." << endl;
			int option;
			cout << "1.Try again.\t\t\t2.Back." << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				tryAgain = true;
				break;
			case 2:
				Login();
				break;
			default:
				cout << "Invalid option";
				break;
			}
		}
	}
}
void App::Admin_Control_Panel() {
	bool p = true;
	while (p) {
		p = false;
		system("cls");
		int option;
		cout << "1.Add new employee.\n2.Update an employee details.\n3.Delete an employee.\n4.Search\n5.Display all employees.\n6.Back." << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			insert_employee();
			break;
		case 2:
			update_employee();
			break;
		case 3:
			delete_employee();
			break;
		case 4:
			search();
			break;
		case 5:
			display();
			break;
		case 6:
			Login();
			break;
		default:
			cout << "Invalid option...please try again." << endl;
			Sleep(500);
			p = true;
			break;
		}
	}
}
void App::User_Control_Panel() {
	bool p = true;
	while (p) {
		p = false;
		system("cls");
		int option;
		cout << "1.Search.\n2.Generate a report.\n3.Back." << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			search();
			break;
		case 2:
			generate_report();
			break;
		case 3:
			User_Login();
			break;
		default:
			cout << "Invalid option...please try again." << endl;

			p = true;
			break;
		}
	}
}
void App::insert_employee() {
	system("cls");
	Node* new_Node = new Node;
	int id;
	string name;
	double salary;
	int month, day, year;
	cout << "Insert Record...." << endl;
	bool p = true;
	while (p) {
		p = false;
		cout << "Employee ID: ";
		cin >> id;
		Node* ptr2;
		ptr2 = Head;
		while (ptr2 != NULL) {
			if (ptr2->employee->getId() == id) {
				p = true;
				cout << "duplicate id.. please, try another id." << endl;
				break;
			}
			ptr2 = ptr2->next;
		}
	}
	cout << "Employee name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\nEmployee salary: ";
	cin >> salary;
	cout << "Date of joining..\nmonth: ";
	cin >> month;
	cout << "\nday: ";
	cin >> day;
	cout << "\nyear: ";
	cin >> year;
	new_Node->next = NULL;
	new_Node->employee = new employee(id, name, salary, month, day, year);
	if (Head == NULL) {
		Head = new_Node;
	}
	else {
		Node* ptr = Head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new_Node;
	}
	cout << "Employee inserted" << endl;
	int x;
	p = true;
	while (p) {
		cout << "1.Add another employee\t\t\t2.exit" << endl;
		cin >> x;
		p = false;
		switch (x)
		{
		case 1:
			insert_employee();
			break;
		case 2:
			Admin_Control_Panel();
			break;
		default:
			cout << "Invalid input.. try again.." << endl;
			p = true;
			break;
		}
	}
}
void App::update_employee() {
	system("cls");
	if (Head == NULL) {
		cout << "No employees to update" << endl;
		cout << "Press any key to exit.";
		_getch();
		Admin_Control_Panel();
	}
	else {
		cout << "Enter employee id to update: ";
		int id;
		cin >> id;
		Node* ptr;
		ptr = Head;
		bool found = false;
		while (ptr != NULL) {
			if (ptr->employee->getId() == id) {
				found = true;
				int id;
				string name;
				double salary;
				int month, day, year;
				bool p = true;
				while (p) {
					p = false;
					cout << "updated id: ";
					cin >> id;
					Node* ptr2;
					ptr2 = Head;
					while (ptr2 != NULL) {
						if (ptr2->employee->getId() == id && ptr2 != ptr) {
							p = true;
							cout << "duplicate id.. please, try another id." << endl;
							break;
						}
						ptr2 = ptr2->next;
					}
				}
				ptr->employee->setId(id);
				cout << "Employee name: ";
				cin.ignore();
				getline(cin, name);
				ptr->employee->setName(name);
				cout << "\nEmployee salary: ";
				cin >> salary;
				ptr->employee->setSalary(salary);
				cout << "Date of joining..\nmonth: ";
				cin >> month;
				cout << "\nday: ";
				cin >> day;
				cout << "\nyear: ";
				cin >> year;
				ptr->employee->setDateOfJoining(month, day, year);
				cout << "\n\t\t Employee Updated!!";
				_getch();
				break;
			}
			ptr = ptr->next;
		}
		if (!found)
			cout << "Employee not found!" << endl;


		bool p = true;
		int option;
		while (p) {
			cout << "\n1.Update another employee?\t\t\t2.exit." << endl;
			cin >> option;
			p = false;
			switch (option) {
			case 1:
				update_employee();
				break;
			case 2:
				Admin_Control_Panel();
				break;
			default:
				cout << "Invalid input.. try again.." << endl;
				p = true;
				break;
			}

		}
	}
}
void App::delete_employee() {
	system("cls");
	if (Head == NULL) {
		cout << "No employees to delete" << endl;
		cout << "Press any key to exit.";
		_getch();
		Admin_Control_Panel();
	}
	else {
		cout << "Enter employee id you want to delete: ";
		int id;
		cin >> id;
		Node* prev;
		Node* curr;
		curr = Head;
		prev = Head;
		bool found = false;
		//in case if it was the first employee in the linked list
		if (curr->employee->getId() == id) {
			found = true;
			cout << "=========================\n";
			cout << "ID: " << curr->employee->getId() << endl;
			cout << "Name: " << curr->employee->getName() << endl;
			cout << "Salary: " << curr->employee->getSalary() << endl;
			cout << "Date of joining: ";
			curr->employee->getDateOfJoining()->print();
			cout << endl;
			cout << "=========================\n";
			cout << "Are you sure you want to delete this employee?" << endl;
			cout << "1.Yes\t\t\t2.No" << endl;
			int option;
			cin >> option;
			switch (option) {
			case 1:
				Head = Head->next;
				curr->next = NULL;
				if (unemployedHead == NULL) {
					unemployedHead = curr;
					cout << "Employee deleted!!" << endl;
				}
				else {
					Node* ptr = unemployedHead;
					while (ptr->next != NULL) {
						ptr = ptr->next;
					}
					ptr->next = curr;
					cout << "Employee deleted!!" << endl;
					bool p = true;
					while (p) {
						p = false;
						int o;
						cout << "1.delete another employee.\t\t\t2.exit" << endl;
						cin >> o;
						switch (o) {
						case 1:
							delete_employee();
							break;
						case 2:
							Admin_Control_Panel();
							break;
						default:
							cout << "Invalid input... please, try again.." << endl;
							p = true;
							break;
						}
					}

				}
				break;
			case 2:
				bool p = true;
				while (p) {
					p = false;
					int o;
					cout << "1.delete another employee.\t\t\t2.exit" << endl;
					cin >> o;
					switch (o) {
					case 1:
						delete_employee();
						break;
					case 2:
						Admin_Control_Panel();
						break;
					default:
						cout << "Invalid input... please, try again.." << endl;
						p = true;
						break;
					}
				}
			}
		}
		if (!found) {
			//if it isn't the first in the linked list
			while (curr != NULL) {
				if (curr->employee->getId() == id) {
					found = true;
					cout << "=========================\n";
					cout << "ID: " << curr->employee->getId() << endl;
					cout << "Name: " << curr->employee->getName() << endl;
					cout << "Salary: " << curr->employee->getSalary() << endl;
					cout << "Date of joining: ";
					curr->employee->getDateOfJoining()->print();
					cout << endl;
					cout << "=========================\n";
					cout << "Are you sure you want to delete this employee?" << endl;
					bool try_again = true;
					bool p = true;
					while (try_again) {
						try_again = false;
						cout << "1.Yes\t\t\t2.No" << endl;
						int option;
						cin >> option;
						switch (option) {
						case 1:
							prev->next = curr->next;
							curr->next = NULL;
							if (unemployedHead == NULL) {
								unemployedHead = curr;
							}
							else {
								Node* ptr = unemployedHead;
								while (ptr->next != NULL) {
									ptr = ptr->next;
								}
								ptr->next = curr;
								cout << "Employee deleted!!" << endl;
								p = true;
								while (p) {
									p = false;
									int o;
									cout << "1.delete another employee.\t\t\t2.exit" << endl;
									cin >> o;
									switch (o) {
									case 1:
										delete_employee();
										break;
									case 2:
										Admin_Control_Panel();
										break;
									default:
										cout << "Invalid input... please, try again.." << endl;
										p = true;
										break;
									}
								}

							}
							break;
						case 2:
							p = true;
							while (p) {
								p = false;
								int o;
								cout << "1.delete another employee.\t\t\t2.exit" << endl;
								cin >> o;
								switch (o) {
								case 1:
									delete_employee();
									break;
								case 2:
									Admin_Control_Panel();
									break;
								default:
									cout << "Invalid input... please, try again.." << endl;
									p = true;
									break;
								}
							}
							break;

						default:
							cout << "Invalid input... please, try again.." << endl;
							try_again = true;
							break;
						}

						break;
					}//end of while

				}
				prev = curr;
				curr = curr->next;

			}
		}//end of if
		if (!found)
			cout << "Employee not found!" << endl;


		bool p = true;
		int option;
		while (p) {
			cout << "1.Delete another employee?\t\t\t2.exit." << endl;
			cin >> option;
			p = false;
			switch (option) {
			case 1:
				delete_employee();
				break;
			case 2:
				Admin_Control_Panel();
				break;
			default:
				cout << "Invalid input.. try again.." << endl;
				p = true;
				break;
			}
		}
	}
}

void App::search() {
	system("cls");
	if (Head == NULL) {
		cout << "No employees to search for" << endl;
		cout << "Press any key to exit.";
		_getch();
		Admin_Control_Panel();
	}
	else {
		cout << "Enter employee id to search for: ";
		int id;
		cin >> id;
		Node* ptr;
		ptr = Head;
		bool found = false;
		while (ptr != NULL) {
			if (ptr->employee->getId() == id) {
				found = true;
				cout << "=========================\n";
				cout << "ID: " << ptr->employee->getId() << endl;
				cout << "Name: " << ptr->employee->getName() << endl;
				cout << "Salary: " << ptr->employee->getSalary() << endl;
				cout << "Date of joining: ";
				ptr->employee->getDateOfJoining()->print();
				cout << endl;
				cout << "=========================\n";
				break;
			}
			ptr = ptr->next;
		}
		if (!found)
			cout << "Employee not found!" << endl;


		bool p = true;
		int option;
		while (p) {
			cout << "1.Search again?\t\t\t2.exit." << endl;
			cin >> option;
			p = false;
			switch (option) {
			case 1:
				search();
				break;
			case 2:
				Admin_Control_Panel();
				break;
			default:
				cout << "Invalid input.. try again.." << endl;
				p = true;
				break;
			}

		}
	}

}
void App::display() {
	system("cls");
	if (Head == NULL) {
		cout << "No employees" << endl;
	}
	else {
		Node* ptr = Head;
		while (ptr != NULL) {
			cout << "=========================\n";
			cout << "ID: " << ptr->employee->getId() << endl;
			cout << "Name: " << ptr->employee->getName() << endl;
			cout << "Salary: " << ptr->employee->getSalary() << endl;
			cout << "Date of joining: ";
			ptr->employee->getDateOfJoining()->print();
			cout << endl;
			cout << "=========================\n";
			ptr = ptr->next;
		}
	}
	cout << "press any key to exit." << endl;
	_getch();
	Admin_Control_Panel();
}
void App::generate_report() {

}