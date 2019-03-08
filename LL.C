//David Garcia
//CS211 Assignment 7
//LList-implementation file
/***************************************************/
#include <iostream>
#include "LL.h"
using namespace std;

//PURPOSE: Constructor, intializes front, rear, and count
LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: Destructor, clears memory befor exiting program
LL::~LL()
{
   while(!isEmpty())
     deleteFront();
}

//PURPOSE: Checks if LList is empty
//PARAMS: N/A
//ALGORITHHM: Checks if front and rear are both set to NULL
bool LL::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;   
  else
    return false;
}

//PURPOSE: Adds elements from smallest to biggest
//PARAMS: New element to be added to linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in ascending order
void LL::addInOrderAscend(el_t e)
{
  if(count == 0)
    addRear(e); //Nothing in linked list yet so add to rear
  else if(e < front-> elem)
    addFront(e); //If the front element is is bigger call add front
  else
    {
      node* p = front; //Make the front new pointer to not move front pointer
      while(p-> next != NULL && p-> next -> elem <= e) //Go to desired location 
	p = p-> next;
      node* n = new node;
      n-> next = p-> next; 
      p-> next = n;
      n-> elem = e;
      count ++;
    }       
}

//PURPOSE: Adds elements from biggest to smallest
//PARAMS: New element to be added to linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in descending order
void LL::addInOrderDescend(el_t e)
{
  if(count == 0)
    addRear(e); //Nothing in the list yet
  else if(e > front-> elem)
    addFront(e);
  else
    {
      node* p = front;
      while(p-> next != NULL && p-> next -> elem >= e)
        p = p-> next;
      node* n = new node;
      n-> next = p-> next;
      p-> next = n;
      n-> elem = e;
      count ++;
    }
}

//PURPOSE:Adds an element at the rear
//PARAMS: New element of el_t type
//ALGORITHHM: If there are no elements yet, makes front and rear point to
//            new el_t type, else just makes rear point to new el_t type
//            else it points rear next to a new node, iserts element into
//            new rear element, and sets rear next pointer equal to NULL 
void LL::addRear(el_t e)
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

//PURPOSE:Adds an element at the front
//PARAMS: New element of el_t type
//ALGORITHHM: If there are no elements yet, calls addRear to make a
//            new el_t type, else makes a temporary equal to front
//            and front point to new node, passes element to element
//            slott in node structure and front pointer equal to temp
void LL::addFront(el_t e)
{
  if(count == 0)
    addRear(e);
  else
    {
      node* temp = front;
      front = new node;
      front-> elem = e;
      front-> next = temp;
      count++;
    }
}

//PURPOSE: Deletes a specific element from list
//PARAMS: Element to be deleted from linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element than sets pointers to new location, finally deletes node
void LL::deleteNode(el_t e)
{
  if(isEmpty())
    return;
  else
    {
      if(e == front-> elem)
	deleteFront();
      else
	{
	  node* p = front;
	  node* d = front-> next;
	  for(p, d; d != NULL && d-> elem != e; p = d, d = d->next);
	  
	  if(d == NULL)
	    return;
	  else if(d != NULL)
	    p-> next = d-> next;
	  else if(d == rear)
	    rear = p;
	  delete d;
	  count --;
	}
    }
}

//PURPOSE: Deletes a specific element from list
//PARAMS: Element to be deleted from linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element than sets pointers to new location, finally deletes node
//            Repets until all occureneces are deleted
void LL::deleteNodes(el_t e)
{
  if(isEmpty())
    return;
  else
    {
      if(front-> elem == e)
	deleteFront();
      if(count > 1)
	{
	  node* p = front;
	  node* d = front-> next;
	  for(p, d; d != NULL; p = d, d = d->next)
	    {
	      if(d == rear && d-> elem == e)
		deleteRear();
	      else if(d-> elem == e)
		{
		  p-> next = d-> next;
		  delete d;
		  count --;
		}
	    }
	}
    }
}

//PURPOSE:Deletes the front element in LList
//PARAMS: N/A
//ALGORITHHM: If only no elements calls emergency exit, 
//            if only one element calls deleteFront, else 
//            sets temp equal to 2nd to last cell, then deletes rear
//            and sets rear equal to temporary, returns element deleted
el_t LL::deleteRear()
{
  el_t x;
  if(count == 0)
    LListError("Error! ");
  else if(count == 1)
    return deleteFront();
  else
    {
      x = rear-> elem;
      node* p = front;
      while(p-> next != rear)
	p = p->next;
      delete rear;
      rear = p;
      rear->next = NULL;
      count --;
      return x;
    }
}

//PURPOSE:Deletes the front element in LList
//PARAMS: N/A
//ALGORITHHM: Sets a temporary equal to front pointer then sets front equal
//            equal to next cell, then deletes temporary, returns element deleted
el_t LL::deleteFront()
{
  el_t x;
  if(isEmpty())
    LListError("Error!");
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

//PURPOSE:Displays content of the LList
//PARAMS: N/A
//ALGORITHHM: Uses while loop and a temporary pointer, that is equal to front, to
//            go through the list and cout's the content
void LL::displayAll()
{
  if(isEmpty())
    return;
  else
    {
      node* p = front;
      while(p != NULL)
	{
	  cout << p-> elem << " ";
	  p = p-> next;
	}
      cout << endl;
    }
}

//PURPOSE: Emergency exit, end program
//PARAMS: String explaining why there was an error
//ALGORITHHM: Uses cout and exits the program
void LL::LListError(string msg)
{
  cout << msg << endl; 
  exit(1); 
}

//PURPOSE: Access the private member front
//PARAMS: N/A
//ALGORITHHM: Calls other function passing front
void LL::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE:Prints the LList in reverse order
//PARAMS:Pointer that points to front
//ALGORITHHM:Uses recursive method, calling itself so it can print out 
//           in reverse. Uses the system stack
void LL::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
    {
      printAllReverse(p->next);
      cout << p-> elem;
    }
}
      
//PURPOSE: Searches the linked list for specific element
//PARAMS: Element to be found in linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element and returns true, if not found or LL is empty it returns false
bool LL::search(el_t e)
{
  if(isEmpty())
    return false;
  else
    {
      node* t = front;
      for(t; t != NULL; t = t->next)
	{
	  if(t-> elem == e)
	    return true;
	}
	return false; 
    }
}
