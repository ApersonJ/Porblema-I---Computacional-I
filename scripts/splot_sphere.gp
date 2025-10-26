set terminal pngcairo size 800,600
set output 'Parcial1.1_grafico.png'
set title 'Movimiento Parabolico Tridimensional Sobre una Semiesfera'
set xlabel '(m)'
set ylabel '(m)'
set zlabel '(m)'
set grid
set ticslevel 0
set view 60, 45
splot 'datosParcial1.1.dat' every ::1 using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Partícula',\
     'datosParcial1.1.dat' index 1 with lines lc rgb 'gray' title 'Semiesfera'
unset output
