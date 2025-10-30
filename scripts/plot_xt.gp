set terminal pngcairo size 800,600
set output '../results/Parcial1.1_grafico_x(t).png'
set title 'Posicion x vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'x (m)'
set grid
plot '../results/datosParcial1.1.dat' index 0 every ::1 using 1:2 with lines lw 2 lc rgb 'blue' title 'x(t)'
