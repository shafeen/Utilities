CFLAGS=-c
LDFLAGS=-std=c++11 

all: test

test: HashMap.o testmain.o 
	g++ HashMap.o testmain.o -o test.out 

testmain.o: testmain.cpp
	g++ $(CFLAGS) testmain.cpp $(LDFLAGS)

HashMap.o: HashMap.cpp
	g++ $(CFLAGS) HashMap.cpp $(LDFLAGS)	


clean:
	rm *.o *.out