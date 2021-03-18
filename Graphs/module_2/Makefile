all: bfs

bfs: obj/bfs.o obj/input.o
	g++ obj/bfs.o obj/input.o -o bfs

obj/bfs.o: src/bfs.cpp
	g++ -c src/bfs.cpp -o obj/bfs.o

obj/input.o: src/input.cpp
	g++ -c src/input.cpp -o obj/input.o
