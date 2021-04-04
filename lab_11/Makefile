CFLAGS=-c -Wall -Wextra -Werror -I include/ -std=c++14
CXX=g++

lab_11: obj/main.o
	$(CXX) obj/main.o -o lab_11

obj:
	mkdir obj

obj/main.o: src/main.cpp include/my_vector.hpp include/my_vector_impl.hpp | obj
	$(CXX) $(CFLAGS) src/main.cpp -o obj/main.o

.PHONY: clean
clean:
	rm -rf obj/ lab_11