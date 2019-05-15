﻿#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <conio.h>

#define max_char 30
#define max_doce 12

/*Definiendo colores a usar*/

#define Color_Red 12 /*color rojo*/
#define Color_Def 15 /*color */
#define Color_Yellow 14 /*color amarillo*/
#define Color_Green 10 /*color verde*/
using namespace std;

/*------ estructura para productos por cada linea ------*/
struct nodoProducto
{
	int codProd;
	char nomProd[max_char];
	float precio;
	struct nodoProducto *izq, *der;
};

/*------ estructura para linea ------*/
struct nodoLinea
{
	int codLinea;
	char descripLinea[max_char];
	struct nodoProducto* enlace;
	struct nodoLinea *izq, *der;
};

/*------ estructura para clientes ------*/
struct nodoCliente
{
	int codCliente;
	char nomCliente[max_char];
	char apellCliente[max_char];
	int dniCliente;
	char rucCliente[max_doce];
	char telefono[max_doce];
	char direccion[max_char];
	char email[max_char];
	struct nodoCliente *izq, *der;
};

struct nodoDetalleVenta
{
	int codigo;
	int codProd;
	int cantidad;
	int codVenta;
	char marca[max_char];
	float subtotal;
	struct nodoProducto* ptrProducto;
	struct nodoDetalleVenta* sgte;
};

struct nodoVenta
{
	int codigo;
	int monto;
	char fecha[max_doce];
	int codCliente;
	struct nodoCliente* ptrCliente;
	struct nodoDetalleVenta* detalle;
	struct nodoVenta* sgte;
};

struct nodoProveedor
{
	int codProveedor;
	char razonSocial[max_char];
	char rucProveedor[max_doce];
	char telefono[max_doce];
	char direccion[max_char];
	char email[max_char];
	char web[max_char];
	struct nodoProveedor *izq, *der;
};

struct nodoDetallePedido
{
	int codigo;
	int codProd;
	int cantidad;
	int codPedido;
	char marca[max_char];
	float subtotal;
	struct nodoProducto* ptrProducto;
	struct nodoDetallePedido* sgte;
};

struct nodoPedido
{
	int codigo;
	int monto;
	char fecha[max_doce];
	int codAlmacen;
	int codProveedor;
	struct nodoProveedor* ptrProveedor;
	struct nodoDetallePedido* detalle;
	struct nodoPedido* sgte;
};

typedef struct nodoProducto* Producto;
typedef struct nodoLinea* Linea;
typedef struct nodoCliente* Cliente;
typedef struct nodoDetalleVenta* DetalleVenta;
typedef struct nodoVenta* Venta;
typedef struct nodoProveedor* Proveedor;
typedef struct nodoPedido* Pedido;
typedef struct nodoDetallePedido* DetallePedido;


/*--------------------Funcion gotoxy -------------------*/
void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

/*-------------------------------  TITULO PRINCIPAL   --------------------------*/
void titulo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);

	cout << "      _____________________________________________________________________" << endl;
	cout << "      |                                   ____________________            |" << endl;
	cout << "      |                                   | IBA\xA5" << "EZ           |___________ |" << endl;
	cout << "      |        XXXXXXXXXXXXXXXXXX         | FERNANDEZ SEGURA |   CORP    ||" << endl;
	cout << "      |        UAM BIEN BONITA            | CASTILLO ALVA    |  INDUSRY  ||" << endl;
	cout << "      |        XXXXXXXXXXXXXXXXXX         | BENITES          |  COMPANY  ||" << endl;
	cout << "      |  ______________XXX________________| LUZURRIAGA       |  BUSINESS ||" << endl;
	cout << "      |  |  _    _     +18   _    _    _  |    __  ____ _    |   ______  ||" << endl;
	cout << "      |  | | |  | |  _____  | |  | |  | | |       ______     |   |  _ |  ||" << endl;
	cout << "      |  | |_|  |_|  | | |  |_|  |_|  |_| |       |  | |     |   |  | |  ||" << endl;
	cout << "      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}


/*---------------------- MENU PRINCIPAL ----------------------*/
void menu1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow); 
	cout << "      ---------------------------------------------------------------------\n";
	cout << "              <<<<<<<<<<       SISTEMA DE ALMACENAJE        >>>>>>>>>>";
	cout << "\n    ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout << " ° 。 ° ˛˚˛ * *。*˚  •˛•˚ * 。˚ ˚      " << endl;
	cout << "	˚ ˛ •˛•˚ * 。˚ ˚  •˛•˚ * 。˚ ˚      " << endl;
	cout<<"	˚ ˛ •˛• ˚    ˚      •˛•˚ * 。˚ ˚        " << endl;
	cout << "      田1---ALMACEN                    " << endl;
	cout << "      田2---CLIENTES                   " << endl;
	cout << "      田3---VENTAS                     " << endl;
	cout << "      田4---PROVEDORES                 " << endl;
	cout << "      田5---PEDIDOS                    " << endl;
	cout << "      田6---SALIR						" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion-->  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}


