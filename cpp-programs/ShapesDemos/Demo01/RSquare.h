#pragma once
#include "Rectangle.h"

class RSquare : public ProperRectangle
{

private:
	Orientation GetOrientation() {
		cout << "private RSquare method. shouldn't be called from outside" << endl;
		//return Orientation::Horizontal; //shouldn't matter as the function is private
		throw exception("RSquare has no orientation");
	}


public:
	RSquare(double side)
		: ProperRectangle(side,side){	}
};
