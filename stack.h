/*****************//*\\*****************/
/*               stack.h               */
/*IMPLEMENTED BY: David Garcia         */
/*CLASS: CS 211, Assig 2               */
/*DUE DATE:3/7/2016                    */
/***************************************/
#include <string>
#ifndef STACK_H  //includes stack.h if not included
#define STACK_H
using namespace std;

const int MAX = 5; //Make the stack into an array and set the limit to a number
typedef int Le; //Make a name for the type

class Stack //Create a class named stack 
{
 private: //Private can only be accessed through the class
  Le ar[MAX]; //Make an array of le elements
  int top; //Make the pointer for the array to mimic a stack
  string msg; //Error message 
 public:
  Stack(); //Set the constuctor
  bool isEmpty(); //A bool is empty function to see when stack is empty
  bool isFull(); //A bool is full function to see when stack 
  void push(Le); //Void function to pass an element to the stack
  Le pop(); //Take an element out of the stack
  Le topElem(); //Show the last element pushed into the stack
  void displayAll(); //Display all the items in the array
  void clearIt(); //Clear all items in the array
  void stackError(string); //Call if the stack has an error
};
#endif   
