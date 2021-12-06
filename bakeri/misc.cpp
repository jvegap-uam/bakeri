#include<iostream>
#include "global.h"
#include "tasks.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

int checkLines() {
	int numLines = 0;
	ifstream fileIn("data.txt");
	string unused;
	while (std::getline(fileIn, unused)) {
		++numLines;
	}
	return numLines;
}

int randNumber() {
	std::ifstream file;
	file.open("data.txt");
	int count = (checkLines() + 1);
	int i = 0;
	while(!file.eof()) {
		file >> orden[i].id;
		i++;
	}
	const int maxNum = 900;
	const int minNum = 100;
	int ranNum = (rand() % (maxNum + 1 - minNum) + minNum);
	for (int i = 0; i < count; i++) {
		if (ranNum == orden[i].id) {
			return randNumber();
		}
		else {
			return ranNum;
		}
	}
}

int searchLine(string id) {
	string str;
	int line = 0;
	ifstream file;
	file.open("data.txt");
	while (getline(file, str, '\t')){
		if (str == id) {
			return line;
		}
		line++;
	}
}

long int getUnixTime(string date) {

	istringstream in(date); // put the date in an istringstream

	std::tm t{};
	t.tm_isdst = -1; // let std::mktime try to figure out if DST is in effect

	in >> std::get_time(&t, "%Y-%m-%d %H:%M"); // extract it into a std::tm

	std::time_t timestamp = std::mktime(&t);   // get epoch

	return timestamp;
}

int searchOrder() {
	int tempID;
	int m = checkLines();
	bool encontrado = 0;
	int pos;

	cout << "Ingrese dato que desea buscar: " << endl;
	cin >> tempID;
	for (int j = 0; j < m; j++) {
		if (temp[j].id == tempID) {
			encontrado = 1;
			pos = j;
			break;
		}
	}

	//Si no se encontró la clave despliega el mensaje de no encontrado.
	if (encontrado != 1) {
		pos = -1;
	}
	return pos;
}

void sortByName() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (sorted[j].name < sorted[min].name) {
				min = j;
			}
		}
		aux = sorted[i];
		sorted[i] = sorted[min];
		sorted[min] = aux;
	}
}

void sortByApellido() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (sorted[j].apellido < sorted[min].apellido) {
				min = j;
			}
		}
		aux = sorted[i];
		sorted[i] = sorted[min];
		sorted[min] = aux;
	}
}

void sortByOrder() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (sorted[j].orderTimestamp < sorted[min].orderTimestamp) {
				min = j;
			}
		}
		aux = sorted[i];
		sorted[i] = sorted[min];
		sorted[min] = aux;
	}
}

void sortByEntrega() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (sorted[j].endTimestamp < sorted[min].endTimestamp) {
				min = j;
			}
		}
		aux = sorted[i];
		sorted[i] = sorted[min];
		sorted[min] = aux;
	}
}

