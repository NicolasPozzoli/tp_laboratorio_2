#ifndef EPantalla_H_
#define EPantalla_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define MAX_CHARS_CADENAS 30
#define TIPO_LED 0
#define TIPO_LCD 1


//*** ePantalla
typedef struct {
	int idPantalla;
	int isEmpty;
	char direccion[MAX_CHARS_CADENAS];
	int tipo;
	char nombre[MAX_CHARS_CADENAS];
	int precioPorDia;
} ePantalla;
//***

/** INICIO CABECERAS DE FUNCION*/
void ePantalla_Inicializar(ePantalla array[], int TAM);
int ePantalla_ObtenerIndexLibre(ePantalla array[], int TAM);
int ePantalla_BuscarPorID(ePantalla array[], int TAM, int ID);
void ePantalla_MostrarUno(ePantalla Pantalla);
int ePantalla_MostrarTodos(ePantalla array[], int TAM);
int ePantalla_MostrarDadosDeBaja(ePantalla array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ePantalla_Sort(ePantalla array[], int TAM, int criterio);

//ABM
ePantalla ePantalla_CargarDatos(void);
ePantalla ePantalla_ModificarUno(ePantalla Pantalla);
int ePantalla_Alta(ePantalla array[], int TAM);
int ePantalla_Baja(ePantalla array[], int TAM);
int ePantalla_Modificacion(ePantalla array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
