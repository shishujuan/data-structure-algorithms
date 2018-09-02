objects = main.o adlist.o
cc = gcc

main: $(objects)
	cc -o $@ $(objects)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(objects)
