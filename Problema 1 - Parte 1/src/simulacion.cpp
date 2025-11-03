#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include "../include/funciones.h"
using namespace std;

/**
 * @file funciones.cpp
 * @brief Implementación de las funciones principales para simular el movimiento de un proyectil
 * y su interacción con una esfera mediante colisiones elásticas.
 */

const double EPSILON = 1.0e-6; ///< Umbral de proximidad usado para detectar colisiones.
const double g = 9.8;          ///< Aceleración de la gravedad (m/s²).
const double PI = 3.14159265;  ///< Constante pi.

/**
 * @brief Solicita al usuario los datos iniciales del sistema.
 *
 * Esta función pide por consola la posición y velocidad inicial del proyectil,
 * la posición del centro y el radio de la esfera, así como el paso temporal de integración.
 *
 * @param x0 Posición inicial en el eje X (m).
 * @param y0 Posición inicial en el eje Y (m).
 * @param z0 Posición inicial en el eje Z (m).
 * @param vx0 Velocidad inicial en el eje X (m/s).
 * @param vy0 Velocidad inicial en el eje Y (m/s).
 * @param vz0 Velocidad inicial en el eje Z (m/s).
 * @param R Radio de la esfera (m).
 * @param xc Coordenada X del centro de la esfera (m).
 * @param yc Coordenada Y del centro de la esfera (m).
 * @param zc Coordenada Z del centro de la esfera (m).
 * @param dt Paso de tiempo (s).
 */
void solicitarDatos(double &x0, double &y0, double &z0, double &vx0,
                    double &vy0, double &vz0, double &R, double &xc, 
					double &yc, double &zc, double &dt) {
    cout << "Posicion inicial del proyectil (x0, y0, z0) (m): "<<endl;
    cin >> x0;
    cin	>> y0;
    cin >> z0;
    
    cout << "Velocidad inicial del proyectil (vx0, vy0, vz0) (m/s): "<<endl;
    cin >> vx0;
    cin	>> vy0;
    cin >> vz0;
    
    cout << "Posicion del centro de la esfera (x, y, z) (m): "<<endl;
    cin >> xc;
    cin	>> yc;
    cin >> zc;

    cout << "Radio de la esfera (m): ";
    cin  >> R;

    cout << "Paso de tiempo dt (s) (se sugiere 0.1s): ";
    cin  >> dt;
}

/**
 * @brief Valida que los datos ingresados por el usuario sean físicamente consistentes.
 *
 * Comprueba que el radio de la esfera y el paso de tiempo sean positivos, que la posición inicial
 * del proyectil esté por encima del suelo, y que el proyectil no empiece dentro o demasiado cerca de la esfera.
 *
 */
void validarDatos(double &x0, double &y0, double &z0, double &R, double &xc, 
					double &yc, double &zc, double &dt) {
	
	// R > 0
    do {
        if (R <= 0.0) {
            cout << "R debe ser positivo. Ingrese R: ";
            cin  >> R;
        }
    } while (R <= 0.0);
	
	// z0 > 0
    do {
        if (z0 < 0.0) {
            cout << "z0 debe ser positivo para no pasar el suelo. Ingrese z0: ";
            cin  >> z0;
        }
    } while (z0 < 0.0);
	
	// Distancia inicial entre el proyectil y el centro de la esfera
	double D0 = sqrt((x0-xc)*(x0-xc)+(y0-yc)*(y0-yc)+(z0-zc)*(z0-zc));					
    // Proyectil dentro o muy cerca de la esfera 
    do {
        if (D0 <= R+0.1) {
            cout << "El proyectil está dentro o demasiado cerca de la esfera, aleje la posicion inicial del proyectil (x0, y0, z0)"<<endl;
            cin >> x0;
    		cin	>> y0;
    		cin >> z0;
        }
    } while (D0 <= R+0.1);

    // 0 < dt
    do {
        if (dt <= 0.0) {
            cout << "dt debe ser positivo. Ingrese dt: ";
            cin  >> dt;
        }
    } while (dt <= 0.0);
}

/**
 * @brief Simula el movimiento del proyectil y registra los resultados en un archivo.
 *
 * Integra la ecuación de movimiento del proyectil bajo la acción de la gravedad y
 * calcula las colisiones elásticas con una esfera fija. Los datos se guardan en un
 * archivo de texto para su posterior análisis o graficación.
 *
 * @param nombreArchivo Nombre del archivo donde se guardarán los resultados.
 */
void simularMovimiento(double &x0, double &y0, double &z0, double &vx0, 
					double &vy0, double &vz0, double &R, double &xc, 
					double &yc, double &zc, double &dt, const string nombreArchivo) {
    // 1) Crear el archivo de salida (nombre simple e intuitivo)
    ofstream myfile(nombreArchivo);

    // 2) Formato uniforme
   myfile << fixed << setprecision(5);

    // 3) Encabezado de columnas
    myfile << setw(12) << "t"
           << setw(15) << "x"
           << setw(15) << "y"
           << setw(15) << "z"
           << setw(15) << "vz" << '\n';
           
    // 4) Estado inicial
    
    double t=0.0, x=x0, y=y0, z=z0, vx=vx0, vy=vy0, vz=vz0;
    int i=0;
           
    // 5) Parámetro de distancia entre el punto y las paredes
    double D = sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)+(z-zc)*(z-zc));
    
    while (z >= -EPSILON) {
        // Escribir una fila por paso
        myfile << setw(12) << t
               << setw(15) << x
               << setw(15) << y
               << setw(15) << z
               << setw(15) << vz << '\n';
               
        i++;
        t = i * dt;
        
		vz -= g*dt;

        // Actualización de la posición del proyectil
        x += vx*dt;
        y += vy*dt;
        z += vz*dt;
        
        // Actualización del parámetro de distancia
        D = sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)+(z-zc)*(z-zc));

        // Verificación de rebotes (colisión elástica)
        if (D <= R+EPSILON) {
        	// Cálculo del vector normal al punto de impacto
        	double nx = (x-xc)/D,
				   ny = (y-yc)/D, 
				   nz = (z-zc)/D;
				   
    		// Producto escalar entre velocidad y vector normal
    		double v_n = (vx*nx)+(vy*ny)+(vz*nz);
    		
    		// Actualización de componentes de velocidad tras el impacto
    		vx = vx-2*v_n*nx;
    		vy = vy-2*v_n*ny;
    		vz = vz-2*v_n*nz;
		}
    }

    // Generar semiesfera (para referencia visual en gráficos)
    const double dtheta = 0.1; ///< Incremento angular polar para la precisión de la esfera.
    const double dphi = 0.1;   ///< Incremento angular azimutal para la precisión de la esfera.
    double xs = 0, ys = 0, zs = 0;

    myfile     << "\n\n";                       
    myfile     << setw(12) << "#xs"
               << setw(15) << "ys"
               << setw(15) << "zs" << '\n';

    for (double theta = 0; theta <= PI / 2; theta += dtheta)
    {
        for (double phi = 0; phi <= 2*PI; phi += dphi)
        {
            xs = xc + R * sin(theta) * cos(phi);
            ys = yc + R * sin(theta) * sin(phi);
            zs = zc + R * cos(theta);

            myfile << setw(12) << xs
               << setw(15) << ys
               << setw(15) << zs << '\n';
         }
        
        myfile << '\n';
    }
    
    // 6) Cerrar archivo
    myfile.close();
}

