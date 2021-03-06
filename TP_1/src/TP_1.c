/*
 ============================================================================
 Name        : TP_1.c
 Author      : Natalia Forclaz
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Librerias
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include "TP_1.h"

//Constantes
#define AEROLINEAS "Aerolineas"
#define LATAM "Latam"
#define BTC 4606954.55
#define KM 7090
#define PRECIO_A 162965
#define PRECIO_L 159339

//Funciones utilizadas
int menuPrincipal() {
	int option;
	printf("\n----------->MAIN MENU<-----------");
	printf("\n");
	printf("\n1. Ingresar Kilometros");
	printf("\n2. Ingresar Precio de Vuelos");
	printf("\n3. Calcular todos los costos");
	printf("\n4. Informar Resultados");
	printf("\n5. Carga forzada de datos");
	printf("\n6. SALIR");
	printf("\n");
	printf("\nOpcion a elegir: ");
	__fpurge(stdin);
	scanf("%d", &option);

	return option;
}

void informe(char empresa[], float precio, float debito, float credito,
		double bitcoin, float tramo) {
	printf("\n%s: $%.2f", empresa, precio);
	printf("\na) Precio con tarjeta de debito: $%.2f", debito);
	printf("\nb) Precio con tarjeta de credito: $%.2f", credito);
	printf("\nc) Precio pagando con bitcoins: %lf BTC", bitcoin);
	printf("\nd) Precio unitario: $%.2f", tramo);
}

void saltoDeLinea() {
	printf("\n");
}

void decorado() {
	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
}

void mensajeError() {
	printf("\nERROR# Revisa lo que hiciste...");
}

void simularPausa() {
	char tecla;
	do {
		printf("\n------------> Presiona 's' para continuar... ");
		__fpurge(stdin);
		scanf("%c", &tecla);
	} while (tecla != 's');

}

void mensajeSistema() {
	//Para LINUX OS
	system("sleep 1");
	system("echo  -----------------------------------");
	system("sleep 1.5s");
	system("echo  -  - Developed by Natt Forclaz -  -");
	system("sleep 1.5s");
	system("echo  -----------------------------------");
	system("sleep 5s");
	system("clear");
}

float ingresarDato(char mensaje[]) {
	float dato = 0;
	do {
		printf("\n%s", mensaje);
		__fpurge(stdin);
		scanf("%f", &dato);
	} while (dato <= 0);

	return dato;
}

float calculoPrecio(float precio, float calculo) {
	float resultado;
	resultado = precio * calculo;

	return resultado;
}

float calculoDiferencia(float precioAero, float precioLata) {
	float calculo = 0;
	if (precioAero > precioLata) {
		calculo = precioAero - precioLata;
	} else if (precioAero < precioLata) {
		calculo = precioLata - precioAero;
	}

	return calculo;
}

int main(void) {
	setbuf(stdout, NULL);

//Declaracion de variables
	int option;
	float km;
	float precioAerolineas;
	float precioLatam;
	float debitoAerolineas;
	float debitoLatam;
	float creditoAerolineas;
	float creditoLatam;
	double btcAerolineas;
	double btcLatam;
	float tramoAerolineas;
	float tramoLatam;
	float diferencia;

	short flagCase1;
	short flagCase2;
	short flagCase3;

	do {
		option = menuPrincipal();

		switch (option) {
		case 1:
			km = ingresarDato("\nIngrese cantidad de KM: ");
			printf("\nKilometros ingresados %.2f", km);
			flagCase1 = 1;
			break;
		case 2:
			if (flagCase1) {
				precioAerolineas = ingresarDato(
						"\nIngrese el precio para Aerolineas: $");
				precioLatam = ingresarDato("\nIngrese el precio para Latam: $");
				printf("\nValor de %s %.2f", AEROLINEAS, precioAerolineas);
				__fpurge(stdin);
				printf("\nValor de %s %.2f", LATAM, precioLatam);
				__fpurge(stdin);
				flagCase2 = 1;
			} else {
				mensajeError();
			}
			break;
		case 3:
			if (flagCase2) {
				printf("\nCalculando precios...");

				//Debito
				debitoAerolineas = calculoPrecio(precioAerolineas, 0.9);
				debitoLatam = calculoPrecio(precioLatam, 0.9);

				//Credito
				creditoAerolineas = calculoPrecio(precioAerolineas, 1.25);
				creditoLatam = calculoPrecio(precioLatam, 1.25);

				//Bitcoins
				btcAerolineas = calculoPrecio(precioAerolineas,
						(precioAerolineas / BTC) / precioAerolineas);
				btcLatam = calculoPrecio(precioLatam,
						(precioAerolineas / BTC) / precioAerolineas);

				//Precio tramo
				tramoAerolineas = calculoPrecio(precioAerolineas,
						(precioAerolineas / km) / precioAerolineas);
				tramoLatam = calculoPrecio(precioLatam,
						(precioLatam / km) / precioLatam);

				//Diferencia
				diferencia = calculoDiferencia(precioAerolineas, precioLatam);

				saltoDeLinea();
				simularPausa();
				printf("\nCalculos realizados!");
				flagCase3 = 1;
			} else {
				mensajeError();
			}
			break;
		case 4:
			if (flagCase3) {
				printf("\nKMs ingresados %.2f km", km);
				saltoDeLinea();
				informe(LATAM, precioLatam, debitoLatam, creditoLatam, btcLatam,
						tramoLatam);
				saltoDeLinea();
				informe(AEROLINEAS, precioAerolineas, debitoAerolineas,
						creditoAerolineas, btcAerolineas, tramoAerolineas);
				saltoDeLinea();
				printf("\nLa diferencia de precio es: $%.2f", diferencia);
			} else {
				mensajeError();
			}

			saltoDeLinea();
			simularPausa();
			break;
		case 5:
			km = KM;
			precioAerolineas = PRECIO_A;
			precioLatam = PRECIO_L;

			//Debito
			debitoAerolineas = calculoPrecio(precioAerolineas, 0.9);
			debitoLatam = calculoPrecio(precioLatam, 0.9);

			//Credito
			creditoAerolineas = calculoPrecio(precioAerolineas, 1.25);
			creditoLatam = calculoPrecio(precioLatam, 1.25);

			//Bitcoins
			btcAerolineas = calculoPrecio(precioAerolineas,
					(precioAerolineas / BTC) / precioAerolineas);
			btcLatam = calculoPrecio(precioLatam,
					(precioAerolineas / BTC) / precioAerolineas);

			//Precio por tramo (unitario)
			tramoAerolineas = calculoPrecio(precioAerolineas,
					(precioAerolineas / km) / precioAerolineas);
			tramoLatam = calculoPrecio(precioLatam,
					(precioLatam / km) / precioLatam);

			//Diferencia
			diferencia = calculoDiferencia(precioAerolineas, precioLatam);

			printf("\nKMs ingresados %.2f km", km);
			saltoDeLinea();
			informe(LATAM, precioLatam, debitoLatam, creditoLatam, btcLatam,
					tramoLatam);
			saltoDeLinea();
			informe(AEROLINEAS, precioAerolineas, debitoAerolineas,
					creditoAerolineas, btcAerolineas, tramoAerolineas);
			saltoDeLinea();
			printf("\nLa diferencia de precio es: $%.2f", diferencia);

			saltoDeLinea();
			simularPausa();
			break;
		case 6:
			printf("\nCon esta opcion decidiste SALIR del programa... SALUDOS");
			break;
		default:
			printf("ERROR# La opcion ingresada no es valida");
			break;
		}
		decorado();

	} while (option != 6);

	mensajeSistema();
	return EXIT_SUCCESS;
}
