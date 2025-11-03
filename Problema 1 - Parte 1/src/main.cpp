//main.cpp

#include <iostream>
#include "../include/funciones.h"

using namespace std;

/**
 * @file main.cpp
 * @brief Programa principal que simula el movimiento parabólico en 3D y genera las gráficas correspondientes.
 *
 * Este archivo contiene la función principal que solicita los datos iniciales,
 * valida las condiciones del sistema, realiza la simulación del movimiento del proyectil
 * respecto a la esfera, y genera los resultados en archivos de datos, imágenes y animaciones.
 */

/**
 * @brief Función principal del programa.
 *
 * Llama a las funciones necesarias para:
 * - Solicitar los datos iniciales del proyectil y la esfera.
 * - Validar los datos ingresados.
 * - Simular el movimiento del proyectil.
 * - Generar gráficos y animaciones de la trayectoria.
 *
 * @return int Código de salida del programa. Retorna 0 si la ejecución fue exitosa.
 */
int main() {
    double x0, y0, z0, vx0, vy0, vz0;	///< Condiciones iniciales del proyectil: posición y velocidad
	double R, xc, yc, zc;				///< Condiciones de la esfera: radio y coordenadas del centro
    double dt;							///< Paso temporal de la simulación

    solicitarDatos(x0, y0, z0, vx0, vy0, vz0, R, xc, yc, zc, dt);
    validarDatos(x0, y0, z0, R, xc, yc, zc, dt);
    simularMovimiento(x0, y0, z0, vx0, vy0, vz0, R, xc, yc, zc, dt, "../results/datosParcial1.1.dat" );

    // Generar PNG, GIF y abrir ventana interactiva con Gnuplot
    graficarDatos("../results/datosParcial1.1.dat", "../results/Parcial1.1_grafico.png", 
				  "../results/Parcial1.1_grafico_x(t).png", "../results/Parcial1.1_grafico_y(t).png", "../results/Parcial1.1_grafico_z(t).png");

    generarAnimacion("../results/datosParcial1.1.dat", "../results/Parcial1.1Animacion.gif");

    return 0;
}
