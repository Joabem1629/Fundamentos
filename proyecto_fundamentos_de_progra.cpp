#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

struct Vendedor {
	string 	nombre_usuario;
	string 	nombre;
	string 	apellido;
	int 	edad;
	string 	telefono = "N/A";
	string 	correo_electronico = "N/A";
	string 	contrasena;
};

vector<Vendedor> Lista_de_vendedores;

struct Producto {	
	string 	nombre_vendedor;
	string 	nombre_producto;
	float 	precio_producto;
	int 	stock_producto;
};

vector<Producto> Lista_de_productos;

struct Comprador {
	string 	nombre_usuario;
	string 	nombre;
	string 	contrasena;
};

vector<Comprador> Lista_de_compradores;

struct Venta {
	string 	nombre_producto;
	string 	nombre_comprador;
	string 	nombre_vendedor;
	float 	precio_producto;
	int 	cantidad_producto;
};

vector<Venta> Lista_de_ventas;

void agregar_datos(){
	Vendedor vendedor;
	vendedor.nombre_usuario = "Joabem";
	vendedor.nombre = "jose";
	vendedor.apellido = "benavides";
	vendedor.edad = 19;
	vendedor.telefono = "N/A";
	vendedor.correo_electronico = "N/A";
	vendedor.contrasena = "9012";
	Lista_de_vendedores.push_back(vendedor);

	Comprador comprador;
	comprador.nombre_usuario = "JP";
	comprador.nombre = "Juan";
	comprador.contrasena = "90123";
	Lista_de_compradores.push_back(comprador);

	Producto producto;
	producto.nombre_vendedor = "Joabem";
	producto.nombre_producto = "Papas";
	producto.precio_producto = 10;
	producto.stock_producto = 10;
	Lista_de_productos.push_back(producto);

	Producto producto2;
	producto2.nombre_vendedor = "Joabem";
	producto2.nombre_producto = "Manzanas";
	producto2.precio_producto = 5;
	producto2.stock_producto = 10;
	Lista_de_productos.push_back(producto2);

	Producto producto3;
	producto3.nombre_vendedor = "Joabem";
	producto3.nombre_producto = "Naranjas";
	producto3.precio_producto = 5;
	producto3.stock_producto = 10;
	Lista_de_productos.push_back(producto3);

	Producto producto4;
	producto4.nombre_vendedor = "Joabem";
	producto4.nombre_producto = "Mangos";
	producto4.precio_producto = 5;
	producto4.stock_producto = 10;
	Lista_de_productos.push_back(producto4);
	
	Venta venta1;
	venta1.nombre_producto = "Papas";
	venta1.nombre_comprador = "JP";
	venta1.nombre_vendedor = "Joabem";
	venta1.precio_producto = 10;
	venta1.cantidad_producto = 5;
	Lista_de_ventas.push_back(venta1);

	Venta venta2;
	venta2.nombre_producto = "Manzanas";
	venta2.nombre_comprador = "JP";
	venta2.nombre_vendedor = "Joabem";
	venta2.precio_producto = 5;
	venta2.cantidad_producto = 5;
	Lista_de_ventas.push_back(venta2);
}

string encriptar(string contrasena){
	string contrasena_encriptada = "";
	string alfabeto_minuscula = "abcdefghijklmnopqrstuvwxyz";
	string alfabeto_mayuscula = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numeros = "0123456789";
	string simbolos = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
	for (int i = 0; i < contrasena.size(); i++) {
		for (int j = 0; j < alfabeto_minuscula.size(); j++) {
			if (contrasena[i] == alfabeto_minuscula[j]) {
				contrasena_encriptada += alfabeto_minuscula[alfabeto_minuscula.size() - j- 4];
			}
		}
		for (int j = 0; j < alfabeto_mayuscula.size(); j++) {
			if (contrasena[i] == alfabeto_mayuscula[j]) {
				contrasena_encriptada += alfabeto_mayuscula[alfabeto_mayuscula.size() - j- 4];
			}
		}
		for (int j = 0; j < numeros.size(); j++) {
			if (contrasena[i] == numeros[j]) {
				contrasena_encriptada += numeros[numeros.size() - j - 4];
			}
		}
		for (int j = 0; j < simbolos.size(); j++) {
			if (contrasena[i] == simbolos[j]) {
				contrasena_encriptada += simbolos[simbolos.size() - j - 4];
			}
		}
	}
	return contrasena_encriptada;
}

