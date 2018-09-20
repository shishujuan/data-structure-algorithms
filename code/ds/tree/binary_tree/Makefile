CC = gcc
OBJECTS = main.o bt.o btstack.o btqueue.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
