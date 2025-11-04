# Física Computacional – Triángulo de Reuleaux

Este proyecto simula el **movimiento de una partícula dentro de un triángulo de Reuleaux** con colisiones perfectamente elásticas en sus bordes.  
El programa genera los datos de la simulación, una gráfica de la trayectoria y una animación en formato GIF que muestra el movimiento de la partícula.

---

## Estructura del proyecto

```
TrianguloReuleaux/
│
├── Makefile
├── README.md
│
├── src/
│   ├── main.cpp
│   ├── simulacion.cpp
│   ├── graficar.cpp
│   ├── animacion.cpp
│   └── funciones.h
│
├── bin/           # Ejecutable compilado
└── results/       # Archivos de salida (.dat, .png, .gif)
```

---

## Compilación

1. Abre una terminal en la carpeta del proyecto.  
2. Escribe:

```bash
make
```

Esto compilará todo el código y generará el ejecutable en:

```
bin/sim
```

Si no existe la carpeta `bin`, se creará automáticamente.

3. Para limpiar los archivos temporales (si deseas recompilar desde cero):

```bash
make clean
```

---

## Ejecución

Ejecuta el programa con:

```bash
./bin/sim
```

El programa pedirá los siguientes valores:

- **L** → Longitud del lado del triángulo equilátero base.  
- **x0**, **y0** → Posición inicial de la partícula (debe estar dentro del triángulo).  
- **vx0**, **vy0** → Componentes de la velocidad inicial.  
- **t0**, **tf**, **dt** → Tiempo inicial, final y paso temporal.

Durante la ejecución:

1. Se genera el archivo `results/datos.dat` con las posiciones y velocidades.  
2. Se abre una ventana de Gnuplot con la trayectoria.  
3. Cuando cierres esa ventana, se genera la animación en `results/reuleaux_anim.gif`.


---

## 💡 Descripción del modelo

El **triángulo de Reuleaux** es una figura de anchura constante construida a partir de tres arcos de radio igual al lado \(L\) de un triángulo equilátero.  
Cada arco está centrado en un vértice del triángulo.

Una partícula libre se mueve en línea recta hasta chocar con uno de los tres arcos.  
Cuando ocurre la colisión, su velocidad se refleja elásticamente conservando la energía cinética:

\[

ec{v}' = ec{v} - 2(ec{v} \cdot \hat{n}) \hat{n}
\]

donde \(\hat{n}\) es la normal al arco en el punto de contacto.

---

## Requisitos

- **g++** 
- **Gnuplot** instalado y accesible desde terminal (para graficar y animar)

Para comprobar que Gnuplot está instalado:
```bash
gnuplot --version
```
 # Autores

Proyecto desarrollado por **Mariana Velandia,Laura Riaño,Jesus Vitola,Nicolas Lopez** para la asignatura  
**Física Computacional I**, 2025.
