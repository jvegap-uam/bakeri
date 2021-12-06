#include <string>

using namespace std;

struct Order {
	int id; //f
	string name; // Nombre del Cliente
	string apellido; // Apellido del Cliente
	string numTel; // Numero de Telefono del cliente
	struct {
		float peso; // Peso del pastel en libras
		string sabor; // Sabor del pastel
		string forma; // Forma de la torta
		bool relleno; // Con o sin relleno 
		string saborRelleno; // Sabor del relleno 
		bool decoracion; // Con o sin decoracion 
		string detalleDecoracion; // Detalles de la Decoracion 
	} pastel;
	string orderDate; // Fecha en la que se registra la orden
	string endDate; // Fecha de entrega de la orden.
	long int orderTimestamp; //Unix timestamp de la fecha de registro de la orden.
	long int endTimestamp; //Unix timestamp de la fecha de entrega de la orden.
	float precio; // Precio del pedido
	bool completed = false; // Indica si la orden ya fue completada.
};

extern struct Order orden[256];
extern struct Order sorted[256];
extern struct Order temp[256];

