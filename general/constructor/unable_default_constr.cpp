// unable to generate default
#include <iostream>
#include <string>

class tri 
{
	// cannot use () initialiation befor c++11
    int triint = 1;
};

class polygon
{
	std::string name;
	int polyint = -1;
public:
	
    // constructor, not default, so causes error for lack of default constructor
	// when r would be constructed, there is no default for polygon
	polygon(std::string name, int i) : name(name), polyint(i) {}
	
	// this will make rect to be able to be constructed, can work with no parameters
	polygon(int i = 0) : polyint(i) {}
	
	virtual int getSides() const = 0;
};

class rect : polygon
{

public:

    virtual int getSides() const
	{
	    return 4;
    }
};


int main()
{
	// the rectangle r cannot be created, since polygon lacks default constructor.
	// but if we uncomment the other constructor, that CAN act like default
	// the one having int i = 0, it can be used without parameters
	rect r;
	std::cout << "r sides: " << r.getSides() << std::endl;
	
	return 0;
}

