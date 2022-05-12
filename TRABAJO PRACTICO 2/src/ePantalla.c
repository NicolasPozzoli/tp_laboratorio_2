#include "ePantalla.h"
#include "Input.h"
static int ePantalla_ObtenerID(void);
static int ePantalla_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION ePantalla_ObtenerID();
	static int Pantalla_idIncremental = 100;
	return Pantalla_idIncremental++;
}

void ePantalla_Inicializar(ePantalla array[], int TAM) {
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

int ePantalla_ObtenerIndexLibre(ePantalla array[], int TAM) {
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

int ePantalla_BuscarPorID(ePantalla array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idPantalla == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void ePantalla_MostrarUno(ePantalla Pantalla) {
	//PRINTF DE UN SOLO Pantalla
	printf("%5d", Pantalla.idPantalla);
	if (Pantalla.tipo == TIPO_LCD) {
		printf("%5s", "LCD");
	} else {
		printf("%5s", "LED");
	}
	printf("\t$%d", Pantalla.precioPorDia);
	printf("\t%3s", Pantalla.nombre);
	printf("\t%3s\n", Pantalla.direccion);
}

int ePantalla_MostrarTodos(ePantalla array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Pantalla");
	printf("%5s\n\n", "ID\tTIPO\tPRECIO\tNOMBRE \tDIRECCION"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int ePantalla_MostrarDadosDeBaja(ePantalla array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Pantalla\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

ePantalla ePantalla_CargarDatos(void) {
	ePantalla auxiliar;
	int resultado2;
	int opcion;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	utn_getString("NOMBRE DE PANTALLA: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.nombre);
	utn_getString("DIRECCION: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.direccion);
	utn_getNumero("PRECIO POR DIA: ", "ERROR.", 1, 1000000, 3, &auxiliar.precioPorDia);
	puts("INGRESE TIPO");
	puts("1) LED");
	puts("2) LCD");
	if(utn_getNumero("OPCION: ", "ERROR. ", 1, 2, 3, &opcion)==0)
	{
	switch (opcion) {
	case 1:
		auxiliar.tipo = TIPO_LED;
		break;
	case 2:
		auxiliar.tipo = TIPO_LCD;
		break;
	}
	}
	return auxiliar;
}

ePantalla ePantalla_ModificarUno(ePantalla Pantalla) {
	ePantalla auxiliar=Pantalla;
	int opcion;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	utn_getString("NOMBRE DE PANTALLA: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.nombre);
	utn_getString("DIRECCION: ", "ERROR. INTENTE NUEVAMENTE", 3, MAX_CHARS_CADENAS,auxiliar.direccion);
	utn_getNumero("PRECIO POR DIA: ", "ERROR.", 1, 1000000, 3, &auxiliar.precioPorDia);
	puts("INGRESE TIPO");
	puts("1) LED");
	puts("2) LCD");
	if(utn_getNumero("OPCION: ", "ERROR. ", 1, 2, 3, &opcion)==0)
	{
	switch (opcion) {
	case 1:
		auxiliar.tipo = TIPO_LED;
		break;
	case 2:
		auxiliar.tipo = TIPO_LCD;
		break;
	}
	}
	return auxiliar;
}

int ePantalla_Alta(ePantalla array[], int TAM) {
	int rtn = 0;
	ePantalla auxPantalla;

	//BUSCO ESPACIO EN ARRAY
	int index = ePantalla_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Pantalla AUXILIAR
		auxPantalla = ePantalla_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPantalla.idPantalla = ePantalla_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPantalla.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPantalla;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePantalla_Baja(ePantalla array[], int TAM) {
	int rtn = 0;
	int idPantalla;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Pantalla
	if (ePantalla_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, TAM, idPantalla) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPantalla);
		}

		//OBTENGO INDEX DEL ARRAY DE Pantalla A DAR DE BAJA
		index = ePantalla_BuscarPorID(array, TAM, idPantalla);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePantalla_Modificacion(ePantalla array[], int TAM) {
	int rtn = 0;
	int idPantalla;
	int index;
	int flag = 0;
	ePantalla auxiliar;

	//LISTO TODOS LOS Pantalla
	if (ePantalla_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla0 PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A MODIFICAR: ");    //MODIFICADO
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, TAM, idPantalla) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A MODIFICAR: ");
			scanf("%d", &idPantalla);
		}

		//OBTENGO INDEX DEL ARRAY DE Pantalla A MODIFICAR
		index = ePantalla_BuscarPorID(array, TAM, idPantalla);

		//LLAMO A FUNCION QUE MODIFICA Pantalla
		auxiliar = ePantalla_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePantalla_Sort(ePantalla array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePantalla aux;

	/** EJEMPLO DE SORT CON ID DE Pantalla
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
						if (array[i].idPantalla > array[j].idPantalla) {
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
						if (array[i].idPantalla < array[j].idPantalla) {
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
