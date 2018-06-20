#ifndef POLYGON_H
#define POLYGON_H

class Polygon
{
	protected:
		int width, height;
		Polygon(int w, int h);
		
	public:
		void setWidth(int width);
		int getWidth(void) const;
		void setHeight(int height);
		int getHeight(void) const;
		virtual int area(void) const = 0;
	
};

#endif // POLYGON_H