/*---------------------- MENU ALMACEN ----------------------*/
void menu2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "_____________________________________________\n";
	cout << "[_]_[_]_[_]_[_]_[_]ALMACEN[_]_[_]_[_]_[_]_[_]";
	cout << "\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "       _________________________             //     //  //       // ////////// " << endl;
	cout << "      |1} [REGISTRAR LINEA]     |           //     //  ////     //     // " << endl;
	cout << "      |2} [MOSTRAR LINEA]       |          //     //  // //    //     // " << endl;
	cout << "      |3} [REGISTRAR PRODUCTO]  |         //     //  //  //   //     // " << endl;
	cout << "      |4} [MOSTRAR PRODUCTOS]   |        //     //  //    // //     // " << endl;
	cout << "      |5} [REGRESAR]            |       //     //  //      ///     // " << endl;
	cout << "      |_________________________|      /////////  //       //     // " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}


/*---------------------- MENU CLIENTES ----------------------*/
void menu3()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      ---------------------------------------------------------------------\n";
	cout << "                 <<<<<<<<<<         CLIENTES        >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "      (1)REGISTRAR CLIENTE               //     //  //       // //////////" << endl;
	cout << "                                        //     //  ////     //     //" << endl;
	cout << "      (2)ACTUALIZAR CLIENTE            //     //  // //    //     //" << endl;
	cout << "                                      //     //  //  //   //     //" << endl;
	cout << "      (3)LISTAR CLIENTES             //     //  //    // //     //" << endl;
	cout << "                                    //     //  //      ///     //" << endl;
	cout << "      (5)REGRESAR                  /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}


/*-------------------- MENU ACTUALIZAR CLIENTE ------------------*/
void menu_actualizar_cliente()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "\n\n      ---------------------------------------------------------------------\n";
	cout << "              <<<<<<<<<<  CLIENTES -> MODIFICAR DATOS   >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "                                        //     //  //       // //////////" << endl;
	cout << "      (1)MODIFICAR NOMBRE              //     //  ////     //     //" << endl;
	cout << "      (2)MODIFICAR APELLIDOS          //     //  // //    //     //" << endl;
	cout << "      (3)MODIFICAR TELEFONO          //     //  //  //   //     //" << endl;
	cout << "      (4)MODIFICAR E-MAIL           //     //  //    // //     //" << endl;
	cout << "      (5)MODIFICAR DIRECCION       //     //  //      ///     //" << endl;
	cout << "      (6)REGRESAR                 /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : "; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}


/*---------------------- MENU VENTAS ----------------------*/
void menu4()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      ---------------------------------------------------------------------\n";
	cout << "                 <<<<<<<<<<         VENTAS        >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "      (1)VENDER PRODUCTOS                //     //  //       // //////////" << endl;
	cout << "                                        //     //  ////     //     //" << endl;
	cout << "      (2)MOSTRAR VENTAS REALIZADAS     //     //  // //    //     //" << endl;
	cout << "                                      //     //  //  //   //     //" << endl;
	cout << "      (3)DETALLAR VENTA              //     //  //    // //     //" << endl;
	cout << "                                    //     //  //      ///     //" << endl;
	cout << "      (5)REGRESAR                  /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*---------------------- MENU PROVEEDORES ---------------------*/
void menu5()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      ---------------------------------------------------------------------\n";
	cout << "                 <<<<<<<<<<         PROVEEDORES        >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "      (1)REGISTRAR PROVEEDOR             //     //  //       // //////////" << endl;
	cout << "                                        //     //  ////     //     //" << endl;
	cout << "      (2)ACTUALIZAR PROVEEDOR          //     //  // //    //     //" << endl;
	cout << "                                      //     //  //  //   //     //" << endl;
	cout << "      (3)LISTAR PROVEEDORES          //     //  //    // //     //" << endl;
	cout << "                                    //     //  //      ///     //" << endl;
	cout << "      (5)REGRESAR                  /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*-------------------- MENU ACTUALIZAR PROVEEDOR ------------------*/
void menu_actualizar_proveedor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      ---------------------------------------------------------------------\n";
	cout << "            <<<<<<<<<<  PROVEEDORES -> MODIFICAR DATOS   >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "                                        //     //  //       // //////////" << endl;
	cout << "      (1)MODIFICAR RAZON SOCIAL        //     //  ////     //     //" << endl;
	cout << "      (2)MODIFICAR TELEFONO           //     //  // //    //     //" << endl;
	cout << "      (3)MODIFICAR E-MAIL            //     //  //  //   //     //" << endl;
	cout << "      (4)MODIFICAR DIRECCION        //     //  //    // //     //" << endl;
	cout << "      (5)MODIFICAR WEB             //     //  //      ///     //" << endl;
	cout << "      (6)REGRESAR                 /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*---------------------- MENU PEDIDOS ----------------------*/
void menu6()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      ---------------------------------------------------------------------\n";
	cout << "                 <<<<<<<<<<         PEDIDOS        >>>>>>>>>>";
	cout << "\n      ---------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	cout << "      (1)REALIZAR UN PEDIDO              //     //  //       // //////////" << endl;
	cout << "                                        //     //  ////     //     //" << endl;
	cout << "      (2)MOSTRAR PEDIDOS REALIZADOS    //     //  // //    //     //" << endl;
	cout << "                                      //     //  //  //   //     //" << endl;
	cout << "      (3)DETALLAR PEDIDO             //     //  //    // //     //" << endl;
	cout << "                                    //     //  //      ///     //" << endl;
	cout << "      (5)REGRESAR                  /////////  //       //     //" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
	cout << "                                  INFORMATICA - ESTRUCTURA DE DATOS" << endl; //SALIR DEL PROGRAMA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	cout << "      Ingrese Opcion : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*-------------------- FUNCION PARA INSERTAR UNA LINEA  --------------------*/
