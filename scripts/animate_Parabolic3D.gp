# ===== Animación 3D =====
datafile='datosParcial1.1.dat'
giffile='Parcial1.1Animacion.gif'

set terminal gif animate delay 6 size 900,600
set output giffile
set title 'Movimiento Parabolico en 3D'
set xlabel 'x(m)'
set ylabel 'y(m)'
set zlabel 'z(m)'
set grid

set view 60, 45
set view equal xyz
set ticslevel 0
set key outside

stats datafile index 0 using 2 nooutput
xmin1 = STATS_min; xmax1 = STATS_max
stats datafile index 0 using 3 nooutput
ymin1 = STATS_min; ymax1 = STATS_max
stats datafile index 0 using 4 nooutput
zmin1 = STATS_min; zmax1 = STATS_max

stats datafile index 1 using 1 nooutput
xmin2 = STATS_min; xmax2 = STATS_max
stats datafile index 1 using 2 nooutput
ymin2 = STATS_min; ymax2 = STATS_max
stats datafile index 1 using 3 nooutput
zmin2 = STATS_min; zmax2 = STATS_max

xmin = (xmin1 < xmin2) ? xmin1 : xmin2
xmax = (xmax1 > xmax2) ? xmax1 : xmax2
ymin = (ymin1 < ymin2) ? ymin1 : ymin2
ymax = (ymax1 > ymax2) ? ymax1 : ymax2
zmin = (zmin1 < zmin2) ? zmin1 : zmin2
zmax = (zmax1 > zmax2) ? zmax1 : zmax2

dx = (xmax - xmin)*0.05
dy = (ymax - ymin)*0.05
dz = (zmax - zmin)*0.05
set xrange [xmin - dx : xmax + dx]
set yrange [ymin - dy : ymax + dy]
set zrange [zmin - dz : zmax + dz]

stats datafile index 0 using 1 nooutput
N = STATS_records
do for [i=1:int(N)] {
    splot \
         datafile index 1 using 1:2:3 with lines lw 1 lc rgb 'gray' title 'Semiesfera', \
         datafile index 0 every ::1::i using 2:3:4 with lines lw 2 lc rgb 'blue' title 'Partícula', \
         datafile index 0 every ::i::i using 2:3:4 with points pt 7 ps 1.5 lc rgb 'red' notitle
    pause 0.02
}
unset output
