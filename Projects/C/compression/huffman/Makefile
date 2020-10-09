project: main.o compress.o decompress.o heap.o table.o tree.o
	cc main.o compress.o decompress.o heap.o table.o tree.o -o project -Wall
main.o: main.c heap.h
	cc -c main.c -Wall
compress.o: compress.c heap.h
	cc -c compress.c -Wall
decompress.o: decompress.c tree.h
	cc -c decompress.c -Wall
heap.o: heap.c heap.h
	cc -c heap.c -Wall
table.o: table.c table.h
	cc -c table.c -Wall
tree.o: tree.c tree.h
	cc -c tree.c -Wall
