CXX = g++
CXXFLAGS = -Wall -g

mytest:	puzzle.o mytest.cpp
	$(CXX) $(CXXFLAGS) puzzle.o mytest.cpp -o mytest

puzzle.o: puzzle.h puzzle.cpp
	$(CXX) $(CXXFLAGS) -c puzzle.cpp

driver.o: driver.h driver.cppp
	$(CXX) $(CXXFLAGS) -c driver.cpp

mytest.o: puzzle.o mytest.cpp
	$(CXX) $(CXXFLAGS) -c mytest.cpp

clean:
	rm *.o*
	rm *~


run:
	./mytest


val:
	valgrind ./mytest

