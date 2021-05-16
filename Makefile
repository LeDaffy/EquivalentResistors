cflags = -O2
lflags = -lgmp

App: main.c operations.h
	gcc $(cflags) -o REQ.out main.c 

test: App
	./REQ.out

clean:
