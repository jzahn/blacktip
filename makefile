all: blacktipexp tests

blacktipexp: blacktipexp.o main.o libblacktip.a
	g++ -lm -o blacktipexp main.o blacktipexp.o -L. -lblacktip -lncurses

tests: tests.o libblacktip.a
	g++ -lm -o run_tests tests.o -L. -lblacktip

tests.o: test/tests.cpp
	g++ -std=c++14 -Wall -c test/tests.cpp

main.o: src/main.cpp
	g++ -std=c++14 -Wall -c src/main.cpp

blacktipexp.o: src/blacktipexp.h src/blacktipexp.cpp
	g++ -std=c++14 -Wall -c src/blacktipexp.cpp

libblacktip.a: ascentmeter.o compartment.o decoalgorithim.o decoalgorithimfactory.o dsat.o haldane.o mix.o o2toxicity.o recplanner.o utility.o workman.o zhl16.o
	ar rcs libblacktip.a ascentmeter.o compartment.o decoalgorithim.o decoalgorithimfactory.o dsat.o haldane.o mix.o o2toxicity.o recplanner.o utility.o workman.o zhl16.o

ascentmeter.o: src/blacktip/ascentmeter.h src/blacktip/ascentmeter.cpp
	g++ -std=c++14 -Wall -c src/blacktip/ascentmeter.cpp

compartment.o: src/blacktip/compartment.h src/blacktip/compartment.cpp
	g++ -std=c++14 -Wall -c src/blacktip/compartment.cpp

decoalgorithim.o: src/blacktip/decoalgorithim.h src/blacktip/decoalgorithim.cpp
	g++ -std=c++14 -Wall -c src/blacktip/decoalgorithim.cpp

decoalgorithimfactory.o: src/blacktip/decoalgorithimfactory.h src/blacktip/decoalgorithimfactory.cpp
	g++ -std=c++14 -Wall -c src/blacktip/decoalgorithimfactory.cpp

dsat.o: src/blacktip/dsat.h src/blacktip/dsat.cpp
	g++ -std=c++14 -Wall -c src/blacktip/dsat.cpp

haldane.o: src/blacktip/haldane.h src/blacktip/haldane.cpp
	g++ -std=c++14 -Wall -c src/blacktip/haldane.cpp

mix.o: src/blacktip/mix.h src/blacktip/mix.cpp
	g++ -std=c++14 -Wall -c src/blacktip/mix.cpp

o2toxicity.o: src/blacktip/o2toxicity.h src/blacktip/o2toxicity.cpp
	g++ -std=c++14 -Wall -c src/blacktip/o2toxicity.cpp

recplanner.o: src/blacktip/recplanner.h src/blacktip/recplanner.cpp
	g++ -std=c++14 -Wall -c src/blacktip/recplanner.cpp

utility.o: src/blacktip/utility.h src/blacktip/utility.cpp
	g++ -std=c++14 -Wall -c src/blacktip/utility.cpp

workman.o: src/blacktip/workman.h src/blacktip/workman.cpp
	g++ -std=c++14 -Wall -c src/blacktip/workman.cpp

zhl16.o: src/blacktip/zhl16.h src/blacktip/zhl16.cpp
	g++ -std=c++14 -Wall -c src/blacktip/zhl16.cpp

clean:
	rm -f blacktipexp run_tests libblacktip.a *.o

clean_obj:
	rm -f *.o
