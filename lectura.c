#include <stdio.h>
#include "lectura.h"


int leerEnteroPositivo(char* mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        if(valor<=0){
            printf("\nEl valor ingresado debe ser mayor a 0\n");
        }
    } while (valor <= 0);
    return valor;
}

float leerFlotantePositivo(char* mensaje) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        if(valor<=0){
            printf("\nEl valor ingresado debe ser mayor a 0\n");
        }
    } while (valor <= 0);
    return valor;
}

int leerEnteroEntre(char* mensaje, int lmenor, int lmayor) {
    int numero;
    do {
        printf("%s", mensaje);
        scanf("%d", &numero);
        if (numero>lmayor || numero<lmenor)
        {
            printf("\nOpcion invalida\n");
        }
        
    } while (numero < lmenor || numero > lmayor);
    return numero;
}

int leerEntero(char* mensaje) {
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
    return numero;
}

int leerEnteroMayor(char* mensaje, int menor){
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor); 
        if(valor < menor){
            printf("\nEl valor no puede ser negativo");
        }
    } while (valor < menor);
    return valor;
}

float leerFlotante(char* mensaje) {
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}

float leerFlotanteEntre(char* mensaje, float lmenor, float lmayor) {
    float numero;
    do {
        printf("%s", mensaje);
        scanf("%f", &numero);
    } while (numero < lmenor || numero > lmayor);
    return numero;
}

char leerCaracter(char* mensaje) {
    char caracter;
    printf("%s", mensaje);
    scanf(" %c", &caracter);
    return caracter;
}

float leerFlotanteMayorIgual(char* mensaje, float menor) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor); 
        if(valor < menor){
            printf("\nEl valor no puede ser negativo");
        }
    } while (valor < menor);
    return valor;
}