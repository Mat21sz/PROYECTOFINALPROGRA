#ifndef CLIENTES_H
#define CLIENTES_H

#include "inventario.h"

#define MAXCEDU 11
#define MAXCLIENTES 100

void cargarClientes(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int *numClientes);
void guardarClientes(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes);
int validarCedula(const char *cedula);
void ingresarCliente(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int *numClientes);
void modificarCliente(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int numClientes);
void consultarCliente(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes);
void listarClientes(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes);

#endif // CLIENTES_H