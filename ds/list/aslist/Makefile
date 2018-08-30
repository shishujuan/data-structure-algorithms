objects = main.o aslist.o
cc = gcc

main: $(objects)
	cc -o $@ $(objects)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(objects)
