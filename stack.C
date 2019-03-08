/*****************//*\\*****************/
/*               stack.C               */
/*IMPLEMENTED BY: David Garcia         */
/*CLASS: CS 211, Assig 2               */
/*DUE DATE:3/7/2016                    */
/***************************************/
#include <iostream>
using namespace std;
#include "stack.h"

Stack::Stack() //Constructor initializes  top
{
  top = -1; //Initialize top top to -1
}

bool Stack::isEmpty() //Function returns true if is empty
{
  if(top == -1) //Top equvalent to -1 means array is empty
    return true; //Return true if top is -1, stack is empty
  else
    return false; //If it's empty return false 
}

bool Stack::isFull() //Function checks if the array 
{
  if(top == MAX - 1) //Top is Max - 1 means the array is at its last slott
    return true; //Return true if stack is full
  else
    return false; //Return false if stack is still not yet full
}

void Stack::push(Le elem) //Add element to array if 
{
  if(isFull()) //Calls isFull, if true then will show error message
    stackError("Cannot push stack is full");
  else //Stack is not full so it adds a new element to the array
    ar[++top] = elem; //Increment the top then store element into stack
}

Le Stack::pop()
{
  if(isEmpty()) //Calls isEmpty file, if true then shows error message
    stackError("Syntax Error");
  else //Stack is not empty so it returns the last element in the stack
    return ar[top--]; //Returns last element in stack and decrease top by 1 to point to next element
}

Le Stack::topElem()
{
  if(isEmpty()) //Checks if stack is empty by calling is empty function 
    stackError("Stack is empty "); //Shows error if the stack is empty
  else //Stack is not empty 
    return ar[top]; //Returns the last element of the stack
}

void Stack::displayAll() //Function displays all the elements in the stack 
{
  for(int i = top; i > -1; i--) //Use of for loop to go through all the elements in the stack
    cout << ar[i] << endl; //Displays element in stack that the loop is pointing at
}

void Stack::clearIt() //Function to clear elements of the array
{
  while(!isEmpty()) //Loop calls isEmpty to check if stack is empty and runs until stack is empty
    pop(); //Calls pop function to move pos back one until it reaches -1, also aka stack is empty
}

void Stack::stackError(string msg) //Backup error function that ends the program if called
{
  cout << msg << endl; //Display the error message that was passed on when calling the function
  exit(1); //Ends program
}
