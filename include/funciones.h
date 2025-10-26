#pragma once
#include <string>
using namespace std;

void solicitarDatos(double &x0, double &y0, double &z0, double &vx0,
                    double &vy0, double &vz0, double &R, double &xc, 
					double &yc, double &zc, double &dt);

void validarDatos(double &x0, double &y0, double &z0, double &R, double &xc, 
					double &yc, double &zc, double &dt);

void simularMovimiento(double &x0, double &y0, double &z0, double &vx0, 
					double &vy0, double &vz0, double &R, double &xc, 
					double &yc, double &zc, double &dt, const string nombreArchivo);

void graficarDatos(const string& nombreArchivo, const string& nombreImagen3D);

void generarAnimacion(const string &nombreArchivo, const string &gifSalida3D);