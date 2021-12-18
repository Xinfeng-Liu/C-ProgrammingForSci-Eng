all: proj5.exe

random.o: random.cpp random.h
	g++ -Wall -g -std=c++98 -Wall -c random.cpp -o random.o

CarClass.o: CarClass.cpp constants.h CarClass.h
	g++ -Wall -g -std=c++98 -Wall -c CarClass.cpp -o CarClass.o

EventClass.o: EventClass.cpp constants.h EventClass.h
	g++ -Wall -g -std=c++98 -Wall -c EventClass.cpp -o EventClass.o

IntersectionSimulationClass.o: IntersectionSimulationClass.cpp constants.h SortedListClass.h FIFOQueueClass.h IntersectionSimulationClass.h EventClass.h CarClass.h random.h
	g++ -Wall -g -std=c++98 -Wall -c IntersectionSimulationClass.cpp -o IntersectionSimulationClass.o

project5.o: project5.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h IntersectionSimulationClass.h random.h EventClass.h CarClass.h constants.h
	g++ -Wall -g -std=c++98 -Wall -c project5.cpp -o project5.o

proj5.exe: project5.o constants.h LinkedNodeClass.h LinkedNodeClass.inl SortedListClass.h SortedListClass.inl FIFOQueueClass.h FIFOQueueClass.inl IntersectionSimulationClass.o CarClass.o EventClass.o random.o
	g++ -Wall -g -std=c++98 random.o CarClass.o EventClass.o IntersectionSimulationClass.o project5.o -o proj5.exe

clean: 
	rm -f *.o *.exe