string ingresar_contrasena() {
    string contrasena = "";
    char ch;
    cout << "Contrasena: ";
    ch = _getch();
    while (ch != 13) {
        if (ch == 8) {
            if (contrasena.size() > 0) {
                cout << "\b \b";
                contrasena.pop_back();
            }
        } else {
            contrasena += ch;
            cout << '*';
        }
        ch = _getch();
    }
    cout << endl;
    return encriptar(contrasena);
}

void agregar_productos(string name){
    Producto producto;
    cout <<"Nombre del Vendedor:" << name << endl;
    producto.nombre_vendedor = name;
    cout<<"Nombre del producto: ";
    cin.ignore();
    getline(cin, producto.nombre_producto);
    cout<<"Precio del producto: ";
    cin >>producto.precio_producto;
    cout<<"Cantidad del producto: ";
    cin >>producto.stock_producto;

    Lista_de_productos.push_back(producto);
}

void listado_de_vendedores(){
	for (int i = 0; i < Lista_de_vendedores.size(); i++) {
		cout << "Nombre de usuario: " << Lista_de_vendedores[i].nombre_usuario << endl;
		cout << "Nombre Completo: " << Lista_de_vendedores[i].nombre << " " << Lista_de_vendedores[i].apellido << endl;
		cout << "Edad: " << Lista_de_vendedores[i].edad << endl;
		cout << "Contacto:" << endl;
		cout << "Telefono: " << Lista_de_vendedores[i].telefono << endl;
		cout << "Correo electronico: " << Lista_de_vendedores[i].correo_electronico << endl;
		cout << "----------------------------------------\n";
	}
}

void listado_de_compradores(){
	for (int i = 0; i < Lista_de_compradores.size(); i++) {
		cout << "Nombre de usuario: " << Lista_de_compradores[i].nombre_usuario << endl;
		cout << "Nombre: " << Lista_de_compradores[i].nombre << endl;
		cout << "----------------------------------------\n";
	}
}

void listado_de_productos(){
	for (int i = 0; i < Lista_de_productos.size(); i++) {
		cout << "Nombre del producto: " << Lista_de_productos[i].nombre_producto << endl;
		cout << "Precio del producto: " << Lista_de_productos[i].precio_producto << endl;
		cout << "Cantidad del producto: " << Lista_de_productos[i].stock_producto << endl;
		cout << "Vendedor: " << Lista_de_productos[i].nombre_vendedor << endl;
		cout << "----------------------------------------\n";
	}
}

void lista_de_productos_por_usuario(){
	for (int i = 0; i < Lista_de_vendedores.size(); i++) {
		cout << "Nombre de usuario: " << Lista_de_vendedores[i].nombre_usuario << endl;
		for (int j = 0; j < Lista_de_productos.size(); j++) {
			if (Lista_de_vendedores[i].nombre_usuario == Lista_de_productos[j].nombre_vendedor) {
				cout << "Nombre del producto: " << Lista_de_productos[j].nombre_producto << endl;
				cout << "Precio del producto: " << Lista_de_productos[j].precio_producto << endl;
				cout << "Cantidad del producto: " << Lista_de_productos[j].stock_producto << endl;
				cout << "----------------------------------------\n";
			}
		}
	}
}

