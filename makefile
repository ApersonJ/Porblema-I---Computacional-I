# ===== Makefile  =====
.PHONY: all build run doc clean

all: run doc            # o solo 'run' si no quiere depender de LaTeX

build:
	mkdir -p bin results scripts documents
	g++ src/main.cpp src/simulacion.cpp src/graficar.cpp src/animar.cpp -Iinclude -o bin/parabolic3D

run: build
	cd bin && ./parabolic3D

doc:
	
	pdflatex -interaction=nonstopmode -output-directory=documents documents/teoria_parabolic3D.tex

clean:
	rm -f bin/box1D results/* scripts/*.gp documents/*.aux documents/*.log documents/*.pdf
