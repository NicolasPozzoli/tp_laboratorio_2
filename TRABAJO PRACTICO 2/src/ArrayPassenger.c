#include "ArrayPassenger.h"
#include "Input.h"
static int ePassenger_ObtenerID(void);
static int ePassenger_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION ePassenger_ObtenerID();
	static int Passenger_idIncremental = 100;
	return Passenger_idIncremental++;
}

void initPassenger(ePassenger array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}
int addPassenger(ePassenger array[], int TAM, int id,char name[],char lastname[],float price, int typePassenger, char flycode[]) {
	int rtn = 0;
	ePassenger auxPassenger;

	if(array!=NULL && TAM>0 && name!=NULL && lastname!=NULL && price>0 && typePassenger>-1 && flycode!=NULL)
	{
	//BUSCO ESPACIO EN ARRAY
	int index = ePassenger_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Passenger AUXILIAR

		switch (typePassenger) {
		case 1:
			auxPassenger.typePassenger = TIPO_COMERCIAL;
			break;
		case 2:
			auxPassenger.typePassenger = TIPO_EJECUTIVO;
			break;
		case 3:
			auxPassenger.typePassenger = TIPO_PRIMERACLASE;
			break;
		}

		strcpy(auxPassenger.name,name);
		strcpy(auxPassenger.lastname,lastname);
		strcpy(auxPassenger.flycode,flycode);
		auxPassenger.price=price;
		auxPassenger.typePassenger=typePassenger;
		//auxPassenger = ePassenger_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL

		rtn = 1;
	}
	}
	return rtn;
}


