#include <stdio.h>
#include "lectura.h"
#include "inventario.h"
#include"clientes.h"
#include"factura.h"

int main (int argc, char *argv[]) {
//menu
int opcion;

//productos
char nombres[MAXPRODUCTOS][MAXNOM];
int cantidades[MAXPRODUCTOS];
float precios[MAXPRODUCTOS];
int numProducto = 0;
cargarInventario(nombres, cantidades, precios, &numProducto);

//clientes
char cedulas[MAXCLIENTES][MAXCEDU];
char nombresClientes[MAXCLIENTES][MAXNOM];
int numClientes = 0;
cargarClientes(cedulas, nombresClientes, &numClientes);

//facturas
char fechas[MAXFACTURAS][20];
char cedulasFacturas[MAXCLIENTES][MAXCEDU];
char nombresFacturas[MAXFACTURAS][MAXNOM];
float valoresPagados[MAXFACTURAS];
int cantidadesCompradas[MAXFACTURAS];
int numFacturas = 0;
cargarFacturas(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, &numFacturas);


    printf("Bienvenido al sistema de inventario y facturacion de la empresa");
    do {
        printf("\n----------Menu----------");
        printf("\n1. Ingresar producto");
        printf("\n2. Modificar producto");
        printf("\n3. Eliminar producto");
        printf("\n4. Consultar producto");
        printf("\n5. Ver productos");
        printf("\n6. Ingresar cliente");
        printf("\n7. Modificar cliente");
        printf("\n8. Consultar cliente");
        printf("\n9. Listar clientes");
        printf("\n10. Facturar");
        printf("\n11. Buscar factura");
        printf("\n12. Listar facturas ");
        printf("\n13. Salir");
        printf("\n---------------------------");
        opcion=leerEnteroEntre("\nSeleccione una opcion\n",1,13);

        switch (opcion)
        {
        case 1:
            ingresarProducto(nombres, cantidades, precios, &numProducto);
            break;

        case 2:
            modificarProducto(nombres, cantidades, precios, numProducto);
            break;
        
        case 3:
            eliminarProducto(nombres, cantidades, precios, &numProducto);
            break;
            
        case 4:
            buscarProducto(nombres, cantidades, precios, numProducto);
            break;
            
        case 5:
            verProductos(nombres, cantidades, precios, numProducto);
            break;
            
        case 6:
            ingresarCliente(cedulas, nombresClientes, &numClientes);
            break;
            
        case 7:
            modificarCliente(cedulas, nombresClientes, numClientes);
            break;
            
        case 8:
            consultarCliente(cedulas, nombresClientes, numClientes);
            break;
            
        case 9:
            listarClientes(cedulas, nombresClientes, numClientes);
            break;
            
        case 10:
            crearFactura(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, &numFacturas, nombres, cantidades, precios, numProducto, cedulas, nombresClientes, numClientes);
            break;
            
        case 11:
            buscarFactura(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, numFacturas);
            break;
            
        case 12:
             listarFacturas(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, numFacturas);
            break;
            
        case 13:
            printf("Cerrando el programa");
            break;
        
        
        }
    } while(opcion !=13);
    return 0;
}