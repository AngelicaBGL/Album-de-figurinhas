all: main

main: main.o jogos.o depende_do_sistema.o folhear.o dados.o album.o
	gcc *.c -g -o main
	
main.o: main.c
	gcc -c -g main.c
	
jogos.o:
	gcc -g -c jogos.c

depende_do_sistema:
	gcc -g -c depende_do_sistema.c
	
folhear.o:
	gcc -g -c folhear.c
	
dados.o:
	gcc -g -c dados.c

album.o:
	gcc -g -c album.c

clean:
	rm -f *.o main

debug:
	gdb ./main

run:
	./main
