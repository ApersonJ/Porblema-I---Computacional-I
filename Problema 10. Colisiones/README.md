# Simulación de Partícula en Caja 1D con Colisiones Inelásticas

## Descripción
Modificar el programa $Particle1Dbox.cpp$ para estudiar colisiones no inelásticas con las paredes, donde la velocidad despues del choque sigue la relación $v´=-ev$ con "$0<e\leq 1$ (coeficiente de restitución). 

El programa calcula la posición, la energía cinetica, detecta las colisiones inelasticas y,   guarda los datos en un archivo, genera tres gráficas en formato PNG y una animación .GIF que contiene dos gráficas.

## Estructura del codigo modularizado.
- `main.cpp`: flujo principal del programa (solicita datos, valida, calculo de energía y llama las funciones).
- `simulacion.cpp`: simula la trayectoria 1D y guarda los resultados en un archivo de texto.
- `graficar.cpp`: genera las tres graficas correspondientes para posición vs. tiempo, velocidad vs. tiempo y, Energía cinetica vs. tiempo en una imagen estatica del tipo .png del movimiento. 

- `animaccion.cpp`: genera las animacións (`.gif`) de la trayectoria de la partícula y la velocidad.
- `include/grafica.h`: contiene los prototipos de las funciones.
- `include/proceso.h`: contiene los prototipos de las funciones.

## Uso
Compila y ejecuta el proyecto en bash de visual basic con:
"g++ -o simulacion.exe inicio/main.cpp inicio/Proceso.cpp inicio/grafica.cpp inicio/animacion.cpp
.\simulacion.exe"

El programa solicitará los datos iniciales (longitud de la caja,posición inicial, velocidad inicial, tiempo inicial, paso del tiempo, coeficiente de restitusion, etc.), luego generará los siguientes archivos:
- `animacion.png`: Animación del movimiento y velocidad
- `velocidad_vs_tiempo.png, posicion_vs_tiempo, energia_vs_tiempo`: gráficas estática 1D.
- `simulacion.dat`: Archivo donde se encuentran los datos.

## Requisitos
- **Compilador:** G++  
- **Gráficas:** Gnuplot  
- **LaTex:** pdfLaTex
