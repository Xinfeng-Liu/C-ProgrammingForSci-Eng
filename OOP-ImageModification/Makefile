all: proj3.exe

proj3.o: proj3.cpp constants.h RowColumnClass.h ColorClass.h RectangleClass.h PatternClass.h ColorImageClass.h printMainMenue.h isInputValid.h colorOptions.h
	g++ -c proj3.cpp -o proj3.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h constants.h RowColumnClass.h ColorClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

printMainMenue.o: printMainMenue.cpp printMainMenue.h constants.h
	g++ -c printMainMenue.cpp -o printMainMenue.o

isInputValid.o: isInputValid.cpp isInputValid.h
	g++ -c isInputValid.cpp -o isInputValid.o

colorOptions.o: colorOptions.cpp colorOptions.h constants.h
	g++ -c colorOptions.cpp -o colorOptions.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h RowColumnClass.h ColorClass.h RectangleClass.h PatternClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -c ColorClass.cpp -o ColorClass.o

PatternClass.o: PatternClass.cpp PatternClass.h constants.h RowColumnClass.h ColorClass.h RectangleClass.h ColorImageClass.h
	g++ -c PatternClass.cpp -o PatternClass.o

proj3.exe: RowColumnClass.o RectangleClass.o proj3.o printMainMenue.o isInputValid.o colorOptions.o ColorImageClass.o ColorClass.o PatternClass.o
	g++ RowColumnClass.o RectangleClass.o proj3.o printMainMenue.o isInputValid.o colorOptions.o ColorImageClass.o ColorClass.o PatternClass.o -o proj3.exe

clean:
	rm -f *.o *.exe