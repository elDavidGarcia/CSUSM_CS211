//David Garcia
//CS211 Assignment 5
//LQueue-implementation file
/***************************************************/
#include <iostream>
#include "lqueue.h"
using namespace std;

//PURPOSE: Constructor, intializes front, rear, and count
LQueue::LQueue()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: Destructor, clears memory befor exiting program
LQueue::~LQueue()
{
    while(!isEmpty())
      deleteFront();
}

//PURPOSE: Checks if queue is empty
//PARAMS: N/A
//ALGORITHHM: Checks if front and rear are both set to zero
bool LQueue::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;
  else
    return false;
}

//PURPOSE:Adds an element at the rear
//PARAMS: New element of el_t type
//ALGORITHHM: If there are no elements yet, makes front and rear point to
//            new el_t type, else just makes rear point to new el_t type
void LQueue::addRear(el_t e)
{
  if(count == 0)
    front = rear = new node;
  else
    {
      rear-> next = new node;
      rear = rear-> next;
    }
  rear-> elem = e;
  rear-> next = NULL;
  count++;
}

//PURPOSE:Deletes the front element in queue
//PARAMS: N/A
//ALGORITHHM: Sets a temporary equal to front pointer then sets front equal
//            equal to next cell, then deletes temporary
el_t LQueue::deleteFront()
{
  el_t x;
  if(isEmpty())
    lqueueError("Error!");
  else
    {
      node* temp = front;
      front = front-> next;
      x = temp-> elem;
      delete temp;
      count --;
      if(count == 0)
	rear = NULL;
      return x;
    }
}

//PURPOSE:Displays content of the queue
//PARAMS: N/A
//ALGORITHHM: Uses while loop and a temporary pointer, that is eual to front, to
//            go through the list and cout's the content
void LQueue::displayAll()
{
  node* p = front;
  while(p != NULL)
    {
      cout << p-> elem;
      p = p-> next;
    }
}

//PURPOSE: Emergency exit, end program
//PARAMS: String explaining why there was an error
//ALGORITHHM: Uses cout and exits the program
void LQueue::lqueueError(string msg)
{
  cout << msg << endl; 
  exit(1); 
}

//PURPOSE: Access the private member front
//PARAMS: N/A
//ALGORITHHM: Calls other function passing front
void LQueue::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE:Prints the queue in reverse order
//PARAMS:Pointer that points to front
//ALGORITHHM:Uses recursive method, calling itself so it can print out 
//           in reverse. Uses the system stack
void LQueue::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
    {
      printAllReverse(p->next);
      cout << p-> elem;
    }
}
      
