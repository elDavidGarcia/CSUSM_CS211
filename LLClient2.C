//David Garcia
//CS211 Assignment 6
//LList-implementation file
/***************************************************/
#include <iostream>
using namespace std;
#include "LL.h"

int main ()
{
  LL l2;
  l2.addRear(3);
  l2.addRear(9);
  l2.addRear(2);
  l2.addRear(1);
  l2.addRear(9);
  l2.addRear(11);
  

  cout << "##### EXTRA CREDIT -  TEST deleteNodes (all occurences) *********************** \
***************************************" << endl;

  l2.displayAll(); //[3] -> [9] -> [2] -> [1] -> [9] -> [11]
  cout << endl;

  l2.deleteNodes(9);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;

  l2.addRear(3);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11] -> [3]
  cout << endl;

  l2.deleteNodes(3);
  l2.displayAll(); //[2] -> [1] -> [11]
  cout << endl;

  l2.addRear(5);
  l2.displayAll(); //[2] -> [1] -> [11] -> [5]
  cout << endl;

  l2.deleteNodes(2);
  l2.displayAll(); //[1] -> [11] -> [5]
  cout << endl;

  l2.deleteNodes(11);
  l2.displayAll(); //[1] -> [5]
  cout << endl;

  l2.deleteNodes(5);
  l2.displayAll(); //[1]
  cout << endl;

  l2.deleteNodes(1);
  l2.displayAll(); //[empty]
  cout << endl;

  l2.deleteNodes(100); //nothing happens

  return 0;
}
  
