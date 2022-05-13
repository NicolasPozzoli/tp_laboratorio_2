#ifndef EPassenger_H_
#define EPassenger_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


#define MAX_CHARS_CADENAS 51
#define INACTIVO 0
#define ACTIVO 1
#define TIPO_COMERCIAL 0
#define TIPO_EJECUTIVO 1
#define TIPO_PRIMERACLASE 2


//*** ePassenger
typedef struct {
	int idPassenger;
	int isEmpty;
	char lastname[MAX_CHARS_CADENAS];
	int typePassenger;
	char name[MAX_CHARS_CADENAS];
	char flycode[MAX_CHARS_CADENAS];
	int statusFlight;
	float price;
} ePassenger;
//***

/** INICIO CABECERAS DE FUNCION*/
void initPassenger(ePassenger array[], int TAM);
int ePassenger_ObtenerIndexLibre(ePassenger array[], int TAM);
int findPassengerById(ePassenger array[], int TAM, int ID);
void ePassenger_MostrarUno(ePassenger Passenger);
void ePassenger_MostrarUnoEstado(ePassenger Passenger);
int printPassenger(ePassenger array[], int TAM);
int MostrarEstadoActivo(ePassenger array[], int TAM);
int ePantalla_MostrarDadosDeBaja(ePassenger array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int sortPassengers(ePassenger array[], int TAM, int criterio);
int sortPassengerByCode(ePassenger array[], int TAM, int criterio);
int ePassenger_Sort(ePassenger array[], int TAM, int criterio);
float CalcularPromedio (float suma, float cantidad);
int acumuladorPrecioPasajes (ePassenger array[], int TAM);
int CuantosSuperanPrecioPromedio (ePassenger array[], int TAM, float promedio);

//ABM
ePassenger ePassenger_CargarDatos(void);
ePassenger ePassenger_ModificarUno(ePassenger Passenger);
int ePassenger_Alta(ePassenger array[], int TAM);
int addPassenger(ePassenger array[], int TAM, int id,char name[],char lastname[],float price, int typePassenger, char flycode[]);
int ePassenger_Baja(ePassenger array[], int TAM);
int removePassenger(ePassenger array[], int TAM, int id);
int ePassenger_Modificacion(ePassenger array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
