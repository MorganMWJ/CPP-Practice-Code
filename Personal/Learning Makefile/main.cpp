#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

//Program start point
int main()
{
	//create space for objects on stack
	Rectangle r(4,5);
	Triangle t(4,5);
	
	//polymorphic pointers to those objects
	Polygon* poly1 = &r;
	Polygon* poly2 = &t;
	
	//print out the area of both polygons
	cout << poly1->area() << endl;
	cout << poly2->area() << endl;
	
	//dynamic cast each to derived class to use to_string
	cout << dynamic_cast<Rectangle*>(poly1)->to_string() << endl;
	cout << dynamic_cast<Triangle*>(poly2)->to_string() << endl;
	
	//prevent program from closing fast
	int temp;
	cin >> temp;
	
	return 0;
}