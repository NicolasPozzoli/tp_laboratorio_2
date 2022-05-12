/*
 * Input.h
 *
 *  Created on: 5 abr. 2022
 *      Author: nicop
 */

#ifndef INPUT_H_
#define INPUT_H_
int utn_getFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, float *pNumeroIngresado);
int utn_getNumero(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pNumeroIngresado);
int getInt(int* pNumeroTomado);
int getFloat(float* pNumeroTomado);
int esFloat(char* string, int limite);
int esFloat(char string[], int limite);
int esNumerica(char arrayPosiblesNumeros[]);
int myGets(char cadena[], int size);
int getString(char* string, int longitud);
int esNombre(char* cadena,int longitud);
int esInt(char* string, int limite);
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);
int esTexto(char* cadena, int longitud);
int getTexto(char* pResultado, int longitud);
int utn_getTexto(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);

#endif /* INPUT_H_ */
