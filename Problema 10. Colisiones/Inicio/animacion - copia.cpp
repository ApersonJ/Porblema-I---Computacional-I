#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void generarAnimacion() {
    cout << "Generando animacion GIF..." << endl;
    
    // Limpiar archivos anteriores
    remove("animacion.gif");
    system("rmdir /s /q frames 2>nul");
    
    // Leer datos
    ifstream datafile("simulacion.txt");
    if (!datafile.is_open()) {
        cerr << "Error: No se pudo abrir simulacion.txt" << endl;
        return;
    }
    
    // Contar lineas
    string line;
    getline(datafile, line); // Saltar encabezado
    
    int total_lines = 0;
    while (getline(datafile, line)) {
        if (!line.empty()) total_lines++;
    }
    
    if (total_lines == 0) {
        cerr << "Error: No hay datos" << endl;
        return;
    }
    
    // Crear directorio
    system("mkdir frames 2>nul");
    
    // Generar script gnuplot
    ofstream script("animacion.gnu");
    script << "set terminal gif animate delay 10 size 900,600" << endl;
    script << "set output 'animacion.gif'" << endl;
    script << "set title 'Simulacion de Particula'" << endl;
    script << "set xlabel 'Tiempo (s)'" << endl;
    script << "set ylabel 'Posicion (m)'" << endl;
    script << "set grid" << endl;
    script << "set key outside" << endl;
    script << endl;
    script << "stats 'simulacion.txt' using 1 nooutput" << endl;
    script << "N = STATS_records" << endl;
    script << "do for [i=1:N] {" << endl;
    script << "    plot 'simulacion.txt' every ::1::i using 1:2 with lines lw 2 lc rgb 'blue' title 'Trayectoria', \\" << endl;
    script << "         'simulacion.txt' every ::i::i using 1:2 with points pt 7 ps 2 lc rgb 'red' title 'Posicion Actual'" << endl;
    script << "}" << endl;
    script << "unset output" << endl;
    script.close();
    
    // Ejecutar gnuplot
    system("gnuplot animacion.gnu");
    
    // Limpiar
    remove("animacion.gnu");
    
    cout << "Animacion guardada como: animacion.gif" << endl;
}