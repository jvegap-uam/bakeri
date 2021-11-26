#include <iostream>
#include "global.h"
#include "tasks.h"
#include <string>
#include <fstream>

struct Order orden[256];
struct Order temp[256];
struct Order sorted[256];

int randNumber() {
	std::ifstream file;
	file.open("data.txt");
	int count = (checkLines()+1);
	for (int i = 0; i < count; i++) {
		file >> orden[i].id;
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
	file.close();
}

void addOrder() {
	int count = (checkLines() + 1);
	bool guardar=0;
	system("cls");
	std::ofstream file;
	file.open("data.txt");
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

		std::cout << "Desea guardar a la base de datos? (1,0): "; std::cin >> guardar;
		if (guardar) {
			file << orden[count].id << "\t";
			file << orden[count].name << "\t";
			file << orden[count].apellido << "\t";
			file << orden[count].numTel << "\t";
			file << orden[count].pastel.peso << "\t";
			file << orden[count].pastel.sabor << "\t";
			file << orden[count].pastel.forma << "\t";
			file << orden[count].pastel.relleno << "\t";
			file << orden[count].pastel.saborRelleno << "\t";
			file << orden[count].pastel.decoracion << "\t";
			file << orden[count].pastel.detalleDecoracion << "\t";
			file << orden[count].orderDate << "\t";
			file << orden[count].endDate << "\t";
			file << orden[count].precio << "\t";
			file << orden[count].completed << std::endl;
		}
		file.close();
		mainMenu();
}

void seeOrder() {
	int count = (checkLines()+1);
	std::ifstream file;
	file.open("data	.txt");
	system("cls");

	for (int i = 0; i < count; i++) {
		file >> orden[i].id;
		file >> orden[i].name;
		file >> orden[i].apellido;
		file >> orden[i].numTel;
		file >> orden[i].pastel.peso;
		file >> orden[i].pastel.sabor;
		file >> orden[i].pastel.forma;
		file >> orden[i].pastel.relleno;
		file >> orden[i].pastel.saborRelleno;
		file >> orden[i].pastel.decoracion;
		file >> orden[i].pastel.detalleDecoracion;
		file >> orden[i].orderDate;
		file >> orden[i].endDate;
		file >> orden[i].precio;
		file >> orden[i].completed;
	}

	for (int i = 0; i < count; i++) {
		sorted[i].id = orden[i].id;
		strcpy(sorted[i].name, orden[i].name);
		strcpy(sorted[i].apellido, orden[i].apellido);
		sorted[i].numTel = orden[i].numTel;
		sorted[i].pastel.peso = orden[i].pastel.peso;
		strcpy(sorted[i].pastel.sabor, orden[i].pastel.sabor);
		strcpy(sorted[i].pastel.forma, orden[i].pastel.forma);
		sorted[i].pastel.relleno = orden[i].pastel.relleno;
		//sorted[i].pastel.saborRelleno = orden[i].pastel.saborRelleno;
		//sorted[i].pastel.decoracion = orden[i].pastel.decoracion;
		//sorted[i].pastel.detalleDecoracion = orden[i].pastel.detalleDecoracion;
		//sorted[i].orderDate = orden[i].orderDate;
		//sorted[i].endDate = orden[i].endDate;
		//sorted[i].precio = orden[i].precio;
		//sorted[i].completed = orden[i].completed;
	}
	file.close();
	mainMenu();
}

void editOrder() {
	system("cls");
	int n = 0;
	int tempID;
	std::cout << "Ingrese la ID de la orden a editar: ";
	std::cin >> tempID;
	n = searchOrder(tempID);
	std::cout << "Nombre: "; std::cin.ignore();
	std::cin.getline(orden[n].name, 51);
	std::cout << "Apellido: ";  std::cin.ignore();
	std::cin.getline(orden[n].apellido, 51);
	std::cout << "Telefono: ";
	std::cin >> orden[n].numTel;
	std::cout << "Pastel" << std::endl;
	std::cout << "Peso: ";  std::cin.ignore();
	std::cin >> orden[n].pastel.peso;
	std::cout << "Sabor: ";  std::cin.ignore();
	std::cin.getline(orden[n].pastel.sabor, 20);
	std::cout << "Forma: ";  std::cin.ignore();
	std::cin.getline(orden[n].pastel.forma, 20);
	std::cout << "Tiene relleno (1 o 0): ";
	std::cin >> orden[n].pastel.relleno;
	if (orden[n].pastel.relleno) {
		std::cout << "Sabor del relleno: ";  std::cin.ignore();
		std::cin.getline(orden[n].pastel.sabor, 20);
	}
	std::cout << "Tiene decoracion (1 o 0): ";
	std::cin >> orden[n].pastel.decoracion;
	if (orden[n].pastel.decoracion) {
		std::cout << "Tipo de decoracion: ";  std::cin.ignore();
		std::cin.getline(orden[n].pastel.sabor, 200);
	}
	std::cout << "Fecha de la orden (ddmmyy): ";  std::cin.ignore();
	std::cin.getline(orden[n].pastel.sabor, 12);
	std::cout << "Fecha de la entrega (ddmmyy): ";  std::cin.ignore();
	std::cin.getline(orden[n].pastel.sabor, 12);
	std::cout << "Precio: ";
	std::cin >> orden[n].precio;

}

int searchOrder(int tempID) {
	int x=0;
	int min, max;



	return x;
}