CC = gcc
UTILDIR = ../../util
OBJECTS = $(UTILDIR)/util.o recur.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

recur.o: recur.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

main.o: main.c
	$(CC) -c -o $@ $< -I$(UTILDIR)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
