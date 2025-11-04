/**
 * @file main.cpp
 * @brief Programa principal para la simulación del movimiento de una partícula confinada en un triángulo de Reuleaux.
 *
 * Este archivo contiene la función principal del programa, que coordina la ejecución de las diferentes
 * etapas del experimento computacional: solicitud de datos, simulación del movimiento, graficación
 * de resultados y generación de una animación en formato GIF.
 *
 * @date 2025-11-04
 * @version 1.0
 */

#include "funciones.h"
#include <iostream>
using namespace std;

// Declaraciones de las funciones implementadas en otros módulos
void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt);
void graficarDatos(const string &archivoDatos, const string &archivoSalida);
void generarAnimacion(const string &archivoDatos, const string &archivoGif);

/**
 * @brief Función principal del programa.
 *
 * Esta función ejecuta el flujo completo del experimento computacional para una partícula confinada
 * dentro de un triángulo de Reuleaux. El proceso incluye:
 * - Solicitud de los parámetros de entrada al usuario.
 * - Validación de los datos ingresados.
 * - Simulación numérica del movimiento de la partícula.
 * - Generación de una gráfica con la trayectoria obtenida.
 * - Creación de una animación GIF que muestra la evolución temporal del sistema.
 *
 * @return 0 si la ejecución finaliza correctamente.
 *
 * @note El programa requiere que **Gnuplot** esté instalado y accesible desde el sistema para generar las gráficas y la animación.
 * @warning Si las rutas de salida no existen o Gnuplot no está configurado, los archivos de resultados podrían no generarse.
 */
int main() {
    double L, x0, y0, vx0, vy0, t0, tf, dt;

    // Entrada y validación de parámetros
    solicitarDatos(L, x0, y0, vx0, vy0, t0, tf, dt);
    validarDatos(L, x0, y0, vx0, vy0, t0, tf, dt);

    // Simulación del movimiento de la partícula confinada
    simularMovimiento(L, x0, y0, vx0, vy0, t0, tf, dt);

    // Generación de la gráfica de la trayectoria
    graficarDatos("results/datos.dat", "results/reuleaux_trayectoria.png");

    // Generación de la animación GIF de la trayectoria
    cout << "Cierra la ventana de la grafica para generar la animacion..." << endl;
    generarAnimacion("results/datos.dat", "results/reuleaux_anim.gif");

    return 0;
}
