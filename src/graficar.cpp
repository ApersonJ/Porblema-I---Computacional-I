#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/funciones.h"
using namespace std;

void graficarDatos(const string &nombreArchivo, const string &nombreImagen3D) {
    ofstream gp("../scripts/splot_sphere.gp");
    gp << "set terminal pngcairo size 800,600\n";
    gp << "set output '" << nombreImagen3D << "'\n";
    gp << "set title 'Movimiento Parabolico Tridimensional Sobre una Semiesfera'\n";
    gp << "set xlabel '(m)'\n";
    gp << "set ylabel '(m)'\n";
    gp << "set zlabel '(m)'\n";
    gp << "set grid\n";
    gp << "set ticslevel 0\n";  // coloca el plano z=0 en la base
    gp << "set view 60, 45\n";  // ángulo de visión: elevación, rotación
    gp << "set view equal xyz\n";
    gp << "splot '" << nombreArchivo
       << "' every ::1 using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Partícula',\\\n";
    gp << "     '" << nombreArchivo
       << "' index 1 with lines lc rgb 'gray' title 'Semiesfera'\n";
    gp << "unset output\n";
    gp.close();
    system("gnuplot ../scripts/splot_sphere.gp");
    cout << " Gráfico generado: " << nombreImagen3D << endl;
}
