
struct Order {
	char id[8]; //
	char name[51]; // Nombre del Cliente
	char apellido[51]; // Apellido del Cliente
	int numTel; // Numero de Telefono del cliente
	struct pastel {
		float peso; // Peso del pastel en libras
		std::string sabor; // Sabor del pastel
		std::string forma; // Forma de la torta
		bool relleno; // Con o sin relleno 
		std::string saborRelleno; // Sabor del relleno 
		bool decoracion; // Con o sin decoracion 
		std::string detalleDecoracion; // Detalles de la Decoracion 
	};
	char orderDate[12]; // Fecha en la que se registra la orden
	char endDate[12]; // Fecha de entrega de la orden.
	float precio; // Precio del pedido
	bool completed = false; // Indica si la orden ya fue completada.
	int state; // Estado de la orden dentro del sistema. 0 "Nada", 1 "Añadido", 2 "Editado", 3 "Borrado".
};


extern struct Order orden[];

extern int listSize;