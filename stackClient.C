//stackClient.C
#include <iostream>
using namespace std;
#include "stack.h"

int main()
{
  Stack myStack;
   
  if(myStack.isEmpty())
    cout << "\nThe stack is empty.\n";
  
  if(!myStack.isFull())
    myStack.push("Mike");
  else
    cout << "\nThe Stack is full. \n";
  
  if(!myStack.isFull())
    myStack.push("Kathy");
  else
    cout << "\nThe Stack is full. \n";
  
  cout << endl << myStack.topElem() << " is on top.\n";
  
  if(!myStack.isFull())
    myStack.push("Dave");
  else
    cout << "\nThe Stack is full. \n";
  
  if(!myStack.isFull())
    myStack.push("Alice");
  else
    cout << "\nThe Stack is full. \n";
  
  if(!myStack.isFull())
    myStack.push("Tom");
  else
    cout << "\nThe Stack is full. \n";
  
  
  if(myStack.isFull())
    cout << "\nThe Stack is full. \n\n";
  
  myStack.displayAll();
  
  if(!myStack.isFull())
    myStack.push("Meg");
  else
    cout << "\nThe Stack is full. \n";
  
  myStack.pop();
      
  cout << endl << myStack.topElem() << " is on top. \n";
  
  myStack.clearIt();
  
  if(myStack.isEmpty())
    cout << "\nThe stack is empty. \n";
  
  return 0;
}

