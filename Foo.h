#pragma once

class Foo {

public:
	Foo() :
		num(1)
	{
	}

	Foo(const int num) :
		num(num)
	{

	}

	~Foo() {

	}

	int GetNum() {
		return num;
	}

private:
	int num;

};