// UIAppV1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ui.h"

AbstractControl* CreateUI(AbstractUIFactory* factory)
{
	AbstractPanel* p1 = factory->CreatePanel();
	p1->Add(factory->CreateTextBox());
	p1->Add(factory->CreateTextBox());

	AbstractPanel* p2 = factory->CreatePanel();
	p2->Add(factory->CreateButton());
	p2->Add(factory->CreateButton());
	p2->Add(factory->CreateButton());

	AbstractPanel* p3 = factory->CreatePanel();
	p3->Add(p1);
	p3->Add(p2);

	AbstractForm* form = factory->CreateForm();
	form->Add(p3);

	return form;

}


int main()
{
	AbstractUIFactory* factory = new SteelUIFactory();

	AbstractControl* ui = CreateUI(factory);

	ui->Draw(); //this line produces output

}
