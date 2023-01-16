#define _CRT_SECURE_NO_WARNINGS
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

void MainMenu::Run(int argc, char** argv) {
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


void MainMenu::AddEvent() {
	system("CLS");
	ofstream file("Event.txt", ios::out | ios::app); {

		string eventName;
		string name;
		cout << endl << "Enter your event name ";
		cin >> eventName;
		name = eventName;
		file << name;
		

		cout << endl << "Event date: (please enter the date following this concept: MM/DD/YYYY) ";
		string date1;
		string date;
		cin >> date1;
		date = date1;

		while (valid_date(date) == false) {
			cout << endl << "Invalid date";
			cout << endl << "Please enter the date again: ";
			cin >> date1;
			date = date1;

		}
		file << endl << date;

		cout << endl << "Event time: (please enter the time following this concept: HH:MM) ";
		string time, time1;
		cin >> time;
		time1 = time;
		while (valid_time(time) == false) {
			cout << endl << "Invalid time";
			cout << endl << "Please enter the time again: ";
			cin >> time;
			time1 = time;
		}
		file << endl << time1;


		cout << endl << "Event duration(in hours): (please enter a value bigger than 0) ";
		int duration, duration1;
		cin >> duration;
		duration1 = duration;
		while (duration <= 0) {
			cout << endl << "Invalid duration";
			cout << endl << "Please enter the duration again: ";
			cin >> duration;
			duration1 = duration;
		}
		file << endl << duration1;

		cout << endl << "Event address: ";
		char address[100], address1[100];
		cin >> address;
		strcpy(address1, address);
		while (valid_address(address) == false) {
			cout << endl << "Invalid address";
			cout << endl << "Please enter your address again: ";
			cin >> address;
			strcpy(address1, address);
		}
		file << endl << address1;
	}
	file.close();
	system("PAUSE");
	system("CLS");
}

void MainMenu::AddLocation() {
	system("CLS");
	ofstream file("Event.txt", ios::out|ios::app); {

		cout << endl << "Numer of Rows: (please enter a positive number) ";
		int noRows, noRows1;
		cin >> noRows;
		noRows1 = noRows;
		while (noRows <= 0 && noRows >= 100) {
			cout << endl << "Invalid number of rows, please try again: ";
			cin >> noRows;
			noRows1 = noRows;
		}
		file << endl << noRows1;

		cout << endl << "Number of seats per row: (between 1 and 50): ";
		int noSeatsPerRow[100], noSeatsPerRow1[100];
		for (int i = 0; i < noRows; i++) {
			cout << endl << "[" << i + 1 << "] --> ";
			cin >> noSeatsPerRow[i];
			noSeatsPerRow1[i] = noSeatsPerRow[i];
			while (noSeatsPerRow[i] < Location::MINIMUM_NO_SEATS_PER_ROW || noSeatsPerRow[i] > Location::MAXIMUM_NO_SEATS_PER_ROW) {
				cout << endl << "Invalid number of seats per row, please try again: ";
				cout << endl << "[" << i + 1 << "] --> ";
				cin >> noSeatsPerRow[i];
				noSeatsPerRow1[i] = noSeatsPerRow[i];
			}
			file << endl << noSeatsPerRow1[i];
		}


		cout << endl << "Number of Zones: ";
		int noZones, noZones1;
		cin >> noZones;
		noZones1 = noZones;
		while (noZones <= 0) {
			cout << endl << "Invalid number of zones, please try again: ";
			cin >> noZones;
			noZones1 = noZones;
		}
		file << endl << noZones1;

		cout << endl << "The seat number: ";
		int noSeat, noSeat1;
		cin >> noSeat;
		noSeat1 = noSeat;
		while (noSeat <= 0) {
			cout << endl << "Invalid seat number, please try again: ";
			cin >> noSeat;
			noSeat1 = noSeat;
		}
		file << endl << noSeat1;
	}
	file.close();
	system("PAUSE");
	system("CLS");
}

void MainMenu::AddTicket() {
	system("CLS");
	ofstream file("Ticket.txt", ios::out | ios::app | ios::binary); {
		int noTickets = 1;

		cout << endl << "Full name: (please enter your full name) ";
		string fullName, fullName1;
		cin >> fullName;
		fullName1 = fullName;
		while (validateFullName(fullName) == false) {
			cout << endl << "Invalid name, please enter your name again ";
			cin >> fullName;
			fullName1 = fullName;
		}
		file <<endl<< fullName1;

		cout << endl << "Age: (please enter positive values) ";
		int age, age1;
		cin >> age;
		age1 = age;
		while (validateAge(age) == false) {
			cout << endl << "Invalid age, please enter your age again ";
			cin >> age;
			age1 = age;
		}
		file << endl << age1;

		cout << endl << "Price: (please enter positive values) ";
		int price, price1;
		cin >> price;
		price1 = price;
		while (validatePrice(price) == false) {
			cout << endl << "Invalid price, please enter your price again ";
			cin >> price;
			price1 = price;
		}
		file << endl << price1;

		cout << endl << "Please choose the following type of ticket: VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
		string value, value1;
		cin >> value;
		transform(value.begin(), value.end(), value.begin(), ::toupper);
		value1 = value;
		while (validateType(value) == false) {
			cout << endl << "Invalid ticket type";
			cout << endl << "Please choose the following type of ticket : VIP, LAWN, TRIBUNE, BOXES, OTHER; ";
			cin >> value;
			transform(value.begin(), value.end(), value.begin(), ::toupper);
			value1 = value;
		}
		file << endl << value1;

		if (availableTicketsForSale(noTickets) == true) {

			srand(time(0));
			cout << endl << "Ticket ID: ";
			int id = rand();
			int id1;
			id1 = id;
			cout << id << endl;
			file << endl << id1;
		}
		else
			cout << endl << "No available tickets, please try again later..";
	}
	file.close();

	system("PAUSE");
	system("CLS");
}


int main(int argc, char** argv) {

	MainMenu menu(12, 100);
	menu.Run(argc, argv);

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