int findPassengerById(ePassenger array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idPassenger == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int removePassenger(ePassenger array[],int TAM,int id)
{
	int rtn = 0;
		int index;

		if(array!=NULL && TAM>0){
		//SI HAY Passenger PARA DAR DE BAJA
		//OBTENGO INDEX DEL ARRAY DE Passenger A DAR DE BAJA
					index = findPassengerById(array, TAM, id);
					/**PREGUNTAR SI DESEA CONTINUAR*/
					//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
					array[index].isEmpty = BAJA;
			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
					rtn=1;
		}
		return rtn;

}

int sortPassengers(ePassenger array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePassenger aux;

	/** EJEMPLO DE SORT CON ID DE Passenger
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(array[i].lastname, array[j].lastname) ==0)                                     //(array[i].lastname==array[j].lastname)
						{
							if (array[i].typePassenger > array[j].typePassenger) {
								//INTERCAMBIO POSICIONES EN ARRAY
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}else
						{

						if (strcmp(array[i].lastname,array[j].lastname)>0) {
							//INTERCAMBIO POSICIONES EN ARRAY
							memcpy(aux.lastname,array[i].lastname,MAX_CHARS_CADENAS);
							memcpy(array[i].lastname,array[j].lastname,MAX_CHARS_CADENAS);
							memcpy(array[j].lastname,aux.lastname,MAX_CHARS_CADENAS);

							memcpy(aux.name,array[i].name,MAX_CHARS_CADENAS);
							memcpy(array[i].name,array[j].name,MAX_CHARS_CADENAS);
							memcpy(array[j].name,aux.name,MAX_CHARS_CADENAS);

							memcpy(aux.flycode,array[i].flycode,MAX_CHARS_CADENAS);
							memcpy(array[i].flycode,array[j].flycode,MAX_CHARS_CADENAS);
							memcpy(array[j].flycode,aux.flycode,MAX_CHARS_CADENAS);

							aux.idPassenger = array[i].idPassenger;
							array[i].idPassenger = array[j].idPassenger;
							array[j].idPassenger = aux.idPassenger;

							aux.isEmpty = array[i].isEmpty;
							array[i].isEmpty = array[j].isEmpty;
							array[j].isEmpty = aux.isEmpty;

							aux.typePassenger = array[i].typePassenger;
							array[i].typePassenger = array[j].typePassenger;
							array[j].typePassenger = aux.typePassenger;

							aux.price = array[i].price;
							array[i].price = array[j].price;
							array[j].price = aux.price;

							aux.statusFlight = array[i].statusFlight;
							array[i].statusFlight = array[j].statusFlight;
						    array[j].statusFlight = aux.statusFlight;



						}
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (strcmp(array[i].lastname,array[j].lastname)<0) {
							//INTERCAMBIO POSICIONES EN ARRAY
							memcpy(aux.lastname,array[i].lastname,MAX_CHARS_CADENAS);
							memcpy(array[i].lastname,array[j].lastname,MAX_CHARS_CADENAS);
							memcpy(array[j].lastname,aux.lastname,MAX_CHARS_CADENAS);

							memcpy(aux.name,array[i].name,MAX_CHARS_CADENAS);
							memcpy(array[i].name,array[j].name,MAX_CHARS_CADENAS);
							memcpy(array[j].name,aux.name,MAX_CHARS_CADENAS);

							memcpy(aux.flycode,array[i].flycode,MAX_CHARS_CADENAS);
							memcpy(array[i].flycode,array[j].flycode,MAX_CHARS_CADENAS);
							memcpy(array[j].flycode,aux.flycode,MAX_CHARS_CADENAS);

							aux.idPassenger = array[i].idPassenger;
							array[i].idPassenger = array[j].idPassenger;
							array[j].idPassenger = aux.idPassenger;

							aux.isEmpty = array[i].isEmpty;
							array[i].isEmpty = array[j].isEmpty;
							array[j].isEmpty = aux.isEmpty;

							aux.typePassenger = array[i].typePassenger;
							array[i].typePassenger = array[j].typePassenger;
							array[j].typePassenger = aux.typePassenger;

							aux.price = array[i].price;
							array[i].price = array[j].price;
							array[j].price = aux.price;

							aux.statusFlight = array[i].statusFlight;
							array[i].statusFlight = array[j].statusFlight;
						    array[j].statusFlight = aux.statusFlight;

						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}


int printPassenger(ePassenger array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO PASAJEROS: ");
	printf("%5s\n\n", "ID\t\tTIPO\t\tPRECIO\t\tNOMBRE \t\tAPELLIDO\tFLYCODE\t\tESTADO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO || array[i].isEmpty == BAJA ) {
				//MUESTRO UN SOLO Passenger
				ePassenger_MostrarUnoEstado(array[i]);
				//CONTADOR DE Passenger
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Passenger PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


int sortPassengerByCode(ePassenger array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePassenger aux;

	/** EJEMPLO DE SORT CON ID DE Passenger
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(array[i].flycode, array[j].flycode) ==0)                                     //(array[i].lastname==array[j].lastname)
						{
							if (array[i].statusFlight > array[j].statusFlight) {
								//INTERCAMBIO POSICIONES EN ARRAY
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}

						}else
						{

						if (strcmp(array[i].flycode,array[j].flycode)>0) {
							//INTERCAMBIO POSICIONES EN ARRAY
							memcpy(aux.lastname,array[i].lastname,MAX_CHARS_CADENAS);
							memcpy(array[i].lastname,array[j].lastname,MAX_CHARS_CADENAS);
							memcpy(array[j].lastname,aux.lastname,MAX_CHARS_CADENAS);

							memcpy(aux.name,array[i].name,MAX_CHARS_CADENAS);
							memcpy(array[i].name,array[j].name,MAX_CHARS_CADENAS);
							memcpy(array[j].name,aux.name,MAX_CHARS_CADENAS);

							memcpy(aux.flycode,array[i].flycode,MAX_CHARS_CADENAS);
							memcpy(array[i].flycode,array[j].flycode,MAX_CHARS_CADENAS);
							memcpy(array[j].flycode,aux.flycode,MAX_CHARS_CADENAS);

							aux.idPassenger = array[i].idPassenger;
							array[i].idPassenger = array[j].idPassenger;
							array[j].idPassenger = aux.idPassenger;

							aux.isEmpty = array[i].isEmpty;
							array[i].isEmpty = array[j].isEmpty;
							array[j].isEmpty = aux.isEmpty;

							aux.typePassenger = array[i].typePassenger;
							array[i].typePassenger = array[j].typePassenger;
							array[j].typePassenger = aux.typePassenger;

							aux.price = array[i].price;
							array[i].price = array[j].price;
							array[j].price = aux.price;

							aux.statusFlight = array[i].statusFlight;
							array[i].statusFlight = array[j].statusFlight;
						    array[j].statusFlight = aux.statusFlight;



						}
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(array[i].flycode, array[j].flycode) ==0)                                     //(array[i].lastname==array[j].lastname)
						{
							if (array[i].statusFlight < array[j].statusFlight) {
								//INTERCAMBIO POSICIONES EN ARRAY
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}else
						{

						if (strcmp(array[i].flycode,array[j].flycode)<0) {
							//INTERCAMBIO POSICIONES EN ARRAY
							memcpy(aux.lastname,array[i].lastname,MAX_CHARS_CADENAS);
							memcpy(array[i].lastname,array[j].lastname,MAX_CHARS_CADENAS);
							memcpy(array[j].lastname,aux.lastname,MAX_CHARS_CADENAS);

							memcpy(aux.name,array[i].name,MAX_CHARS_CADENAS);
							memcpy(array[i].name,array[j].name,MAX_CHARS_CADENAS);
							memcpy(array[j].name,aux.name,MAX_CHARS_CADENAS);

							memcpy(aux.flycode,array[i].flycode,MAX_CHARS_CADENAS);
							memcpy(array[i].flycode,array[j].flycode,MAX_CHARS_CADENAS);
							memcpy(array[j].flycode,aux.flycode,MAX_CHARS_CADENAS);

							aux.idPassenger = array[i].idPassenger;
							array[i].idPassenger = array[j].idPassenger;
							array[j].idPassenger = aux.idPassenger;

							aux.isEmpty = array[i].isEmpty;
							array[i].isEmpty = array[j].isEmpty;
							array[j].isEmpty = aux.isEmpty;

							aux.typePassenger = array[i].typePassenger;
							array[i].typePassenger = array[j].typePassenger;
							array[j].typePassenger = aux.typePassenger;

							aux.price = array[i].price;
							array[i].price = array[j].price;
							array[j].price = aux.price;

							aux.statusFlight = array[i].statusFlight;
							array[i].statusFlight = array[j].statusFlight;
						    array[j].statusFlight = aux.statusFlight;

						}
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}



int ePassenger_ObtenerIndexLibre(ePassenger array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
void ePassenger_MostrarUnoEstado(ePassenger Passenger) {
	//PRINTF DE UN SOLO Passenger
	printf("%d", Passenger.idPassenger);
	if (Passenger.typePassenger == TIPO_COMERCIAL) {
		printf("  %20s", "COMERCIAL    ");
	}
	else
	{
		if(Passenger.typePassenger == TIPO_EJECUTIVO)
		{
			printf("  %20s", "EJECUTIVO    ");
		}
		else
		{
			printf("  %20s", "PRIMERA CLASE");
		}
	}


	printf("\t$%.2f", Passenger.price);
	printf("\t%-10s", Passenger.name);
	printf("\t%-5s   ", Passenger.lastname);
	printf("\t%-10s", Passenger.flycode);
	if(Passenger.statusFlight==ACTIVO)
	{
		printf("  %10s", "\tACTIVO\n");
	}
	else
	{
		printf("  %10s", "\tINACTIVO\n");
	}

}

void ePassenger_MostrarUno(ePassenger Passenger) {
	//PRINTF DE UN SOLO Passenger
	printf("%5d", Passenger.idPassenger);
	if (Passenger.typePassenger == TIPO_COMERCIAL) {
		printf("  %5s", "COMERCIAL    ");
	}
	else
	{
		if(Passenger.typePassenger == TIPO_EJECUTIVO)
		{
			printf("  %5s", "EJECUTIVO    ");
		}
		else
		{
			printf("  %5s", "PRIMERA CLASE");
		}
	}


	printf("\t    $%.2f", Passenger.price);
	printf("\t\t%3s", Passenger.name);
	printf("\t\t%3s", Passenger.lastname);
	printf("\t\t%3s", Passenger.flycode);


}


int ePassenger_MostrarDadosDeBaja(ePassenger array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> PASAJEROS ESTADO BAJA.\n");
	printf("%5s\n\n", "ID\t\tTIPO\t\tPRECIO\t\tNOMBRE \t\tAPELLIDO\tFLYCODE\t\tESTADO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "ACTIVO"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Passenger
				ePassenger_MostrarUnoEstado(array[i]);
				//CONTADOR DE Passenger
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Passenger PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}



int MostrarEstadoActivo(ePassenger array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> PASAJEROS ORDENADOS .\n");
	printf("%5s\n\n", "ID\t\tTIPO\t\tPRECIO\t\tNOMBRE \t\tAPELLIDO\tFLYCODE\t\tESTADO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "ACTIVO"
			if (array[i].statusFlight == ACTIVO) {
				//MUESTRO UN SOLO Passenger
				ePassenger_MostrarUnoEstado(array[i]);
				//CONTADOR DE Passenger
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Passenger PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

ePassenger ePassenger_CargarDatos(void) {
	ePassenger auxiliar;

	int opcion;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

		utn_getString("NOMBRE DE PASAJERO: ", "ERROR. INTENTE NUEVAMENTE  ", 3, MAX_CHARS_CADENAS,auxiliar.name);
		utn_getString("APELLIDO: ", "ERROR. INTENTE NUEVAMENTE  ", 3, MAX_CHARS_CADENAS,auxiliar.lastname);
		utn_getTexto("CODIGO: ", "ERROR. INTENTE NUEVAMENTE  ", 3, MAX_CHARS_CADENAS,auxiliar.flycode);
		utn_getFloat("PRECIO: ", "ERROR.  ", 1, 1000000, 3, &auxiliar.price);
		puts("INGRESE TIPO DE PASAJERO");
		puts("1) COMERCIAL");
		puts("2) EJECUTIVO");
		puts("3) PRIMERA CLASE");
		if(utn_getNumero("OPCION: ", "ERROR. ", 0, 3, 3, &opcion)==0)
		{
		switch (opcion) {
		case 1:
			auxiliar.typePassenger = TIPO_COMERCIAL;
			break;
		case 2:
			auxiliar.typePassenger = TIPO_EJECUTIVO;
			break;
		case 3:
			auxiliar.typePassenger = TIPO_PRIMERACLASE;
			break;
		}
		}


	return auxiliar;
}

ePassenger ePassenger_ModificarUno(ePassenger Passenger) {
	ePassenger auxiliar=Passenger;
	int opcion;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	utn_getString("NOMBRE DE PASAJERO: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.name);
	utn_getString("APELLIDO: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.lastname);
	utn_getTexto("CODIGO: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.flycode);
	utn_getFloat("PRECIO: ", "ERROR.", 1, 1000000, 3, &auxiliar.price);
	puts("INGRESE TIPO DE PASAJERO");
	puts("1) COMERCIAL");
	puts("2) EJECUTIVO");
	puts("3) PRIMERA CLASE");
	if(utn_getNumero("OPCION: ", "ERROR. ", 1, 3, 3, &opcion)==0)
	{
	switch (opcion) {
	case 1:
		auxiliar.typePassenger = TIPO_COMERCIAL;
		break;
	case 2:
		auxiliar.typePassenger = TIPO_EJECUTIVO;
		break;
	case 3:
		auxiliar.typePassenger = TIPO_PRIMERACLASE;
		break;
	}
	}
	return auxiliar;
}
int ePassenger_Alta(ePassenger array[], int TAM) {
	int rtn = 0;
	ePassenger auxPassenger;

	//BUSCO ESPACIO EN ARRAY
	int index = ePassenger_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Passenger AUXILIAR
		auxPassenger = ePassenger_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPassenger.idPassenger = ePassenger_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPassenger.isEmpty = OCUPADO;
		auxPassenger.statusFlight=ACTIVO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPassenger;
		if(addPassenger(array, TAM, 100, auxPassenger.name, auxPassenger.lastname, auxPassenger.price, auxPassenger.typePassenger, auxPassenger.flycode)==1)
		{
			rtn = 1;
		}
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	/*	if(array!=NULL && TAM>0 && auxPassenger.name!=NULL && auxPassenger.lastname!=NULL && auxPassenger.price>0 && auxPassenger.typePassenger>0 && auxPassenger.flycode!=NULL)
		{
			rtn = 1;
		}*/

	}

	return rtn;
}





