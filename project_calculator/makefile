a.out : main.o add.o mul.o div.o sub.o count.o check.o
	gcc -o a.out main.o add.o mul.o div.o sub.o count.o check.o
main.o : main.c
	gcc -c main.c
add.o : add.c
	gcc -c add.c
sub.o : sub.c
	gcc -c sub.c
mul.o : mul.c
	gcc -c mul.c
div.o : div.c
	gcc -c div.c
count.o : count.c
	gcc -c count.c
check.o : check.c
	gcc -c check.c
clean :
	rm *.out *.o
