#pragma once

class AbstractButton
{

};

class AbstractTextBox
{

};

class AbstractForm
{
public:
	void Add(AbstractButton* button) {}
	void Add(AbstractTextBox* textBox) {}
	void Draw(){}
};



class AbstractUIFactory {
public:
	virtual AbstractForm* CreateForm() = 0;
	virtual AbstractButton* CreateButton() = 0;
	virtual AbstractTextBox* CreateTextBox() = 0;
};

class RubberForm :public AbstractForm {};
class RubberTextBox : public AbstractTextBox {};
class RubberButton : public AbstractButton {};

class RubberUIFactory :public AbstractUIFactory {

public:
	virtual AbstractForm* CreateForm() { return new RubberForm; }
	virtual AbstractButton* CreateButton() { return new RubberButton; }
	virtual AbstractTextBox* CreateTextBox() { return new RubberTextBox; }
};


