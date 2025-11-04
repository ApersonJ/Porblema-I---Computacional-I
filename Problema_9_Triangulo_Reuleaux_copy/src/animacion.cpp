/**
 * @file animacion.cpp
 * @brief Genera una animación en formato GIF de la trayectoria de la partícula.
 *
 * Este módulo ejecuta un script de Gnuplot (`results/animacion.plt`) que crea
 * la animación correspondiente al movimiento simulado de la partícula confinada
 * en la figura geométrica seleccionada (en este caso, el triángulo de Reuleaux).
 * El resultado se guarda como un archivo GIF en el directorio `results/`.
 *
 * @date 2025-11-04
 * @version 1.0
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/**
 * @brief Genera la animación de la trayectoria de la partícula.
 *
 * Esta función utiliza el comando del sistema para ejecutar Gnuplot con el script
 * `results/animacion.plt`. Dicho script debe leer los datos de posición generados
 * por la simulación (`datos.dat`) y producir un archivo de animación (`.gif`)
 * que muestre la trayectoria de la partícula dentro de la figura geométrica.
 *
 * @param archivoDatos Ruta al archivo de datos generado por la simulación.
 * @param archivoGif Ruta donde se guardará la animación en formato GIF.
 *
 * @note El archivo `animacion.plt` debe existir y estar correctamente configurado
 *       para leer los datos y generar el GIF con los comandos de Gnuplot.
 * @warning Si Gnuplot no está instalado o no se encuentra en el PATH del sistema,
 *          la animación no podrá generarse.
 */
void generarAnimacion(const string &archivoDatos, const string &archivoGif) {
    cout << "\nGenerando animacion...\n";
    system("gnuplot results/animacion.plt");
    cout << "Animacion generada: " << archivoGif << endl;
}
