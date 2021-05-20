FLAGS = -O2

SRC = source/
BLD = build/
INC = include/

OBJECTS = main.o input.o engConvert.o operations.o print.o search.o resistor.o
SOURCES = $(OBJECTS:.o=.c)


app: objs
	gcc $(FLAGS) $(addprefix build/, $(OBJECTS)) -o REQ

objs: source/* include/*
	cd build && gcc -c $(addprefix ../source/, $(SOURCES))


test: app
	./REQ -i 48.3k -r 47k -p 15

.PHONY: clean

clean:
	rm $(BLD)*
