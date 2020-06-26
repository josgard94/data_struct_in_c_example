//test array struct
#include <string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

int cliente;
int contador = 0;
//char NameCategorias[2] = {"Televisores","Celulares"};
//variables globales
float TotalElectronica = 0.0 ,TotalMedicina = 0.0 , TotalRopa = 0.0;
int TotalArtElectronica = 0, TotalArtMedicina = 0, TotalArtRopa = 0;
int TotalPas1Electronica = 0, TotalPas2Electronica = 0;

//Declaración  de la estrutura para generar las notas de venta.
struct Cliente
{
	int NumProductos;
	int NumCliente;
	char Departamento[50], categoria[50];
	char NomProducto[50], MarcaProducto[50];
	float PrecioProducto;
		
};

//Declaración de array tipo struct para guardar los datos de la compra usando los campos de la structura cliente. 
struct Cliente DatosCompra [150];

//Declaración de los campos de la strutura departamento
struct departamento
{
	char Nombre[20];
	char Cat1[20], Cat2[20];
};

//Inicialización de los campos de la estructura departamento
struct departamento Elec ={
	"Electronica",
	"Celulares",
	"Televisores"
};

//declaración de los campos de la struct producto.
struct producto{
	char categoria[50];
	char Nombre[50];
	char Marca[50];
	float Precio;
};

//inicialización  de los campos de la estructura producto
struct producto SubCat[8] = {
	//Categoria 	Nombre		   Marca   Precio
	//Productos de la subcategoria Televisores
	"Televisores","Smart TV 3000", "Sonyc", 1800,
	"Televisores","TV Led 755", "Philis", 12000,
	//Productos de la subcategoria Celulares
	"Celulares","Galaxi A10s", "Samsung", 5300,
	"Celulares","MOTO G7", "Motorola", 6500
};

//Funcion encargada de realizar  el proceso de gurdado de los productos seleccionados en la estrutura DatosCompra -> Cliente.
void realizar_compras(int dep)
{
	
	int i,id;
	//mostrar producto de las subcategorias
	switch(dep)
	{
		char op[2];
		case 1: //Operaciones para compra en departamento electronica
			do
			{
				printf("Televisores:\n");
				for(i = 0; i < 2; i++)
				{
					printf("%i).- \t%s \t%s \t%1.2f\n",i, SubCat[i].Nombre,SubCat[i].Marca,SubCat[i].Precio);
				}
				printf("Celulares:\n");
				for(i = 2; i < 4; i++)
				{
					printf("%i).- \t%s \t%s \t%1.2f\n",i, SubCat[i].Nombre,SubCat[i].Marca,SubCat[i].Precio);
				}
				printf("Id del producto que quiere comprar: "); 
				scanf("%i",&id);
				DatosCompra[contador].NumCliente = cliente;
				strcpy(DatosCompra[contador].Departamento,Elec.Nombre);
				strcpy(DatosCompra[contador].categoria,SubCat[id].categoria);
				strcpy(DatosCompra[contador].NomProducto,SubCat[id].Nombre);
				strcpy(DatosCompra[contador].MarcaProducto,SubCat[id].Marca);
				DatosCompra[contador].PrecioProducto = SubCat[id].Precio;
				contador += 1;
				printf("realizar otra compra ? (s/n)"); scanf("%s",&op);
				system("cls");
			}while(strcmp(op,"s")!= -1);
			
			break;
		case 2: //Mostrar datos del departamento medicina y realizar operaciones de compra
			break;
		case 3: //Mostrar datos del departamento ropa y realizar operaciones de compra
			break;
		case 4:
			printf("Good bye !!");
			exit(0);
			break;
	}
}
//contar el numero de articulos por pasillo adquiridos por el cliente
void cuenta_articulo_pasillo(int i)
{
	if(strcmp(DatosCompra[i].categoria,"Televisores")!= -1)
	{
		TotalPas1Electronica += 1;
	}
	else if(strcmp(DatosCompra[i].categoria,"Celulares")!= -1)
	{
		TotalPas2Electronica += 1;
	}
	
}
//Calculo de la suma total de compra por departamento
void calcular_totales(int i, float precio)
{
	if(strcmp(DatosCompra[i].Departamento,"Electronica")!=-1)
	{
		TotalElectronica += precio;
		TotalArtElectronica += 1; //cuenta el numero de articulo comprados en electronica.
	}
	if(strcmp(DatosCompra[i].Departamento,"Medicina")!=-1)
	{
		TotalMedicina += precio;
		TotalArtMedicina += 1;
	}
	if(strcmp(DatosCompra[i].Departamento,"Ropa")!=-1)
	{
		TotalRopa += precio;
		TotalArtRopa += 1;
	}
}

