CC = gcc
UTILDIR = ../../util
OBJECTS = $(UTILDIR)/util.o sort.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	
sort.o: sort.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

main.o: main.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
