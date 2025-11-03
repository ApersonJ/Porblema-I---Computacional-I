set terminal pngcairo size 800,600
set output '../results/Parcial1.1_grafico_y(t).png'
set title 'Posicion y vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'y (m)'
set grid
plot '../results/datosParcial1.1.dat' index 0 every ::1 using 1:3 with lines lw 2 lc rgb 'red' title 'y(t)'
