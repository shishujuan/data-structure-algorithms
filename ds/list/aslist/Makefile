objects = main.o aslist.o
cc = gcc


main: $(objects)
	cc -o $@ $(objects)

.c.o:
	cc -c $<

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(objects)