void insertar_linea(Linea& arbol, int x)
{
	if (arbol == nullptr)
	{
		arbol = new (struct nodoLinea);
		arbol->codLinea = x;
		cin.ignore();
		cout << "\n\tIngrese descripcion:";
		cin.getline(arbol->descripLinea, max_char);
		arbol->enlace = nullptr;
		arbol->izq = nullptr;
		arbol->der = nullptr;
	}
	else if (x < arbol->codLinea) insertar_linea(arbol->izq, x);
	else if (x > arbol->codLinea) insertar_linea(arbol->der, x);
}

/*------------------ FUNCION PARA MOSTRAR TODAS LAS LINEAS -----------------*/
void mostrar_linea(Linea arbol)
{
	if (arbol != nullptr)
	{
		mostrar_linea(arbol->izq);
		cout << "\n\t" << arbol->codLinea << "\t" << arbol->descripLinea << endl;
		mostrar_linea(arbol->der);
	}
}

/*------------ Funcion que inserta un nuevo producto a la linea ---------------------*/
void insertar_producto(Producto& q, int x)
{
	if (q == nullptr)
	{
		q = new(struct nodoProducto);
		q->codProd = x;
		cin.ignore();
		cout << "\n\tIngrese el nombre del producto: ";
		cin.getline(q->nomProd, max_char);
		cout << "\n\tIngrese el precio del producto: ";

		while (!(cin >> q->precio))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada invalida. Por favor digite un numero sin espacios o letras." << endl << endl;
			cout << "\n\tIngrese el precio del producto: ";
		}

		q->izq = nullptr;
		q->der = nullptr;
	}
	else if (x < q->codProd) insertar_producto(q->izq, x);
	else if (x > q->codProd) insertar_producto(q->der, x);
}

/*---Funcion que busca el codigo de linea para agregar en el, el producto ingresaro  ----*/
void registrar_producto(Linea arbol, int cod)
{
	if (arbol != nullptr)
	{
		if (arbol->codLinea == cod)
		{
			int x;
			cout << "\n\n\t\t[  REGISTRO DE PRODUCTO ]\n";
			cout << "\t\t------------------------";
			cout << "\n\tCODIGO:";
			cin >> x;
			insertar_producto(arbol->enlace, x);
		}
		else if (cod < arbol->codLinea) registrar_producto(arbol->izq, cod);
		else if (cod > arbol->codLinea) registrar_producto(arbol->der, cod);
	}
}

/*--------- Funcion que muestra todos los productos ingresados en una linea   ------*/
void listar_productos(Producto q)
{
	if (q != nullptr)
	{
		listar_productos(q->izq);
		cout << "\t" << q->codProd << "\t" << q->nomProd << "\t" << q->precio << endl;
		listar_productos(q->der);
	}
}

/*---------  Funcion que valida de que linea se mostraran los productos ---------*/
void mostrar_producto(Linea arbol, int x)
{
	if (arbol != nullptr)
	{
		if (arbol->codLinea == x)
		{
			cout << "Lista de productos con la Linea:" << arbol->codLinea << endl;
			cout << " Cod Prod ||   Nombre   ||  precio" << endl;
			listar_productos(arbol->enlace);
		}
		else if (x < arbol->codLinea) mostrar_producto(arbol->izq, x);
		else if (x > arbol->codLinea) mostrar_producto(arbol->der, x);
	}
}

/*-----------------    Funcion para registrar clientes ---------------*/
void registrar_cliente(Cliente& cliente, int x)
{
	if (cliente == nullptr)
	{
		cliente = new (struct nodoCliente);
		cliente->codCliente = x;

		cin.ignore();
		cout << "\n\tNOMBRE :";
		cin.getline(cliente->nomCliente, max_char);
		cin.ignore();
		cout << "\n\tAPELLIDOS :";
		cin.getline(cliente->apellCliente, max_char);
		cout << "\n\tDNI :";
		cin >> cliente->dniCliente;
		cin.ignore();
		cout << "\n\tRUC :";
		cin.getline(cliente->rucCliente, max_doce);
		cin.ignore();
		cout << "\n\tTELEFONO :";
		cin.getline(cliente->telefono, max_doce);
		cin.ignore();
		cout << "\n\tDIRECCION :";
		cin.getline(cliente->direccion, max_char);
		cin.ignore();
		cout << "\n\tE-MAIL :";
		cin.getline(cliente->email, max_char);

		cliente->izq = nullptr;
		cliente->der = nullptr;
	}
	else if (x < cliente->codCliente) registrar_cliente(cliente->izq, x);
	else if (x > cliente->codCliente) registrar_cliente(cliente->der, x);
}

