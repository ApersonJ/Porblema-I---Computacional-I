#pragma once
#include <string>
using namespace std;

void solicitarDatos(double &L0, double &x0, double &v0,
                    double &u, double &t0, double &tf, double &dt);

void validarDatos(double &L0, double &x0, double &v0,
                  double &u, double &t0, double &tf, double &dt);

void simularMovimiento(double L0, double x0, double v0, double u,
                       double t0, double tf, double dt,
                       const string &nombreArchivo);

void graficarDatos(const string &nombreArchivo, const string &nombreImagen);

void generarAnimacion(const string &nombreArchivo, const string &gifSalida);