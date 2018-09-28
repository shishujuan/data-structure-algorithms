CC = gcc
UTILDIR = ../../util
STACKDIR = ../../ds/stack
OBJECTS = $(UTILDIR)/util.o $(STACKDIR)/stack.o sort.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	
sort.o: sort.c
	$(CC) -c -o $@ $< -I$(UTILDIR) -I$(STACKDIR)

main.o: main.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
