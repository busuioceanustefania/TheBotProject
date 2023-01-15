#pragma once
#include <iostream>
#include <string>
using namespace std;

class MainMenu {

protected:
	int availableTickets = 0;
	double ticketPrice = 0;

public:
	//defaulft constructor

	MainMenu() {

	}

	MainMenu(int availableTickets, double ticketPrice) : availableTickets(availableTickets),
		ticketPrice(ticketPrice) {

	}

	~MainMenu() {

		cout << endl << "The main menu destructor";
	}

	int getAvailableTickets() {
		return this->availableTickets;
	}

	double getTicketPrice() {
		return this->ticketPrice;
	}

	void Run();
	void DisplayMenu();
	void AddEvent();
	void AddLocation();
	void AddTicket();

	bool availableTicketsForSale(int noTickets) {
		if (noTickets > this->availableTickets) {
			return false;
		}
		else {
			this->availableTickets--;
			return true;
		}
	}
};

