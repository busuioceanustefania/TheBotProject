#pragma once
#include <iostream>
#include <string>
using namespace std;

enum TicketType { VIP, LAWN, TRIBUNE, BOXES, OTHER};

class Ticket {

private:
	const int ticketId;
	TicketType type = OTHER;
	double price = 0;
	string fullName = "No Name";
	int age = 0;

	static int NO_OF_TICKETS;
public:

	

	//default constructor
	Ticket() : ticketId(0), fullName("Unknown") {
		cout << endl << "Default constructor";
	}

	//constructor
	Ticket(int ID, string fullName, double price, int age, TicketType type) : ticketId(ID) {
		this->setFullName(fullName);
		this->setPrice(price);
		this->setAge(age);
		this->setType(type);

		Ticket::NO_OF_TICKETS++;
	}

	//setters and getters

	void setFullName(string fullName) {
		/*if (fullName.length() < 3) {
			throw "Please enter a valid name (at least 3 characters)";
		}*/
		this->fullName = fullName;
	}

	string getFullName() {
		return this->fullName;
	}

	void setPrice(int price) {
		/*if (price < 0) {
			throw "Invalid price";
		}*/
		this->price = price;
	}

	int getPrice() {
		return this->price;
	}

	void setAge(int age) {
		/*if (age < 0) {
			throw "Invalid age";
		}*/
		this->age = age;
	}

	int getAge() {
		return this->age;
	}

	void setType(TicketType type) {
		this->type = (TicketType)type;
	}

	TicketType getType() {
		return this->type;
	}

	//the copy constructor
	Ticket(const Ticket& ticket) :ticketId(ticket.ticketId) {
		cout << endl << "The copy constructor";
		this->setFullName(ticket.fullName);
		this->setAge(ticket.age);
		this->setPrice(ticket.price);
		this->setType(ticket.type);

		Ticket::NO_OF_TICKETS++;
	}

	//the equal operator
	void operator=(const Ticket& ticket) {
		if (this == &ticket) {
			return;
		}
		this->fullName = ticket.fullName;
		this->age = ticket.age;
		this->price = ticket.price;
		this->type = ticket.type;

		Ticket::NO_OF_TICKETS++;
	}

	static int getCount() {
		return NO_OF_TICKETS;
	}

	double getDiscount() {
		double newPrice = 0;
		newPrice =this->price-( 0.20 * this->price);
		return newPrice;
	}

	void applyDiscount(int percent)
	{
		if (percent < 1 || percent>50) {
			throw "The discount is too low or too big";
		}
		this->price = this->price - (this->price * percent / 100);

	}

	friend void operator<<(ostream& out, Ticket ticket);
	friend void operator>>(istream& in, Ticket& ticket);

	void operator*=(float value) {
		this->price *= value;
	}

	bool operator<=(float value) {
		return this->price <= value;
	}
};

int Ticket::NO_OF_TICKETS = 0;

void operator<<(ostream& out, Ticket ticket) {
	out << endl << "ID: " << ticket.ticketId;
	out << endl << "Full name: " << ticket.fullName;
	out << endl << "Age: " << ticket.age;
	out << endl << "Price: " << ticket.price;
	out << endl << "Ticket type: " << ticket.type;
}

void operator>>(istream& in, Ticket& ticket) {
	/*srand(time(0));
	cout << endl << "Ticket ID: ";
	ticket.ticketId = rand();*/

	cout << endl << "Full name: (please enter your full name)";
	in >> ticket.fullName;
	if (ticket.fullName.length() < 3) {
		cout << endl << "Please enter a valid name (at least 3 characters)";
	}

	cout << endl << "Age: (please enter positive values) ";
	in >> ticket.age;
	if (ticket.age < 0) {
		cout << endl << "Invalid age";
	}

	cout << endl << "Price: (please enter positive values) ";
	in >> ticket.price;
	if (ticket.price < 0) {
		cout << endl << "Invalid price";
	}
	cout << endl << "Please choose the following type of ticket: VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
	int value;
	in >> value;
	if (value == VIP) {
		ticket.type = VIP;
	}
	else
		if (value == LAWN) {
			ticket.type = LAWN;
		}
		else
			if (value == TRIBUNE) {
				ticket.type = TRIBUNE;
			}
			else
				if (value == BOXES) {
					ticket.type = BOXES;
				}
				else
					if (value == OTHER) {
						ticket.type = OTHER;
					}
				else
		            cout << endl << "Invalid type";

	Ticket::NO_OF_TICKETS++;
}