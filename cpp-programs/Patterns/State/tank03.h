#pragma once


#pragma once
#include <iostream>
using namespace std;


class TankMode
{
public:
	virtual void AttackBehavior() = 0;
	virtual void DefendBehavior() = 0;
	virtual void MoveBehavior() = 0;
};

class AggresiveTankMode :public TankMode
{
public:
	virtual void AttackBehavior() { cout << "Fire" << endl; }
	virtual void DefendBehavior() { cout << "Cover Fire" << endl; }
	virtual void MoveBehavior() { cout << "Run towards Enemy" << endl; }

};

class DefensiveTankMode :public TankMode
{
public:
	virtual void AttackBehavior() { cout << "Wait" << endl; }
	virtual void DefendBehavior() { cout << "Hide" << endl; }
	virtual void MoveBehavior() { cout << "Run away from Enemy" << endl; }

};

class GurillaTankMode :public TankMode
{
public:
	virtual void AttackBehavior() { cout << "Fire" << endl; MoveBehavior(); }
	virtual void DefendBehavior() { cout << "Duck" << endl; }
	virtual void MoveBehavior() { cout << "Hapazard Move" << endl; }

};

class Tank
{
	TankMode *_mode;
public:
	TankMode* & Mode() { return _mode; }

	void Move() {
		_mode->MoveBehavior();
	}

	void Attack() {
		_mode->AttackBehavior();
	}

	void Defend() {
		_mode->DefendBehavior();
	}

};

