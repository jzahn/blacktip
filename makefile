compile: src/main.cpp
	g++ -std=c++14 -Wall -o blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

debug:
	g++ -std=c++14 -Wall -g -o blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

static:
	g++ -std=c++14 -static -Wall -g -o  blacktipexp src/*.cpp src/blacktip/*.cpp -lncurses

clean:
	rm blacktipexp
