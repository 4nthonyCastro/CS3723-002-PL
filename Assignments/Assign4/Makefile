a2objects = prog.o

prog.o: prog.c
	gcc -g -c prog.c -o prog.o

prog: ${a2objects}
	gcc -g -o prog ${a2objects}

clean:     
	rm -f ${a2objects}
