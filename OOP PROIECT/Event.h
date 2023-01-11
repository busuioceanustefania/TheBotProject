#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Event {
private:
	string eventName="Event";
	char* address = nullptr;
	string time="12:00";
	string date="11/11/2011";
	int duration = 0;

protected:
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
		/*if (strlen(address) < Event::MIN_ADDRESS_SIZE) {
			throw "Invalid address";
		}*/
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
		/*regex pattern("([01][0-9]|2[0-3]):[0-5][0-9]");
		smatch m;
		regex_search(time, m, pattern);
		if (m[0].matched == false) {
			cout<<endl<< "Invalid time";
		}
		else*/
		this->time = time;
	}
	
	string getEventTime() {
		return this->time;
	}

	void setEventDate(string date) {
		/*regex pattern("^(1[0-2]|0[1-9])/(3[01]|[12][0-9]|0[1-9])/[0-9]{4}$");
		smatch m;
		regex_search(date, m, pattern);
		if (m[0].matched == false) {
			cout<<endl<< "Invalid date";
		}
		else*/
		this->date = date;
	}

	string getEventDate() {
		return this->date;
	}

	void setEventDuration(int duration) {
		/*if (duration <= 0) {
			cout<<endl<< "Invalid duration";
		}*/
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

	virtual void print() {
		cout << endl << "Event name: " << this->eventName;
		if (this->address != nullptr) {
			cout << endl << "Event address: " << this->address;
		}
		cout << endl << "Event time: " << this->time;
		cout << endl << "Event date: " << this->date;
		cout << endl << "Event duration: " << this->duration;
	}

	virtual void adsPerEvent() {
		cout << endl << "Expected events: " << Event::NO_OF_EVENTS;
	}
};

class eventAds : public Event {
	int noAds = 0;
public:
	eventAds(int noAds, string eventName, const char* eventAddress, string eventTime, string eventDate, int eventDuration)  
		: Event(eventName, eventAddress, eventTime, eventDate, eventDuration), noAds(noAds) {

	}

	void print() {
		this->Event::print();
		cout << endl << "Number of ads: " << this->noAds;
	}

	void adsPerEvent() {
		this->Event::adsPerEvent();
		cout << endl << "Number of total ads: " << this->noAds * Event::NO_OF_EVENTS;
	}
};
bool valid_date(string date) {
	regex pattern("^(1[0-2]|0[1-9])/(3[01]|[12][0-9]|0[1-9])/[0-9]{4}$");
	smatch m;
	regex_search(date, m, pattern);
	if (m[0].matched == true)
		return true;
	else
		return false;
}
////https://regex101.com/r/mN1iT5/16
bool valid_time(string time) {
	regex pattern("([01][0-9]|2[0-3]):[0-5][0-9]");
	smatch m;
	regex_search(time, m, pattern);
	if (m[0].matched == true)
		return true;
	else
		return false;
}

bool valid_address(const char* address ) {
	if (strlen(address) < Event::MIN_ADDRESS_SIZE) {
		return false;
	}
	else
		return true;
}

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
	cout << endl << "Event name: ";
	in >> event.eventName;

	cout << endl << "Event date: (please enter the date following this concept: MM/DD/YYYY) ";
	in >> event.date;
	while (valid_date(event.date) == false) {
		cout << endl << "Invalid date";
		cout << endl << "Please enter the date again: ";
		in >> event.date;
	}

	cout << endl << "Event time: (please enter the time following this concept: HH:MM) ";
	in >> event.time;
	while (valid_time(event.time) == false) {
		cout << endl << "Invalid time";
		cout << endl << "Please enter the time again: ";
		in >> event.time;
	}

	cout << endl << "Event duration(in hours): (please enter a value bigger than 0) ";
	in >> event.duration;
	while (event.duration <= 0) {
		cout << endl << "Invalid duration";
		cout << endl << "Please enter the duration again: ";
		in >> event.duration;
	}


	cout << endl << "Event address: ";
	char buffer[100];
	in >> buffer;
	if (event.address != nullptr) {
		delete[] event.address;
		event.address = nullptr;
	}
	event.address = new char[strlen(buffer) + 1];
	strcpy(event.address, buffer);
	while (valid_address(event.address) == false) {
		cout << endl << "Invalid address";
		cout << endl << "Please enter your address again: ";
		in >> buffer;
		if (event.address != nullptr) {
			delete[] event.address;
			event.address = nullptr;
		}
		event.address = new char[strlen(buffer) + 1];
		strcpy(event.address, buffer);
	}
	Event::NO_OF_EVENTS++;

}