CC = gcc
OBJECTS = main.o stack.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
