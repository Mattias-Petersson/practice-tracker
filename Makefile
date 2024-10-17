CXX = g++
CXXFLAGS = -std=c++23 -g

SRCS = main.cpp practicesession/practicesession.cpp practicegroup/practicegroup.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all data clean

all: data main.out
	./main.out

data:
	mkdir -p data

main.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -f main.out $(OBJS)