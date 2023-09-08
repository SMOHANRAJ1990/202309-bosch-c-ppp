#pragma once
#include <iostream>
using namespace std;
#include "Shape.h"

enum Orientation{Horizontal,Vertical};

class ProperRectangle : public Rectangle
{
	double width, height;

public:
	ProperRectangle(double width, double height)
	{
		this->width = width;
		this->height = height;
	}


	virtual double Perimeter() { return 2 * (width + height); }
	virtual double Area() { return  (width * height); }
	virtual void Draw() 
	{ 
		cout << typeid(*this).name() << "[" << width << "," << height << "] drawn" << endl;
	}
	virtual Orientation GetOrientation() 
	{ 
		return width > height ? Orientation::Horizontal 
							: Orientation::Vertical; }

	double& Width() { return width; }
	double& Height() { return height; }
};
