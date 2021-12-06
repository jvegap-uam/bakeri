#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include "global.h"
#include "tasks.h"

using namespace std;

struct Order orden[256];
struct Order temp[256];
struct Order sorted[256];

int main() {
	srand((unsigned)time(0));
	std::system("cls");
	//startScreen();

	psswd();
	return 0;
}
/*
void startScreen() {
	ifstream file;
	file.open("startScreen.txt");
	if (file.is_open()) {
		cout << file.rdbuf();
	}
	else if (file.fail()) {
		cout << "Archivo de pantalla de inicio no pudo ser abierto. Se procederá al inicio de sesion.";
	}
	std::system("pause");
	psswd();
}
*/
void psswd() {
	int max = 3;
	int x = 0;
	int line1 = 0;
	int line2 = 0;
	string password, user;
	string passwordInput, userInput;
	bool found = 0;
	ifstream f;
	f.open("signin.txt");

	while (!f.eof()) {	
		f >> user >> password;
	}

	for (int i = 0; i < max; i++) {

		cout << "Usuario: "; getline(cin, userInput);
		cout << "Contrasena: ";  getline(cin, passwordInput);

		if (user == userInput && password == passwordInput) {
			found = 1;
			break;
		}
	}

	if (found) {
		mainMenu();
	}
	else {
		cout << "Se ha alcanzado el numero maximo de ingresos erroneos, el programa se abortara." << endl;
		exit(1);
	}
}