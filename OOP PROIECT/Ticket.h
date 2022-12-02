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
};