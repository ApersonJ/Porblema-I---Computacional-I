#include <fstream>
#include <cstdlib>
#include <iostream>
#include "funciones.h"
using namespace std;

void graficarDatos(const string &nombreArchivo, const string &nombreImagen) {
    ofstream gp("plot_reuleaux.gp");
    gp << "set terminal pngcairo size 800,600\n";
    gp << "set output '" << nombreImagen << "'\n";
    gp << "set title 'Trayectoria en triangulo de Reuleaux'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set grid\n";
    gp << "set size ratio -1\n";
    gp << "plot '" << nombreArchivo << "' every ::1 using 2:3 with lines title 'trayectoria'\n";
    gp << "unset output\n";
    gp << "set terminal qt size 800,600\n";
    gp << "plot '" << nombreArchivo << "' every ::1 using 2:3 with lines title 'trayectoria'\n";
    gp << "pause -1 'Cierra esta ventana para continuar'\n";
    gp.close();
    system("gnuplot plot_reuleaux.gp");
}
