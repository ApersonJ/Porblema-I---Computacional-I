#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    double L, x0, y0, vx0, vy0, t0, tf, dt;

    solicitarDatos(L, x0, y0, vx0, vy0, t0, tf, dt);
    validarDatos(L, x0, y0, vx0, vy0, t0, tf, dt);
    simularMovimiento(L, x0, y0, vx0, vy0, t0, tf, dt);

    cout << "\nCierra la ventana de la grafica para generar la animacion...\n";
    graficarDatos("results/datos.dat", "results/reuleaux_trayectoria.png");

    generarAnimacion("results/datos.dat", "results/reuleaux_anim.gif");
    return 0;
}
