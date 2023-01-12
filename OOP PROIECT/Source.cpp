#define _CRT_SECURE_NO_WARNINGS
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {


	/*int noSeatsPerRow[] = { 11, 23, 12 };
	Location teatru(noSeatsPerRow, 3, 2, 12);*/
	//teatru.print();

	//Location copy = teatru;
	//copy.print();
	//cout << endl << teatru.getTotalNoSeatsZone();
	//cout << teatru;
	//cin >> teatru;
	//teatru = teatru - 2;
	//cout << teatru;
	/*if (teatru == copy) {
		cout << endl << "It's the same location";
	}*/


	/*eventAds petrecere(2,"Neversea", "Constanta", "22 pm", "22 oct 2022", 3);
	petrecere.print();
	petrecere.adsPerEvent();*/

	//cout << petrecere;
	//cin >> petrecere;
	/*Event party = petrecere;
	cout << party;*/

	/*if (party == petrecere) {
		cout << endl << "The same event";
	}*/

	/*if (party != petrecere) {
		cout << endl << "Different duration";
	}
	else
		cout << endl << "The same duration";*/

	//srand(time(0));
	//Ticket bilet(rand(), "Popescu Ilie", 100, 18, VIP);
	//cout << bilet;
	//cout << endl << "-----------------------";
	//cin >> bilet;
	//cout << endl << "-----------------------";
	//bilet *= 2;
	//cout << bilet;

	//Event Party;
	//Location Club;
	//Ticket bilet;
	///*MENU
	//do {*/
	//	cout << "\n\t\t\t -------------------------------";
	//	cout << "\n\t\t\t Ticketing APP Validating System";
	//	cout << "\n\t\t\t -------------------------------";
	//	cout << "\n\t\t\t\t Welcome!";
	//	cout << "\n\n\t\t\t\t Please enter your event!";
	//	cin >> Party;
	//	cin >> Club;
	//	cin >> bilet;

	//FreeTickets ticket1(1, 1, "Stefania", 123, 20, VIP);
	//ticket1.print();
	//ticket1.paidForTickets();


	/*int noSeatsPerRow[] = { 11, 23, 12 };
	Gates teatru(4,noSeatsPerRow, 3, 2, 12);
	teatru.print();
	teatru.totalNumberOfSeats();*/

	//Event event1("evenimentul anului", "apple", "serbare","bucuresti", "17", "12/12/2022", 2);
	//event1.printInfo();

	Ticket* tickets[3];
	tickets[0] = new Ticket(1, "Stefania", 100, 20, VIP);
	tickets[1] = new Ticket(2, "Mihai", 100, 21, VIP);
	tickets[2] = new Ticket(3, "Andrei", 100, 19, VIP);

	Ticket::generateTickets(tickets, 3, "generateTickets.txt");

}