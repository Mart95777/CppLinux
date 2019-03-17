// const function problems
#include <iostream>

#define ARRSIZE 100

class MyArray
{
	int ar[ARRSIZE];
	int accessCnt = 0;
	
public:
	int getItem(int pos) const 
	{
		// cannot be used in const function
		//accessCnt++;
		
		// using const_cast, but use only when really needed
		// bad idea
		const_cast<MyArray*>(this)->accessCnt++;
		return ar[pos];
	}
	
	// needed just int, not ref, would be to const int
	int getAccessed() const
	{
		return accessCnt;
	}
};

int main()
{
	MyArray a;
	
	std::cout << "a[7]: " << a.getItem(7) << std::endl;
	std::cout << " accessed: "  << a.getAccessed() << std::endl;
	std::cout << "a[90]: " << a.getItem(90) << std::endl;
	std::cout << " accessed: "  << a.getAccessed() << std::endl;
	
    return 0;
}