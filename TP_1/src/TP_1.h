/*
 * TP_1.h
 *
 *  Created on: Apr 15, 2022
 *      Author: natalia.forclaz
 */

#ifndef TP_1_H_
#define TP_1_H_

/**
 * @brief Este es el Menú principal
 * @return La opción a seleccionar en el Menú
 */
int menuPrincipal();

/**
 * @brief Muestra los resultados ingresados
 * @param Muestra valor 'empresa' si es Aerolineas o Latam
 * @param Muestra valor 'precio' segun la empresa ingresada
 * @param Muestra valor 'debito' segun la empresa ingresada
 * @param Muestra valor 'credito' segun la empresa ingresada
 * @param Muestra valor 'bitcoin' segun la empresa ingresada
 * @param Muestra valor 'tramo' segun los km ingresados
 */
void informe(char empresa[],float precio, float debito, float credito, double bitcoin, float tramo);

/**
 * @brief Imprime un salto de linea
 */
void saltoDeLinea();

/**
 * @brief Imprime separador/decorado
 */
void decorado();

/**
 * @brief Imprime mensaje de Error para los cases
 */
void mensajeError();

/**
 * @brief Seleccionar que tipo de dato quiero usar
 * @param mensaje que va a mostrar
 * @return El tipo de dato ingresado (float)
 */
float ingresarDato(char mensaje[]);

/**
 * @brief Toma el valor 'precio' y realiza los calculos correspondientes
 * @param 'precio' segun que empresa
 * @param 'calculo' operacion que multiplica (descuento, recargo, etc)
 * @return resultado de la operacion
 */
float calculoPrecio(float precio, float calculo);

/**
 * @brief Calcula la diferencia (resta) de 2 valores
 * @param precioAero valor de precio para Aerolineas
 * @param precioLata valor de precio para Latam
 * @return el resultado del 'calculo'
 */
float calculoDiferencia(float precioAero, float precioLata);

#endif /* TP_1_H_ */


