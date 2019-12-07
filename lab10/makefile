sort : main.o util.o insertionsort.o quicksort.o
	gcc --std=c99 -Wall -o sort main.o util.o insertionsort.o quicksort.o

quicksort.o : quicksort.c quicksort.h
	gcc --std=c99 -Wall -c -o quicksort.o quicksort.c

insertionsort.o : insertionsort.c insertionsort.h
	gcc --std=c99 -Wall -c -o insertionsort.o insertionsort.c

util.o : util.c util.h
	gcc --std=c99 -Wall -c -o util.o util.c

main.o : main.c main.h util.h insertionsort.h quicksort.h
	gcc  --std=c99 -Wall -c -o main.o main.c



