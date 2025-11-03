datafile = 'results/datos.dat'
giffile  = 'results/reuleaux_anim.gif'

set term gif animate optimize delay 10 size 800,800
set output giffile

set title 'Animacion triangulo de Reuleaux'
set xlabel 'x (m)'
set ylabel 'y (m)'
set grid
set size ratio -1

L = 2
c1x = 0; c1y = 0
c2x = L; c2y = 0
c3x = L/2; c3y = L*sqrt(3)/2

set parametric
arc1x(t)=c1x+L*cos(t)
arc1y(t)=c1y+L*sin(t)
arc2x(t)=c2x+L*cos(t-2*pi/3)
arc2y(t)=c2y+L*sin(t-2*pi/3)
arc3x(t)=c3x+L*cos(t+2*pi/3)
arc3y(t)=c3y+L*sin(t+2*pi/3)

stats datafile using 1 nooutput
N = STATS_records

if (N < 2) {
    print "Error: no hay suficientes datos en " . datafile
} else {
    do for [i=1:N:5] {
        plot datafile every ::1::i using 2:3 with lines lw 2 lc rgb 'blue' notitle, \
             datafile every ::i::i using 2:3 with points pt 7 ps 1.5 lc rgb 'red' notitle, \
             arc1x(t), arc1y(t) lw 1 lc rgb 'black' notitle, \
             arc2x(t), arc2y(t) lw 1 lc rgb 'black' notitle, \
             arc3x(t), arc3y(t) lw 1 lc rgb 'black' notitle
    }
}

unset output
set output
set term wxt
pause -1
