#define _CRT_SECURE_NO_WARNINGS
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void MainMenu::Run() {

	int option;

	do {

		DisplayMenu();
		cout << endl << "\t\t\t\tPlease select an option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			AddEvent();
			system("PAUSE");
			system("CLS");
			break;


		case 2:
			AddLocation();
			system("PAUSE");
			system("CLS");
			break;

		case 3:
			AddTicket();
			break;

		case 4:
			break;

		default:
			cout << endl << "Please choose a valid option: ";
			cout << endl << "------------------------------";
			cin.ignore();
		}
	} while (option != 4);
}

void MainMenu::DisplayMenu() {
	cout << endl << "\t\t\t\t------------------------------";
	cout << endl << "\t\t\t\t Welcome to your TicketingApp ";
	cout << endl << "\t\t\t\t------------------------------";
	cout << endl << "\t\t\t\t\tMAIN MENU: ";
	cout << endl << "\t\t\t\t1--> Add your event";
	cout << endl << "\t\t\t\t2--> Add the location of the event";
	cout << endl << "\t\t\t\t3--> Add the tickets of the event";
	cout << endl << "\t\t\t\t4--> QUIT";
}

//bool valid_date(string date) {
//	regex pattern("^(1[0-2]|0[1-9])/(3[01]|[12][0-9]|0[1-9])/[0-9]{4}$");
//	smatch m;
//	regex_search(date, m, pattern);
//	if (m[0].matched == true)
//		return true;
//	else
//		return false;
//}
//////https://regex101.com/r/mN1iT5/16
//bool valid_time(string time) {
//	regex pattern("([01][0-9]|2[0-3]):[0-5][0-9]");
//	smatch m;
//	regex_search(time, m, pattern);
//	if (m[0].matched == true)
//		return true;
//	else
//		return false;
//}

void MainMenu::AddEvent() {
	system("CLS");
	int eventName;
	cout << endl << "Event name: ";
	cin >> eventName;

	cout << endl << "Event date: (please enter the date following this concept: MM/DD/YYYY) ";
	string date;
	cin >> date;

	while (valid_date(date) == false) {
		cout << endl << "Invalid date";
		cout << endl << "Please enter the date again: ";
		cin >> date;
		
	}

	cout << endl << "Event time: (please enter the time following this concept: HH:MM) ";
	string time;
	cin >> time;
	while (valid_time(time) == false) {
		cout << endl << "Invalid time";
		cout << endl << "Please enter the time again: ";
		cin >> time;
	}

	cout << endl << "Event duration(in hours): (please enter a value bigger than 0) ";
	int duration;
	cin >> duration;
	while (duration <= 0) {
		cout << endl << "Invalid duration";
		cout << endl << "Please enter the duration again: ";
		cin >> duration;
	}


	cout << endl << "Event address: ";
	char address[100];
	cin >> address;
	
	while (valid_address(address) == false) {
		cout << endl << "Invalid address";
		cout << endl << "Please enter your address again: ";
		cin >> address;	
	}

	system("PAUSE");
	system("CLS");
}

void MainMenu::AddLocation() {
	system("CLS");
	cout << endl << "Numer of Rows: (please enter a positive number) ";
	int noRows;
	cin >> noRows;
	while (noRows <= 0 && noRows>=100) {
		cout << endl << "Invalid number of rows, please try again: ";
		cin >> noRows;
	}

	cout << endl << "Number of seats per row: (between 1 and 50): ";
	
	int noSeatsPerRow[100];
	for (int i = 0; i < noRows; i++) {
		cout << endl << "[" << i+1 << "] --> ";
		cin >> noSeatsPerRow[i];
		while (noSeatsPerRow[i] < Location::MINIMUM_NO_SEATS_PER_ROW || noSeatsPerRow[i] > Location::MAXIMUM_NO_SEATS_PER_ROW) {
			cout << endl << "Invalid number of seats per row, please try again: ";
			cout << endl << "[" << i + 1 << "] --> ";
			cin >> noSeatsPerRow[i];
		}
	}


	cout << endl << "Number of Zones: ";
	int noZones;
	cin >> noZones;
	while (noZones <= 0) {
		cout << endl << "Invalid number of zones, please try again: ";
		cin >> noZones;
	}

	cout << endl << "The seat number: ";
	int noSeat;
	cin >> noSeat;
	while (noSeat <= 0) {
		cout << endl << "Invalid seat number, please try again: ";
		cin >> noSeat;
	}

	system("PAUSE");
	system("CLS");
}

void MainMenu::AddTicket() {
	system("CLS");
	int noTickets = 1;

	cout << endl << "Full name: (please enter your full name) ";
	string fullName;
	cin >> fullName;
	while (validateFullName(fullName) == false) {
		cout << endl << "Invalid name, please enter your name again ";
		cin >> fullName;

	}


	cout << endl << "Age: (please enter positive values) ";
	int age;
	cin >> age;
	while (validateAge(age) == false) {
		cout << endl << "Invalid age, please enter your age again ";
		cin >> age;
	}

	cout << endl << "Price: (please enter positive values) ";
	int price;
	cin >> price;
	while (validatePrice(price) == false) {
		cout << endl << "Invalid price, please enter your price again ";
		cin >> price;
	}

	cout << endl << "Please choose the following type of ticket: VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
	string value;
	cin >> value;
	transform(value.begin(), value.end(), value.begin(), ::toupper);
	while (validateType(value) == false) {
		cout << endl << "Invalid ticket type";
		cout << endl << "Please choose the following type of ticket : VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
		cin >> value;
		transform(value.begin(), value.end(), value.begin(), ::toupper);
	}
	
	if (availableTicketsForSale(noTickets) == true) {

		srand(time(0));
		cout << endl << "Ticket ID: ";
		int id = rand();
		cout << id << endl;
	}
	else
		cout << endl << "No available tickets, please try again later..";
	

	system("PAUSE");
	system("CLS");
}


int main() {

	MainMenu menu(12, 100);
	menu.Run();

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

	/*Ticket* tickets[3];
	tickets[0] = new Ticket(1, "Stefania", 100, 20, VIP);
	tickets[1] = new Ticket(2, "Mihai", 100, 21, VIP);
	tickets[2] = new Ticket(3, "Andrei", 100, 19, VIP);

	Ticket::generateTickets(tickets, 3, "generateTickets.txt");*/

}