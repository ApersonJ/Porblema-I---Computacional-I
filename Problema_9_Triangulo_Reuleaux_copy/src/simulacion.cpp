/**
 * @file simulacion.cpp
 * @brief Implementación de la simulación del movimiento de una partícula confinada en un triángulo de Reuleaux.
 *
 * Este módulo integra el movimiento de una partícula libre dentro de un dominio con forma de triángulo de Reuleaux.
 * Se modelan las colisiones elásticas contra las fronteras curvas de la figura, reflejando la dirección
 * del vector velocidad cada vez que la partícula impacta un límite.
 *
 * @date 2025-11-04
 * @version 1.0
 */

#include <fstream>
#include <cmath>
using namespace std;

/**
 * @brief Simula el movimiento de una partícula dentro de un triángulo de Reuleaux.
 *
 * La partícula se mueve con velocidad constante y rebota de forma elástica sobre los bordes curvos del triángulo
 * de Reuleaux, definidos por la intersección de tres círculos de radio *L* cuyos centros corresponden
 * a los vértices de un triángulo equilátero.
 *
 * En cada iteración:
 * - Se actualiza la posición de la partícula.
 * - Se calcula la distancia al cuadrado entre la partícula y cada uno de los tres centros.
 * - Si alguna distancia excede \(L^2\), significa que la partícula ha salido de la región interior.
 *   En ese caso, se calcula la normal al borde y se refleja el vector velocidad.
 * - Los resultados (tiempo y posición) se guardan en el archivo `results/datos.dat`.
 *
 * @param L   Longitud del lado del triángulo de Reuleaux (y radio de los arcos que lo conforman).
 * @param x0  Posición inicial de la partícula en el eje X (m).
 * @param y0  Posición inicial de la partícula en el eje Y (m).
 * @param vx0 Velocidad inicial de la partícula en el eje X (m/s).
 * @param vy0 Velocidad inicial de la partícula en el eje Y (m/s).
 * @param t0  Tiempo inicial de la simulación (s).
 * @param tf  Tiempo final de la simulación (s).
 * @param dt  Paso temporal de integración (s).
 *
 * @note Se asume una colisión perfectamente elástica, es decir, no hay pérdida de energía al rebotar.
 * @warning Si el paso de tiempo `dt` es muy grande, la partícula puede atravesar los límites antes de detectar la colisión.
 */
void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt) {
    double x = x0;
    double y = y0;
    double vx = vx0;
    double vy = vy0;
    double t = t0;

    // Archivo de salida con posiciones (tiempo, x, y)
    ofstream datos("results/datos.dat");
    datos << t << " " << x << " " << y << endl;

    // Coordenadas de los centros de los tres arcos
    double c1x = 0.0, c1y = 0.0;
    double c2x = L, c2y = 0.0;
    double c3x = L / 2.0, c3y = L * sqrt(3) / 2.0;

    while (t <= tf) {
        // Movimiento libre (integración simple)
        x += vx * dt;
        y += vy * dt;
        t += dt;

        // Distancias al cuadrado desde los tres centros
        double d1 = (x - c1x) * (x - c1x) + (y - c1y) * (y - c1y);
        double d2 = (x - c2x) * (x - c2x) + (y - c2y) * (y - c2y);
        double d3 = (x - c3x) * (x - c3x) + (y - c3y) * (y - c3y);

        // Rebote si la partícula sale del límite interior (d_i > L^2)
        if (d1 > L * L) {
            double nx = -(x - c1x) / sqrt(d1);
            double ny = -(y - c1y) / sqrt(d1);
            double dot = vx * nx + vy * ny;
            vx -= 2 * dot * nx;
            vy -= 2 * dot * ny;
            x += vx * dt;
            y += vy * dt;
        } else if (d2 > L * L) {
            double nx = -(x - c2x) / sqrt(d2);
            double ny = -(y - c2y) / sqrt(d2);
            double dot = vx * nx + vy * ny;
            vx -= 2 * dot * nx;
            vy -= 2 * dot * ny;
            x += vx * dt;
            y += vy * dt;
        } else if (d3 > L * L) {
            double nx = -(x - c3x) / sqrt(d3);
            double ny = -(y - c3y) / sqrt(d3);
            double dot = vx * nx + vy * ny;
            vx -= 2 * dot * nx;
            vy -= 2 * dot * ny;
            x += vx * dt;
            y += vy * dt;
        }

        // Guardar el estado actual
        datos << t << " " << x << " " << y << endl;
    }

    datos.close();
}
