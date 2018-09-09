CC = g++
OBJECTS = main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
