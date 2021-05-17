FLAGS = -O2

SRC = source/
BLD = build/
INC = include/

OBJECTS = main.o input.o engConvert.o
SOURCES = $(OBJECTS:.o=.c)


app: objs
	gcc $(FLAGS) $(addprefix build/, $(OBJECTS)) -o REQ

objs: source/* include/*
	cd build && gcc -c $(addprefix ../source/, $(SOURCES))


test: app
	./REQ -i 22.4k -r 1.1 11k 12 12.34M 2.54 5.3 -p 2.5 

.PHONY: clean

clean:
	rm $(BLD)*
