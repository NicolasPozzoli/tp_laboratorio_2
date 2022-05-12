/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: nicop
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

int utn_getNumero(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pNumeroIngresado)
{
	int retorno = -1;
	int auxiliarFloat;


	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{

		do
		{
			printf("%s",mensaje);
			if(getInt(&auxiliarFloat)==0 && auxiliarFloat>=minimo && auxiliarFloat<=maximo)
			{
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;

			}
		}while(reintentos > 0);
	}
	return retorno;
}

int utn_getFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, float *pNumeroIngresado)
{
	int retorno = -1;
	float auxiliarFloat;


	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{

		do
		{
			printf("%s",mensaje);
			if(getFloat(&auxiliarFloat)==0 && auxiliarFloat>=minimo && auxiliarFloat<=maximo)
			{
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;

			}
		}while(reintentos > 0);
	}
	return retorno;
}




int getInt(int* pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[10];

	if(pNumeroTomado != NULL)
	{
		if(getString(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
				&& esInt(numeroAuxiliar, sizeof(numeroAuxiliar)) == 1)
		{
			*pNumeroTomado= atoi(numeroAuxiliar);
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float* pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[10];

	if(pNumeroTomado != NULL)
	{
		if(getString(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
				&& esFloat(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0)
		{
			*pNumeroTomado= atof(numeroAuxiliar);
			retorno = 0;
		}
	}
	return retorno;
}


int esNumerica(char arrayPosiblesNumeros[])
{
	int retorno = 0;
	int i;

	if(arrayPosiblesNumeros != NULL)
	{
		i = 0;

		while(arrayPosiblesNumeros[i] != '\0')
		{
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else
	{
		retorno = -1 ;
	}
	return retorno;
}
int esInt(char* string, int limite)
{
	int retorno;
	int i = 0;
	//printf("el array tiene datos\n");
	for(i=0; i<limite && string[i] !='\0'; i++)
	{
		if(i == 0 && (string[i] == '-' || string[i] == '+'))
		{
			continue;
		}
		if(string[i] < '0' || string[i] > '9')
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 0;
			break;
		}
		else
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 1;
		}
	}
	return retorno;
}

/*int esFloat(char* string, int limite)
{
	int retorno;
	int i = 0;
	int flagPunto=0;
	//printf("el array tiene datos\n");
	for(i=0; i<limite && string[i] !='\0'; i++)
	{
		if(i == 0 && (string[i] == '-' || string[i] == '+'))
		{
			continue;
		}
		if(string[i] < '0' || string[i] > '9')      // modificar
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 0;
			break;
		}
		else
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 1;
		}
		if(string[i]=='.')
		{
			if(flagPunto==1)
			{
				retorno=-1;
			}
			else
			{
				flagPunto=1;
			}
		}
	}
	return retorno;
}

*/

int esFloat(char string[], int limite)
{
	int retorno=-1;
	int i=0;
	int puntos=0;

	if(string!=NULL && limite>0)
	{
		retorno=0;
		if(string[0] == '-' || string[0] == '+')
		{
			i=1;
		}
		while(string[i] != '\0')
		{
			if(string[i] == '.' && puntos== 0)
			{
				puntos++;
				i++;
				continue;
			}
			if(string[i] < '0' || string[i] > '9')
			{
				retorno=-2;
				break;
			}
			i++;
		}
	}
	return retorno;
}



/*
int myGets(char cadena[], int size)
{
	int retorno = -1;
	cadena[strlen(cadena)-1]='\0';
	if(cadena != NULL && size > 0 && fgets(cadena, size, stdin) == cadena)
	{
		retorno = 0;
	}
	return retorno;
}
*/
//-----------------------------------------------GET STRING------------------------------------------------------------
int getString(char* string, int longitud)
{
	int retorno = -1;
	//aprender memoria dinamica
	char bufferString[4096];


	if(string != NULL && longitud > 0)
	{
		fflush(stdin);

		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			//si aca hay un salto de linea ponele un \0
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(bufferString[0] == '\0')
			{
				return -1;
			}

			//si la longitud de la cadena a revisar es <= a la longitud deseada copiamos
			//el contenido
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(string,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}


static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer, sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


int esTexto(char* string, int longitud)
{
	int i=0;
	int retorno = 1;
	if(string != NULL && longitud > 0)
	{
		for (i=0 ; string[i] != '\0' && i < longitud; i++)
		{
			if(string[i] < 32 || string[i] > 126)
			{
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

int getTexto(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if (getString(buffer, sizeof(buffer))==0 &&
			esTexto(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud)

		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}
	return retorno;
}


int utn_getTexto(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char buffer[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos --;
		printf("%s", mensaje);
		if(getTexto(buffer, sizeof(buffer)) == 0 && strnlen(buffer,sizeof(buffer)) <= longitud)
		{
			strncpy(pResultado,buffer, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}



