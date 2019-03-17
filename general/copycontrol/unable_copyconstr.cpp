// unable to generate default
#include <iostream>

class Base
{
public:
	int n;
	Base(int n =1) : n(n) {}
	Base(const Base& b) : n(b.n) {}
};

class Deriv : public Base
{

};

class Deriv2 : public Deriv
{
public:
    Deriv2() : Deriv() {}
private:
    Deriv2(const Deriv2&);
};
	

int main()
{
	Base b1(3);
	Base b2(b1);
	
	Deriv d;
	Base b3 = d;
	
	volatile Base vb(7);
	// error
	Base b4 = vb;
	
	Deriv2 dt;
	// declared private copy constructor, cannot be used.
	//Deriv2 dt1 = dt;
	
	return 0;
}

