#define _CRT_SECURE_NO_WARNINGS
#include "Location.h"
#include <iostream>
#include <string>
using namespace std;

int main() {


	int noSeatsPerRow[] = { 11, 23, 12 };
	Location teatru(noSeatsPerRow, 3, 2, 12);
	//teatru.print();

	Location copy = teatru;
	//copy.print();
	//cout << endl << teatru.getTotalNoSeatsZone();
	//cout << teatru;
	//cin >> teatru;
	//teatru = teatru - 2;
	//cout << teatru;
	/*if (teatru == copy) {
		cout << endl << "It's the same location";
	}*/
}