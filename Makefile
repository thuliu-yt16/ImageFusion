all: main.exe

main.exe: obj/main.o obj/image.o obj/vector3.o obj/matrix.o obj/mask.o
	g++ -o main.exe obj/main.o obj/image.o obj/vector3.o obj/matrix.o obj/mask.o -O2 -std=c++11

obj/main.o: main.cpp
	g++ -c main.cpp -o obj/main.o -O2 -std=c++11

obj/image.o: image.cpp image.h
	g++ -c image.cpp -o obj/image.o -O2 -std=c++11

obj/vector3.o: vector3.cpp vector3.h
	g++ -c vector3.cpp -o obj/vector3.o -O2 -std=c++11

obj/mask.o: mask.cpp mask.h
	g++ -c mask.cpp -o obj/mask.o -O2 -std=c++11

obj/matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -o obj/matrix.o -O2 -std=c++11

clean:
	rm obj/*.o main.exe

run: main.exe
	./main.exe