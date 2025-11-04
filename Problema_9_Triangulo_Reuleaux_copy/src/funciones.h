/**
 * @file funciones.h
 * @brief Declaración e implementación de funciones auxiliares para la solicitud y validación de datos.
 *
 * Este archivo contiene funciones de entrada y validación utilizadas en el programa principal
 * para obtener los parámetros necesarios en la simulación del movimiento de una partícula
 * confinada dentro de figuras geométricas 2D.
 *
 * @date 2025-11-04
 * @version 1.0
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

/**
 * @brief Solicita al usuario los parámetros de entrada para la simulación.
 *
 * Esta función pide por consola los valores iniciales necesarios para el cálculo del movimiento
 * de la partícula, incluyendo dimensiones geométricas, posiciones y velocidades iniciales,
 * así como los tiempos de simulación y el paso temporal.
 *
 * @param L   Longitud característica de la figura geométrica (por ejemplo, el lado del triángulo de Reuleaux).
 * @param x0  Posición inicial de la partícula en el eje X (m).
 * @param y0  Posición inicial de la partícula en el eje Y (m).
 * @param vx0 Velocidad inicial de la partícula en el eje X (m/s).
 * @param vy0 Velocidad inicial de la partícula en el eje Y (m/s).
 * @param t0  Tiempo inicial de la simulación (s).
 * @param tf  Tiempo final de la simulación (s).
 * @param dt  Paso de tiempo utilizado en la integración (s).
 *
 * @note La función no realiza validación; únicamente recopila los valores introducidos por el usuario.
 */
inline void solicitarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                           double &t0, double &tf, double &dt) {
    cout << "Longitud del lado L (m): ";
    cin >> L;
    cout << "Posicion inicial x0 (m): ";
    cin >> x0;
    cout << "Posicion inicial y0 (m): ";
    cin >> y0;
    cout << "Velocidad inicial vx0 (m/s): ";
    cin >> vx0;
    cout << "Velocidad inicial vy0 (m/s): ";
    cin >> vy0;
    cout << "Tiempo inicial t0 (s): ";
    cin >> t0;
    cout << "Tiempo final tf (s): ";
    cin >> tf;
    cout << "Paso de tiempo dt (s): ";
    cin >> dt;
}

/**
 * @brief Verifica y corrige los valores introducidos por el usuario.
 *
 * Esta función valida que los parámetros de entrada sean coherentes y físicamente posibles.
 * En caso de detectar valores inválidos (como longitudes o pasos de tiempo negativos),
 * se asignan valores por defecto razonables para garantizar la estabilidad de la simulación.
 *
 * @param L   Longitud característica de la figura geométrica.
 * @param x0  Posición inicial en X.
 * @param y0  Posición inicial en Y.
 * @param vx0 Velocidad inicial en X.
 * @param vy0 Velocidad inicial en Y.
 * @param t0  Tiempo inicial.
 * @param tf  Tiempo final.
 * @param dt  Paso temporal.
 *
 * @note Si `L <= 0`, se fija L = 1.
 * @note Si `dt <= 0`, se fija dt = 0.01.
 * @note Si `tf <= t0`, se ajusta `tf = t0 + 1`.
 */
inline void validarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                         double &t0, double &tf, double &dt) {
    if (L <= 0) L = 1;
    if (dt <= 0) dt = 0.01;
    if (tf <= t0) tf = t0 + 1;
}

#endif
