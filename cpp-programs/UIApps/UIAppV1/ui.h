#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;

#define TYPE() (&(typeid(*this).name()[6]))

class AbstractControl
{
public:
	virtual void Draw(string indent = "")
	{
		cout << indent << TYPE() << " drawn" << endl;
	}
};


class AbstractButton : public AbstractControl{};

class AbstractTextBox: public AbstractControl{};


class AbstractContainer : public  AbstractControl {
	vector<AbstractControl*> children;
public:
	virtual void Add(AbstractControl* control) {
		children.push_back(control);
	}
	virtual void Draw(string indent = "") {
		AbstractControl::Draw(indent);

		for (auto i = 0; i < children.size(); i++) {
			children[i]->Draw(indent + "\t");
		}
	}
};

class AbstractForm: public AbstractContainer{ };

class AbstractPanel : public AbstractContainer { };


class AbstractUIFactory 
{
public:
	virtual AbstractForm* CreateForm() = 0;
	virtual AbstractTextBox* CreateTextBox() = 0;
	virtual AbstractButton* CreateButton() = 0;
	virtual AbstractPanel* CreatePanel() = 0;
};




class SteelButton : public AbstractButton {};
class SteelTextBox :public AbstractTextBox {};
class SteelForm : public AbstractForm {};
class SteelPanel : public AbstractPanel {};

class SteelUIFactory: public AbstractUIFactory
{
public:
	virtual AbstractForm* CreateForm() { return new SteelForm; }
	virtual AbstractTextBox* CreateTextBox() { return new SteelTextBox; }
	virtual AbstractButton* CreateButton() { return new SteelButton; }
	virtual AbstractPanel* CreatePanel() { return new SteelPanel; }

};

class RubberButton : public AbstractButton {};
class RubberTextBox :public AbstractTextBox {};
class RubberForm : public AbstractForm {};
class RubberPanel : public AbstractPanel {};

class RubberUIFactory : public AbstractUIFactory
{
public:
	virtual AbstractForm* CreateForm() { return new RubberForm; }
	virtual AbstractTextBox* CreateTextBox() { return new RubberTextBox; }
	virtual AbstractButton* CreateButton() { return new RubberButton; }
	virtual AbstractPanel* CreatePanel() { return new RubberPanel; }

};

