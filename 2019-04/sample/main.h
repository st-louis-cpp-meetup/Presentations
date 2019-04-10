#pragma once

#include <iostream>

class A
{
public:
	A() {};

	virtual void print() { std::cout << "Class A" << "\n"; }
}

class B : public A
{
public:
	B() : member_(0) { /* a comment */ };

	virtual void print() { std::cout << "Class B\n  member_: " << member_; << "\n"; }


private:
	int member_ = 0;
}