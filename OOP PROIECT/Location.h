#pragma once
#include <iostream>
#include <string>
using namespace std;

class Location {

private:

	int noSeat = 0;   //the seat number
	int noRows = 0;   //the number of rows
	int noZones = 0;  //the number of zones
	int* noSeatsPerRow = nullptr;   //the number of seats per row

public:

	const static int MINIMUM_NO_SEATS_PER_ROW = 1;
	const static int MAXIMUM_NO_SEATS_PER_ROW = 50;

	//setters and getters
	void setNoSeat(int noSeat) {
		/*if (noSeat <= 0) {
			throw "Invalid number of seats";
		}*/
		this->noSeat = noSeat;
	}

	int getNoSeat() {
		return this->noSeat;
	}

	void setNoRows(int noRows) {
		/*if (noRows <= 0) {
			throw "Invalid number of rows";
		}*/
		this->noRows = noRows;
	}

	int getNoRows() {
		return this->noRows;
	}

	void setNoZones(int noZones) {
		/*if (noZones <= 0) {
			throw "Invalid number of zones";
		}*/
		this->noZones = noZones;
	}

	int getNoZones() {
		return this->noZones;
	}

	void setNoSeatsPerRow(int* noNewSeatsPerRow, int noNewRows) {
		if (noNewRows <= 0) {
			throw "Number of rows is not ok";
		}
		if (noNewSeatsPerRow == nullptr) {
			throw "The SeatsPerRow pointer is not ok";
		}

		for (int i = 0; i < noRows; i++) {
			if (noNewSeatsPerRow[i] < Location::MINIMUM_NO_SEATS_PER_ROW || noNewSeatsPerRow[i]>Location::MAXIMUM_NO_SEATS_PER_ROW) {
				throw "Number of seats is not ok";
			}
		}

		if (this->noSeatsPerRow != nullptr)
			delete[] this->noSeatsPerRow;
		this->noSeatsPerRow = new int[noNewRows];
		for (int i = 0; i < noNewRows; i++) {
			this->noSeatsPerRow[i] = noNewSeatsPerRow[i];
		}
		this->noRows = noNewRows;
	}

	int* getNoSeatsPerRow() {
		int* copy = this->copyArray(this->noSeatsPerRow, this->noRows);
		return copy;
	}

	//default constructor
	Location() {
		cout << endl << "Calling Location default constructor";
	}

	//constructor with argumemts
	Location(int* noSeatsPerRow, int noRows, int noZones, int noSeat) {
		this->setNoSeatsPerRow(noSeatsPerRow, noRows);
		this->setNoZones(noZones);
		this->setNoSeat(noSeat);
	}

	//copy constructor
	Location(const Location& location) {
		cout << endl << "The copy constructor";
		this->setNoRows(location.noRows);
		this->setNoSeat(location.noSeat);
		this->setNoZones(location.noZones);
		this->setNoSeatsPerRow(location.noSeatsPerRow, location.noRows);
	}

	//class destructor
	~Location() {
		cout << endl << "Calling the Location destructor";
		if (this->noSeatsPerRow != nullptr) {
			//delete[] this->noSeatsPerRow;
		}
	}

	//generic method print
	void print() {
		cout << endl << "The number of seats per row: ";
		for (int i = 0; i < this->noRows; i++)
			cout << this->noSeatsPerRow[i] << " ";
		cout << endl << "The number of rows " << this->noRows;
		cout << endl << "The number of zones " << this->noZones;
		cout << endl << "The seat number " << this->noSeat;
	}

	void operator=(const Location& location) {
		//test for self equal
		if (this == &location) {
			return;
		}
		this->noRows = location.noRows;
		this->noSeat = location.noSeat;
		this->noZones = location.noZones;

		if (this->noSeatsPerRow) {
			delete[] this->noSeatsPerRow;
			this->noSeatsPerRow = nullptr;
		}

		if (location.noSeatsPerRow != nullptr) {
			this->noSeatsPerRow = new int[location.noRows];
			/*memcpy(this->noSeatsPerRow, location.noSeatsPerRow, location.noRows);*/
			for (int i = 0; i <location.noRows; i++) {
				this->noSeatsPerRow[i] = location.noSeatsPerRow[i];
			}
		}
		else {
			this->noSeatsPerRow = nullptr;
		}
	}

	//compute total number of seats in a zone
	int getTotalNoSeatsZone() {
		int totalNoSeats = 0;
		for (int i = 0; i < this->noRows; i++) {
			totalNoSeats = totalNoSeats + this->noSeatsPerRow[i];
		}
		return totalNoSeats;
	}

	int getTotalNumberofSeats() {
		int totalNoSeats = 0;
		for (int i = 0; i < this->noZones; i++) {
			for (int j = 0; j < this->noRows; j++)
			{
				totalNoSeats= totalNoSeats + this->noSeatsPerRow[i];
			}
		}
		return totalNoSeats;
	}

	friend void operator<<(ostream& out, Location location);
	friend void operator>>(istream& in, Location& location);

private:
	static int* copyArray(int* array, int noElements) {
		int* copy = new int[noElements];
		for (int i = 0; i < noElements; i++) {
			copy[i] = array[i];
		}
		return copy;
	}


};

bool validateNoSeatsPerRow(int* noSeatsPerRow, int noRows) {
	for (int i = 0; i < noRows; i++) {
		if (noSeatsPerRow[i] < Location::MINIMUM_NO_SEATS_PER_ROW || noSeatsPerRow[i] > Location::MAXIMUM_NO_SEATS_PER_ROW) {
			return false;
		}
	}
	return true;
}

Location operator+(Location location, int value) {
	//increasing the number of rows

	Location result = location;
	result.setNoSeat(location.getNoSeat() + value);
	return result;
}

Location operator-(Location location, int value) {

	//decreasing the number of rows
	Location result = location;
	result.setNoSeat(location.getNoSeat() - value);
	return result;
}

void operator<<(ostream& out, Location location) {
	out << endl << "Number of Rows " << location.noRows;
	out << endl << "Number of seats per row ";
	for (int i = 0; i < location.noRows; i++) {
		out << location.noSeatsPerRow[i] << " ";
	}
	out << endl << "Number of Zones " << location.noZones;
	out << endl << "Number of seat " << location.noSeat;
}

void operator>>(istream& in, Location& location) {
	cout << endl << "Numer of Rows: (please enter a positive number) ";
	in >> location.noRows;
	if (location.noRows <= 0) {
		cout << endl << "Invalid number of rows";
	}

	cout << endl << "Number of seats per row: (between 1 and 50): ";
	if (location.noSeatsPerRow != nullptr) {
		delete[] location.noSeatsPerRow;
		location.noSeatsPerRow = nullptr;
	}
	location.noSeatsPerRow = new int[location.noRows];
	for (int i = 0; i < location.noRows; i++) {
		in >> location.noSeatsPerRow[i];
		if (location.noSeatsPerRow[i] < Location::MINIMUM_NO_SEATS_PER_ROW || location.noSeatsPerRow[i] > Location::MAXIMUM_NO_SEATS_PER_ROW) {
			cout << endl << "Invalid number of seats per row";
		}
	}


	cout << endl << "Number of Zones: ";
	in >> location.noZones;
	if (location.noZones <= 0) {
		cout << endl << "Invalid number of zones";
	}

	cout << endl << "Number of seats: ";
	in >> location.noSeat;
	if (location.noSeat <= 0) {
		cout << endl << "Invalid number of seats";
	}
}
