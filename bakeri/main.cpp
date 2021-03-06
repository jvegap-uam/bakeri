// bakeri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "global.h"
#include "tasks.h"
#include <string>
#include <ctime>

int main()
{
	srand((unsigned)time(0));
	system("cls");
	psswd();
    return 0;
}

void mainMenu() {
	system("cls");
	int opt = 0;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Base de Datos de Fontana's Bakery" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "	1) Visualizar Ordenes." << std::endl;
	std::cout << "	2) Agregar Ordenes." << std::endl;
	std::cout << "	3) Editar Ordenes." << std::endl;
	std::cout << "Opcion: "; std::cin >> opt;

	switch (opt) {
	case 1:
		seeOrder();
		break;
	case 2:
		addOrder();
		break;
	case 3:
		editOrder();
		break;
	default:
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Ingrese un valor valido. (1-3)" << std::endl;
		system("pause");
		mainMenu();
		break;
	}
}