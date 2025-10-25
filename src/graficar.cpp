#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void graficarDatos(const string &nombreArchivo, const string &nombreImagen) {
    ofstream gp("scripts/plot_box1D.gp");
    gp << "set terminal pngcairo size 800,600\n";
    gp << "set output '" << nombreImagen << "'\n";
    gp << "set title 'Movimiento en caja 1D con pared móvil'\n";
    gp << "set xlabel 'Tiempo (s)'\n";
    gp << "set ylabel 'Posición (m)'\n";
    gp << "set grid\n";
    gp << "plot '" << nombreArchivo
       << "' every ::1 using 1:2 with lines lw 2 lc rgb 'blue' title 'Partícula',\\\n";
    gp << "     '" << nombreArchivo
       << "' every ::1 using 1:4 with lines lw 1 lc rgb 'gray' title 'Pared móvil'\n";
    gp << "unset output\n";
    gp.close();
    system("gnuplot scripts/plot_box1D.gp");
    cout << " Gráfico generado: " << nombreImagen << endl;
}
