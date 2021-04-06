all:
	gcc main.c morsecode.c -o test -O2 -Wall

clean:
	rm -f test
