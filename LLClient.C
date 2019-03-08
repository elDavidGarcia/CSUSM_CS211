//David Garcia
//CS211 Assignment 6
//LList-implementation file
/***************************************************/
#include <iostream>
using namespace std;
#include "LL_T_E.h"

int main ()
{
  LL<int> l;
  
  try
    {
      //l.deleteFront();
      l.deleteRear();

      //Add to front of LList
      l.addFront(1); 
      l.addFront(2);
      l.addFront(3);
      //Add to rear of LList
      l.addRear(4); 
      l.addRear(5);
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl; 
      //Delete two elements
      cout<< "Element deleted: " << l.deleteFront() << endl;
      cout<< "Element deleted: " << l.deleteRear() << endl;;
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl;
      //Delete two elements
      cout<< "Element deleted: " << l.deleteFront() << endl;
      cout<< "Element deleted: " << l.deleteRear() << endl;
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl;
      //Delete one element
      cout<< "Element deleted: " << l.deleteFront() << endl;
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl;
      //Add to rear and front of LList
      l.addRear(10);
      l.addFront(11);
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl;
      //Delete two elements
      cout<< "Element deleted: " << l.deleteRear() << endl;
      cout<< "Element deleted: " << l.deleteRear() << endl;
      //Display contents of LList
      cout << "Contents of Linked List: ";
      l.displayAll();
      cout << endl;

      //l.deleteFront();
      //l.deleteRear();
    }
  
  catch(LL<int>::Underflow)
    {
      cout << "Error: trying to delete when the List is empty\n";
    }
  
  return 0;
}
