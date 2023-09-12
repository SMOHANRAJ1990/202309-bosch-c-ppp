#pragma once
#include <iostream>
using namespace std;


class Tank
{
public:
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void Move() = 0;
};

class AggresiveTank :public Tank
{
public:
	virtual void Attack() { cout << "Fire" << endl; }
	virtual void Defend() { cout << "Cover Fire" << endl; }
	virtual void Move() { cout << "Run towards Enemy" << endl; }

};

class DefensiveTank :public Tank
{
public:
	virtual void Attack() { cout << "Wait" << endl; }
	virtual void Defend() { cout << "Hide" << endl; }
	virtual void Move() { cout << "Run away from Enemy" << endl; }

};

class GurillaTank :public Tank
{
public:
	virtual void Attack() { cout << "Fire" << endl; Move(); }
	virtual void Defend() { cout << "Duck" << endl; }
	virtual void Move() { cout << "Hapazard Move" << endl; }

};

void TestTank(Tank* tank) {
	cout << "Testing Tank " << typeid(*tank).name() << endl;
	tank->Move();
	tank->Attack();
	tank->Defend();
	cout << endl << endl;
}