#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class DROP_TABLE {

public:
	 string tableName=" ";

	DROP_TABLE()   {
		this->setTableName("studenti");

	}

	 void setTableName(string tableName) {
		 this->tableName = tableName;
	 }

	 string getTableName() {
		 return this->tableName;
	 }

};

int main() {
	
	string a= "";
	DROP_TABLE tabel= DROP_TABLE();
	while (true) {
		cout << endl << "input: ";
		getline(cin, a);
		/*if (a != "") {

		}*/

	}

}