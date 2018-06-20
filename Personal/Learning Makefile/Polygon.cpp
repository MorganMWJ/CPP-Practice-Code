#include "Polygon.h"

Polygon::Polygon(int w, int h): width(w), height(h) 
{
}

void Polygon::setWidth(int width)
{
	Polygon::width = width;
}

int Polygon::getWidth(void) const
{
	return Polygon::width;
}

void Polygon::setHeight(int height)
{
	Polygon::height = height;
}

int Polygon::getHeight(void) const
{
	return Polygon::height;
}