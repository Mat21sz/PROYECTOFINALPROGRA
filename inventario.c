#include <stdio.h>
#include <string.h>
#include "inventario.h"
#include "lectura.h"



void cargarInventario(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    *numProducto = 0;
    while (fscanf(archivo, "%s %d %f", nombres[*numProducto], &cantidades[*numProducto], &precios[*numProducto]) != EOF) {
        (*numProducto)++;
    }

    fclose(archivo);
}

void guardarInventario(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto) {
    FILE *archivo = fopen("inventario.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    for (int i = 0; i < numProducto; i++) {
        fprintf(archivo, "%s %d %f\n", nombres[i], cantidades[i], precios[i]);
    }

    fclose(archivo);
}

void ingresarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto) {
    if (*numProducto >= MAXPRODUCTOS) {
        printf("Error: inventario lleno.\n");
        return;
    }

    char nombreNuevo[MAXNOM];
    int cantidadNueva;
    float precioNuevo;

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombreNuevo);

    // Verificar si el producto ya existe
    for (int i = 0; i < *numProducto; i++) {
        if (strcmp(nombres[i], nombreNuevo) == 0) {
            printf("Producto ya existente, intente modificarlo.\n");
            return;
        }
    }

    // Agregar el nuevo producto
    strcpy(nombres[*numProducto], nombreNuevo);

    // Verificar la cantidad ingresada
    cantidadNueva=leerEnteroPositivo("\nIngrese la cantidad:\n");

    // Verificar el precio ingresado
    precioNuevo=leerFlotantePositivo("\nIngrese el precio:\n");

    cantidades[*numProducto] = cantidadNueva;
    precios[*numProducto] = precioNuevo;

    (*numProducto)++;
    printf("Producto ingresado correctamente.\n");
    guardarInventario(nombres, cantidades, precios, *numProducto);
}

void modificarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int numProducto) {
    char nombreEditar[MAXNOM];
    int nuevaCantidad;
    float nuevoPrecio;

    printf("\nIngrese el nombre del producto a editar: \n");
    scanf("%s", nombreEditar);

    for (int i = 0; i < numProducto; i++) {
        if (strcmp(nombres[i], nombreEditar) == 0) {
            nuevaCantidad=leerEnteroMayor("\nIngrese la nueva cantidad: \n",0);
            cantidades[i] = nuevaCantidad;

            nuevoPrecio=leerFlotanteMayorIgual("\nIngrese el nuevo precio: \n",0);
            precios[i]=nuevoPrecio;
            printf("Producto modificado de forma correcta.\n");
            guardarInventario(nombres, cantidades, precios, numProducto);
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto) {
    char nombreEliminar[MAXNOM];
    printf("\nIngrese el nombre del producto a eliminar: \n");
    scanf("%s", nombreEliminar);

     for (int i = 0; i < *numProducto; i++) {
        if (strcmp(nombres[i], nombreEliminar) == 0) {
            for (int j = i; j < *numProducto - 1; j++) {
                for (int k = 0; k < MAXNOM; k++) {
                    nombres[j][k] = nombres[j + 1][k];
                }
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            (*numProducto)--;
            printf("\nProducto eliminado de forma correcta.\n");
            guardarInventario(nombres, cantidades, precios, *numProducto);
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}

void verProductos(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto) {
    printf("___________________________________________________________________\n");
    printf("| %-25s | %10s | %10s | %10s |\n", "Nombre del producto", "Cantidad", "Precio", "Total");
    

    for (int i = 0; i < numProducto; i++) {
        float total = cantidades[i] * precios[i];
        printf("| %-25s | %10d | $%9.2f | $%9.2f |\n", nombres[i], cantidades[i], precios[i], total);
    }

    if (numProducto == 0) {
        printf("|%-57s|\n", " No hay repuestos en el inventario.");
    }

    printf("___________________________________________________________________\n");
}

void buscarProducto(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto) {
    char nombreBuscar[MAXNOM];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numProducto; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("___________________________________________________________________\n");
            printf("| %-25s | %10s | %10s | %10s |\n", "Nombre del producto", "Cantidad", "Precio", "Total");
            float total = cantidades[i] * precios[i];
            printf("| %-25s | %10d | $%9.2f | $%9.2f |\n", nombres[i], cantidades[i], precios[i], total);
            printf("___________________________________________________________________\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}