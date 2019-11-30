compile: src/main.cpp
	g++ -Wall -o blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

debug:
	g++ -Wall -g -o blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

static:
	g++ -static -Wall -g -o  blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

clean:
	rm blacktipexp
