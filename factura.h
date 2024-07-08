#ifndef FACTURAS_H
#define FACTURAS_H

#include "inventario.h"
#include"clientes.h"

#define MAXFACTURAS 100

void cargarFacturas(char fechas[][20], char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], float valoresPagados[], int cantidadesCompradas[], int *numFacturas);
void guardarFacturas(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);
void crearFactura(char fechas[][20], char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], float valoresPagados[], int cantidadesCompradas[], int *numFacturas, const char nombres[][MAXNOM], int cantidades[], float precios[], int numRepuestos, const char cedulasClientes[][MAXCEDU], const char nombresClientesFactura[][MAXNOM], int numClientes);
void listarFacturas(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);
void buscarFactura(const char fechas[][20], const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);

#endif // FACTURAS_H