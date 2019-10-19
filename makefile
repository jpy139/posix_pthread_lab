bin/app:obj/main.o obj/thread.o
	gcc obj/main.o obj/thread.o -lpthread -o bin/app

obj/main.o:src/main.c
	gcc -c src/main.c -o obj/main.o

obj/thread.o:src/thread.c
	gcc -c src/thread.c -o obj/thread.o