int ePassenger_Baja(ePassenger array[], int TAM) {
	int rtn = 0;
	int id;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Passenger
	if (printPassenger(array, TAM)) {
		//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Passenger PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
	utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. INTENTE NUEVAMENTE: ", 1, 1000000, 3, &id);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, TAM, id) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. INTENTE NUEVAMENTE: ", 1, 1000000, 3, &id);
		}

		//OBTENGO INDEX DEL ARRAY DE Passenger A DAR DE BAJA
		index = findPassengerById(array, TAM, id);
		if(removePassenger(array,TAM,id)==1)
		{
			/**PREGUNTAR SI DESEA CONTINUAR*/
			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			array[index].isEmpty = BAJA;
			array[index].statusFlight=0;

			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			rtn = 1;
		}

	}

	return rtn;
}

int ePassenger_Modificacion(ePassenger array[], int TAM) {
	int rtn = 0;
	int idPassenger;
	int index;
	int flag = 0;
	ePassenger auxiliar;

	//LISTO TODOS LOS Passenger
	if (printPassenger(array, TAM)) {
		//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Passenger0 PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero("INGRESE ID A MODIFICAR: ", "ERROR. INTENTE NUEVAMENTE: ", 1, 1000000, 3, &idPassenger);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, TAM, idPassenger) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero("INGRESE ID A MODIFICAR: ", "ERROR. INTENTE NUEVAMENTE: ", 1, 1000000, 3, &idPassenger);
		}

		//OBTENGO INDEX DEL ARRAY DE Passenger A MODIFICAR
		index = findPassengerById(array, TAM, idPassenger);

		//LLAMO A FUNCION QUE MODIFICA Passenger
		auxiliar = ePassenger_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}




