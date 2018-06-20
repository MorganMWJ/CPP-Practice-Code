#include "Rectangle.h"

Rectangle::Rectangle(int w, int h): Polygon(w,h)
{
}

int Rectangle::area(void) const
{
	return width*height;
}

int Rectangle::perimeter(void) const
{
	return (width*2)+(height*2);
}

std::string Rectangle::to_string(void) const
{
	std::string output = "";
	output += "Ploygon Class:  Rectangle\n";
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