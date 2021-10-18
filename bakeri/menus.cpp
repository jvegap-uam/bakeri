#include <iostream>
#include "global.h"
#include "tasks.h"

void mainMenu() {
	int opt=0;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Base de Datos de Fontana's Bakery" << std::endl;
	std::cout << "	1) Visualizar Ordenes." << std::endl;
	std::cout << "	2) Agregar Ordenes." << std::endl;
	std::cout << "	3) Editar Ordenes." << std::endl;
	std::cout << "Opcion: "; std::cin >> opt;

	switch (opt) {
	case 1:
		//seeOrders();
		break;
	case 2:
		//addOrders();
		break;
	case 3:
		//editOrders();
		break;
	default:
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Ingrese un valor valido. (1-3)" << std::endl;
		system("pause");
		mainMenu();
		break;
	}
}