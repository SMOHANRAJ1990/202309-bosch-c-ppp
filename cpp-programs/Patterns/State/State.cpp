// State.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
using namespace std;
//#include "tank01.h"
//#include "tank02.h"
#include "tank03.h"




template<typename TANK, typename MODE>
void TestTankMode(TANK* tank, MODE mode) {
    cout << "Testing Tank  mode "  << typeid(*mode).name() << endl;
    tank->Mode() = mode;
    tank->Move();
    tank->Attack();
    tank->Defend();
    cout << endl << endl;
}

int main()
{
    /*TestTank(new AggresiveTank());
    TestTank(new DefensiveTank());
    TestTank(new GurillaTank());*/

    Tank* tank = new Tank();

    TestTankMode(tank, new AggresiveTankMode());
    TestTankMode(tank, new DefensiveTankMode());
    TestTankMode(tank, new GurillaTankMode());
}
