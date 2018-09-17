CC = gcc
INCLUDE = ../../util
OBJECTS = $(INCLUDE)/util.o heap.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

heap.o: heap.c
	$(CC) -c -o $@ $< -I$(INCLUDE)

main.o: main.c
	$(CC) -c -o $@ $< -I$(INCLUDE)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