//Funcion encargada de mostrar en pantall los datos de los clientes registrados
void print_nota()
{
	printf("\n\t\tCompras reaizadas\n");
	int i;
	int NC;
	float TotalSinDescuento = 0.0;
	float TotalConDescuento = 0.0;
	int bandera = 0;
	printf("\n-----------------------------------------------------\n");
	for(i = 0; i < contador; i ++)
	{
		if(bandera == 0)
		{
			NC = DatosCompra[i].NumCliente;
			
			printf("Num Cliente: %i\n", DatosCompra[i].NumCliente);
			printf("\n-----------------------------------------------------\n");
			printf("Departamento: %s \n",DatosCompra[i].Departamento);
			printf("Categoria: %s\n", DatosCompra[i].categoria);
			printf("Producto: %s Marca: %s ",DatosCompra[i].NomProducto, DatosCompra[i].MarcaProducto);
			printf("Precio: %1.2f\n" ,DatosCompra[i].PrecioProducto);
			calcular_totales(i,DatosCompra[i].PrecioProducto);
			cuenta_articulo_pasillo(i);
			bandera = 1;
		}
		else if(NC == DatosCompra[i].NumCliente)
		{
			printf("Departamento: %s\n",DatosCompra[i].Departamento);
			printf("Categoria: %s\n", DatosCompra[i].categoria);
			printf("Producto: %s Marca: %s ",DatosCompra[i].NomProducto, DatosCompra[i].MarcaProducto);
			printf("Precio: %1.2f\n" ,DatosCompra[i].PrecioProducto);
			calcular_totales(i,DatosCompra[i].PrecioProducto);
			cuenta_articulo_pasillo(i);
		}
		else
		{
			printf("Total de articulos por departanento -> Electronica %i, Medicina %i, Ropa %i\n",TotalArtElectronica,TotalArtMedicina,TotalArtRopa);
			TotalArtElectronica = 0; TotalArtMedicina = 0; TotalArtRopa = 0; //reiniciamos contadores
			printf("Articulos por pasillo Electronica -> Televisores: %i, Celulares: %i\n",TotalPas1Electronica, TotalPas2Electronica);
			TotalPas1Electronica = 0; TotalPas2Electronica = 0;
			TotalSinDescuento = TotalElectronica + TotalMedicina + TotalRopa;
			TotalConDescuento = (TotalElectronica-(TotalElectronica * 0.20)) + (TotalMedicina-(TotalMedicina*0.50)) + (TotalRopa-(TotalRopa*0.10));
			printf("Total sin descuento: %1.2f\n",TotalSinDescuento);
			printf("Total con descuento: %1.2f\n",TotalConDescuento);
			
			TotalSinDescuento = 0.0;
			TotalElectronica = 0.0; TotalMedicina = 0.0; TotalRopa = 0.0;
			printf("\n-----------------------------------------------------\n");
			NC = DatosCompra[i].NumCliente;
			printf("Num Cliente: %i\n", DatosCompra[i].NumCliente);
			printf("\n-----------------------------------------------------\n");
			printf("Departamento: %s\n",DatosCompra[i].Departamento);
			printf("Categoria: %s\n", DatosCompra[i].categoria);
			
			printf("Producto: %s Marca: %s ",DatosCompra[i].NomProducto, DatosCompra[i].MarcaProducto);
			printf("Precio: %1.2f\n" ,DatosCompra[i].PrecioProducto);
			calcular_totales(i,DatosCompra[i].PrecioProducto);
			cuenta_articulo_pasillo(i);
			
		}
			
	}
	printf("Total de articulos por departamento -> Electronica %i, Medicina %i, Ropa %i\n",TotalArtElectronica,TotalArtMedicina,TotalArtRopa);
	TotalArtElectronica = 0; TotalArtMedicina = 0; TotalArtRopa = 0; //reiniciamos contadores
	printf("Articulos por pasillo Electronica -> Televisores: %i, Celulares: %i\n",TotalPas1Electronica, TotalPas2Electronica);
	TotalPas1Electronica = 0; TotalPas2Electronica = 0;
	TotalSinDescuento = TotalElectronica + TotalMedicina + TotalRopa;
	TotalConDescuento = (TotalElectronica-(TotalElectronica * 0.20)) + (TotalMedicina-(TotalMedicina*0.50)) + (TotalRopa-(TotalRopa*0.10));
	printf("Total sin descuento: %1.2f\n",TotalSinDescuento);
	printf("Total con descuento: %1.2f\n",TotalConDescuento);
	printf("\n-----------------------------------------------------\n");
}
void print_menu()
{
	
		int dep;
		char op[2],op2[2];
		do{
			
			printf("Numero de cliente: ");scanf("%i",&cliente);
			do
			{
				
				printf("\t\tTienda departamental\n");
				printf("Departamentos:\n");
				printf("\t1).- %s\n", Elec.Nombre);
				printf("\t4).- Salir\n");
				printf("Opcion: ");scanf("%i",&dep);
				
				realizar_compras(dep);
					
				printf("Visitar otro departamento? (s/n)");scanf("%s",&op);
			}while(strcmp(op,"s")!=-1);
			printf("Registrar otro cliente ?(s/n)");scanf("%s",&op2);
			
		}while(strcmp(op2,"s") != -1);
}

main()
{
	print_menu();
	print_nota();
}
