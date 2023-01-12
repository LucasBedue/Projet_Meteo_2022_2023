all: execmeteotri

Meteotri.o: Meteotri.c Meteotri.h
	gcc -c Meteotri.c -o Meteotri.o

Meteotrifct.o: Meteotrifct.c Meteotri.h
	gcc -c Meteotrifct.c -o Meteotrifct.o

execmeteotri: Meteotri.o Meteotrifct.o
	gcc Meteotri.o Meteotrifct.o -o execmeteotri

Meteotmpfiles:
	mkdir ./Meteotmpfiles

cleanfiles:
	rm -r ./Meteotmpfiles

clean:
	rm -f *.o
	rm execmeteotri