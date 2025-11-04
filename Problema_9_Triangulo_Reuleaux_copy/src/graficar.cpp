/**
 * @file graficar.cpp
 * @brief Genera una gráfica de la trayectoria de la partícula confinada en una figura geométrica.
 *
 * Este módulo ejecuta comandos de Gnuplot desde C++ para producir una imagen en formato PNG
 * que muestra la trayectoria de la partícula en el triángulo de Reuleaux, a partir de los datos
 * generados durante la simulación numérica.
 *
 * @date 2025-11-04
 * @version 1.0
 */

#include <cstdlib>
#include <string>
using namespace std;

/**
 * @brief Genera una gráfica PNG de la trayectoria de la partícula.
 *
 * Esta función construye una instrucción de Gnuplot mediante un comando del sistema
 * que grafica los datos de posición almacenados en un archivo de texto (`archivoDatos`)
 * y los exporta como una imagen PNG (`archivoSalida`).
 *
 * El gráfico muestra el desplazamiento de la partícula en el plano XY y utiliza
 * una relación de aspecto 1:1 para conservar la forma geométrica del triángulo de Reuleaux.
 *
 * @param archivoDatos  Ruta del archivo que contiene los datos de la simulación (formato texto, columnas: t x y).
 * @param archivoSalida Ruta del archivo de salida donde se guardará la imagen PNG generada.
 *
 * @note Requiere tener instalado **Gnuplot** y que el ejecutable esté disponible en el PATH del sistema.
 * @warning Si Gnuplot no está instalado o el archivo de datos no existe, no se generará la gráfica.
 */
void graficarDatos(const string &archivoDatos, const string &archivoSalida) {
    string comando = "gnuplot -e \"set terminal png size 800,800; "
                     "set output '" + archivoSalida + "'; "
                     "set title 'Trayectoria en Triangulo de Reuleaux'; "
                     "set xlabel 'x (m)'; set ylabel 'y (m)'; set grid; "
                     "set size ratio -1; "
                     "plot '" + archivoDatos + "' using 2:3 with lines lw 2 lc rgb 'blue' title 'Trayectoria'\"";
    system(comando.c_str());
}
