//David Garcia
//CS211 Assignment &
//LList_T-header file
/***************************************************/
#include <iostream>
#ifndef LL_T_E_H
#define LL_T_E_H
using namespace std;

template<class T>
struct node //Node structure to be used in LL.C, two objects: element and pointer 
{
  T elem; //holds element
  node<T>* next; //Points to next element
};

//class Underflow{};

template <class T>
class LL //Start a class named LList
{
 private: //Can only be accessed through the public functions of class
  // Data members are:
  int count; //Tracks how big LLsit is 
  node<T>* front; //points to the front element of the LList is.
  node<T>* rear; //points the rear element of the LList is.
  //HOW TO CALL: Must be called by public function iside LList class 
  //PURPOSE: Emergency exit
  void LListError(string);
  //HOW TO CALL: Uses the front node pointer in the private
  //PURPOSE: Prints LList in reverse order
  void printAllReverse(node<T>*);
 public:
  LL(); // constructor
  ~LL(); //destructor
  //HOW TO CALL: No parameters
  //PURPOSE: Checks if queue is empty
  bool isEmpty(); 
  //HOW TO CALL: Pass element to be added (greatest to least)
  //PURPOSE: Adds an element to list from greatest to smallest
  void addInOrderDescend(T);
  //HOW TO CALL: Pass element to be added 
  //PURPOSE: Adds an element to list from smallest to greatest
  void addInOrderAscend(T);
  //HOW TO CALL: Pass element to be added to rear
  //PURPOSE: Adds an element at the rear
  void addRear(T);
  //HOW TO CALL: Pass element to be added to front
  //PURPOSE: Adds an element at the front
  void addFront(T);
  //HOW TO CALL: Pass an element to be deleted
  //PURPOSE: Finds element inputed by user and deletes it from the list
  void deleteNode(T);
  //HOW TO CALL: Pass an element to be deleted
  //PURPOSE: Finds element inputed by user and deletes all occurences from the list
  void deleteNodes(T);
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the rear element in LList
  T deleteRear();
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the front element in LList
  T deleteFront();
  //HOW TO CALL: No parameters
  //PURPOSE: Displays content of the LList
  void displayAll();
  //HOW TO CALL: No parameters
  //PURPOSE: Prints the LList in reverse order
  void printAllReverse();
  //HOW TO CALL: Pass element to be found
  //PURPOSE: Checks if an element is in the array
  bool search(T);
  class Underflow{};
};

//PURPOSE: Constructor, intializes front, rear, and count
template <class T>
LL<T>::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: Destructor, clears memory befor exiting program
template <class T>
LL<T>::~LL()
{
  while(!isEmpty())
    deleteFront();
}

//PURPOSE: Checks if LList is empty
//PARAMS: N/A
//ALGORITHHM: Checks if front and rear are both set to NULL
template <class T>
bool LL<T>::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;
  else
    return false;
}

//PURPOSE: Adds elements from smallest to biggest
//PARAMS: New element to be added to linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in ascending order
template <class T>
void LL<T>::addInOrderAscend(T e)
{
  if(count == 0)
    addRear(e); //Nothing in linked list yet so add to rear
  else if(e < front-> elem)
    addFront(e); //If the front element is is bigger call add front
  else
    {
      node<T>* p = front; //Make the front new pointer to not move front pointer
      while(p-> next != NULL && p-> next -> elem <= e) //Go to desired location
        p = p-> next;
      node<T>* n = new node<T>;
      n-> next = p-> next;
      p-> next = n;
      n-> elem = e;
      count ++;
    }
}

//PURPOSE: Adds elements from biggest to smallest
//PARAMS: New element to be added to linked list
//ALGORITHHM: Checks if count is not zero, if its not then adds elements in descending order
template <class T>
void LL<T>::addInOrderDescend(T e)
{
  if(count == 0)
    addRear(e); //Nothing in the list yet
  else if(e > front-> elem)
    addFront(e);
  else
    {
      node<T>* p = front;
      while(p-> next != NULL && p-> next -> elem >= e)
        p = p-> next;
      node<T>* n = new node<T>;
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
template <class T>
void LL<T>::addRear(T e)
{
  if(count == 0)
    front = rear = new node<T>;
  else
    {
      rear-> next = new node<T>;
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
template <class T>
void LL<T>::addFront(T e)
{
  if(count == 0)
    addRear(e);
  else
    {
      node<T>* temp = front;
      front = new node<T>;
      front-> elem = e;
      front-> next = temp;
      count++;
    }
}

//PURPOSE: Deletes a specific element from list
//PARAMS: Element to be deleted from linked list
//ALGORITHHM: Checks if count is not zero, if false, checks linked list until
//            it finds element than sets pointers to new location, finally deletes node
template <class T>
void LL<T>::deleteNode(T e)
{
  if(isEmpty())
    return;
  else
    {
      if(e == front-> elem)
        deleteFront();
      else
        {
          node<T>* p = front;
          node<T>* d = front-> next;
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
template <class T>
void LL<T>::deleteNodes(T e)
{
  if(isEmpty())
    return;
  else
    {
      if(front-> elem == e)
        deleteFront();
      if(count > 1)
        {
          node<T>* p = front;
          node<T>* d = front-> next;
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
template <class T>
T LL<T>::deleteRear()
{
  T x;
  if(count == 0)
    throw Underflow();
  else if(count == 1)
    return deleteFront();
  else
    {
      x = rear-> elem;
      node<T>* p = front;
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
template <class T>
T LL<T>::deleteFront()
{
  T x;
  if(isEmpty())
    throw Underflow();
  else
    {
      node<T>* temp = front;
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
template <class T>
void LL<T>::displayAll()
{
  if(isEmpty())
    return;
  else
    {
      node<T>* p = front;
      while(p != NULL)
        {
          cout << p-> elem << " ";
          p = p-> next;
        }
      //cout << endl;
    }
}

//PURPOSE: Emergency exit, end program
//PARAMS: String explaining why there was an error
//ALGORITHHM: Uses cout and exits the program
template <class T>
void LL<T>::LListError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//PURPOSE: Access the private member front
//PARAMS: N/A
//ALGORITHHM: Calls other function passing front
template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE:Prints the LList in reverse order
//PARAMS:Pointer that points to front
//ALGORITHHM:Uses recursive method, calling itself so it can print out
//           in reverse. Uses the system stack
template <class T>
void LL<T>::printAllReverse(node<T>* p)
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
template <class T>
bool LL<T>::search(T e)
{
  if(isEmpty())
    return false;
  else
    {
      node<T>* t = front;
      for(t; t != NULL; t = t->next)
        {
          if(t-> elem == e)
            return true;
        }
      return false;
    }
}

#endif
