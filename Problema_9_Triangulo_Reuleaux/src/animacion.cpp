#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "funciones.h"
using namespace std;

void generarAnimacion(const string &nombreArchivo, const string &gifSalida) {
    double L = 1.0;
    cout << "Ingrese nuevamente L para animacion (m): ";
    cin >> L;
    ofstream gp("animate_reuleaux.gp");
    gp << "datafile = '" << nombreArchivo << "'\n";
    gp << "giffile  = '" << gifSalida << "'\n";
    gp << "set terminal gif animate delay 10 size 800,800\n";
    gp << "set output giffile\n";
    gp << "set title 'Animacion triangulo de Reuleaux'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set grid\n";
    gp << "set size ratio -1\n";
    gp << "L = " << L << "\n";
    gp << "c1x = 0; c1y = 0\n";
    gp << "c2x = L; c2y = 0\n";
    gp << "c3x = L/2; c3y = L*sqrt(3)/2\n";
    gp << "set parametric\n";
    gp << "arc1x(t)=c1x+L*cos(t)\n";
    gp << "arc1y(t)=c1y+L*sin(t)\n";
    gp << "arc2x(t)=c2x+L*cos(t-2*pi/3)\n";
    gp << "arc2y(t)=c2y+L*sin(t-2*pi/3)\n";
    gp << "arc3x(t)=c3x+L*cos(t+2*pi/3)\n";
    gp << "arc3y(t)=c3y+L*sin(t+2*pi/3)\n";
    gp << "stats datafile every ::1 using 1 nooutput\n";
    gp << "N = STATS_records\n";
    gp << "do for [i=1:N:2] {\n";
    gp << "    plot datafile every ::1::i using 2:3 with lines lw 2 lc rgb 'blue' notitle, \\\n";
    gp << "         datafile every ::i::i using 2:3 with points pt 7 ps 1.5 lc rgb 'red' notitle, \\\n";
    gp << "         arc1x(t), arc1y(t) lw 1 lc rgb 'black' notitle, \\\n";
    gp << "         arc2x(t), arc2y(t) lw 1 lc rgb 'black' notitle, \\\n";
    gp << "         arc3x(t), arc3y(t) lw 1 lc rgb 'black' notitle\n";
    gp << "}\n";
    gp << "unset output\n";
    gp.close();
    system("gnuplot animate_reuleaux.gp");
    cout << "\nAnimacion generada: " << gifSalida << endl;
}
