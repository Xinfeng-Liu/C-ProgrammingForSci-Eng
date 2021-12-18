all: proj4.exe

proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4.o
	g++ -Wall -g -std=c++98 LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4.o -o proj4.exe

project4.o: project4.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -Wall -g -std=c++98 -Wall -c project4.cpp -o project4.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -Wall -g -std=c++98 -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp LinkedNodeClass.h SortedListClass.h
	g++ -Wall -g -std=c++98 -Wall -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp LinkedNodeClass.h FIFOQueueClass.h
	g++ -Wall -g -std=c++98 -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp LinkedNodeClass.h LIFOStackClass.h
	g++ -Wall -g -std=c++98 -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

clean: 
	rm -f *.o *.exe