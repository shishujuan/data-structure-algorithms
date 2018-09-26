CC = gcc
UTILDIR = ../../util
OBJECTS = $(UTILDIR)/util.o bsearch.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	
main.o: main.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
