simpletron.exe: simpletron.o libsimple.a
	gcc -g -o simpletron.exe simpletron.o -L. -lsimple 

simpletron.o: simpletron.c
	gcc -g -c simpletron.c

util.o: util.c simple.h
	gcc  -g -c util.c
	
libsimple.a: util.o
	ar cr libsimple.a util.o

clean:
	rm *.o libsimple.a		
