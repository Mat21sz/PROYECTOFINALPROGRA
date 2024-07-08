#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inventario.h"
#include"clientes.h"

void cargarClientes(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int *numClientes) {
    FILE *archivo = fopen("clientes.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de clientes.\n");
        return;
    }

    *numClientes = 0;
    while (fscanf(archivo, "%s %s", cedulas[*numClientes], nombresClientes[*numClientes]) != EOF) {
        (*numClientes)++;
    }

    fclose(archivo);
}

void guardarClientes(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes) {
    FILE *archivo = fopen("clientes.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de clientes.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(archivo, "%s %s\n", cedulas[i], nombresClientes[i]);
    }

    fclose(archivo);
}

int validarCedula(const char *cedula) {
    //verifica si la cedula tiene mas de 10 digitos
    if (strlen(cedula) != 10) {
        return 0; 
    }
    //verifica si cada valor ingresado es un digito
    for (int i = 0; i < 10; i++) {
        if (!isdigit(cedula[i])) {
            return 0; 
        }
    }

    
    int verificador = cedula[9] - '0';
    //extrae el valor numerico entero
    int sumaPonderada = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) { 
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        sumaPonderada += digito;
    }

    int digitoCalculado = 10 - (sumaPonderada % 10);
    if (digitoCalculado == 10) {
        digitoCalculado = 0;
    }

    if (verificador == digitoCalculado) {
        return 1; 
    } else {
        return 0;
    }
}

void ingresarCliente(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int *numClientes) {
    if (*numClientes >= MAXCLIENTES) {
        printf("Error: lista de clientes llena.\n");
        return;
    }

    char cedulaNueva[MAXCEDU];
    char nombreNuevo[MAXNOM];

    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedulaNueva);

    //si la funcion validarCedula retorna 0 (falso) 
    if (!validarCedula(cedulaNueva)) {
        printf("Error: cedula no válida.\n");
        return;
    }

    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(cedulas[i], cedulaNueva) == 0) {
            printf("Error: cedula ya registrada.\n");
            return;
        }
    }

    printf("Ingrese el nombre del cliente: ");
    //" %[^\n]" lee cualquier caracter que no sea un salto de linea
    scanf(" %[^\n]", nombreNuevo);

    strcpy(cedulas[*numClientes], cedulaNueva);
    strcpy(nombresClientes[*numClientes], nombreNuevo);

    (*numClientes)++;
    printf("Cliente ingresado correctamente.\n");
    guardarClientes(cedulas, nombresClientes, *numClientes);
}

void modificarCliente(char cedulas[][MAXCEDU], char nombresClientes[][MAXNOM], int numClientes) {
    char cedulaEditar[MAXCEDU];
    char nuevoNombre[MAXNOM];

    printf("Ingrese la cedula del cliente a editar: ");
    scanf("%s", cedulaEditar);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedulaEditar) == 0) {
            printf("Ingrese el nuevo nombre del cliente: ");
            scanf(" %[^\n]", nuevoNombre);

            strcpy(nombresClientes[i], nuevoNombre);
            printf("Cliente editado correctamente.\n");
            guardarClientes(cedulas, nombresClientes, numClientes);
            return;
        }
    }

    printf("Cliente no encontrado.\n");
}

void consultarCliente(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes) {
    char cedulaBuscar[MAXCEDU];

    printf("Ingrese la cedula del cliente a consultar: ");
    scanf("%s", cedulaBuscar);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedulaBuscar) == 0) {
            printf("Cliente encontrado:\n");
            printf("Cedula: %s\n", cedulas[i]);
            printf("Nombre: %s\n", nombresClientes[i]);
            return;
        }
    }

    printf("Cliente no encontrado.\n");
}

void listarClientes(const char cedulas[][MAXCEDU], const char nombresClientes[][MAXNOM], int numClientes) {
     printf("|%-12s|%-32s|\n", "Cedula", "Nombre");

    for (int i = 0; i < numClientes; i++) {
        printf("|%-12s|%-32s|\n", cedulas[i], nombresClientes[i]);
    }

    if (numClientes == 0) {
        printf("|%-44s|\n", " No hay clientes en la lista.");
    }
}