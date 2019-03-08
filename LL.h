//David Garcia
//CS211 Assignment &
//LList-header file
/***************************************************/
#include <string>
#ifndef LL_H
#define LL_H
using namespace std;

typedef int el_t; //Element is int for LLTest2.C and string for dictionary.C

struct node //Node structure to be used in LL.C, two objects: element and pointer 
{
  el_t elem; //holds element
  node* next; //Points to next element
};

class LL //Start a class named LList
{
 private: //Can only be accessed through the public functions of class
  // Data members are:
  int count; //Tracks how big LLsit is 
  node* front; //points to the front element of the LList is.
  node* rear; //points the rear element of the LList is.
  //HOW TO CALL: Must be called by public function iside LList class 
  //PURPOSE: Emergency exit
  void LListError(string);
  //HOW TO CALL: Uses the front node pointer in the private
  //PURPOSE: Prints LList in reverse order
  void printAllReverse(node*);
 public:
  LL(); // constructor
  ~LL(); //destructor
  //HOW TO CALL: No parameters
  //PURPOSE: Checks if queue is empty
  bool isEmpty(); 
  //HOW TO CALL: Pass element to be added (greatest to least)
  //PURPOSE: Adds an element to list from greatest to smallest
  void addInOrderDescend(el_t );
  //HOW TO CALL: Pass element to be added 
  //PURPOSE: Adds an element to list from smallest to greatest
  void addInOrderAscend(el_t);
  //HOW TO CALL: Pass element to be added to rear
  //PURPOSE: Adds an element at the rear
  void addRear(el_t);
  //HOW TO CALL: Pass element to be added to front
  //PURPOSE: Adds an element at the front
  void addFront(el_t);
  //HOW TO CALL: Pass an element to be deleted
  //PURPOSE: Finds element inputed by user and deletes it from the list
  void deleteNode(el_t);
  //HOW TO CALL: Pass an element to be deleted
  //PURPOSE: Finds element inputed by user and deletes all occurences from the list
  void deleteNodes(el_t e);
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the rear element in LList
  el_t deleteRear();
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the front element in LList
  el_t deleteFront();
  //HOW TO CALL: No parameters
  //PURPOSE: Displays content of the LList
  void displayAll();
  //HOW TO CALL: No parameters
  //PURPOSE: Prints the LList in reverse order
  void printAllReverse();
  //HOW TO CALL: Pass element to be found
  //PURPOSE: Checks if an element is in the array
  bool search(el_t);
};
#endif
