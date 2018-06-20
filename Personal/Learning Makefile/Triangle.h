#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Polygon.h"

class Triangle: public Polygon
{		
	
	public:
		Triangle(int w, int h);
		virtual int area(void) const;
		std::string to_string(void) const; 
};

#endif // TRIANGLE_H