void ver_mis_ventras(string name){
	for (int i = 0; i < Lista_de_ventas.size(); i++) {
		if (name == Lista_de_ventas[i].nombre_vendedor) {
			cout << "Nombre del producto:         " << Lista_de_ventas[i].nombre_producto << endl;
			cout << "Precio del producto:         " << Lista_de_ventas[i].precio_producto << endl;
			cout << "Cantidad del producto:       " << Lista_de_ventas[i].cantidad_producto << endl;
			cout << "Comprador:                   " << Lista_de_ventas[i].nombre_comprador << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void ver_mis_compras(string name){
	for (int i = 0; i < Lista_de_ventas.size(); i++) {
		if (name == Lista_de_ventas[i].nombre_comprador) {
			cout << "Nombre del producto:        " << Lista_de_ventas[i].nombre_producto << endl;
			cout << "Precio del producto:        " << Lista_de_ventas[i].precio_producto << endl;
			cout << "Cantidad del producto:      " << Lista_de_ventas[i].cantidad_producto << endl;
			cout << "Vendedor:                   " << Lista_de_ventas[i].nombre_vendedor << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void opciones_editar_producto(string contra){
	string nombre_producto;
	string contrasena;
	string nuevo_nombre_producto;
	float nuevo_precio_producto;
	int nuevo_stock_producto;
	string nombre_producto2;
	string nombre_producto3;

	int a;
	
	while (a != 4) {
		cout << "Menu:\n";
		cout << "1. Editar nombre del producto\n";
		cout << "2. Editar precio del producto\n";
		cout << "3. Editar cantidad del producto\n";
		cout << "4. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> a;

		switch(a) {
		case 1:
			system("cls");
			listado_de_productos();
			cout << "Nombre del producto: ";
			cin >> nombre_producto;
			contrasena = ingresar_contrasena();
			for (int i = 0; i < Lista_de_productos.size(); i++) {
				if (nombre_producto == Lista_de_productos[i].nombre_producto && contrasena == contra) {
					cout << "Producto encontrado.\n";
					cout << "Nuevo nombre del producto: ";
					cin >> nuevo_nombre_producto;
					if (nuevo_nombre_producto == Lista_de_productos[i].nombre_producto) {
						cout << "Nombre de producto ya existe. Intente de nuevo.\n";
						return;
					}
					Lista_de_productos[i].nombre_producto = nuevo_nombre_producto;
					return;
				} else if (nombre_producto == Lista_de_productos[i].nombre_producto && contrasena != contra) {
					cout << "Contrasena incorrecta.\n";
				} else if (nombre_producto != Lista_de_productos[i].nombre_producto && contrasena != contra) {
					cout << "Producto no encontrado.\n";
				}
			}
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			listado_de_productos();
			cout << "Nombre del producto: ";
			cin >> nombre_producto2;
			contrasena = ingresar_contrasena();
			for (int i = 0; i < Lista_de_productos.size(); i++) {
				if (nombre_producto2 == Lista_de_productos[i].nombre_producto && contrasena == contra) {
					cout << "Producto encontrado.\n";
					cout << "Nuevo precio del producto: ";
					cin >> nuevo_precio_producto;
					Lista_de_productos[i].precio_producto = nuevo_precio_producto;
					return;
				} else if (nombre_producto2 == Lista_de_productos[i].nombre_producto && contrasena != contra) {
					cout << "Contrasena incorrecta.\n";
				} else if (nombre_producto2 != Lista_de_productos[i].nombre_producto && contrasena == contra){
					cout << "Producto no encontrado.\n";
				}
			}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			listado_de_productos();
			cout << "Nombre del producto: ";
			cin >> nombre_producto3;
			contrasena = ingresar_contrasena();
			for (int i = 0; i < Lista_de_productos.size(); i++) {
				if (nombre_producto3 == Lista_de_productos[i].nombre_producto && contrasena == contra) {
					cout << "Producto encontrado.\n";
					cout << "Nuevo stock del producto: ";
					cin >> nuevo_stock_producto;
					Lista_de_productos[i].stock_producto = nuevo_stock_producto;
					return;
				} else if (nombre_producto3 == Lista_de_productos[i].nombre_producto && contrasena != contra) {
					cout << "Contrasena incorrecta.\n";
				} else if (nombre_producto3 != Lista_de_productos[i].nombre_producto && contrasena != contra) {
					cout << "Producto no encontrado.\n";
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Regresando...\n";
			break;
		default:
			system("cls");
			cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void eliminar_producto(string contra){
	string nombre_producto;
	string contrasena;
	char opcion;
	listado_de_productos();
	
	cout << "Nombre del producto: ";
	cin >> nombre_producto;
	contrasena = ingresar_contrasena();

	for (int i = 0; i < Lista_de_productos.size(); i++) {
		if (nombre_producto == Lista_de_productos[i].nombre_producto && contrasena == contra) {
			cout << "Producto encontrado.\n";
			cout << "Eliminar producto?\n1. No\n2. Si\n";
			cin >> opcion;
			if (opcion == '2') {
				Lista_de_productos.erase(Lista_de_productos.begin() + i);
			}
			return;
		} else {
			cout << "Producto no encontrado.\n";
		}
	}
}

void iniciar_compra(string name){
	string nombre_producto;
	int cantidad_producto;
	char opcion;
	
	listado_de_productos();
	cout << "Nombre del producto: ";
	cin >> nombre_producto;
	
	for (int i = 0; i < Lista_de_productos.size(); i++) {
		if (nombre_producto == Lista_de_productos[i].nombre_producto) {
			cout << "Producto encontrado.\n";
			cout << "Cantidad del producto: ";
			cin >> cantidad_producto;

			cout << "Continuar?\n1. No\n2. Si\n";
			cin >> opcion;
			if (opcion == '2') {
				if (cantidad_producto <= Lista_de_productos[i].stock_producto) {
					Lista_de_productos[i].stock_producto -= cantidad_producto;
					cout << "Compra realizada.\n";
					for (int i = 0; i < Lista_de_productos.size(); i++) {
						if (nombre_producto == Lista_de_productos[i].nombre_producto) {
							system("cls");
							cout << "----------------------------------------\n";
							cout << "Gracias por su compra.\n";
							cout << "----------------------------------------\n";
							cout << "*Venta realizada en ventaMas*\n";
							cout << "Nombre del producto: " << Lista_de_productos[i].nombre_producto << endl;
							cout << "Precio del producto: " << Lista_de_productos[i].precio_producto << endl;
							cout << "Cantidad del producto: " << cantidad_producto << endl;
							cout << "Cantidad a pagar: " << Lista_de_productos[i].precio_producto * cantidad_producto << endl;
							cout << "Comprador: " << name << endl;
							cout << "Vendedor: " << Lista_de_productos[i].nombre_vendedor << endl;
							cout << "----------------------------------------\n";
							Venta venta;
							venta.nombre_producto = Lista_de_productos[i].nombre_producto;
							venta.precio_producto = Lista_de_productos[i].precio_producto;
							venta.cantidad_producto = cantidad_producto;
							venta.nombre_comprador = name;
							venta.nombre_vendedor = Lista_de_productos[i].nombre_vendedor;
							Lista_de_ventas.push_back(venta);
							system("pause");
							system("cls");
							cout << "Desea revisar compras anteriores?" << endl;
							cout << "1. Si\n2. No\n";
							cin >> opcion;
							if (opcion == '1') {
								system("cls");
								ver_mis_compras(name);
							}
							return;
						}
					}
				} else {
					cout << "Cantidad no disponible.\n";
				}
			} else {
				cout << "Compra cancelada.\n";
			}
		}
	}
	cout << "Producto no encontrado.\n";
}

void ingresar_vendedor(){
	string contrasena;
	Vendedor vendedor;
	cout << "Nombre de usuario: ";
	cin >> vendedor.nombre_usuario;
	if (Lista_de_vendedores.size() > 0) {
		for (int i = 0; i < Lista_de_vendedores.size(); i++) {
			if (vendedor.nombre_usuario == Lista_de_vendedores[i].nombre_usuario) {
				cout << "Nombre de usuario ya existe. Intente de nuevo.\n";
				ingresar_vendedor();
				return;
			}
		}
	}
	cout << "Nombre: ";
	cin >> vendedor.nombre;
	cout << "Apellido: ";
	cin >> vendedor.apellido;
	cout << "Edad: ";
	cin >> vendedor.edad;
	cout << "Agregar contacto?\n1. No\n2. Si\n";
	char p;
	cin >> p;
	if (p == '2') {
		cout << "Elijir contacto:\n1. Telefono\n2. Correo electronico\n3. Ambos\n4. Ninguno\n";
		cin >> p;
		switch (p) {
		case '1':
			cout << "Telefono: ";
			cin >> vendedor.telefono;
			break	;
		case '2':
			cout << "Correo electronico: ";
			cin >> vendedor.correo_electronico;
			break;
		case '3':
			cout << "Telefono: ";
			cin >> vendedor.telefono;
			cout << "Correo electronico: ";
			cin >> vendedor.correo_electronico;
			break;
		case '4':
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo.\n";
			break;
		}
	}
	string contrasena2 = ingresar_contrasena();
	vendedor.contrasena = contrasena2;
	Lista_de_vendedores.push_back(vendedor);
}

void ingresar_comprador(){
	string contrasena;
	Comprador comprador;
	cout << "Nombre de usuario: ";
	cin >> comprador.nombre_usuario;
	if (Lista_de_compradores.size() > 0) {
		for (int i = 0; i < Lista_de_compradores.size(); i++) {
			if (comprador.nombre_usuario == Lista_de_compradores[i].nombre_usuario) {
				cout << "Nombre de usuario ya existe. Intente de nuevo.\n";
				ingresar_comprador();
				return;
			}
		}
	}
	cout << "Nombre: ";
	cin >> comprador.nombre;
	string contrasena2 = ingresar_contrasena();
	comprador.contrasena = contrasena2;
	Lista_de_compradores.push_back(comprador);
}

void crear_usuario(){
	char opcion;
	
	while (opcion != '3') {
		cout << "Tipo de usuario:\n";
		cout << "1. Vendedor\n";
		cout << "2. Comprador\n";
		cout << "3. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			system("cls");
			ingresar_vendedor();
			system("cls");
			opcion = '3';
			break;
		case '2':
			system("cls");
			ingresar_comprador();
			system("cls");
			opcion = '3';
			break;
		case '3':
			system("cls");
			cout << "Regresando...";
			break;
		default:
			system("cls");
			cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void opciones_vendedor(string x, string y){
	char opcion;
	
	while (opcion != '5') {
		cout << "Menu:\n";
		cout << "1. Agregar producto\n";
		cout << "2. Editar producto\n";
		cout << "3. Eliminar producto\n";
		cout << "4. Ver mis ventas\n";
		cout << "5. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			system("cls");
			agregar_productos(x);
			system("pause");
			system("cls");
			break;
		case '2':
			system("cls");
			opciones_editar_producto(y);
			system("pause");
			system("cls");
			break;
		case '3':
			system("cls");
			eliminar_producto(y);
			system("pause");
			system("cls");
			break;
		case '4':
			system("cls");
			ver_mis_ventras(x);
			system("pause");
			system("cls");
			break;
		case '5':
			system("cls");
			cout << "Regresando...\n";
			break;
		default:
			system("cls");
			cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void opciones_comprador(string x){
	char opcion;
	
	while (opcion != '4') {
		cout << "Menu:\n";
		cout << "1. Iniciar compra\n";
		cout << "2. Ver vendedores\n";
		cout << "3. Ver mis compras anteriores\n";
		cout << "4. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			system("cls");
			iniciar_compra(x);
			system("pause");
			system("cls");
			break;
		case '2':
			system("cls");
			listado_de_vendedores();
			system("pause");
			system("cls");
			break;
		case '3':
			system("cls");
			ver_mis_compras(x);
			system("pause");
			system("cls");
			break;
		case '4':
			system("cls");
			cout << "Regresando...\n";
			break;
		default:
			system("cls");
			cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}
	}
}


void acceder_al_usuario(){
	string nombre_usuario;
	string contrasena;
	char opcione;
	while (opcione != '3'){
		cout << "Tipo de usuario:\n";
		cout << "1. Vendedor\n";
		cout << "2. Comprador\n";
		cout << "3. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> opcione;
		switch (opcione){
			case '1':
				system("cls");
				if (Lista_de_vendedores.size() == 0){
					cout << "No hay vendedores registrados.\n";
					break;
				}
				cout << "Nombre de usuario: ";
				cin >> nombre_usuario;
				contrasena = ingresar_contrasena();
				for (int i = 0; i < Lista_de_vendedores.size(); i++){
					if (nombre_usuario == Lista_de_vendedores[i].nombre_usuario && contrasena == Lista_de_vendedores[i].contrasena){
						system("cls");
						opciones_vendedor(nombre_usuario, contrasena);
						return;
					}
				}
				system("cls");
				cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo.\n";		
				system("pause");
				system("cls");
				break;
			case '2':
				system("cls");
				if (Lista_de_compradores.size() == 0){
					cout << "No hay compradores registrados.\n";
					break;
				}
				cout << "Nombre de usuario: ";
				cin >> nombre_usuario;
				contrasena = ingresar_contrasena();
				for (int i = 0; i < Lista_de_compradores.size(); i++){
					if (nombre_usuario == Lista_de_compradores[i].nombre_usuario && contrasena == Lista_de_compradores[i].contrasena){
						system("cls");
						opciones_comprador(nombre_usuario);
						return;
					}
				}
				system("cls");
				cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo.\n";		
				system("pause");
				system("cls");
				break;
			case '3':
				system("cls");
				cout << "Regresando...\n";
				break;
			case '4':
				system("cls");
				cout << "Usuario:\n";
				cin >> nombre_usuario;
				cout << "Contrasena:\n";
				cin >> contrasena;
				if (nombre_usuario == "admin" && contrasena == "admin") {
					system("cls");
					cout << "MENU DE ADMINISTRACION:\n";
					cout << "1. Ver informacion de vendedores\n";
					cout << "2. Ver informacion de compradores\n";
					cout << "3. Ver informacion de productos\n";
					cout << "4. Ver informacion de ventas\n";
					cout << "5. Ver informacion de productos por usuario\n";
					cout << "6. Regresar\n";
					cout << "Ingrese una opcion: ";
					cin >> opcione;
					switch (opcione) {
					case '1':
						system("cls");
						for (int i = 0; i < Lista_de_vendedores.size(); i++) {
							cout << "Nombre de usuario: " << Lista_de_vendedores[i].nombre_usuario << endl;
							cout << "Nombre Completo: " << Lista_de_vendedores[i].nombre << " " << Lista_de_vendedores[i].apellido << endl;
							cout << "Edad: " << Lista_de_vendedores[i].edad << endl;
							cout << "Contacto:" << endl;
							cout << "Telefono: " << Lista_de_vendedores[i].telefono << endl;
							cout << "Correo electronico: " << Lista_de_vendedores[i].correo_electronico << endl;
							cout << "contrasena: " << Lista_de_vendedores[i].contrasena << endl;
							cout << "----------------------------------------\n";
						}
						system("pause");
						system("cls");
						break;
					case '2':
						system("cls");
						for (int i = 0; i < Lista_de_compradores.size(); i++) {
							cout << "Nombre de usuario: " << Lista_de_compradores[i].nombre_usuario << endl;
							cout << "Nombre: " << Lista_de_compradores[i].nombre << endl;
							cout << "contrasena: " << Lista_de_compradores[i].contrasena << endl;
							cout << "----------------------------------------\n";
						}
						system("pause");
						system("cls");
						break;
					case '3':
						system("cls");
						for (int i = 0; i < Lista_de_productos.size(); i++) {
							cout << "Nombre del producto: " << Lista_de_productos[i].nombre_producto << endl;
							cout << "Precio del producto: " << Lista_de_productos[i].precio_producto << endl;
							cout << "Cantidad del producto: " << Lista_de_productos[i].stock_producto << endl;
							cout << "Vendedor: " << Lista_de_productos[i].nombre_vendedor << endl;
							cout << "----------------------------------------\n";
						}
						system("pause");
						system("cls");
						break;
					case '4':
						system("cls");
						for (int i = 0; i < Lista_de_ventas.size(); i++) {
							cout << "Nombre del producto:        " << Lista_de_ventas[i].nombre_producto << endl;
							cout << "Precio del producto:        " << Lista_de_ventas[i].precio_producto << endl;
							cout << "Cantidad del producto:      " << Lista_de_ventas[i].cantidad_producto << endl;
							cout << "Comprador:                  " << Lista_de_ventas[i].nombre_comprador << endl;
							cout << "Vendedor:                   " << Lista_de_ventas[i].nombre_vendedor << endl;
							cout << "---------------------------------------------\n";
						}
						system("pause");
						system("cls");
						break;
					case '5':
						system("cls");
						lista_de_productos_por_usuario();
						system("pause");
						system("cls");
						break;
					case '6':
						system("cls");
						cout << "Regresando...\n";
						break;
					}
					system("pause");
					system("cls");
				} else {
					system("cls");
					cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo.\n";		
					system("pause");
					system("cls");
				}
				break;
			default:
				system("cls");
				cout << "Opcion no valida. Intente de nuevo.\n";
				break;
		}
	}
}

void eliminar_usuario(){
	string nombre_usuario;
	string contrasena;
	char opcione;
	while (opcione != '3'){
		cout << "Tipo de usuario:\n";
		cout << "1. Vendedor\n";
		cout << "2. Comprador\n";
		cout << "3. Regresar\n";
		cout << "Ingrese una opcion: ";
		cin >> opcione;
		switch (opcione){
			case '1':
				system("cls");
				if (Lista_de_vendedores.size() == 0){
					cout << "No hay vendedores registrados.\n";
					break;
				}
				for (int i = 0, j = 0; i < Lista_de_vendedores.size(); i++, j++){
					cout << j + 1 << ". " << Lista_de_vendedores[i].nombre_usuario << endl;
				}
				cout << "Nombre de usuario: ";
				cin >> nombre_usuario;
				contrasena = ingresar_contrasena();
				for (int i = 0; i < Lista_de_vendedores.size(); i++){
					if (nombre_usuario == Lista_de_vendedores[i].nombre_usuario && contrasena == Lista_de_vendedores[i].contrasena){
						cout << "Usuario encontrado.\n";
						cout << "Eliminar usuario?\n1. No\n2. Si\n";
						cin >> opcione;
						if (opcione == '2'){
							Lista_de_vendedores.erase(Lista_de_vendedores.begin() + i);
						}
						return;
					}
				}
				cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo.\n";		
				break;
			case '2':
				system("cls");
				if (Lista_de_compradores.size() == 0){
					cout << "No hay compradores registrados.\n";
					break;
				}
				for (int i = 0, j = 0; i < Lista_de_compradores.size(); i++, j++){
					cout << j + 1 << ". " << Lista_de_compradores[i].nombre_usuario << endl;
				}
				cout << "Nombre de usuario: ";
				cin >> nombre_usuario;
				contrasena = ingresar_contrasena();
				for (int i = 0; i < Lista_de_compradores.size(); i++){
					if (nombre_usuario == Lista_de_compradores[i].nombre_usuario && contrasena == Lista_de_compradores[i].contrasena){
						cout << "Usuario encontrado.\n";
						cout << "Eliminar usuario?\n1. No\n2. Si\n";
						cin >> opcione;
						if (opcione == '2'){
							Lista_de_compradores.erase(Lista_de_compradores.begin() + i);
						}
						return;
					}
				}
				cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo.\n";		
				break;
			case '3':
				system("cls");
				cout << "Regresando...\n";
				break;
			default:
				system("cls");
				cout << "Opcion no valida. Intente de nuevo.\n";
				break;
			
		}
	}
}

void opciones(){
	char opcion;

	while (opcion != '4'){
		cout << "Menu:\n";
		cout << "1. Crear usuario\n";
		cout << "2. Acceder al usuario\n";
		cout << "3. Eliminar usuario\n";
		cout << "4. Salir\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			system("cls");
			crear_usuario();
			system("pause");
			system("cls");
			break;
		case '2':
			system("cls");
			acceder_al_usuario();
			system("pause");
			system("cls");
			break;
		case '3':
			system("cls");
			eliminar_usuario();
			system("pause");
			system("cls");
			break;
		case '4':
			system("cls");
			cout << "Saliendo...\n";
			break;
		default:
			system("cls");
			cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

int main() {
	system("color D");
	agregar_datos();
	opciones();
	return 0;
}

