#include<iostream>
#include "global.h"
#include "tasks.h"

using namespace std;
void psswd() {
	int contador;
	int contador2;
	string contrasena;
	string usuario;
	contador = 1;
	contador2 = 1;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Base de Datos de Fontana's Bakery" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;
	while (contador <= 3) {
		cout << "Usuario " << endl;
		cin >> usuario;
		if (usuario == "wal2021") {
			contador = 4;
			while (contador2 <= 3) {
				cout << "Contrasena:" << endl;
				cin >> contrasena;
				if (contrasena == "wal2022") {
					contador2 = 4;
					cout << " " << endl;
					system("cls");
					mainMenu();
				}
				else {
					if (contador2 == 3) {
						cout << "Lo siento has fallado los 3 intentos" << endl;
					}
					else {
						cout << "La contrasena es incorrecta" << endl;
					}
					contador2 = contador2 + 1;
				}
			}
		}
		else {
			if (contador == 3) {
				cout << "Lo siento has fallado los 3 intentos" << endl;
			}
			else {
				cout << "Usuario no Encontrado" << endl;
			}
			contador = contador + 1;
		}
	}
}