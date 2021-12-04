#include <iostream>
#include "global.h"
#include "tasks.h"
#include <string>
#include <fstream>
#include <algorithm>

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
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Ingrese los valores de la orden. " << std::endl;
		orden[count].id = randNumber();
		std::cout << "Nombre: "; std::cin.ignore();
		std::cin.getline(orden[count].name, 51);
		std::cout << "Apellido: ";  std::cin.ignore();
		std::cin.getline(orden[count].apellido, 51);
		std::cout << "Telefono: ";  
		std::cin >> orden[count].numTel;
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
		std::cin.getline(orden[count].pastel.saborRelleno, 20);
		}
		
		std::cout << "Tiene decoracion (1 o 0): ";
		std::cin >> orden[count].pastel.decoracion;
		if (orden[count].pastel.decoracion) {
		std::cout << "Tipo de decoracion: ";  std::cin.ignore();
			std::cin.getline(orden[count].pastel.detalleDecoracion, 200);
		}
	
		std::cout << "Fecha de la orden (yymmdd): ";  std::cin.ignore();
		std::cin.getline(orden[count].orderDate, 12);
		std::cout << "Fecha de la entrega (yymmdd): ";  std::cin.ignore();
		std::cin.getline(orden[count].endDate, 12);
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
	int min, aux, sortOpt;
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

		sorted[i] = orden[i];

		//sorted[i].id = orden[i].id;
		//strcpy_s(sorted[i].name, orden[i].name);
		//strcpy_s(sorted[i].apellido, orden[i].apellido);
		//sorted[i].numTel = orden[i].numTel;
		//sorted[i].pastel.peso = orden[i].pastel.peso;
		//strcpy_s(sorted[i].pastel.sabor, orden[i].pastel.sabor);
		//strcpy_s(sorted[i].pastel.forma, orden[i].pastel.forma);
		//sorted[i].pastel.relleno = orden[i].pastel.relleno;
		//strcpy_s(sorted[i].pastel.saborRelleno, orden[i].pastel.saborRelleno);
		//sorted[i].pastel.decoracion = orden[i].pastel.decoracion;
		//strcpy_s(sorted[i].pastel.detalleDecoracion, orden[i].pastel.detalleDecoracion);
		//strcpy_s(sorted[i].orderDate, orden[i].orderDate);
		//strcpy_s(sorted[i].endDate, orden[i].endDate);
		//sorted[i].precio = orden[i].precio;
		//sorted[i].completed = orden[i].completed;
	}

	orderSortMenu();
	
	printOrders();

	file.close();
	mainMenu();
}

void editOrder() {
	system("cls");
	int n = 0;
	n = searchOrder();
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Ingrese los valores a modificar. " << std::endl;
	std::cout << "Nombre: "; std::cin.ignore();
	std::cin.getline(temp[n].name, 51);
	std::cout << "Apellido: ";  std::cin.ignore();
	std::cin.getline(temp[n].apellido, 51);
	std::cout << "Telefono: ";
	std::cin >> temp[n].numTel;
	std::cout << "Peso: ";  std::cin.ignore();
	std::cin >> temp[n].pastel.peso;
	std::cout << "Sabor: ";  std::cin.ignore();
	std::cin.getline(temp[n].pastel.sabor, 20);
	std::cout << "Forma: ";  std::cin.ignore();
	std::cin.getline(temp[n].pastel.forma, 20);

	std::cout << "Tiene relleno (1 o 0): ";
	std::cin >> temp[n].pastel.relleno;
	if (temp[n].pastel.relleno) {
		std::cout << "Sabor del relleno: ";  std::cin.ignore();
		std::cin.getline(temp[n].pastel.saborRelleno, 20);
	}

	std::cout << "Tiene decoracion (1 o 0): ";
	std::cin >> temp[n].pastel.decoracion;
	if (temp[n].pastel.decoracion) {
		std::cout << "Tipo de decoracion: ";  std::cin.ignore();
		std::cin.getline(temp[n].pastel.detalleDecoracion, 200);
	}

	std::cout << "Fecha de la orden (yymmdd): ";  std::cin.ignore();
	std::cin.getline(temp[n].orderDate, 12);
	std::cout << "Fecha de la entrega (yymmdd): ";  std::cin.ignore();
	std::cin.getline(temp[n].endDate, 12);
	std::cout << "Precio: ";
	std::cin >> temp[n].precio;

}

int searchOrder() {
	int tempID;
	int m = checkLines();
	bool encontrado = 0;
	int pos;

	std::cout << "Ingrese dato que desea buscar: " << std::endl;
	std::cin >> tempID;
	for (int j = 0; j < m; j++) {
		if (orden[j].id == tempID) {
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
			if (orden[j].name < orden[min].name) {
				min = j;
			}
		}
		aux = orden[i];
		orden[i] = orden[min];
		orden[min] = aux;
	}
}

void sortByApellido() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (orden[j].apellido < orden[min].apellido) {
				min = j;
			}
		}
		aux = orden[i];
		orden[i] = orden[min];
		orden[min] = aux;
	}
}

void sortByOrder() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (orden[j].orderDate < orden[min].orderDate) {
				min = j;
			}
		}
		aux = orden[i];
		orden[i] = orden[min];
		orden[min] = aux;
	}
}

void sortByEntrega() {
	int count = checkLines();
	int min;
	struct Order aux;
	for (int i = 0; i < count; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (orden[j].endDate < orden[min].endDate) {
				min = j;
			}
		}
		aux = orden[i];
		orden[i] = orden[min];
		orden[min] = aux;
	}
}

void printOrders() {
	int n = (checkLines()+1);
	system("cls");
	for (int i = 0; i < n; i++) {
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "\t" << "ID de la orden: " << sorted[i].id << std::endl;
		std::cout << "\t" << "Nombre del Cliente: " << sorted[i].name << std::endl;
		std::cout << "\t" << "Apellido del Cliente: " << sorted[i].apellido << std::endl;
		std::cout << "\t" << "Telefono del Cliente: " << sorted[i].numTel << std::endl;
		std::cout << "\t" << "Peso del Pastel: " << sorted[i].pastel.peso << std::endl;
		std::cout << "\t" << "Sabor del Pastel: " << sorted[i].pastel.sabor << std::endl;
		std::cout << "\t" << "Forma del Pastel: " << sorted[i].pastel.forma << std::endl;
		std::cout << "\t" << "Relleno del Pastel: " << sorted[i].pastel.relleno << std::endl;
		std::cout << "\t" << "Sabor de Relleno del Pastel: " << sorted[i].pastel.saborRelleno << std::endl;
		std::cout << "\t" << "Decoración del Pastel: " << sorted[i].pastel.decoracion << std::endl;
		std::cout << "\t" << " Detalle de Decoración: " << sorted[i].pastel.detalleDecoracion << std::endl;
		std::cout << "\t" << "Fecha de Orden: " << sorted[i].orderDate << std::endl;
		std::cout << "\t" << "Fecha de Entrega: " << sorted[i].endDate << std::endl;
		std::cout << "\t" << "Precio del Pastel: " << sorted[i].precio << std::endl;
	}
	system("pause");
}

/*
void editMenu() {
	int opt = 0;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Aspectos a Editar:" << std::endl;
	std::cout << "	1) Nombre del Cliente | " << std::endl;
	std::cout << "	2) Apellido del Cliente | " << std::endl;

	switch (opt) {

	}
}
*/
