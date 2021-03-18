all: test_bipartite test_articulationpoints test_bridges

test_articulationpoints: obj/test_articulationpoints.o obj/input.o
	g++ obj/test_articulationpoints.o obj/input.o -o test_articulationpoints

obj/test_articulationpoints.o: src/test_articulationpoints.cpp
	g++ -c src/test_articulationpoints.cpp -o obj/test_articulationpoints.o


test_bipartite: obj/test_bipartite.o obj/input.o
	g++ obj/test_bipartite.o obj/input.o -o test_bipartite

obj/test_bipartite.o: src/test_bipartite.cpp
	g++ -c src/test_bipartite.cpp -o obj/test_bipartite.o

test_bridges: obj/test_bridges.o obj/input.o
	g++ obj/test_bridges.o obj/input.o -o test_bridges

obj/test_bridges.o: src/test_bridges.cpp
	g++ -c src/test_bridges.cpp -o obj/test_bridges.o

obj/input.o: src/input.cpp
	g++ -c src/input.cpp -o obj/input.o