/*------- Funcion que modifica un dato de un cliente seleccionado  --------*/
void actualizar_cliente(Cliente& cliente, int cod)
{
	if (cliente != nullptr)
	{
		if (cliente->codCliente == cod)
		{
			int op;
			system("cls");
			cout << "\n\n\t\t[  MODIFICAR CLIENTE ]\n";
			cout << "\t\t------------------------";
			cout << "\n\n\tCODIGO :" << cliente->codCliente;
			cout << "\n\n\tNOMBRE :" << cliente->nomCliente;
			cout << "\n\n\tAPELLIDOS :" << cliente->apellCliente;
			cout << "\n\n\tDNI :" << cliente->dniCliente;
			cout << "\n\n\tRUC :" << cliente->rucCliente;
			cout << "\n\n\tTELEFONO :" << cliente->telefono;
			cout << "\n\n\tDIRECCION :" << cliente->direccion;
			cout << "\n\n\tE-MAIL :" << cliente->email;


			menu_actualizar_cliente();
			cin >> op;
			switch (op)
			{
			case 1: cin.ignore();
				cout << "\n\tINGRESE NUEVO NOMBRE :";
				cin.getline(cliente->nomCliente, max_char);
				break;

			case 2: cin.ignore();
				cout << "\n\tINGRESE NUEVO APELLIDO :";
				cin.getline(cliente->apellCliente, max_char);
				break;

			case 3: cin.ignore();
				cout << "\n\tINGRESE NUEVO TELEFONO :";
				cin.getline(cliente->telefono, max_doce);
				break;

			case 4: cin.ignore();
				cout << "\n\tINGRESE NUEVO E-MAIL :";
				cin.getline(cliente->email, max_char);
				break;

			case 5: cin.ignore();
				cout << "\n\tINGRESE NUEVA DIRECCION :";
				cin.getline(cliente->direccion, max_char);
				break;

			case 6: break;

			default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
				break;
			}
		}
		else if (cod < cliente->codCliente) actualizar_cliente(cliente->izq, cod);
		else if (cod > cliente->codCliente) actualizar_cliente(cliente->der, cod);
	}
}

/*---------- Funcion que muestra todos los clientes registrados ---------*/
void mostrar_clientes(Cliente cliente)
{
	if (cliente != nullptr)
	{
		mostrar_clientes(cliente->izq);
		cout << "\n\n\t\t[    MOSTRAR CLIENTES    ]\n";
		cout << "\t\t------------------------";
		cout << "\n\n\tCODIGO :" << cliente->codCliente;
		cout << "\n\n\tNOMBRE :" << cliente->nomCliente;
		cout << "\n\n\tAPELLIDOS :" << cliente->apellCliente;
		cout << "\n\n\tDNI :" << cliente->dniCliente;
		cout << "\n\n\tRUC :" << cliente->rucCliente;
		cout << "\n\n\tTELEFONO :" << cliente->telefono;
		cout << "\n\n\tDIRECCION :" << cliente->direccion;
		cout << "\n\n\tE-MAIL :" << cliente->email;
		mostrar_clientes(cliente->der);
	}
}

/*------- Funcion que retorna true cuando el codigo es valido  --------*/
bool validar_codigo_cliente(Cliente cliente, int cod, Cliente& ptrCliente)
{
	if (cliente != nullptr)
	{
		if (cliente->codCliente == cod)
		{
			ptrCliente = cliente;
			return true;
		}
		else if (cod < cliente->codCliente) validar_codigo_cliente(cliente->izq, cod, ptrCliente);
		else if (cod > cliente->codCliente) validar_codigo_cliente(cliente->der, cod, ptrCliente);
	}
}

/*------- Funcion que valida si el codigo del producto es verdadero--------*/
bool validar_cod_producto(Producto producto, int codprod, Producto& puntProducto)
{
	if (producto != nullptr)
	{
		if (producto->codProd == codprod)
		{
			puntProducto = producto;
			return true;
		}

		else if (codprod < producto->codProd) validar_cod_producto(producto->izq, codprod, puntProducto);
		else if (codprod > producto->codProd) validar_cod_producto(producto->der, codprod, puntProducto);
	}
}

/*------- Funcion que busca el codigo de linea del producto en el arbol --------*/
bool validar_codigo_producto(Linea arbol, int codlinea, int codprod, Producto& puntProducto)
{
	bool validar;
	validar = false;
	if (arbol != nullptr)
	{
		if (arbol->codLinea == codlinea)
		{
			validar = validar_cod_producto(arbol->enlace, codprod, puntProducto);
			if (validar == true)
				return validar;
		}
		else if (codlinea < arbol->codLinea) validar_codigo_producto(arbol->izq, codlinea, codprod, puntProducto);
		else if (codlinea > arbol->codLinea) validar_codigo_producto(arbol->der, codlinea, codprod, puntProducto);
	}
}

