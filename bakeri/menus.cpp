#include <iostream>
#include <limits>
#include "tasks.h"
#include "global.h"

using namespace std;

void mainMenu() {
	system("cls");
	int opt = 0;
	cout << "---------------------------------" << endl;
	cout << "Base de Datos de Fontana's Bakery" << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
	cout << "	1) Visualizar Ordenes." << endl;
	cout << "	2) Agregar Ordenes." << endl;
	cout << "	3) Editar Ordenes." << endl;
	cout << "Opcion: "; cin >> opt;

	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Haz ingresado un valor invalido." << endl;
			std::system("pause");
			std::system("cls");
			cout << "---------------------------------" << endl;
			cout << "Base de Datos de Fontana's Bakery" << endl;
			cout << "---------------------------------" << endl;
			cout << endl;
			cout << "	1) Visualizar Ordenes." << endl;
			cout << "	2) Agregar Ordenes." << endl;
			cout << "	3) Editar Ordenes." << endl;
			cout << "Opcion: "; cin >> opt;
		}
		if (!cin.fail())
			break;
	}

	switch (opt) {
	case 1:
		seeOrder();
		break;
	case 2:
		addOrders();
		break;
	case 3:
		editarOrder();
		break;
	default:
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Ingrese un valor valido. (1-3)" << std::endl;
		system("pause");
		mainMenu();
		break;
	}
}

void orderSortMenu() {
	int opt;
	cout << "Como desea ordenar las ordenes? " << endl;
	cout << "1) Por Nombre del Cliente" << endl;
	cout << "2) Por Apellido del Cliente" << endl;
	cout << "3) Por Fecha de Orden "<< endl;
	cout <<	"4) Por Fecha de Entrega" << endl;
	cin >> opt;

	switch (opt) {
	case 1:
		sortByName();
		break;
	case 2:
		sortByApellido();
		break;
	case 3:
		sortByOrder();
		break;
	case 4:
		sortByEntrega();
		break;
	case 5:
		searchPrintOrder();
	}
}