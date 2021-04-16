CFLAGS=-c -Wall -Wextra -Werror -I include/ -std=c++14
CXX=g++

all: lab_13

lab_13: obj/main.o
	$(CXX) obj/main.o -o lab_13

obj:
	mkdir obj

obj/main.o: src/main.cpp include/my_array.hpp | obj
	$(CXX) $(CFLAGS) src/main.cpp -o obj/main.o

.PHONY: clean
clean:
	rm -rf obj/ lab_13