/*------- Funcion que agrega un producto a la boleta de venta --------*/
void insertar_producto_venta(DetalleVenta& q, Linea arbol)
{
	bool validado;
	int codLinea, x;
	char op;

	DetalleVenta t, r;
	r = new(struct nodoDetalleVenta);
	cout << "\n\tCODIGO:";
	cin >> r->codigo;
	r->ptrProducto = nullptr;
	validado = false;
	do
	{
		cout << "\n\tINGRESE LINEA DEL PRODUCTO: ";
		cin >> codLinea;
		cout << "\n\tCODIGO DE PRODUCTO:";
		cin >> x;
		validado = validar_codigo_producto(arbol, codLinea, x, r->ptrProducto);
		if (validado == true)
		{
			cout << "\n\t NOMBRE :" << (r->ptrProducto)->nomProd;
			cout << "\n\t PRECIO :" << (r->ptrProducto)->precio;
		}
		if (validado == false)
		{
			cout << "\n\tCODIGO INVALIDO...!!";
		}
		cout << "\n\n\tDesea continuar  ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': return;

		case 'N': return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (validado == false);
	r->codProd = x;
	cout << "\n\tCANTIDAD:";
	cin >> r->cantidad;

	strcpy_s(r->marca, (r->ptrProducto)->nomProd);

	r->subtotal = (r->cantidad) * ((r->ptrProducto)->precio);
	r->sgte = nullptr;

	if (q == nullptr)
		q = r;
	else
	{
		t = q;
		while (t->sgte != nullptr)
			t = t->sgte;

		t->sgte = r;
	}
}

/*------- Funcion que ordena agregar la cantidad de productos deseados  --------*/
void detalle_de_venta(DetalleVenta& detalle, Linea arbol, Venta& venta)
{
	char op;
	cout << "\n\n\t\t[    LISTA DE PRODUCTOS VENDIDOS  ]\n";
	cout << "\t\t-------------------------------";
	do
	{
		insertar_producto_venta(detalle, arbol);
		cout << "\n\n\tDesea agregar otro producto a la venta ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': return;

		case 'N': return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (op == 'y' || op == 'Y');
}

/*------- Funcion que registra una venta a la lista enlazada venta  --------*/
void registrar_venta(Venta& venta, Cliente cliente, Linea arbol)
{
	int x;
	char op;
	float total = 0;
	bool validado;
	Venta q, t;
	DetalleVenta aux;
	q = new(struct nodoVenta);
	cout << "\n\n\t\t[    BOLETA DE VENTAS   ]\n";
	cout << "\t\t------------------------";
	cout << "\n\tCODIGO:";
	cin >> q->codigo;
	cin.ignore();
	cout << "\n\tFECHA:";
	cin.getline(q->fecha, max_doce);
	validado = false;
	do
	{
		cout << "\n\tCODIGO DE CLIENTE:";
		cin >> x;
		validado = validar_codigo_cliente(cliente, x, q->ptrCliente);
		if (validado == true)
			cout << "\n\tNOMBRE:" << (q->ptrCliente)->nomCliente;
		if (validado == false)
			cout << "\n\tCODIGO INVALIDO...!!";
		cout << "\n\n\tDesea continuar con el registro de venta ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': delete(q);
			return;

		case 'N': delete(q);
			return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (validado == false);

	q->codCliente = x;
	q->detalle = nullptr;
	q->sgte = nullptr;
	detalle_de_venta(q->detalle, arbol, q); //insertamos los productos deseados
	/*--- calculamos el monto */
	aux = q->detalle;
	while (aux != nullptr)
	{
		total = total + aux->subtotal;
		aux = aux->sgte;
	}
	q->monto = total;
	if (venta == nullptr)
		venta = q;

	else
	{
		t = venta;
		while (t->sgte != nullptr)
			t = t->sgte;

		t->sgte = q;
	}
}


/*------- Funcion muestra todas las ventas de la lista q  --------*/
void listar_ventas(Venta q)
{
	int i = 1;
	while (q != nullptr)
	{
		cout << "\n\n\tDATOS DE LA VENTA [" << i << "] ";
		cout << "\n\t------------------------";
		cout << "\n\tCODIGO DE VENTA: " << q->codigo;
		cout << "\n\tFECHA  : " << q->fecha;
		cout << "\n\tCODIGO DE CLIENTE : " << q->codCliente;
		cout << "\n\tNOMBRE DEL CLIENTE:" << (q->ptrCliente)->nomCliente;
		cout << "\n\tMONTO:" << q->monto;

		q = q->sgte;
		i++;
	}
}

/*------- Funcion que muestra una venta con sus productos  --------*/
void mostrar_venta(Venta q, int cod)
{
	int i = 1;
	while (q != nullptr)
	{
		if (q->codigo == cod)
		{
			cout << "\n\n\t[  DATOS DE LA VENTA   ]";
			cout << "\n\t------------------------";
			cout << "\n\tCODIGO DE VENTA: " << q->codigo;
			cout << "\n\tFECHA  : " << q->fecha;
			cout << "\n\tCODIGO DE CLIENTE : " << q->codCliente;
			cout << "\n\tNOMBRE DEL CLIENTE:" << (q->ptrCliente)->nomCliente;
			cout << "\n\tMONTO:" << q->monto << endl;
			while (q->detalle != nullptr)
			{
				cout << "\n\n\tPRODUCTO [" << i << "]\n";
				cout << "\n\tCODIGO:" << (q->detalle)->codigo;
				cout << "\n\tCODIGO DEL PRODUCTO:" << (q->detalle)->codProd;
				cout << "\n\tCANTIDAD:" << (q->detalle)->cantidad;
				cout << "\n\tMARCA:" << (q->detalle)->ptrProducto->nomProd;
				cout << "\n\tSUBTOTAL:" << (q->detalle)->subtotal;
				(q->detalle) = (q->detalle)->sgte;
				i++;
			}
			q = q->sgte;
		}
		else q = q->sgte;
	}
}

/*-----------------    Funcion para registrar proveedores ---------------*/
void registrar_proveedor(Proveedor& proveedor, int x)
{
	if (proveedor == nullptr)
	{
		proveedor = new (struct nodoProveedor);
		proveedor->codProveedor = x;

		cin.ignore();
		cout << "\n\tRAZON SOCIAL :";
		cin.getline(proveedor->razonSocial, max_char);
		cin.ignore();
		cout << "\n\tRUC :";
		cin.getline(proveedor->rucProveedor, max_doce);
		cin.ignore();
		cout << "\n\tTELEFONO :";
		cin.getline(proveedor->telefono, max_doce);
		cin.ignore();
		cout << "\n\tDIRECCION :";
		cin.getline(proveedor->direccion, max_char);
		cin.ignore();
		cout << "\n\tE-MAIL :";
		cin.getline(proveedor->email, max_char);
		cin.ignore();
		cout << "\n\tWEB :";
		cin.getline(proveedor->web, max_char);
		proveedor->izq = nullptr;
		proveedor->der = nullptr;
	}
	else if (x < proveedor->codProveedor) registrar_proveedor(proveedor->izq, x);
	else if (x > proveedor->codProveedor) registrar_proveedor(proveedor->der, x);
}

/*------- Funcion que modifica un dato de un proveedor seleccionado  --------*/
void actualizar_proveedor(Proveedor& proveedor, int cod)
{
	if (proveedor != nullptr)
	{
		if (proveedor->codProveedor == cod)
		{
			int op;
			system("cls");
			cout << "\n\n\t\t[  MODIFICAR CLIENTE ]\n";
			cout << "\t\t------------------------";
			cout << "\n\n\tCODIGO :" << proveedor->codProveedor;
			cout << "\n\n\tRAZON SOCIAL :" << proveedor->razonSocial;
			cout << "\n\n\tRUC :" << proveedor->rucProveedor;
			cout << "\n\n\tTELEFONO :" << proveedor->telefono;
			cout << "\n\n\tDIRECCION :" << proveedor->direccion;
			cout << "\n\n\tE-MAIL :" << proveedor->email;
			cout << "\n\n\tWEB :" << proveedor->web;


			menu_actualizar_proveedor();
			cin >> op;
			switch (op)
			{
			case 1: cin.ignore();
				cout << "\n\tINGRESE NUEVA RAZON SOCIAL :";
				cin.getline(proveedor->razonSocial, max_char);
				break;

			case 2: cin.ignore();
				cout << "\n\tINGRESE NUEVO TELEFONO :";
				cin.getline(proveedor->telefono, max_doce);
				break;

			case 3: cin.ignore();
				cout << "\n\tINGRESE NUEVO E-MAIL :";
				cin.getline(proveedor->email, max_char);
				break;

			case 4: cin.ignore();
				cout << "\n\tINGRESE NUEVA DIRECCION :";
				cin.getline(proveedor->direccion, max_char);
				break;

			case 5: cin.ignore();
				cout << "\n\tINGRESE NUEVA WEB :";
				cin.getline(proveedor->web, max_char);
				break;

			case 6: break;

			default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
				break;
			}
		}
		else if (cod < proveedor->codProveedor) actualizar_proveedor(proveedor->izq, cod);
		else if (cod > proveedor->codProveedor) actualizar_proveedor(proveedor->der, cod);
	}
}

/*---------- Funcion que muestra todos los proveedores registrados ---------*/
void mostrar_proveedores(Proveedor proveedor)
{
	if (proveedor != nullptr)
	{
		mostrar_proveedores(proveedor->izq);
		cout << "\n\n\t\t[    MOSTRAR PROVEEDOR    ]\n";
		cout << "\t\t------------------------";
		cout << "\n\n\tCODIGO :" << proveedor->codProveedor;
		cout << "\n\n\tRAZON SOCIAL :" << proveedor->razonSocial;
		cout << "\n\n\tRUC :" << proveedor->rucProveedor;
		cout << "\n\n\tTELEFONO :" << proveedor->telefono;
		cout << "\n\n\tDIRECCION :" << proveedor->direccion;
		cout << "\n\n\tE-MAIL :" << proveedor->email;
		cout << "\n\n\tWEB :" << proveedor->web;
		mostrar_proveedores(proveedor->der);
	}
}

/*------- Funcion muestra todas las ventas de la lista q  --------*/
void listar_pedidos(Pedido q)
{
	int i = 1;
	while (q != nullptr)
	{
		cout << "\n\n\tDATOS DEL PEDIDO [" << i << "] ";
		cout << "\n\t------------------------";
		cout << "\n\tCODIGO DE PEDIDO: " << q->codigo;
		cout << "\n\tFECHA  : " << q->fecha;
		cout << "\n\tCODIGO DE PROVEEDOR : " << q->codProveedor;
		cout << "\n\tRAZON SOCIAL:" << (q->ptrProveedor)->razonSocial;
		cout << "\n\tMONTO:" << q->monto;

		q = q->sgte;
		i++;
	}
}


/*------- Funcion que agrega un producto a la proforma de pedido --------*/
void insertar_producto_pedido(DetallePedido& q, Linea arbol)
{
	bool validado;
	int codLinea, x;
	char op;

	DetallePedido t, r;
	r = new(struct nodoDetallePedido);
	cout << "\n\tCODIGO:";
	cin >> r->codigo;
	r->ptrProducto = nullptr;
	validado = false;
	do
	{
		cout << "\n\tINGRESE LINEA DEL PRODUCTO: ";
		cin >> codLinea;
		cout << "\n\tCODIGO DE PRODUCTO:";
		cin >> x;
		validado = validar_codigo_producto(arbol, codLinea, x, r->ptrProducto);
		if (validado == true)
		{
			cout << "\n\t NOMBRE :" << (r->ptrProducto)->nomProd;
			cout << "\n\t PRECIO :" << (r->ptrProducto)->precio;
		}
		if (validado == false)
			cout << "\n\tCODIGO INVALIDO...!!";
		cout << "\n\n\tDesea continuar  ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': return;

		case 'N': return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (validado == false);
	r->codProd = x;
	cout << "\n\tCANTIDAD:";
	cin >> r->cantidad;

	strcpy_s(r->marca, (r->ptrProducto)->nomProd);

	r->subtotal = (r->cantidad) * ((r->ptrProducto)->precio);
	r->sgte = nullptr;

	if (q == nullptr)
		q = r;
	else
	{
		t = q;
		while (t->sgte != nullptr)
			t = t->sgte;

		t->sgte = r;
	}
}


/*------- Funcion que ordena agregar la cantidad de productos deseados al detalle del pedido  --------*/
void detalle_de_pedido(DetallePedido& detalle, Linea arbol, Pedido& pedido)
{
	char op;
	cout << "\n\n\t\t[    LISTA DE PRODUCTOS A PEDIR  ]\n";
	cout << "\t\t-------------------------------";
	do
	{
		insertar_producto_pedido(detalle, arbol);
		cout << "\n\n\tDesea agregar otro producto a la Proforma ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': return;

		case 'N': return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (op == 'y' || op == 'Y');
}

/*------- Funcion que retorna true cuando el codigo es valido  --------*/
bool validar_codigo_proveedor(Proveedor proveedor, int cod, Proveedor& ptrProveedor)
{
	if (proveedor != nullptr)
	{
		if (proveedor->codProveedor == cod)
		{
			ptrProveedor = proveedor;
			return true;
		}
		else if (cod < proveedor->codProveedor) validar_codigo_proveedor(proveedor->izq, cod, ptrProveedor);
		else if (cod > proveedor->codProveedor) validar_codigo_proveedor(proveedor->der, cod, ptrProveedor);
	}
}

/*------- Funcion que registra un Pedido a la lista enlazada Pedido  --------*/
void registrar_pedido(Pedido& pedido, Proveedor proveedor, Linea arbol)
{
	int x;
	char op;
	float total = 0;
	bool validado;
	Pedido q, t;
	DetallePedido aux;
	q = new(struct nodoPedido);
	cout << "\n\n\t\t[    PROFORMA DE PEDIDO   ]\n";
	cout << "\t\t-----------------------------";
	cout << "\n\tCODIGO:";
	cin >> q->codigo;
	cin.ignore();
	cout << "\n\tFECHA:";
	cin.getline(q->fecha, max_doce);
	validado = false;
	do
	{
		cout << "\n\tCODIGO DE PROVEEDOR:";
		cin >> x;
		validado = validar_codigo_proveedor(proveedor, x, q->ptrProveedor);
		if (validado == true)
			cout << "\n\tRAZON SOCIAL:" << (q->ptrProveedor)->razonSocial;

		if (validado == false)
			cout << "\n\tCODIGO INVALIDO...!!";
		cout << "\n\n\tDesea continuar con el registro de Pedido ? <y/n>: ";
		cin >> op;
		switch (op)
		{
		case 'y': break;

		case 'Y': break;

		case 'n': delete(q);
			return;

		case 'N': delete(q);
			return;

		default: cout << "\n\t Ingrese una opcion valida";
		}
	}
	while (validado == false);

	q->codProveedor = x;
	q->detalle = nullptr;
	q->sgte = nullptr;
	detalle_de_pedido(q->detalle, arbol, q); //insertamos los productos deseados

	/*--- calculamos el monto */
	aux = q->detalle;
	while (aux != nullptr)
	{
		total = total + aux->subtotal;
		aux = aux->sgte;
	}
	q->monto = total;
	if (pedido == nullptr)
		pedido = q;

	else
	{
		t = pedido;
		while (t->sgte != nullptr)
			t = t->sgte;

		t->sgte = q;
	}
}

/*------- Funcion que muestra un pedido con sus productos  --------*/
void mostrar_pedido(Pedido q, int cod)
{
	int i = 1;
	while (q != nullptr)
	{
		if (q->codigo == cod)
		{
			cout << "\n\n\t[   DATOS DEL PEDIDO   ]";
			cout << "\n\t------------------------";
			cout << "\n\tCODIGO DE PEDIDO: " << q->codigo;
			cout << "\n\tFECHA  : " << q->fecha;
			cout << "\n\tCODIGO DE PROVEEDOR : " << q->codProveedor;
			cout << "\n\tRAZON SOCIAL:" << (q->ptrProveedor)->razonSocial;
			cout << "\n\tMONTO:" << q->monto << endl;
			while (q->detalle != nullptr)
			{
				cout << "\n\n\tPRODUCTO [" << i << "]\n";
				cout << "\n\tCODIGO:" << (q->detalle)->codigo;
				cout << "\n\tCODIGO DEL PRODUCTO:" << (q->detalle)->codProd;
				cout << "\n\tCANTIDAD:" << (q->detalle)->cantidad;
				cout << "\n\tMARCA:" << (q->detalle)->ptrProducto->nomProd;
				cout << "\n\tSUBTOTAL:" << (q->detalle)->subtotal;
				(q->detalle) = (q->detalle)->sgte;
				i++;
			}
			q = q->sgte;
		}
		else q = q->sgte;
	}
}

/*---------------------- FUNCION PRINCIPAL ----------------------*/
int main()
{
	Linea arbol = nullptr;
	Cliente cliente = nullptr;
	Venta venta = nullptr;
	Proveedor proveedor = nullptr;
	Pedido pedido = nullptr;


	int op, op2, dato;
	do
	{
		titulo();
		menu1();
		cin >> op;

		switch (op)
		{
			/*-------------  ALMACEN ---------------*/
		case 1: system("cls");
			do
			{
				titulo();
				menu2();
				cin >> op2;

				switch (op2)
				{
				case 1: cout << "\nIngrese codigo de linea:";
					cin >> dato;
					insertar_linea(arbol, dato);
					break;

				case 2: mostrar_linea(arbol);
					break;

				case 3: cout << "\nIngrese codigo de Linea del Producto:";
					cin >> dato;
					registrar_producto(arbol, dato);
					break;

				case 4: cout << "\nIngrese codigo de Linea del Producto:";
					cin >> dato;
					mostrar_producto(arbol, dato);
					break;

				case 5: break;

				default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
					break;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			while (op2 != 5);
			break;

			/*-------------  CLIENTES ---------------*/
		case 2: system("cls");
			do
			{
				titulo();
				menu3();
				cin >> op2;

				switch (op2)
				{
				case 1: cout << "\n\n\t\t[  REGISTRO DE CLIENTE ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tCodigo de cliente:";
					cin >> dato;
					registrar_cliente(cliente, dato);
					break;

				case 2: cout << "\n\n\t\t[  ACTUALIZAR CLIENTE ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tCodigo de cliente:";
					cin >> dato;
					actualizar_cliente(cliente, dato);
					break;

				case 3: system("cls");
					mostrar_clientes(cliente);
					break;


				case 5: break;

				default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
					break;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			while (op2 != 5);
			break;

			/*-------------  VENTAS ---------------*/
		case 3: system("cls");
			do
			{
				titulo();
				menu4();
				cin >> op2;

				switch (op2)
				{
				case 1: registrar_venta(venta, cliente, arbol);
					break;

				case 2: cout << "\n\n\t\t[  LISTAR VENTAS REALIZADAS ]\n";
					cout << "\t\t------------------------\n";
					listar_ventas(venta);
					break;
				case 3: cout << "\n\n\t\t[    DETALLES DE VENTA    ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tIngrese codigo de venta:";
					cin >> dato;
					mostrar_venta(venta, dato);
					break;

				case 5: break;

				default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
					break;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			while (op2 != 5);
			break;
			/*-------------  PROVEEDOR ---------------*/
		case 4: system("cls");
			do
			{
				titulo();
				menu5();
				cin >> op2;

				switch (op2)
				{
				case 1: cout << "\n\n\t\t[  REGISTRO DE PROVEEDOR ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tCodigo de Proveedor:";
					cin >> dato;
					registrar_proveedor(proveedor, dato);
					break;

				case 2: cout << "\n\n\t\t[  ACTUALIZAR PROVEEDOR ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tCodigo de Proveedor:";
					cin >> dato;
					actualizar_proveedor(proveedor, dato);
					break;

				case 3: system("cls");
					mostrar_proveedores(proveedor);
					break;


				case 5: break;

				default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
					break;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			while (op2 != 5);
			break;

			/*-------------  PEDIDOS ---------------*/
		case 5: system("cls");
			do
			{
				titulo();
				menu6();
				cin >> op2;

				switch (op2)
				{
				case 1: registrar_pedido(pedido, proveedor, arbol);
					break;

				case 2: cout << "\n\n\t\t[  LISTAR PEDIDOS REALIZADOS ]\n";
					cout << "\t\t------------------------\n";
					listar_pedidos(pedido);
					break;

				case 3: cout << "\n\n\t\t[    DETALLES DE PEDIDO    ]\n";
					cout << "\t\t------------------------\n";
					cout << "\n\tIngrese codigo de pedido:";
					cin >> dato;
					mostrar_pedido(pedido, dato);
					break;

				case 5: break;

				default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
					break;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			while (op2 != 5);
			break;
		case 6: return 0;


		default: cout << "\nINGRESE UNA OPCION VALIDA...\n";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	while (op != 6);

	system("pause");


	return 0;
}
