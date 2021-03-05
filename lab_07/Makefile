CFLAGS:=-Wall -Wextra -Werror -I include -std=c++11
 
lab_07: obj/main.o obj/matrix.o
	g++ obj/main.o obj/matrix.o -o lab_07

obj: 
	mkdir obj
 
obj/main.o: src/main.cpp include/*.hpp | obj
	g++ -c $(CFLAGS) src/main.cpp -o obj/main.o
  
obj/matrix.o: src/matrix.cpp include/*.hpp | obj
	g++ -c $(CFLAGS) src/matrix.cpp -o obj/matrix.o
 
.PHONY: clean
clean:
	rm -rf lab_07 obj
