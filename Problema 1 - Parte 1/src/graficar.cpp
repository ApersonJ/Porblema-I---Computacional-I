#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/funciones.h"
using namespace std;

/**
 * @file graficar.cpp
 * @brief Implementa las rutinas de generación de gráficos con Gnuplot para visualizar
 * el movimiento parabólico tridimensional de una partícula sobre una semiesfera.
 *
 * Esta función crea gráficos 3D y gráficos individuales de las componentes de posición
 * x(t), y(t) y z(t) a lo largo del tiempo, utilizando scripts de Gnuplot que se ejecutan automáticamente.
 */

/**
 * @brief Genera los gráficos de la trayectoria y las posiciones temporales del proyectil.
 *
 * Esta función crea varios scripts de Gnuplot para graficar:
 * - La trayectoria 3D del proyectil junto con la semiesfera.
 * - Las funciones x(t), y(t) y z(t) en gráficos separados.
 *
 * Cada script es generado en la carpeta `../scripts/` y luego ejecutado para crear
 * los archivos de imagen en formato PNG. Los resultados se muestran por consola.
 *
 * @param nombreArchivo Nombre del archivo de datos de entrada con los resultados de la simulación.
 * @param nombreImagen3D Nombre del archivo de salida para el gráfico 3D (por ejemplo, "trayectoria3D.png").
 * @param nombre_xt Nombre del archivo de salida para el gráfico x(t) (por ejemplo, "xt.png").
 * @param nombre_yt Nombre del archivo de salida para el gráfico y(t) (por ejemplo, "yt.png").
 * @param nombre_zt Nombre del archivo de salida para el gráfico z(t) (por ejemplo, "zt.png").
 */
void graficarDatos(const string &nombreArchivo, const string &nombreImagen3D, 
                   const string &nombre_xt, const string &nombre_yt, const string &nombre_zt) {
    
    // 1. Primero generar el gráfico 3D
    ofstream gp3d("../scripts/splot_sphere.gp");
    gp3d << "set terminal pngcairo size 800,600\n";
    gp3d << "set output '" << nombreImagen3D << "'\n";
    gp3d << "set title 'Movimiento Parabolico Tridimensional Sobre una Semiesfera'\n";
    gp3d << "set xlabel 'x (m)'\n";
    gp3d << "set ylabel 'y (m)'\n";
    gp3d << "set zlabel 'z (m)'\n";
    gp3d << "set grid\n";
    gp3d << "set ticslevel 0\n";
    gp3d << "set view 60, 45\n";
    gp3d << "set view equal xyz\n";
    gp3d << "splot '" << nombreArchivo
         << "' every ::1 using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Partícula',\\\n";
    gp3d << "     '" << nombreArchivo
         << "' index 1 with lines lc rgb 'gray' title 'Semiesfera'\n";
    gp3d.close();
    
    // Ejecutar gnuplot para el gráfico 3D
    system("gnuplot ../scripts/splot_sphere.gp");
    cout << "Gráfico 3D generado: " << nombreImagen3D << endl;
    
    // 2. Generar gráfico x(t)
    ofstream gpx("../scripts/plot_xt.gp");
    gpx << "set terminal pngcairo size 800,600\n";
    gpx << "set output '" << nombre_xt << "'\n";
    gpx << "set title 'Posicion x vs Tiempo'\n";
    gpx << "set xlabel 'Tiempo (s)'\n";
    gpx << "set ylabel 'x (m)'\n";
    gpx << "set grid\n";
    gpx << "plot '" << nombreArchivo 
        << "' index 0 every ::1 using 1:2 with lines lw 2 lc rgb 'blue' title 'x(t)'\n";
    gpx.close();
    system("gnuplot ../scripts/plot_xt.gp");
    cout << "Gráfico x(t) generado: " << nombre_xt << endl;
    
    // 3. Generar gráfico y(t)
    ofstream gpy("../scripts/plot_yt.gp");
    gpy << "set terminal pngcairo size 800,600\n";
    gpy << "set output '" << nombre_yt << "'\n";
    gpy << "set title 'Posicion y vs Tiempo'\n";
    gpy << "set xlabel 'Tiempo (s)'\n";
    gpy << "set ylabel 'y (m)'\n";
    gpy << "set grid\n";
    gpy << "plot '" << nombreArchivo 
        << "' index 0 every ::1 using 1:3 with lines lw 2 lc rgb 'red' title 'y(t)'\n";
    gpy.close();
    system("gnuplot ../scripts/plot_yt.gp");
    cout << "Gráfico y(t) generado: " << nombre_yt << endl;
    
    // 4. Generar gráfico z(t)
    ofstream gpz("../scripts/plot_zt.gp");
    gpz << "set terminal pngcairo size 800,600\n";
    gpz << "set output '" << nombre_zt << "'\n";
    gpz << "set title 'Posicion z vs Tiempo'\n";
    gpz << "set xlabel 'Tiempo (s)'\n";
    gpz << "set ylabel 'z (m)'\n";
    gpz << "set grid\n";
    gpz << "plot '" << nombreArchivo 
        << "' index 0 every ::1 using 1:4 with lines lw 2 lc rgb 'green' title 'z(t)'\n";
    gpz.close();
    system("gnuplot ../scripts/plot_zt.gp");
    cout << "Gráfico z(t) generado: " << nombre_zt << endl;
}

