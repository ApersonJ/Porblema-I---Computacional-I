#pragma once
#include <string>

void solicitarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                    double &t0, double &tf, double &dt);

void validarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0,
                  double &t0, double &tf, double &dt);

void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt);

void graficarDatos(const std::string &nombreArchivo, const std::string &nombreImagen);

void generarAnimacion(const std::string &nombreArchivo, const std::string &gifSalida);