int ePassenger_Sort(ePassenger array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePassenger aux;


	/** EJEMPLO DE SORT CON ID DE Passenger
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].typePassenger > array[j].typePassenger) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].typePassenger < array[j].typePassenger) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

float CalcularPromedio (float suma, float cantidad)
{
	int rtn=-1;
	float promedio;
	if(cantidad>0 && suma >=0)
	{
		promedio=suma/cantidad;
		rtn=promedio;
	}


	return rtn;
}

int acumuladorPrecioPasajes (ePassenger array[], int TAM)
{
	float rtn=-1;
	int i;
	float acumuladorPreciosPasajes=0;

	if(array!=NULL && TAM>0)
	{

		for(i=0;i<TAM;i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				acumuladorPreciosPasajes+=array[i].price;
			}
		}

		rtn=acumuladorPreciosPasajes;
	}

	return rtn;
}

int CuantosSuperanPrecioPromedio (ePassenger array[], int TAM, float promedio)
{
	float rtn=-1;
	int i;
	int contadorMayoresPrecioPromedio=0;

	if(array!=NULL && TAM>0 && promedio>0)
	{
		for(i=0;i<TAM;i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				if(array[i].price > promedio)
				{
					contadorMayoresPrecioPromedio++;
					rtn=0;

				}
			}
		}
	}
	printf("\nCANTIDAD DE PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO: %d\n",contadorMayoresPrecioPromedio);
	puts("\n----------------------------------------------------------------------------------------------------------------\n");
	return rtn;
}





