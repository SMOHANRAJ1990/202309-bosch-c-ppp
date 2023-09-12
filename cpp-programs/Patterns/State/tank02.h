#pragma once
#include <iostream>
using namespace std;

enum TankMode{Aggresive, Defensive, Gurilla};

class Tank
{
	TankMode _mode;
public:
	TankMode& Mode() { return _mode; }

	void Move() {
		switch (_mode) {
		case TankMode::Aggresive:
			cout << "Move Towards Enemy" << endl;
			break;
		case TankMode::Defensive:
			cout << "Run Away from Enemy" << endl;
			break;
		case TankMode::Gurilla:
			cout << "Move Hapazard" << endl;
			break;
		}
	}

	void Attack() {
		switch (_mode) {
		case TankMode::Aggresive:
			cout << "Fire" << endl;
			break;
		case TankMode::Defensive:
			cout << "Wait" << endl;
			break;
		case TankMode::Gurilla:
			cout << "Fire" << endl;
			Move();
			break;
		}
	}

	void Defend() {
		switch (_mode) {
		case TankMode::Aggresive:
			cout << "Cover Fire" << endl;
			break;
		case TankMode::Defensive:
			cout << "Hide" << endl;
			break;
		case TankMode::Gurilla:
			cout << "Duck" << endl;
			break;
		}
	}
};