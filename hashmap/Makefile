CFLAGS=-c
LDFLAGS=-std=c++11 

all: test

	
test: HashMap.o DebugLogger.o testmain.o 
	g++ HashMap.o DebugLogger.o testmain.o -o test.out 

runtest: test
	./test.out

testmain.o: testmain.cpp
	g++ $(CFLAGS) testmain.cpp $(LDFLAGS)

HashMap.o: HashMap.cpp
	gcc $(CFLAGS) HashMap.cpp $(LDFLAGS)

DebugLogger.o: DebugLogger.cpp
	g++ $(CFLAGS) DebugLogger.cpp $(LDFLAGS)	


clean:
	rm *.o *.out

# typo catchers
clena: clean

clnea: clean

