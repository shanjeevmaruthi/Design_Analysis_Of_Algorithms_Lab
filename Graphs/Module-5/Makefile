all: prims kruskal ouralgo

prims: obj/prims.o obj/input.o
	g++ obj/prims.o obj/input.o -o prims

kruskal: obj/kruskal.o obj/input.o
	g++ obj/kruskal.o obj/input.o -o kruskal

ouralgo: obj/ouralgo.o obj/input.o
	g++ obj/ouralgo.o obj/input.o -o ouralgo

obj/ouralgo.o: src/ouralgo.cpp
	g++ -c src/ouralgo.cpp -o obj/ouralgo.o

obj/prims.o: src/prims.cpp
	g++ -c src/prims.cpp -o obj/prims.o

obj/kruskal.o: src/kruskal.cpp
	g++ -c src/kruskal.cpp -o obj/kruskal.o

obj/input.o: src/input.cpp
	g++ -c src/input.cpp -o obj/input.o

