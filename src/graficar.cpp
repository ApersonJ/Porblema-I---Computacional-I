#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/funciones.h"
using namespace std;

void graficarDatos(const string &nombreArchivo, const string &nombreImagen3D, 
                   const string &nombre_xt, const string &nombre_yt, const string &nombre_zt) {
    
    // 1. Primero generar el gr�fico 3D
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
         << "' every ::1 using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Part�cula',\\\n";
    gp3d << "     '" << nombreArchivo
         << "' index 1 with lines lc rgb 'gray' title 'Semiesfera'\n";
    gp3d.close();
    
    // Ejecutar gnuplot para el gr�fico 3D
    system("gnuplot ../scripts/splot_sphere.gp");
    cout << "Gr�fico 3D generado: " << nombreImagen3D << endl;
    
    // 2. Generar gr�fico x(t)
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
    cout << "Gr�fico x(t) generado: " << nombre_xt << endl;
    
    // 3. Generar gr�fico y(t)
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
    cout << "Gr�fico y(t) generado: " << nombre_yt << endl;
    
    // 4. Generar gr�fico z(t)
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
    cout << "Gr�fico z(t) generado: " << nombre_zt << endl;
}
