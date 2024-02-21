test: test_minqueue.o 
	g++ -o test test_minqueue.o 

main.o: test_minqueue.cpp minqueue.h minqueue.cpp 
	g++ -c test_minqueue.cpp