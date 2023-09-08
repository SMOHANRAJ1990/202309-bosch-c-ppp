#pragma once

#include <iostream>
using namespace std;

#include "Shape.h"

class Square : public Rectangle
{
	double side;

public:
	Square(double side)
	{
		this->side = side;
		
	}


	virtual double Perimeter() { return 4 * side; }
	
	virtual double Area() { return  (side * side); }

	virtual void Draw()
	{
		cout <<  "Square[" << side << "] drawn" << endl;
	}
	
	double& Side() { return side; }
	
};

