//David Garcia
//CS, Assignment 4
//Queue class: header file
#include <string>
#ifndef QUEUE_H //If not defined 
#define QUEUE_H //Define queue.h
using namespace std;

enum op {ADD, SUB, MULT, DIVI}; //Enum operator used for equations in game.c

struct expr //Structure to make questions used in game.c
{
  int oprd1; //First number 
  op oprt; //Operator '+', '-', '*', or '/'
  int oprd2; //Second number
};

typedef expr el_t; //Element is expr for game.c, change to char for queueClient.C

const int QSIZE = 10; //Size of queue set to 10 for game.c, set to 5 for queueClient.C

class Queue //Start a class named Queue
{
 private: //Can only be accessed through the public functions of class
  // Data members are:
  el_t el[QSIZE]; // an array called el to store the typedef
  int count; //number of elements in the queue
  int front; // where the front element of the queue is.
  int rear; // where the rear element of the queue is.
  void queueError(string); 
 public:
  Queue(); // constructor
  bool isEmpty(); // returns true if queue is empty, otherwise false
  bool isFull(); // returns true if queue is full, otherwise false
  // if full, calls an emergency exit routine
  // if not full, changes rear to the next slot and enters an element at rear
  void add(el_t);
  // if empty, calls an emergency exit routine
  // if not empty, remove(return) the front element and change front to the next slot
  el_t remove();
  // if empty, calls an emergency exit routine
  // if not empty, return the front element (but does not remove it)
  el_t getFront();
  //if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();
  //returns the current size
  int getSize();
  //display everything in the queue from front to rear enclosed in []. E.g. [a][b][c]
  //Do not call the emergency exit routine when the queue is empty.
  //void displayAll();//Displays contents of queue when called, if empty calls queueError()
};
#endif
