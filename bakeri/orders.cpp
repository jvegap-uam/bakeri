#include <iostream>
#include "global.h"
#include "tasks.h"
#include <string>

int count = 0;
struct Order orden[256];
struct Order temp[256];

int randNumber() {
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
/*
string createID() {
	char id = std::to_char(randNumber());
	for (int i = 0; i < count; i++) {
		if (strcmp(orden[i].name, "") == 0) break;
		if (strcmp(orden[i].id, id.c_str()) == 0) return createID();
	}
	return id;
}
*/
void addOrder() {
	count++;
		orden[count].id = randNumber();
		std::cout << "Nombre: "; std::cin.ignore();
		std::cin.getline(orden[count].name, 51);
		std::cout << "Apellido: ";  std::cin.ignore();
		std::cin.getline(orden[count].apellido, 51);
		std::cout << "Telefono: ";  
		std::cin >> orden[count].numTel;
	std::cout << "Pastel" << std::endl;
	std::cout << "Peso: ";  std::cin.ignore();
		std::cin >> orden[count].pastel.peso;
		std::cout << "Sabor: ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.sabor, 20);
		std::cout << "Forma: ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.forma, 20);
		std::cout << "Tiene relleno (1 o 0): ";
		std::cin >> orden[count].pastel.relleno;
	if (orden[count].pastel.relleno) {
		std::cout << "Sabor del relleno: ";  std::cin.ignore();
			std::cin.getline(orden[count].pastel.sabor, 20);
	}
	std::cout << "Tiene decoracion (1 o 0): ";
		std::cin >> orden[count].pastel.decoracion;
	if (orden[count].pastel.decoracion) {
		std::cout << "Tipo de decoracion: ";  std::cin.ignore();
			std::cin.getline(orden[count].pastel.sabor, 200);
	}
	std::cout << "Fecha de la orden (ddmmyy): ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.sabor, 12);
		std::cout << "Fecha de la entrega (ddmmyy): ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.sabor, 12);
		std::cout << "Precio: ";
		std::cin >> orden[count].precio;
}

void seeOrder() {

}

void editOrder() {

	std::cout << "Nombre: "; std::cin.ignore();
	std::cin.getline(orden[count].name, 51);
	std::cout << "Apellido: ";  std::cin.ignore();
	std::cin.getline(orden[count].apellido, 51);
	std::cout << "Telefono: ";
	std::cin >> orden[count].numTel;
	std::cout << "Pastel" << std::endl;
	std::cout << "Peso: ";  std::cin.ignore();
	std::cin >> orden[count].pastel.peso;
	std::cout << "Sabor: ";  std::cin.ignore();
	std::cin.getline(orden[count].pastel.sabor, 20);
	std::cout << "Forma: ";  std::cin.ignore();
	std::cin.getline(orden[count].pastel.forma, 20);
	std::cout << "Tiene relleno (1 o 0): ";
	std::cin >> orden[count].pastel.relleno;
	if (orden[count].pastel.relleno) {
		std::cout << "Sabor del relleno: ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.sabor, 20);
	}
	std::cout << "Tiene decoracion (1 o 0): ";
	std::cin >> orden[count].pastel.decoracion;
	if (orden[count].pastel.decoracion) {
		std::cout << "Tipo de decoracion: ";  std::cin.ignore();
		std::cin.getline(orden[count].pastel.sabor, 200);
	}
	std::cout << "Fecha de la orden (ddmmyy): ";  std::cin.ignore();
	std::cin.getline(orden[count].pastel.sabor, 12);
	std::cout << "Fecha de la entrega (ddmmyy): ";  std::cin.ignore();
	std::cin.getline(orden[count].pastel.sabor, 12);
	std::cout << "Precio: ";
	std::cin >> orden[count].precio;
}