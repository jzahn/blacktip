compile: src/main.cpp
	g++ -Wall -o blacktip src/*.cpp src/blacktip/*.cpp -lncurses

debug:
	g++ -Wall -g -o blacktip src/*.cpp src/blacktip/*.cpp -lncurses

static:
	g++ -static -Wall -g -o  blacktip src/*.cpp src/blacktip/*.cpp -lncurses

clean:
	rm blacktip
