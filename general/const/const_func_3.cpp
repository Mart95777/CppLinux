// const function problems
#include <iostream>

#define ARRSIZE 100

class MyArray
{
	int ar[ARRSIZE];
	
	int *p;
	
	// connot be without mutable: increment of member ... in read-only...
	//int accessCnt;
	mutable int accessCnt = 0;
	
public:
	
	MyArray()
	{
		p = ar;
	}
	
	int getItem(int pos) const 
	{
		accessCnt++;
		return ar[pos];
	}
	
	// const function, but changes array value
	void setItem(int pos, int val) const
	{
		*(p+pos) = val;
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
	
	a.setItem(7,17);
	
	std::cout << "a[7]: " << a.getItem(7) << std::endl;
	std::cout << " accessed: "  << a.getAccessed() << std::endl;
	
    return 0;
}