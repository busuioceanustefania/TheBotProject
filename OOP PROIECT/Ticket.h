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
	}

	//setters and getters

	void setFullName(string fullName) {
		this->fullName = fullName;
	}

	string getFullName() {
		return this->fullName;
	}

	void setPrice(int price) {
		this->price = price;
	}

	int getPrice() {
		return this->price;
	}

	void setAge(int age) {
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

void operator<<(ostream& out, Ticket ticket) {
	out << endl << "Full name: " << ticket.fullName;
	out << endl << "Age: " << ticket.age;
	out << endl << "Price: " << ticket.price;
	out << endl << "Ticket type: " << ticket.type;
}

void operator>>(istream& in, Ticket& ticket) {
	cout << endl << "Full name: ";
	in >> ticket.fullName;
	cout << endl << "Age: ";
	in >> ticket.age;
	cout << endl << "Price: ";
	in >> ticket.price;
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
					ticket.type = OTHER;
}