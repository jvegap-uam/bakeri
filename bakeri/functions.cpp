#include <iostream>
#include "global.h"
#include "tasks.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <ios>
#include <limits>

using namespace std;

void addOrders(){
	ofstream file;
	file.open("data.txt", ios::app);

	bool guardar = 0;
	int x; //Numero de la linea a llenar
	x = checkLines() + 1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Ingrese los datos de la orden. " << endl;

	cout << "Nombre del cliente: "; getline(cin, orden[x].name);
	cout << "Apellido del cliente: "; getline(cin, orden[x].apellido);  
	cout << "Numero de telefono: "; getline(cin, orden[x].numTel);  
	cout << "Peso del pastel en libras: "; cin >> orden[x].pastel.peso;  
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Sabor del pastel: "; getline(cin, orden[x].pastel.sabor);  
	cout << "Forma del pastel: "; getline(cin,orden[x].pastel.forma);  
	cout << "El pastel tiene relleno? (0,1): "; cin >> orden[x].pastel.relleno;  
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (orden[x].pastel.relleno) {
		cout << "Sabor del relleno: "; getline(cin, orden[x].pastel.saborRelleno); 
	}
	else {
		orden[x].pastel.saborRelleno = "none";
	}
	cout << "El pastel tiene decoracion? (0,1): "; cin >> orden[x].pastel.decoracion;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (orden[x].pastel.decoracion) {
		cout << "Decoracion del pastel: "; getline(cin, orden[x].pastel.detalleDecoracion);
	}
	else {
		orden[x].pastel.detalleDecoracion = "none";
	}
	cout << "Fecha de la orden (yyyy-mm-dd): "; getline(cin, orden[x].orderDate);
	cout << "Fecha de entrega de la orden (yyyy-mm-dd): "; getline(cin, orden[x].endDate);
	cout << "Precio de la orden ($): "; cin >> orden[x].precio;
	cout << "La orden ya fue completada? (0,1): "; cin >> orden[x].completed;
	
	orden[x].orderTimestamp = getUnixTime(orden[x].orderDate);
	orden[x].endTimestamp = getUnixTime(orden[x].endDate);
	orden[x].id = randNumber();
	cout << "Desea guardar a archivo? (0,1): "; cin >> guardar;
	if (guardar) {
		file << orden[x].name << "\t";
		file << orden[x].apellido << "\t";
		file << orden[x].numTel << "\t";
		file << orden[x].pastel.peso << "\t";
		file << orden[x].pastel.sabor << "\t";
		file << orden[x].pastel.forma << "\t";
		file << orden[x].pastel.relleno << "\t";
		file << orden[x].pastel.saborRelleno << "\t";
		file << orden[x].pastel.decoracion << "\t";
		file << orden[x].pastel.detalleDecoracion << "\t";
		file << orden[x].orderDate << "\t";
		file << orden[x].endDate << "\t";
		file << orden[x].orderTimestamp << "\t";
		file << orden[x].endTimestamp << "\t";
		file << orden[x].precio << "\t";
		file << orden[x].completed << "\n";
	}

	file.close();
	mainMenu();
}

void print(int x) {
	cout << "------------------------------------------------" << endl;
	cout << "Nombre: " << orden[x].name << endl;
	cout << "Apellido: " << orden[x].apellido << endl;
	cout << "Numero de telefono: " << orden[x].numTel << endl;
	cout << "Peso del pastel: " << orden[x].pastel.peso << endl;
	cout << "Sabor del pastel: " << orden[x].pastel.sabor << endl;
	cout << "Forma del pastel: " << orden[x].pastel.forma << endl;
	if (orden[x].pastel.relleno)
	cout << "Sabor de relleno del pastel: " << orden[x].pastel.saborRelleno << endl;
	if (orden[x].pastel.decoracion)
	cout << "Decoracion del pastel: " << orden[x].pastel.detalleDecoracion << endl;
	cout << "Fecha de la orden: " << orden[x].orderDate << endl;
	cout << "Entrega de la orden: " << orden[x].endDate << endl;
	cout << "Completado: " << orden[x].completed << endl;
	cout << orden[x].endTimestamp << endl;
	cout << orden[x].orderTimestamp << endl;
}


