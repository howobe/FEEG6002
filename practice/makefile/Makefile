figure: plotfile.py data.txt
	python plotfile.py data.txt

data.txt: tabulatesin
	./tabulatesin > data.txt

tabulatesin: tabulatesin.o
	gcc tabulatesin.o -o tabulatesin

tabulatesin.o: tabulatesin.c
	gcc -c tabulatesin.c -Wall -ansi -pedantic -lm

clean:
	rm data.txt tabulatesin dataplot.pdf
