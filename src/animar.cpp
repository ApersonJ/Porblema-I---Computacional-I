#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void generarAnimacion(const string &nombreArchivo, const string &gifSalida) {
    ofstream gp("scripts/animate_box1D.gp");
    

    gp << "# ===== Animación x(t) y x_R(t) =====\n";
    gp << "datafile='" << nombreArchivo << "'\n";
    gp << "giffile='" << gifSalida << "'\n\n";

    gp << "set terminal gif animate delay 4 size 900,600\n";
    gp << "set output giffile\n";
    gp << "set title 'Evolución temporal: posición de partícula y pared'\n";
    gp << "set xlabel 'Tiempo (s)'\n";
    gp << "set ylabel 'Posición (m)'\n";
    gp << "set grid\n\n";

    gp << "stats datafile using 1 nooutput\n";
    gp << "tmin = STATS_min; tmax = STATS_max\n";
    gp << "stats datafile using 2 nooutput\n";
    gp << "xmin = STATS_min; xmax = STATS_max\n";
    gp << "stats datafile using 4 nooutput\n";
    gp << "xRmin = STATS_min; xRmax = STATS_max\n";
    gp << "dy = (xRmax - xmin)*0.05\n";
    gp << "set xrange [tmin:tmax]\n";
    gp << "set yrange [xmin - dy:xRmax + dy]\n\n";

    gp << "N = system(sprintf(\"grep -v '^ *$' '%s' | tail -n +2 | wc -l\", datafile))\n";

    gp << "do for [i=1:N] {\n";
    gp << "    plot datafile every ::1::i using 1:2 with lines lw 2 lc rgb 'blue' title 'Partícula',\\\n";
    gp << "         datafile every ::1::i using 1:4 with lines lw 2 lc rgb 'gray' title 'Pared móvil'\n";
    gp << "}\n";
    gp << "unset output\n";
    gp.close();

    cout << "Generando animación de x(t)...\n";
    system("gnuplot scripts/animate_box1D.gp");
    cout << "Animación guardada en: " << gifSalida << endl;
}
