/*
 ============================================================================
 Name        : TRABAJO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "Input.h"


#define MAX_TAM_PASSANGER 2000

int main(void) {
	setbuf (stdout ,NULL);
	int opcion;
	int flag1=0;
	int contadorPasajeros=0;
	float acumuladorPreciopasajes=0;
	float precioPromedio;




	ePassenger arrayPassenger[MAX_TAM_PASSANGER];

	initPassenger(arrayPassenger, MAX_TAM_PASSANGER);
	do
	{
	if(utn_getNumero("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n"
					"   MENU\n"
					"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n"
					"1--> ALTAS                        °\n\n"
					"2--> MODIFICAR                    °\n\n"
					"3--> BAJAS                        °\n\n"
					"4--> INFORMAR                     °\n\n"
					"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n"
					"ESCOJA OPCION: ", "Opcion Invalida. Intente nuevamente ", 0, 4, 3, &opcion)==0)
	{
		switch(opcion)
		{
		case 1:
			if(ePassenger_Alta(arrayPassenger, MAX_TAM_PASSANGER)==1)
			{
				puts("ALTA REALIZADA.");
				flag1=1;
				contadorPasajeros++;
				acumuladorPreciopasajes=acumuladorPrecioPasajes(arrayPassenger, MAX_TAM_PASSANGER);

			}
			else
			{
				puts("\nERROR AL DAR DE ALTA.");
			}

			break;
		case 2:
			if(flag1==1)
			{
			if(ePassenger_Modificacion(arrayPassenger, MAX_TAM_PASSANGER)==1)
			{
				puts("MODIFICACION REALIZADA.\n");
				acumuladorPreciopasajes=acumuladorPrecioPasajes(arrayPassenger, MAX_TAM_PASSANGER);

			}
			else
			{
				puts("ERROR AL MODIFICAR.");
			}
			}else
			{
				puts("\nERROR. NO SE INGRESARON PASAJEROS");
			}
			break;
		case 3:
			if(flag1==1)
			{
			if(ePassenger_Baja(arrayPassenger, MAX_TAM_PASSANGER)==1)
			{
				puts("BAJA REALIZADA.\n");
				contadorPasajeros--;
				acumuladorPreciopasajes=acumuladorPrecioPasajes(arrayPassenger, MAX_TAM_PASSANGER);
			}
			else
			{
				puts("ERROR AL DAR DE BAJA.");
			}
			}else
			{
				puts("\nERROR. NO SE INGRESARON PASAJEROS");
			}
			break;
		case 4:
			if(flag1==1)
			{
			if(sortPassengers(arrayPassenger, MAX_TAM_PASSANGER, -1)==1)    //ORDENO: -1 ASCENDENTE  / 1 DESCENDENTE
			{
				printPassenger(arrayPassenger, MAX_TAM_PASSANGER);
				puts("\nORDENADO APELLIDO Y TIPO DE PASAJERO.");
				puts("\n----------------------------------------------------------------------------------------------------------------");
			}
			else
			{
				puts("\nERROR AL INFORMAR.");
			}

			printf("\nPRECIO TOTAL DE PASAJES: $%.2f (Sin contar los inactivos)\n",acumuladorPreciopasajes);

			precioPromedio=CalcularPromedio(acumuladorPreciopasajes, contadorPasajeros);
			if(precioPromedio>0)
			{
				printf("PRECIO PROMEDIO: %.2f", precioPromedio);
			}

			}else
			{
				puts("\nERROR. NO SE INGRESARON PASAJEROS");
			}

			CuantosSuperanPrecioPromedio(arrayPassenger, MAX_TAM_PASSANGER, precioPromedio);


			if(sortPassengerByCode(arrayPassenger, MAX_TAM_PASSANGER, -1)==1)
			{
				printPassenger(arrayPassenger, MAX_TAM_PASSANGER);
				puts("\nORDENADO POR CODIGO Y ESTADO.");
				puts("----------------------------------------------------------------------------------------------------------------");
			}
			else
			{
				puts("ERROR AL ORDENAR POR CODIGO Y ESTADO.");
			}


			break;
		}
	}
	}while(opcion!=0);
	return EXIT_SUCCESS;
}
