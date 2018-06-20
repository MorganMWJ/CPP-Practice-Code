#This is my first ever Makefile
#command [make all] will compile the whole program
#FORMAT OF MAKEFILE below
#
#target: dependency
#	action
#
#To compile whole thing requires all object 
#files be compiled. 
#
# Currently only works when giving make command
# the name of the make file
# i.e: [make -f makefile.mak all] (-B option means unconditionally make all targets)
all: main.o Polygon.o Rectangle.o Triangle.o
	g++ main.o Polygon.o Rectangle.o Triangle.o -o polygonProgram
		
main.o: main.cpp
	g++ -c main.cpp
	
Polygon.o: Polygon.cpp Polygon.h
	g++ -c Polygon.cpp
	
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp
	
Triangle.o: Triangle.cpp Triangle.h
	g++ -c Triangle.cpp
	
#command [make -f makefile.mak clean] 
clean:
	rm *.o *.exe