#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event {
private:
	const string eventName;
	char* address = nullptr;
	string time=" ";
	string date=" ";
	int duration = 0;

	static int NO_OF_EVENTS;
public:

	const static int MIN_ADDRESS_SIZE = 3;
	 
	//default ctor
	Event() : eventName("Event") {

		cout << endl << "Defaul constructor";
		Event::NO_OF_EVENTS += 1;
	}

	//ctor with parameters
	Event(string eventName, const char* eventAddress, string eventTime, string eventDate, int eventDuration) : eventName(eventName) {
		this->setEventAddress(eventAddress);
		this->setEventTime(eventTime);
		this->setEventDate(eventDate);
		this->setEventDuration(eventDuration);

		Event::NO_OF_EVENTS += 1;
	}

	//setters and getters
	void setEventAddress(const char* address) {
		if (strlen(address) < Event::MIN_ADDRESS_SIZE) {
			throw "Invalid address";
		}
		if (this->address != nullptr)
			delete this->address;
		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);
	}

	char* getEventAddress() {
		char* eventAddressCopy = new char[strlen(this->address) + 1];
		strcpy(eventAddressCopy, this->address);
		return eventAddressCopy;
	}

	void setEventTime(string time) {
		this->time = time;
	}
	
	string getEventTime() {
		return this->time;
	}

	void setEventDate(string date) {
		this->date = date;
	}

	string getEventDate() {
		return this->date;
	}

	void setEventDuration(int duration) {
		this->duration = duration;
	}

	int getEventDuration() {
		return this->duration;
	}

	//destructor
	~Event() {
		cout << endl << "Event destructor";
		this->deleteEvent();

		Event::NO_OF_EVENTS -= 1;
	}

	void deleteEvent() {
		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
	}

	//copy ctor
	Event(const Event& event) : eventName(event.eventName) {
		cout << endl << "The copy constructor";
		this->setEventAddress(event.address);
		this->setEventDate(event.date);
		this->setEventTime(event.time);
		this->setEventDuration(event.duration);
	}

	//copy assign. operator
	void operator=(const Event& event) {
		if (this == &event) {
			return;
		}
		this->date = event.date;
		this->time = event.time;
		this->duration = event.duration;

		if (this->address) {
			delete[] this->address;
			this->address = nullptr;
		}

		if (event.address != nullptr) {
			this->address = new char[strlen(event.address) + 1];
			memcpy(this->address, event.address, strlen(event.address) + 1);
		}
		else {
			this->address = nullptr;
		}
		
	}

	friend void operator<< (ostream& out, Event event);
	friend void operator>> (istream& in, Event& event);

	bool operator==(Event event) {
		if (this->eventName == event.eventName && this->date == event.date
			&& this->time == event.time && this->duration == duration) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Event event) {
		if (this->duration != event.duration) {
			return true;
		}
		else {
			return false;
		}
	}

	static int getCount() {
		return NO_OF_EVENTS;
	}

	char* upperCase(const char* text) {
		char* newText = new char[strlen(text) + 1];
		strcpy(newText, text);
		for (int i = 0; i < strlen(text); i++) {
			newText[i] = toupper(text[i]);
		}
		return newText;
	}

	char* removeSpaces(const char* text) {

		int i, nr = 0;
		for (i = 0; i < strlen(text); i++)
		{
			if (text[i] == ' ')
				nr++;
		}
		char* newtext = new char[strlen(text) - nr + 1];
		int ok = 0;
		for (i = 0; i < strlen(text); i++)
		{
			if (text[i] != ' ')
				newtext[ok++] = text[i];
		}
		newtext[strlen(text) - nr] = '\0';
		return newtext;
	}
};

int Event::NO_OF_EVENTS = 0;

void operator<<(ostream& out, Event event) {
	out << endl << "Event name: " << event.eventName;
	out << endl << "Event date: " << event.date;
	out << endl << "Event time: " << event.time;
	out << endl << "Event duration: " << event.duration;
	if (event.address != nullptr) {
		out << endl << "Event address: " << event.address;
	}
}

void operator>>(istream& in, Event& event) {
	cout << endl << "Event date: ";
	in >> event.date;
	cout << endl << "Event time: ";
	in >> event.time;
	cout << endl << "Event duration: ";
	in >> event.duration;

	cout << endl << "Event address: ";
	char buffer[100];
	in >> buffer;
	if (event.address != nullptr) {
		delete[] event.address;
		event.address = nullptr;
	}
	event.address = new char[strlen(buffer) + 1];
	strcpy(event.address, buffer);

}