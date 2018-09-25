CC = gcc
UTILDIR = ../../../util
ASLISTDIR = ../../list/aslist
OBJECTS = $(UTILDIR)/util.o $(ASLISTDIR)/aslist.o bt.o btstack.o btqueue.o quiz.o main.o

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	
quiz.o: quiz.c
	$(CC) -c -o $@ $< -I$(UTILDIR) -I$(ASLISTDIR)

main.o: main.c
	$(CC) -c -o $@ $< -I$(UTILDIR) -I$(ASLISTDIR)

test: clean main
	./main

.PHONY: clean
clean:
	-rm -f main $(OBJECTS)
