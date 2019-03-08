//David Garcia
//Assignment 5
//Pointer lab
#include <iostream>
using namespace std;
int main()
{
  int* p1;
  int* p2;
  p1 = new int;
  p2 = new int;
  *p1 = 1;
  *p2 = 2;
  cout << "\nPointer 1: " << *p1 
       << "\nPointer 2: " << *p2;
  delete p2;
  p2 = p1;
  cout << "\n\nPointer 2: " << *p2;
  delete p1;
  p1 = NULL;
  
  p2 = new int;
  *p2 = 3;
  cout << "\n\nPointer 2: " << *p2 << endl << endl;
  return 0;
}
