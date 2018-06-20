#include "Triangle.h"

Triangle::Triangle(int w, int h): Polygon(w,h)
{
}

int Triangle::area(void) const
{
	return (width*height)/2;
}

std::string Triangle::to_string(void) const
{
	std::string output = "";
	output += "Ploygon Class:  Triangle\n";
	output += "Ploygon Area:   ";
	output += std::to_string(this->area());
	output += "\n";
	output += "Ploygon Width:   ";
	output += std::to_string(this->width);
	output += "\n";
	output += "Ploygon Height:   ";
	output += std::to_string(this->height);
	output += "\n";
	return output; //returns a copy of the stack object output
}