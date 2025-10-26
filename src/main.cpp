//main.cpp

#include <iostream>
#include "../include/funciones.h"

using namespace std;

int main() {
    double x0, y0, z0, vx0, vy0, vz0;	//condiciones proyectil
	double R, xc, yc, zc;				//condiciones esfera
    double dt;							//condiciones tiempo

    solicitarDatos(x0, y0, z0, vx0, vy0, vz0, R, xc, yc, zc, dt);
    validarDatos(x0, y0, z0, R, xc, yc, zc, dt);
    simularMovimiento(x0, y0, z0, vx0, vy0, vz0, R, xc, yc, zc, dt, "datosParcial1.1.dat" );

    // Generar PNG, GIF y abrir ventana interactiva con Gnuplot
    graficarDatos("datosParcial1.1.dat", "Parcial1.1_grafico.png");

    return 0; // solo mensajes informativos de graficarDatos
}