CXX = g++
CXXFLAGS = -std=c++23 -g

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main.out main.cpp practicesession/practicesession.cpp practicegroup/practicegroup.cpp
	./main.out


clean:
	rm -f main.out


