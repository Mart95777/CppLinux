#include <iostream>

int main()
{
  // non-const variable
  int i = 3;
  i = 5; // ok to change

  // const variable
  const int j = 7;
  // uncomment to see
  // error: assignment of read-only ...
  //j = 8;
  
  // writing it differently
  int const k = 9;
  //k = 10;
  
  // data is const, pointer NOT const
  const int *p1 = &k;
  // error
  //*p1 = 2;
  // but we can change pointer
  std::cout << "*p1: " << *p1 << std::endl;
  p1++;
  std::cout << "*p1: " << *p1 << std::endl;

  // and somewhat differently
  int const *p2 = &k;
  // error
  //*p2 = 2;
  // but we can change pointer
  std::cout << "*p2: " << *p2 << std::endl;
  p2++;
  std::cout << "*p2: " << *p2 << std::endl;

  // this is opposite, data is not const, but pointer is, using i variable
  int * const p3 = &i;
  std::cout << "*p3: " << *p3 << std::endl;
  *p3 = 10;
  std::cout << "*p3: " << *p3 << std::endl;
  // error
  //p3++;
  
  return 0;
}

