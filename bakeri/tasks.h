#pragma once

struct Order {
	char id[8]; //
	char name[51]; // Nombre del Cliente
	char apellido[51]; // Apellido del Cliente
	char orderDate[12]; // Fecha en la que se registra la orden
	char endDate[12]; // Fecha de entrega de la orden.
	bool completed = false; // Indica si la orden ya fue completada.
	int state; // Estado de la orden dentro del sistema. 0 "Nada", 1 "Añadido", 2 "Editado", 3 "Borrado".
};


extern struct Order list[];

extern int listSize;