//David Garcia
//CS211 Assignment 5
//LQueue-implementation file
/***************************************************/
#include <iostream>
using namespace std;
#include "lqueue.h"

int main()
{
  LQueue q; //Declare lqueue variable
  //Check if its empty
  if(q.isEmpty())
    cout << "Linked queue is empty!\n";
  else
    cout << "Linked queue is not empty\n";

  q.displayAll();//Display contents of queue
  cout << endl;

  q.addRear(1); //Add element
  q.displayAll(); //Display all
  cout << endl;
  
  q.addRear(2); //Add three more elements
  q.addRear(3);
  q.addRear(4);
  
  q.displayAll(); //Display all
  
  cout << "\nElement deleted: " << q.deleteFront() << endl; //Delete 3 elements and
  cout << "Element deleted: " << q.deleteFront() << endl;   //display them
  cout << "Element deleted: " << q.deleteFront() << endl;

  q.displayAll(); // Diaply contents of queue
  //Check if queue is empty
  if(q.isEmpty())
    cout << "\nLinked queue is empty!\n";
  else
    cout << "\nLinked queue is not empty\n";

  cout << "Element deleted: " << q.deleteFront() << endl; //Delete element, diplay it
  //Check if queue is empty
  if(q.isEmpty())
    cout << "Linked queue is empty!\n";
  else
    cout << "Linked queue is not empty\n";

  q.displayAll(); //Display contents of queue
  cout << endl;

  return 0;
}

  
