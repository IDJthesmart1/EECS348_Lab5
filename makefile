# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall -Wextra -pedantic

# both "make" and "make all" will build both programs
all: Sales Matrix
Sales: sales-report-lab.o
	gcc sales-report-lab.o -o Sales

sales-report-lab.o: sales-report-lab.c
	gcc $(CFLAGS) sales-report-lab.c

Matrix: matrix-lab.o
	gcc matrix-lab.o -o Matrix

matrix-lab.o: matrix-lab.c
	gcc $(CFLAGS) matrix-lab.c

# auxiliary functions

runSales: Sales
	./Sales

runMatrix: Matrix
	./Matrix

# removes any ".o" files
clean:
	rm -rf *.o