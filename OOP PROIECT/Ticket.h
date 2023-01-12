#pragma once
#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

enum TicketType { VIP, LAWN, TRIBUNE, BOXES, OTHER};

class Ticket {

protected:

	Location location;
	const int ticketId;
	TicketType type = OTHER;
	double price = 0;
	string fullName = "No Name";
	int age = 0;


public:

	static int NO_OF_TICKETS;

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
		newPrice = this->price - (0.20 * this->price);
		return newPrice;
	}

	void applyDiscount(int percent)
	{
		if (percent < 1 || percent>50) {
			throw "The discount is too low or too big";
		}
		this->price = this->price - (this->price * percent / 100);

	}

	virtual void paidForTickets() {
		cout << endl << "The number of tickets is: " << Ticket::NO_OF_TICKETS;
	}

	virtual void print() {
		cout << endl << "Full name: " << this->fullName;
		cout << endl << "Age: " << this->age;
		cout << endl << "Ticket ID: " << this->ticketId;
		cout << endl << "Ticket price: " << this->price;
		cout << endl << "Type: ";
		if (this->type == 0)
			cout << "VIP";
		if (this->type == 1)
			cout << "LAWN";
		if (this->type == 2)
			cout << "TRIBUNE";
		if (this->type == 3)
			cout << "BOXES";
		if (this->type == 4)
			cout << "OTHER";
	}

	friend void operator<<(ostream& out, Ticket ticket);
	friend void operator>>(istream& in, Ticket& ticket);

	void operator*=(float value) {
		this->price *= value;
	}

	bool operator<=(float value) {
		return this->price <= value;
	}

	bool availableTickets() {
		if (Ticket::NO_OF_TICKETS >= location.getTotalNumberofSeats()) {
			return true;
		}
		else
			return false;
	}
};

class FreeTickets : public Ticket {

	int freeTickets = 10;
public:
	FreeTickets(int freeTickets, int ID, string fullName, double price, int age, TicketType type) : Ticket(ID, fullName, price, age, type), freeTickets(freeTickets) {

	}

	void print() {
		this->Ticket::print();
		if (this->freeTickets > 0) {
			cout << endl << "Free tickets remained: " << this->freeTickets;
			this->freeTickets--;
		}
		else
			cout << endl << "No more free tickets!";
	}

	void paidForTickets() {
		this->Ticket::paidForTickets();
		cout << endl << "Number of paid tickets is: " << Ticket::NO_OF_TICKETS-this->freeTickets;
	}

};

bool validateFullName(string name) {
	if (name.length() < 3)
		return false;
	else
		return true;
}

bool validateAge(int age) {
	if (age < 0) {
		return false;
	}
	else
		return true;
}

bool validatePrice(int price) {
	if (price < 0) {
		return false;
	}
	else
		return true;
}

bool validateType(string value) {
	if (value == "VIP")
		return true;
	else
		if (value == "TRIBUNE")
			return true;
		else
			if (value == "LAWN")
				return true;
			else
				if (value == "BOXES")
					return true;
				else
					if (value == "OTHER")
						return true;
					else
						return false;
}

int Ticket::NO_OF_TICKETS = 0;


void operator<<(ostream& out, Ticket ticket) {
	out << endl << "ID: " << ticket.ticketId;
	out << endl << "Full name: " << ticket.fullName;
	out << endl << "Age: " << ticket.age;
	out << endl << "Price: " << ticket.price;
	out << endl << "Ticket type: " << ticket.type;
}


void operator>>(istream& in, Ticket& ticket) {

	if (ticket.availableTickets() == true) {

		srand(time(0));
		cout << endl << "Ticket ID: ";
		int id = rand();
		cout << id;

		cout << endl << "Full name: (please enter your full name) ";
		in >> ticket.fullName;
		while (validateFullName(ticket.fullName) == false) {
			cout << endl << "Invalid name, please enter your name again ";
			in >> ticket.fullName;

		}


		cout << endl << "Age: (please enter positive values) ";
		in >> ticket.age;
		while (validateAge(ticket.age) == false) {
			cout << endl << "Invalid age, please enter your age again ";
			in >> ticket.age;
		}

		cout << endl << "Price: (please enter positive values) ";
		in >> ticket.price;
		while (validatePrice(ticket.price) == false) {
			cout << endl << "Invalid price, please enter your price again ";
			in >> ticket.price;
		}

		cout << endl << "Please choose the following type of ticket: VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
		string value;
		in >> value;
		transform(value.begin(), value.end(), value.begin(), ::toupper);
		if (value == "VIP") {
			ticket.type = TicketType::VIP;
		}
		else
			if (value == "LAWN") {
				ticket.type = TicketType::LAWN;
			}
			else
				if (value == "TRIBUNE") {
					ticket.type = TicketType::TRIBUNE;
				}
				else
					if (value == "BOXES") {
						ticket.type = TicketType::BOXES;
					}
					else
						if (value == "OTHER") {
							ticket.type = TicketType::OTHER;
						}
		while (validateType(value) == false) {
			cout << endl << "Invalid ticket type";
			cout << endl << "Please choose the following type of ticket : VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
			in >> value;
			transform(value.begin(), value.end(), value.begin(), ::toupper);
			if (value == "VIP") {
				ticket.type = TicketType::VIP;
			}
			else
				if (value == "LAWN") {
					ticket.type = TicketType::LAWN;
				}
				else
					if (value == "TRIBUNE") {
						ticket.type = TicketType::TRIBUNE;
					}
					else
						if (value == "BOXES") {
							ticket.type = TicketType::BOXES;
						}
						else
							if (value == "OTHER") {
								ticket.type = TicketType::OTHER;
							}
		}

		Ticket::NO_OF_TICKETS++;
	}
	else
		cout << endl << "There are no tickets available. Come again later!";
}