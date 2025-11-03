/**
 * @file animacion.cpp
 * @brief Genera una animación en 3D del movimiento parabólico de una partícula sobre una semiesfera.
 * 
 * Este archivo crea un script de Gnuplot que produce un GIF animado de la trayectoria
 * de una partícula en movimiento parabólico tridimensional. La animación muestra tanto la
 * trayectoria acumulada como la posición actual del objeto en cada instante.
 */

#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

/**
 * @brief Genera un archivo de animación GIF mostrando el movimiento parabólico en 3D.
 * 
 * La función crea un script de Gnuplot que dibuja cuadro por cuadro la trayectoria
 * acumulada de una partícula hasta un punto determinado, junto con la representación
 * de una semiesfera de referencia. Cada fotograma se agrega a un GIF animado.
 * 
 * @param nombreArchivo Ruta al archivo de datos que contiene la información de la trayectoria y la semiesfera.
 * @param gifSalida Nombre del archivo GIF de salida donde se guardará la animación generada.
 * 
 * @note El script de Gnuplot se guarda en la carpeta "../scripts/" con el nombre "animate_Parabolic3D.gp".
 * @warning Es necesario tener instalado Gnuplot en el sistema para ejecutar correctamente la animación.
 */
void generarAnimacion(const string &nombreArchivo, const string &gifSalida) {
    ofstream gp("../scripts/animate_Parabolic3D.gp");

    gp << "# ===== AnimaciÃ³n 3D =====\n";
    gp << "datafile='" << nombreArchivo << "'\n";
    gp << "giffile='" << gifSalida << "'\n\n";

    gp << "set terminal gif animate delay 6 size 900,600\n";
    gp << "set output giffile\n";
    gp << "set title 'Movimiento Parabolico en 3D'\n";
    gp << "set xlabel 'x(m)'\n";
    gp << "set ylabel 'y(m)'\n";
    gp << "set zlabel 'z(m)'\n";
    gp << "set grid\n\n";

    // Vista igual que el PNG y escalas iguales en los 3 ejes
    gp << "set view 60, 45\n";
    gp << "set view equal xyz\n";
    gp << "set ticslevel 0\n";          // z=0
    gp << "set key outside\n\n";        // leyenda fuera

    // EstadÃ­sticas del bloque 0 (trayectoria)
    gp << "stats datafile index 0 using 2 nooutput\n";
    gp << "xmin1 = STATS_min; xmax1 = STATS_max\n";
    gp << "stats datafile index 0 using 3 nooutput\n";
    gp << "ymin1 = STATS_min; ymax1 = STATS_max\n";
    gp << "stats datafile index 0 using 4 nooutput\n";
    gp << "zmin1 = STATS_min; zmax1 = STATS_max\n\n";

    // EstadÃ­sticas del bloque 1 (semiesfera)
    gp << "stats datafile index 1 using 1 nooutput\n";
    gp << "xmin2 = STATS_min; xmax2 = STATS_max\n";
    gp << "stats datafile index 1 using 2 nooutput\n";
    gp << "ymin2 = STATS_min; ymax2 = STATS_max\n";
    gp << "stats datafile index 1 using 3 nooutput\n";
    gp << "zmin2 = STATS_min; zmax2 = STATS_max\n\n";

    // Combinar rangos para cubrir ambos conjuntos
    gp << "xmin = (xmin1 < xmin2) ? xmin1 : xmin2\n";
    gp << "xmax = (xmax1 > xmax2) ? xmax1 : xmax2\n";
    gp << "ymin = (ymin1 < ymin2) ? ymin1 : ymin2\n";
    gp << "ymax = (ymax1 > ymax2) ? ymax1 : ymax2\n";
    gp << "zmin = (zmin1 < zmin2) ? zmin1 : zmin2\n";
    gp << "zmax = (zmax1 > zmax2) ? zmax1 : zmax2\n\n";

    gp << "dx = (xmax - xmin)*0.05\n";
    gp << "dy = (ymax - ymin)*0.05\n";
    gp << "dz = (zmax - zmin)*0.05\n";
    gp << "set xrange [xmin - dx : xmax + dx]\n";
    gp << "set yrange [ymin - dy : ymax + dy]\n";
    gp << "set zrange [zmin - dz : zmax + dz]\n\n";

    // NÃºmero de registros vÃ¡lidos del bloque 0 (trayectoria)
    gp << "stats datafile index 0 using 1 nooutput\n";
    gp << "N = STATS_records\n";

    // Recorremos i ascendente: cada frame muestra la trayectoria acumulada hasta i
    gp << "do for [i=1:int(N)] {\n";

    // Orden de splot: primero semiesfera (index 1), luego la curva acumulada (index 0 every ::2::i),
    // y POR ÃšLTIMO un punto marcador en la fila i para indicar la posiciÃ³n actual.
    gp << "    splot \\\n";
    gp << "         datafile index 1 using 1:2:3 with lines lw 1 lc rgb 'gray' title 'Semiesfera', \\\n";
    gp << "         datafile index 0 every ::1::i using 2:3:4 with lines lw 2 lc rgb 'blue' title 'PartÃ­cula', \\\n";
    // marcador: actual punto i (usamos every ::i::i para dibujar solo el punto i)
    gp << "         datafile index 0 every ::i::i using 2:3:4 with points pt 7 ps 1.5 lc rgb 'red' notitle\n";
    gp << "    pause 0.02\n";
    gp << "}\n";

    gp << "unset output\n";
    gp.close();

    cout << "Generando animaciÃ³n...\n";
    system("gnuplot ../scripts/animate_Parabolic3D.gp");
    cout << "AnimaciÃ³n guardada en: " << gifSalida << endl;
}

