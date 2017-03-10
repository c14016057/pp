all: main.o RMQ.o
	g++ main.o RMQ.o -std=c++11 -o out
main.o: main.cpp
	g++ -std=c++11 -c -O2 main.cpp
RMQ.o: RMQ.cpp
	g++ -std=c++11 -c -O2 RMQ.cpp
