// Demo01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
using namespace std;
#include "Shape.h"
#include "Rectangle.h"
#include "RSquare.h"
#include "Square.h"

int main()
{
    Rectangle* rectangles[] = {
        new ProperRectangle(4, 9),
        new RSquare(9),
        new Square(9),
        new ProperRectangle(8, 2),
        NULL
    };

    for (int i = 0; rectangles[i]; i++) {
        rectangles[i]->Draw();
        cout << "Area " << rectangles[i]->Area() << endl
            << "Perimeter " << rectangles[i]->Perimeter() << endl;

        ProperRectangle* pr = dynamic_cast<ProperRectangle*>(rectangles[i]); //returns NULL FOR INVALID CAST

        if(pr!=NULL)
            cout << "Orientation " << (pr->GetOrientation()?"Vertical":"Horizontal") << endl;

        cout << endl;
    }

    RSquare s(5);
    
    cout << typeid(s).name() << endl;
    s.Draw();
    s.Width() = 50;
    s.Draw();
}
