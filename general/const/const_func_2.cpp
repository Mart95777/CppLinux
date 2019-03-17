// const function problems
#include <iostream>

#define ARRSIZE 100

class MyArray
{
	int ar[ARRSIZE];
	// connot be without mutable: increment of member ... in read-only...
	//int accessCnt;
	mutable int accessCnt = 0;
	
public:
	int getItem(int pos) const 
	{
		accessCnt++;
		return ar[pos];
	}
	
	int& getAccessed() const
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