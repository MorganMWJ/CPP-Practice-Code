#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Polygon.h"

class Rectangle: public Polygon
{		
	public:
		Rectangle(int w, int h);
		virtual int area(void) const;
		int perimeter(void) const;
		std::string to_string(void) const;
};

#endif // RECTANGLE_H