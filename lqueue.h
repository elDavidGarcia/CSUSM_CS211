//David Garcia
//CS211 Assignment 5
//LQueue-header file
/***************************************************/
#include <string>
#ifndef LQUEUE_H
#define LQUEUE_H
using namespace std;

typedef int el_t; //Element is expr for game.c, change to char for queueClient.C

struct node
{
  el_t elem;
  node* next;
};

class LQueue //Start a class named Queue
{
 private: //Can only be accessed through the public functions of class
  // Data members are:
  int count; //Tracks how big queue is 
  node* front; //points to the front element of the queue is.
  node* rear; //points the rear element of the queue is.
  //HOW TO CALL: Must be called by public function iside LQueue class 
  //PURPOSE: Emergency exit
  void lqueueError(string);
  //HOW TO CALL: Uses the front node pointer in the private
  //PURPOSE: Prints queue in reverse order
  void printAllReverse(node*);
 public:
  LQueue(); // constructor
  ~LQueue(); //destructor
  //HOW TO CALL: No parameters
  //PURPOSE: Checks if queue is empty
  bool isEmpty(); 
  //HOW TO CALL: Pass element to be added to rear
  //PURPOSE: Adds an element at the rear
  void addRear(el_t);
  //HOW TO CALL: No parameters
  //PURPOSE: Deletes the front element in queue
  el_t deleteFront();
  //HOW TO CALL: No parameters
  //PURPOSE: Displays content of the queue
  void displayAll();
  //HOW TO CALL: No parameters
  //PURPOSE: Prints the queue in reverse order
  void printAllReverse();
};
#endif
