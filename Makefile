CFLAGS=-Wall -Wextra

all: bTLB_calc libbTLB_calc.a docs

bTLB_calc.o: bTLB_calc.c bTLB_calc.h
	$(CC) -c bTLB_calc.c

bTLB_calc: bTLB_calc.o main.c
	$(CC) -o bTLB_calc bTLB_calc.o main.c $(LDFLAGS)

libbTLB_calc.a: bTLB_calc.o
	$(AR) rcs libbTLB_calc.a bTLB_calc.o

docs: bTLB_calc.cfg mainpage.dox *.h
	rm -rf docs
	doxygen bTLB_calc.cfg

clean:
	rm -f *.o bTLB_calc libbTLB_calc.a
	rm -rf docs
