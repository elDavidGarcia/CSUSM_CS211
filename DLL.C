//David Garcia
//CS211 Assignment 7
//DLList-implementation file
/***************************************************/
#include <iostream>
#include "DLL.h"
using namespace std;

//PURPOSE: Constructor, intializes front, rear, and count
DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: Destructor, clears memory before exiting program
DLL::~DLL()
{
  while(!isEmpty())
    deleteFront();
}

//PURPOSE: Checks if DLList is empty
//PARAMS: N/A
//ALGORITHHM: Checks if front and rear are both set to NULL, returns true or false
bool DLL::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;   
  else
    return false;
}

//PURPOSE: Adds elements from smallest to biggest
//PARAMS: New element to be added to double linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in ascending order
void DLL::addInOrderAscend(el_t e)
{
  if(count == 0)
    addRear(e); //Nothing in linked list yet so add to rear
  else if(e <= front-> elem)
    addFront(e); //If the front element is is bigger call add front
  else if( e >= rear -> elem) 
    addRear(e); //If the front element is is smaller call addRear
  else
    {
      node* p = front; //Make the front new pointer to not move front pointer
      for(p; p-> next != NULL && p-> next -> elem <= e; p = p-> next); //Go to desired location 
      node* n = new node;  
      n-> next = p-> next; 
      n-> prev = p;        
      p-> next-> prev = n;
      p-> next = n;
      n-> elem = e;
      count ++;
    }       
}

//PURPOSE: Adds elements from biggest to smallest
//PARAMS: New element to be added to double linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in descending order
void DLL::addInOrderDescend(el_t e)
{
  if(count == 0)
    addRear(e); //Nothing in the list yet
  else if(e >= front-> elem)
    addFront(e);
  else if(e <= rear-> elem)
    addRear(e);
  else
    {
      node* p = front; //Make a new node pointed by p equal to front
      for(p; p-> next != NULL && p-> next -> elem >= e; p = p-> next); //Go to desired location
      node* n = new node;
      n-> next = p-> next;
      n-> prev = p;
      p-> next-> prev = n;
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
void DLL::addRear(el_t e)
{
  if(count == 0) //The list is empty
    {
      front = rear = new node; //Create the first new node
      front-> next = NULL;
      front-> prev = NULL;
    }
  else
  {
    rear-> next = new node; //List alreaduy contains some element
    rear-> next -> prev = rear;
    rear = rear-> next;
  }
  rear-> next = NULL;
  rear-> elem = e;
  count++;
}

//PURPOSE:Adds an element at the front
//PARAMS: New element of el_t type
//ALGORITHHM: If there are no elements yet, calls addRear to make a
//            new el_t type, else makes a temporary equal to front
//            and front point to new node, passes element to element
//            slott in node structure and front pointer equal to temp
void DLL::addFront(el_t e)
{
  if(count == 0) //No contents in list call addRear to add first
    addRear(e);
  else //Already existing elements in list
    {
      node* temp = front;
      front = new node;
      front-> elem = e;
      front-> next = temp;
      temp-> prev = front;
      front-> prev = NULL;
      count++;
    }
}

//PURPOSE: Deletes a specific element from list
//PARAMS: Element to be deleted from linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element than sets pointers to new location, finally deletes node
void DLL::deleteNode(el_t e)
{
  if(isEmpty())
    return;
  else
    {
      if(e == front-> elem)
	deleteFront();
      else
	{
	  node* d = front;
	  for(d; d != NULL && d-> elem != e; d = d->next);
	  if(d == NULL) //Element not found
	    return;
	  else if(d == rear)
	    {
	      rear = d-> prev;
	      rear-> next = NULL;
	    }
	  else if(d != NULL)
	    {
	      d-> prev-> next = d-> next;
	      d-> next-> prev = d-> prev;
	    } 
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
void DLL::deleteNodes(el_t e)
{
  if(isEmpty())
    return;
  else
    {
      node* d = front;
      for(d; d != NULL; d = d->next)
	{
	  if(d == front && d-> elem == e)
	    deleteFront();
	  else if(d == rear && d-> elem == e)
	    deleteRear();
	  else if(d-> elem == e)
	    {
	      d-> prev-> next = d-> next;
	      d-> next-> prev = d-> prev;
	      delete d;
	      count --;
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
el_t DLL::deleteRear()
{
  el_t x;
  if(count == 0) //No existing contents in the list, call error
    DLListError("Error! ");
  else if(count == 1)
    return deleteFront(); //Only one content, call delete front
  else
    {
      x = rear-> elem;
      rear = rear-> prev;
      delete rear-> next;
      rear-> next = NULL;
      count --;
      return x; //Return the element deleted
    }
}

//PURPOSE:Deletes the front element in LList
//PARAMS: N/A
//ALGORITHHM: Sets a temporary equal to front pointer then sets front equal
//            equal to next cell, then deletes temporary, returns element deleted
el_t DLL::deleteFront()
{
  el_t x;
  if(isEmpty()) //No contents in the list, call error
    DLListError("Error!");
  else if(count == 1) //Only one node in the list
    {
      x = front-> elem;
      delete front;
      front = rear = NULL;
    }
  else
    {
      x = front-> elem;
      front = front-> next;
      delete front-> prev;
      front-> prev = NULL;
    }
  count--;
  return x; //Return element deleted in the list
}

//PURPOSE:Displays content of the LList
//PARAMS: N/A
//ALGORITHHM: Uses while loop and a temporary pointer, that is equal to front, to
//            go through the list and cout's the content
void DLL::displayAll()
{
  if(isEmpty()) //Nohting inside list
    return;
  else
    {
      for(node* p = front; p != NULL; p = p-> next) //Go one by one in the list
	cout << p-> elem << " "; //Cout the element with a space in between
    }
}

//PURPOSE: Emergency exit, end program
//PARAMS: String explaining why there was an error
//ALGORITHHM: Uses cout and exits the program
void DLL::DLListError(string msg)
{
  cout << msg << endl; 
  exit(1); //emergency exit
}

//PURPOSE: Access the private member front
//PARAMS: N/A
//ALGORITHHM: Calls other function passing front
void DLL::printAllReverseDLL()
{
  if(isEmpty())
    return;
  else
    printAllReverseDLL(rear); //Call other reverse function and pass the node
}

//PURPOSE:Prints the LList in reverse order
//PARAMS:Pointer that points to front
//ALGORITHHM:Uses recursive method, calling itself so it can print out 
//           in reverse. Uses the system stack
void DLL::printAllReverseDLL(node* p)//pointer p is equal to front pointer
{
  for(p; p != NULL; p = p-> prev)
    cout << p-> elem << " ";
}
      
//PURPOSE: Searches the linked list for specific element
//PARAMS: Element to be found in linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element and returns true, if not found or LL is empty it returns false
bool DLL::search(el_t e)
{
  if(isEmpty()) //Nothing in the list
    return false;
  else
    {
      for(node* t = front; t != NULL; t = t->next) //go throught the list
	{
	  if(t-> elem == e)//element was found, return true
	    return true;
	}
	return false; 
    }
}
