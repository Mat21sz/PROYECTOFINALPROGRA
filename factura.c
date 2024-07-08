#include <stdio.h>
#include <string.h>
#include <time.h>
#include "inventario.h"
#include"clientes.h"
#include"factura.h"

void cargarFacturas(char fechas[][20], char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], float valoresPagados[], int cantidadesCompradas[], int *numFacturas) {
    FILE *archivo = fopen("facturas.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de facturas.\n");
        return;
    }

    *numFacturas = 0;
    while (*numFacturas < MAXFACTURAS && fscanf(archivo, "%19s %10s %99s %f %d", fechas[*numFacturas], cedulas[*numFacturas], nombresClientes[*numFacturas], &valoresPagados[*numFacturas], &cantidadesCompradas[*numFacturas]) == 5) {
        (*numFacturas)++;
    }

    fclose(archivo);
}

void guardarFacturas(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    FILE *archivo = fopen("facturas.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de facturas para escritura.\n");
        return;
    }

    for (int i = 0; i < numFacturas; i++) {
        fprintf(archivo, "%s %s %s %.2f %d\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
    }

    fclose(archivo);
}

void obtenerFechaActual(char fecha[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(fecha, 20, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void crearFactura(char fechas[][20], char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], float valoresPagados[], int cantidadesCompradas[], int *numFacturas, const char nombres[][MAXNOM], int cantidades[], float precios[], int numRepuestos, const char cedulasClientes[][MAXCEDU], const char nombresClientesInventario[][MAXNOM], int numClientes) {
    if (*numFacturas >= MAXFACTURAS) {
        printf("Error: lista de facturas llena.\n");
        return;
    }

    char cedulaCliente[MAXCEDU];
    char nombreProducto[MAXNOM];
    int cantidadComprar;

    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedulaCliente);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulasClientes[i], cedulaCliente) == 0) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente no encontrado.\n");
        return;
    }

    printf("Ingrese el nombre del producto a comprar: ");
    scanf("%s", nombreProducto);

    int indiceProducto = -1;
    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            indiceProducto = i;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    while (1) {
        printf("Ingrese la cantidad a comprar: ");
        scanf("%d", &cantidadComprar);
        if (cantidadComprar > cantidades[indiceProducto]) {
            printf("Error: no hay suficiente stock. Disponible: %d\n", cantidades[indiceProducto]);
        } else {
            break;
        }
    }

    cantidades[indiceProducto] -= cantidadComprar;
    guardarInventario(nombres, cantidades, precios, numRepuestos);

    obtenerFechaActual(fechas[*numFacturas]);
    strncpy(cedulas[*numFacturas], cedulaCliente, MAXCEDU - 1); //deja espacio para el caracter nulo \0
    strncpy(nombresClientes[*numFacturas], nombresClientesInventario[indiceProducto], MAXNOM - 1);
    valoresPagados[*numFacturas] = precios[indiceProducto] * cantidadComprar;
    cantidadesCompradas[*numFacturas] = cantidadComprar;

    (*numFacturas)++;
    printf("Factura creada correctamente.\n");
    guardarFacturas(fechas, cedulas, nombresClientes, valoresPagados, cantidadesCompradas, *numFacturas);
}

void listarFacturas(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    printf("______________________________________________________________________________\n");
    printf("| %-10s | %-10s | %-25s | %-10s | %-10s |\n", "Fecha", "Cedula", "Nombre Cliente", "Valor", "Cantidad");
    printf("______________________________________________________________________________\n");

    for (int i = 0; i < numFacturas; i++) {
        printf("| %-10s | %-10s | %-25s | $%9.2f | %9d |\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
    }

    if (numFacturas == 0) {
        printf("|%-61s|\n", " No hay facturas en la lista.");
    }

    printf("______________________________________________________________________________\n");
}

void buscarFactura(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    char cedulaBuscar[MAXCEDU];

    printf("Ingrese la cedula del cliente para buscar facturas: ");
    scanf("%s", cedulaBuscar);

    printf("______________________________________________________________________________\n");
    printf("| %-10s | %-10s | %-25s | %-10s | %-10s |\n", "Fecha", "Cedula", "Nombre Cliente", "Valor", "Cantidad");

    int facturasEncontradas = 0;
    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(cedulas[i], cedulaBuscar) == 0) {
            printf("| %-10s | %-10s | %-25s | $%9.2f | %9d |\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
            facturasEncontradas++;
        }
    }

    if (facturasEncontradas == 0) {
        printf("|%-61s|\n", " No hay facturas para esta cedula.");
    }

    printf("______________________________________________________________________________\n");
}