labapp : labapp.o
	gcc -o labapp labapp.o
labapp.o : labapp.c zoomrecs.o 
	gcc -c labapp.c
zoomrecs.o : zoomrecs.c zoomrecs.h
	gcc -c zoomrecs.c
	gcc -o zoomrecs zoomrecs.h	
