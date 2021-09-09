/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: josue
 *
 * Created on 6 de septiembre de 2021, 19:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
//por FF18023 y PA19031

char temporal[100];

char ***matrix = NULL; //Valores va a contener todos los valores leidos
int *campos_linea = NULL;

char *cambio = NULL;
int linea= 0;
int campos_L = 0;
int distancia = 0;
int filas,cols;

void Leermatriz_transpuesta(){
     printf("Matriz transpuesta\n");
    for (int cols = 1; cols < 6;cols++) {
        
        for (int  filas= 1; filas < 60; filas++)
          
            printf(" %s", matrix[filas][cols]);
            printf("\n");
        } 
}
void multiplicacion_matriz1(){
    printf("Multiplicacion de matriz\n");
    
}
void leer_matriz(){
    FILE *datos = NULL;
    datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    if (datos != NULL) {
        do {
            memset(temporal, 0, 100);
            fgets(temporal, 100, datos);
            linea++;
            matrix = realloc(matrix, linea * sizeof (char*));
            campos_linea = realloc(campos_linea, linea * sizeof (int));
            matrix[linea - 1] = NULL;
            cambio = strtok(temporal, ",");
            campos_L = 0;
            while (cambio != NULL) {
                campos_L++;
                matrix[linea - 1] = realloc(matrix[linea - 1], sizeof (char*)*campos_L);
                distancia = strlen(cambio);
                matrix[linea - 1][campos_L - 1] = calloc(distancia + 1, sizeof (char));
                strncpy(matrix[linea - 1][campos_L - 1], cambio, distancia);
                cambio = strtok(NULL, ",");
            }
            campos_linea[linea -1] = campos_L;
        } while (feof(datos) == 0);
        fclose(datos);
        printf("Matriz de valores leidos \n");
        filas = 1;
        while (filas < linea) {
            cols = 1;
            
            while (cols < campos_linea[filas]) { // Aqui es donde se procesarian los campos para transformarlos a valores enteres flotantes etc....
                printf(" %s", matrix[filas][cols]); //Actualmente todos los campos son char*
                cols++;
            }
            filas++;
        }
        
    } else {
        printf("Error leyendo el archivo\n");
        }
   

    
    fclose(datos);
}
int main() {
    
    
    leer_matriz();
    Leermatriz_transpuesta();
    multiplicacion_matriz1();
        }
    


