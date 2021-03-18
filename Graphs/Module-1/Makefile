all: dfs

dfs: obj/dfs.o obj/input.o
	g++ obj/dfs.o obj/input.o -o dfs

obj/dfs.o: src/dfs.cpp
	g++ -c src/dfs.cpp -o obj/dfs.o

obj/input.o: src/input.cpp
	g++ -c src/input.cpp -o obj/input.o