void editarOrder() {
	string searchedValue;
	int i = 0;
	bool found = 0;
	bool confirm = 0;
	int opt = 0;

	ifstream ficheroIn;
	ficheroIn.open("data.txt", ios::in);

	ofstream ficheroOut;
	ficheroOut.open("temp.txt", ios::in);

	if (!ficheroIn) {
		cout << "Error al abrir el archivo datos.txt" << endl;
		exit(1);
	}
	cout << "Ingrese el nombre del orden a modificar: "; cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searchedValue);

	while (!ficheroIn.eof()) {
		ficheroIn >> orden[i].name;
		ficheroIn >> orden[i].apellido;
		ficheroIn >> orden[i].numTel;
		ficheroIn >> orden[i].pastel.peso;
		ficheroIn >> orden[i].pastel.sabor;
		ficheroIn >> orden[i].pastel.forma;
		ficheroIn >> orden[i].pastel.relleno;
		ficheroIn >> orden[i].pastel.saborRelleno;
		ficheroIn >> orden[i].pastel.decoracion;
		ficheroIn >> orden[i].pastel.detalleDecoracion;
		ficheroIn >> orden[i].orderDate;
		ficheroIn >> orden[i].endDate;
		ficheroIn >> orden[i].orderTimestamp;
		ficheroIn >> orden[i].endTimestamp;
		ficheroIn >> orden[i].precio;
		ficheroIn >> orden[i].completed;

		if (searchedValue == to_string(orden[i].id)) {
			cout << "Archivo encontrado: " << endl;
			cout << "Nombre: " << orden[i].name << endl;
			cout << "Apellido: " << orden[i].apellido << endl;
			cout << "Numero de telefono: " << orden[i].numTel << endl;
			cout << "Peso del pastel: " << orden[i].pastel.peso << endl;
			cout << "Sabor del pastel: " << orden[i].pastel.sabor << endl;
			cout << "Forma del pastel: " << orden[i].pastel.forma << endl;
			if (orden[i].pastel.relleno)
				cout << "Sabor de relleno del pastel: " << orden[i].pastel.saborRelleno << endl;
			if (orden[i].pastel.decoracion)
				cout << "Decoracion del pastel: " << orden[i].pastel.detalleDecoracion << endl;
			cout << "Fecha de la orden: " << orden[i].orderDate << endl;
			cout << "Entrega de la orden: " << orden[i].endDate << endl;
			cout << "Completado: " << orden[i].completed << endl;
			cout << orden[i].endTimestamp << endl;
			cout << orden[i].orderTimestamp << endl;

			cout << "Es este el archivo que desea modificar? (0,1): "; cin >> confirm;
			if (confirm) {
				cout << "Elija el elemento que va a editar: " << endl;
				cout << "	01) Nombre" << endl;
				cout << "	02) Apellido" << endl;
				cout << "	03) Numero de Telefono" << endl;
				cout << "	04) Peso del pastel" << endl;
				cout << "	05) Forma del pastel" << endl;
				cout << "	06) Sabor del pastel" << endl;
				cout << "	07) Relleno del pastel" << endl;
				cout << "	08) Decoracion del pastel" << endl;
				cout << "	09) Fecha de la orden" << endl;
				cout << "	10) Fecha de entrega de la orden" << endl;
				cout << "	11) Precio de la orden" << endl;
				cout << "	12) Estado de la orden" << endl;
				cout << "Opcion: "; cin >> opt;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Haz ingresado un valor invalido." << endl;
						std::system("pause");
						std::system("cls");
						cout << "Elija el elemento que va a editar: " << endl;
						cout << "	01) Nombre" << endl;
						cout << "	02) Apellido" << endl;
						cout << "	03) Numero de Telefono" << endl;
						cout << "	04) Peso del pastel" << endl;
						cout << "	05) Forma del pastel" << endl;
						cout << "	06) Sabor del pastel" << endl;
						cout << "	07) Relleno del pastel" << endl;
						cout << "	08) Decoracion del pastel" << endl;
						cout << "	09) Fecha de la orden" << endl;
						cout << "	10) Fecha de entrega de la orden" << endl;
						cout << "	11) Precio de la orden" << endl;
						cout << "	12) Estado de la orden" << endl;
						cout << "Opcion: "; cin >> opt;
					}
					if (!cin.fail())
						break;
				}

				switch (opt) {
				case 1:
					cout << "Ingrese nuevo nombre: "; cin.ignore(); getline(cin, temp[i].name);
					orden[i].name = temp[i].name;
					break;
				case 2:
					cout << "Ingrese nuevo apellido: "; cin.ignore(); getline(cin, temp[i].apellido);
					orden[i].apellido = temp[i].apellido;
					break;
				case 3:
					cout << "Ingrese nuevo numero telefonico: "; cin >> temp[i].numTel;
					orden[i].numTel = temp[i].numTel;
					break;
				case 4:
					cout << "Ingrese nuevo peso:"; cin.ignore(); cin >> temp[i].pastel.peso;
					orden[i].pastel.peso = temp[i].pastel.peso;
					break;
				case 5:
					cout << "Ingrese nueva forma:"; cin.ignore(); getline(cin, temp[i].pastel.forma);
					orden[i].pastel.forma = temp[i].pastel.forma;
					break;
				case 6:
					cout << "Ingrese nuevo sabor:"; cin.ignore(); cin >> temp[i].pastel.sabor;
					orden[i].pastel.sabor = temp[i].pastel.sabor;
					break;
				case 7:
					cout << "Ingrese nuevo estado de relleno (0,1):"; cin >> temp[i].pastel.relleno;
					orden[i].pastel.relleno = temp[i].pastel.relleno;
					if (temp[i].pastel.relleno) {
						cout << "Ingrese nuevo sabor del relleno: "; getline(cin, temp[i].pastel.saborRelleno);
						orden[i].pastel.saborRelleno = temp[i].pastel.saborRelleno;
					}
					else {
						orden[i].pastel.saborRelleno = "none";
					}
					break;
				case 8:
					cout << "Ingrese nuevo estado de decoracion (0,1):"; cin >> temp[i].pastel.decoracion;
					orden[i].pastel.decoracion = temp[i].pastel.decoracion;
					if (temp[i].pastel.decoracion) {
						cout << "Ingrese nuevos detalles de la decoracion: "; getline(cin, temp[i].pastel.detalleDecoracion);
						orden[i].pastel.detalleDecoracion = temp[i].pastel.detalleDecoracion;
					}
					else {
						orden[i].pastel.detalleDecoracion = "none";
					}
					break;
				case 9:
					cout << "Ingrese nueva fecha de ingreso de la orden (yyyy-mm-dd): "; getline(cin, temp[i].orderDate);
					orden[i].orderDate = temp[i].orderDate;
					orden[i].orderTimestamp = getUnixTime(orden[i].orderDate);
					break;
				case 10:
					cout << "Ingrese nueva fecha de entrega de la orden (yyyy-mm-dd): "; getline(cin, temp[i].endDate);
					orden[i].endDate = temp[i].endDate;
					orden[i].endTimestamp = getUnixTime(orden[i].endDate);
					break;
				case 11:
					cout << "Ingrese el nuevo precio de la orden ($): "; cin >> temp[i].precio;
					orden[i].precio = temp[i].precio;
					break;
				case 12:
					cout << "Ingrese el nuevo estado de la orden (0,1): "; cin >> temp[i].completed;
					orden[i].completed = temp[i].completed;
					break;
				default:
					std::cout << "---------------------------------" << std::endl;
					std::cout << "Ingrese un valor valido. (1-12)" << std::endl;
					system("pause");
					editarOrder();
					break;
				}
			}

			ficheroOut << orden[i].name << "\t";
			ficheroOut << orden[i].apellido << "\t";
			ficheroOut << orden[i].numTel << "\t";
			ficheroOut << orden[i].pastel.peso << "\t";
			ficheroOut << orden[i].pastel.sabor << "\t";
			ficheroOut << orden[i].pastel.forma << "\t";
			ficheroOut << orden[i].pastel.relleno << "\t";
			ficheroOut << orden[i].pastel.saborRelleno << "\t";
			ficheroOut << orden[i].pastel.decoracion << "\t";
			ficheroOut << orden[i].pastel.detalleDecoracion << "\t";
			ficheroOut << orden[i].orderDate << "\t";
			ficheroOut << orden[i].endDate << "\t";
			ficheroOut << orden[i].orderTimestamp << "\t";
			ficheroOut << orden[i].endTimestamp << "\t";
			ficheroOut << orden[i].precio << "\t";
			ficheroOut << orden[i].completed << "\n";

			mainMenu();
		}
		else {
			editarOrder();
		}
	
	i++;

	ficheroIn.close();
	ficheroOut.close();

	std::remove("data.txt");
	std::rename("temp.txt", "data.txt");
	mainMenu();
	}
}

void seeOrder() {
	int x = checkLines() + 1;
	ifstream file;
	file.open("data	.txt");
	system("cls");
	for (int i = 0; i < x; i++ ) {
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
		file >> orden[i].orderTimestamp;
		file >> orden[i].endTimestamp;
		file >> orden[i].precio;
		file >> orden[i].completed;
		i++;
	}

	for (int j = 0; j < x; j++) {
		sorted[j] = orden[j];
		j++;
	}

	orderSortMenu();

	printOrders();

	file.close();
	mainMenu();
}

void printOrders() {
	int n = (checkLines() + 1);
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

void searchPrintOrder() {
	int i = searchOrder();
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