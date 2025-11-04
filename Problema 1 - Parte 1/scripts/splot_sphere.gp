set terminal pngcairo size 800,600
set output '../results/Parcial1.1_grafico.png'
set title 'Movimiento Parabolico Tridimensional Sobre una Semiesfera'
set xlabel 'x (m)'
set ylabel 'y (m)'
set zlabel 'z (m)'
set grid
set ticslevel 0
set view 60, 45
set view equal xyz
splot '../results/datosParcial1.1.dat' every ::1 using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Partícula',\
     '../results/datosParcial1.1.dat' index 1 with lines lc rgb 'gray' title 'Semiesfera'
