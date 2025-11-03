set terminal pngcairo size 800,600
set output '../results/Parcial1.1_grafico_z(t).png'
set title 'Posicion z vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'z (m)'
set grid
plot '../results/datosParcial1.1.dat' index 0 every ::1 using 1:4 with lines lw 2 lc rgb 'green' title 'z(t)'
