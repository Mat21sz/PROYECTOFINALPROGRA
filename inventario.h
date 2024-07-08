#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAXPRODUCTOS 100
#define MAXNOM 100




void cargarInventario(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto);
void guardarInventario(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto);
void ingresarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto);
void modificarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int numProducto);
void eliminarProducto(char nombres[][MAXNOM], int cantidades[], float precios[], int *numProducto);
void verProductos(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto);
void buscarProducto(const char nombres[][MAXNOM], const int cantidades[], const float precios[], int numProducto);

#endif // INVENTARIO_H