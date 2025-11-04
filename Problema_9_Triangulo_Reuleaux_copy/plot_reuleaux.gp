set terminal pngcairo size 800,600
set output 'results/reuleaux_trayectoria.png'
set title 'Trayectoria en triangulo de Reuleaux'
set xlabel 'x (m)'
set ylabel 'y (m)'
set grid
set size ratio -1
plot 'results/datos.dat' every ::1 using 2:3 with lines title 'trayectoria'
unset output
set terminal qt size 800,600
plot 'results/datos.dat' every ::1 using 2:3 with lines title 'trayectoria'
pause -1 'Cierra esta ventana para continuar'
