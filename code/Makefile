CFLAGS = -g -Iinclude 

all: DnD

DnD: obj obj/main.out obj/logics.out 
	g++ -o  DnD obj/main.out obj/logics.out

obj:
	mkdir -p obj

obj/main.out: src/main.cpp include/logics.h | obj
	g++ -c -o obj/main.out $(CFLAGS) src/main.cpp

obj/logics.out: src/logics.cpp include/logics.h | obj
	g++ -c -o obj/logics.out $(CFLAGS) src/logics.cpp

clean:
	rm  -rf DnD obj