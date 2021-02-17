all: blacktipexp

blacktipexp: blacktipexp.o main.o libblacktip.a
	g++ -lm -o blacktipexp main.o blacktipexp.o -L. -lblacktip -lncurses

test: compiletests
	./run_tests -s

compiletests: tests.o libblacktip.a
	g++ -lm -o run_tests tests.o -L. -lblacktip

tests.o: test/tests.cpp
	g++ -std=c++17 -Wall -c test/tests.cpp

main.o: src/main.cpp
	g++ -std=c++17 -Wall -c src/main.cpp

blacktipexp.o: src/blacktipexp.hpp src/blacktipexp.cpp
	g++ -std=c++17 -Wall -c src/blacktipexp.cpp

libblacktip.a: ascentmeter.o compartment.o decoalgorithm.o decoalgorithmfactory.o dsat.o haldane.o mix.o o2toxicity.o recplanner.o utility.o workman.o zhl16.o
	ar rcs libblacktip.a ascentmeter.o compartment.o decoalgorithm.o decoalgorithmfactory.o dsat.o haldane.o mix.o o2toxicity.o recplanner.o utility.o workman.o zhl16.o

ascentmeter.o: src/blacktip/ascentmeter.hpp src/blacktip/ascentmeter.cpp
	g++ -std=c++17 -Wall -c src/blacktip/ascentmeter.cpp

compartment.o: src/blacktip/compartment.hpp src/blacktip/compartment.cpp
	g++ -std=c++17 -Wall -c src/blacktip/compartment.cpp

decoalgorithm.o: src/blacktip/decoalgorithm.hpp src/blacktip/decoalgorithm.cpp
	g++ -std=c++17 -Wall -c src/blacktip/decoalgorithm.cpp

decoalgorithmfactory.o: src/blacktip/decoalgorithmfactory.hpp src/blacktip/decoalgorithmfactory.cpp
	g++ -std=c++17 -Wall -c src/blacktip/decoalgorithmfactory.cpp

dsat.o: src/blacktip/dsat.hpp src/blacktip/dsat.cpp
	g++ -std=c++17 -Wall -c src/blacktip/dsat.cpp

haldane.o: src/blacktip/haldane.hpp src/blacktip/haldane.cpp
	g++ -std=c++17 -Wall -c src/blacktip/haldane.cpp

mix.o: src/blacktip/mix.hpp src/blacktip/mix.cpp
	g++ -std=c++17 -Wall -c src/blacktip/mix.cpp

o2toxicity.o: src/blacktip/o2toxicity.hpp src/blacktip/o2toxicity.cpp
	g++ -std=c++17 -Wall -c src/blacktip/o2toxicity.cpp

recplanner.o: src/blacktip/recplanner.hpp src/blacktip/recplanner.cpp
	g++ -std=c++17 -Wall -c src/blacktip/recplanner.cpp

utility.o: src/blacktip/utility.hpp src/blacktip/utility.cpp
	g++ -std=c++17 -Wall -c src/blacktip/utility.cpp

workman.o: src/blacktip/workman.hpp src/blacktip/workman.cpp
	g++ -std=c++17 -Wall -c src/blacktip/workman.cpp

zhl16.o: src/blacktip/zhl16.hpp src/blacktip/zhl16.cpp
	g++ -std=c++17 -Wall -c src/blacktip/zhl16.cpp

lint:
	clang-tidy -checks='*' src/blacktip/* -- -std=c++17 -I. -DMY_DEFINES

clean:
	rm -f blacktipexp run_tests lint_output libblacktip.a *.o
