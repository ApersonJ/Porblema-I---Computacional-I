# Simulación: Partícula que Choca con una Esfera 3D

## Descripción
Simula el movimiento parabólico tridimensional de una partícula que colisiona elásticamente con una esfera.  
El programa calcula la trayectoria, detecta los rebotes, guarda los datos en un archivo, genera una gráfica en formato PNG y una animación GIF.

## Estructura
- `main.cpp`: flujo principal del programa (solicita datos, valida y llama las funciones).
- `simulacion.cpp`: simula la trayectoria 3D y guarda los resultados en un archivo de texto.
- `graficar.cpp`: genera una imagen estática (`.png`) del movimiento y la semiesfera.
- `animar.cpp`: genera la animación (`.gif`) de la trayectoria de la partícula.
- `include/funciones.h`: contiene los prototipos de las funciones.
- `scripts/`: carpeta donde se guardan los scripts `.gp` de Gnuplot.

## Uso
Compila y ejecuta el proyecto con:
```bash
make
```

El programa solicitará los datos iniciales (posición, velocidad, radio de la esfera, paso de tiempo, etc.), luego generará los siguientes archivos:
- `Parcial1.1_grafico.png`: gráfica estática 3D.
- `Parcial1.1Animacion.gif`: animación del movimiento.
- Graficas de x(t), y(t) y z(t).

## Requisitos
- **Compilador:** G++  
- **Gráficas:** Gnuplot  
- **LaTex:** pdfLaTex

