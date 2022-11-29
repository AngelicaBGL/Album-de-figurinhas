all: main

main: main.o jogos.o depende_do_sistema.o folhear.o dados.o
	gcc *.c -o main
	
main.o: main.c
	gcc -c main.c
	
jogos.o:
	gcc -c jogos.c

depende_do_sistema:
	gcc -c depende_do_sistema.c
	
folhear.o:
	gcc -c folhear.c
	
dados.o:
	gcc -c dados.c


clean:
	rm -f *.o main
	
run:
	./main
