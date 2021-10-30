all: compile link
compile:
	g++ -Isrc/Include -c code/main.cpp

link:
	g++ main.o -o build/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system