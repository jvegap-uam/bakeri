#include <string>

struct Order {
	int id; //
	char name[51]; // Nombre del Cliente
	char apellido[51]; // Apellido del Cliente
	int numTel; // Numero de Telefono del cliente
	struct {
		float peso; // Peso del pastel en libras
		char sabor[20]; // Sabor del pastel
		char forma[20]; // Forma de la torta
		bool relleno; // Con o sin relleno 
		char saborRelleno[20]; // Sabor del relleno 
		bool decoracion; // Con o sin decoracion 
		char detalleDecoracion[200]; // Detalles de la Decoracion 
	} pastel;
	char orderDate[12]; // Fecha en la que se registra la orden
	char endDate[12]; // Fecha de entrega de la orden.
	float precio; // Precio del pedido
	bool completed = false; // Indica si la orden ya fue completada.
	//int state; // Estado de la orden dentro del sistema. 0 "Nada", 1 "Añadido", 2 "Editado", 3 "Borrado".
};

extern struct Order orden[256];
extern struct Order sorted[256];

