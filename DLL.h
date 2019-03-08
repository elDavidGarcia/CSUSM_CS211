//David Garcia
//CS211 Assignment 9
//DLList-header file
/***************************************************/
#include <string>
#ifndef DLL_H
#define DLL_H
using namespace std;

typedef int el_t; //Element is int for DLLTest.C and string for dictionary.C

struct node //Node structure to be used in DLL.C, three objects: element and pointers 
{
  el_t elem; //holds element
  node* next; //Points to next node
  node* prev; //Points to previous node
};

class DLL //Start a class named DLL
{
 private: //Can only be accessed through the public functions of class
  // Data members are:
  int count; //Tracks how big DLList is 
  node* front; //points to the front element of the DLList is.
  node* rear; //points the rear element of the DLList is.
  //HOW TO CALL: Must be called by public function inside DLList class 
  //PURPOSE: Emergency exit
  void DLListError(string);
  //HOW TO CALL: Uses the front node pointer in the private
  //PURPOSE: Prints DLList in reverse order
  void printAllReverseDLL(node*);
 public:
  DLL(); // constructor
  ~DLL(); //destructor
  //HOW TO CALL: No parameters
  //PURPOSE: Checks if DLL is empty
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
  //PURPOSE: Deletes the rear element in DLList
  el_t deleteRear();
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the front element in DLList
  el_t deleteFront();
  //HOW TO CALL: No parameters
  //PURPOSE: Displays content of the DLList
  void displayAll();
  //HOW TO CALL: No parameters
  //PURPOSE: Prints the DLList in reverse order
  void printAllReverseDLL();
  //HOW TO CALL: Pass element to be found
  //PURPOSE: Checks if an element is in the DLL
  bool search(el_t);
};
#endif
