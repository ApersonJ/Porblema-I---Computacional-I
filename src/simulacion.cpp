#include <iostream>
#include <iomanip>
#include <fstream>
#include "../include/funciones.h"
using namespace std;

void solicitarDatos(double &L0, double &x0, double &v0,
                    double &u, double &t0, double &tf, double &dt) {
    cout << "Longitud inicial de la caja L0 (m): "; cin >> L0;
    cout << "Posición inicial x0 (m): "; cin >> x0;
    cout << "Velocidad inicial de la partícula v0 (m/s): "; cin >> v0;
    cout << "Velocidad de la pared derecha u (m/s): "; cin >> u;
    cout << "Tiempo inicial t0 (s): "; cin >> t0;
    cout << "Tiempo final tf (s): "; cin >> tf;
    cout << "Paso de tiempo dt (s): "; cin >> dt;
}

void validarDatos(double &L0, double &x0, double &v0,
                  double &u, double &t0, double &tf, double &dt) {
    while (L0 <= 0) { cout << "L0 debe ser positivo: "; cin >> L0; }
    while (x0 < 0 || x0 > L0) { cout << "x0 en [0, L0]: "; cin >> x0; }
    while (tf <= t0) { cout << "tf > t0: "; cin >> tf; }
    while (dt <= 0 || dt >= (tf - t0)) {
        cout << "dt debe ser menor que (tf - t0): "; cin >> dt;
    }
}

void simularMovimiento(double L0, double x0, double v0, double u,
                       double t0, double tf, double dt,
                       const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    archivo << fixed << setprecision(5);
    archivo << setw(12) << "t" << setw(15) << "x"
             << setw(15) << "v" << setw(15) << "x_R" << '\n';

    double t = t0, x = x0, v = v0, L = L0;
    int i = 0;

    while (t <= tf && L > 0) {
        archivo << setw(12) << t << setw(15) << x
                 << setw(15) << v << setw(15) << L << '\n';

        x += v * dt;
        i++;
        t = t0 + i * dt;
        L = L0 - u * t; // pared móvil

        if (x < 0.0) { x = 0.0; v = -v; }
        if (x > L)  { x = L;  v = -2*u - v; }
    }
    archivo << '\n';
    archivo.close();
    cout << "✅ Datos guardados en: " << nombreArchivo << endl;
}