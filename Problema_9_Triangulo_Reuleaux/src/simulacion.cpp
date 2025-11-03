#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "funciones.h"
using namespace std;

const double EPSILON = 1.0e-9;

void solicitarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                    double &t0, double &tf, double &dt) {
    cout << "Longitud del lado L (m): "; cin >> L;
    cout << "Posicion inicial x0 (m): "; cin >> x0;
    cout << "Posicion inicial y0 (m): "; cin >> y0;
    cout << "Velocidad inicial vx0 (m/s): "; cin >> vx0;
    cout << "Velocidad inicial vy0 (m/s): "; cin >> vy0;
    cout << "Tiempo inicial t0 (s): "; cin >> t0;
    cout << "Tiempo final tf (s): "; cin >> tf;
    cout << "Paso de tiempo dt (s): "; cin >> dt;
}

void validarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                  double &t0, double &tf, double &dt) {
    do { if (L <= 0.0) { cout << "L debe ser positivo. Ingrese L: "; cin >> L; } } while (L <= 0.0);
    double c1x = 0.0;
    double c1y = 0.0;
    double c2x = L;
    double c2y = 0.0;
    double c3x = L / 2.0;
    double c3y = L * sqrt(3.0) / 2.0;
    double d1, d2, d3;
    do {
        d1 = sqrt((x0 - c1x)*(x0 - c1x) + (y0 - c1y)*(y0 - c1y));
        d2 = sqrt((x0 - c2x)*(x0 - c2x) + (y0 - c2y)*(y0 - c2y));
        d3 = sqrt((x0 - c3x)*(x0 - c3x) + (y0 - c3y)*(y0 - c3y));
        if (d1 > L || d2 > L || d3 > L) {
            cout << "La posicion inicial debe estar dentro del triangulo de Reuleaux. Ingrese x0: "; cin >> x0;
            cout << "Ingrese y0: "; cin >> y0;
        }
    } while (d1 > L || d2 > L || d3 > L);
    do { if (vx0 == 0.0 && vy0 == 0.0) { cout << "La velocidad no puede ser cero. Ingrese vx0: "; cin >> vx0; cout << "Ingrese vy0: "; cin >> vy0; } } while (vx0 == 0.0 && vy0 == 0.0);
    do { if (tf <= t0) { cout << "tf debe ser mayor que t0. Ingrese tf: "; cin >> tf; } } while (tf <= t0);
    do { if (dt <= 0.0 || dt >= (tf - t0)) { cout << "dt debe ser positivo y menor que (tf - t0). Ingrese dt: "; cin >> dt; } } while (dt <= 0.0 || dt >= (tf - t0));
}

void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt) {
    #ifdef _WIN32
system("if not exist results mkdir results");
#else
system("mkdir -p results");
#endif
    ofstream archivo("results/datos.dat");
    archivo << fixed << setprecision(5);
    archivo << setw(12) << "t" << setw(12) << "x" << setw(12) << "y" << setw(12) << "vx" << setw(12) << "vy" << '\n';
    double c1x = 0.0;
    double c1y = 0.0;
    double c2x = L;
    double c2y = 0.0;
    double c3x = L / 2.0;
    double c3y = L * sqrt(3.0) / 2.0;
    double t = t0;
    double x = x0;
    double y = y0;
    double vx = vx0;
    double vy = vy0;
    int i = 0;
    while (t <= tf + EPSILON) {
        archivo << setw(12) << t << setw(12) << x << setw(12) << y << setw(12) << vx << setw(12) << vy << '\n';
        double nx, ny, dn, d1, d2, d3;
        double pen1, pen2, pen3;
        x += vx * dt;
        y += vy * dt;
        i++;
        t = t0 + i * dt;
        d1 = sqrt((x - c1x)*(x - c1x) + (y - c1y)*(y - c1y));
        d2 = sqrt((x - c2x)*(x - c2x) + (y - c2y)*(y - c2y));
        d3 = sqrt((x - c3x)*(x - c3x) + (y - c3y)*(y - c3y));
        pen1 = d1 - L;
        pen2 = d2 - L;
        pen3 = d3 - L;
        double mayorPen = pen1;
        int arco = 1;
        if (pen2 > mayorPen) { mayorPen = pen2; arco = 2; }
        if (pen3 > mayorPen) { mayorPen = pen3; arco = 3; }
        if (mayorPen > 0.0) {
            double cx, cy, dd;
            if (arco == 1) { cx = c1x; cy = c1y; dd = d1; }
            if (arco == 2) { cx = c2x; cy = c2y; dd = d2; }
            if (arco == 3) { cx = c3x; cy = c3y; dd = d3; }
            if (dd < EPSILON) { nx = 1.0; ny = 0.0; dn = 1.0; }
            else { nx = (x - cx) / dd; ny = (y - cy) / dd; dn = sqrt(nx*nx + ny*ny); }
            double vn = vx * nx + vy * ny;
            vx = vx - 2.0 * vn * nx;
            vy = vy - 2.0 * vn * ny;
            x = cx + nx * L;
            y = cy + ny * L;
        }
    }
    archivo.close();
}
