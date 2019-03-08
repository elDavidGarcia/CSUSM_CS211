/*****************//*\\*****************/
/*              postfix.C              */
/*IMPLEMENTED BY: David Garcia         */
/*CLASS: CS 211, Assig 2               */
/*DUE DATE:3/7/2016                    */
/***************************************/
#include <iostream>
#include <string>
using namespace std;
#include "stack.h"

bool isOperand(char ch); //return true if ch is an operand
int charToInt(char ch); //convert a charcter to integer(if an item is a digit)
bool isOperator(char ch); //return true if it is an operator (+,-,*,/)
int doMath(int opr1, char opt, int opr2); //returns the result of opr1 opt opr2

int main()
{
  Stack myStack; //Declare a stack class called myStack
  string exp; //String to get the input expression
  bool error = false; //Bool used to get out of the loop once expression has been evaluated
  int i = 0, total = 0; //Intialize counter for loop and a total to store result
  cout << "Enter an expression: "; //Ask for the input
  cin >> exp; //Get the expression with a cin
  
  do //Use do while because the stack is empty to begin with
    {
      char curItem = exp[i]; //Get one charcter of the expression at a time and store it as a single character
      if(isOperand(curItem)) //First check to see if the charcter is a number
	{
	  int item = charToInt(curItem); //If it is a number convert from chracter to an integer
	  myStack.push(item); //Store the newly converted integer and push it into the array
	}
      else if(isOperator(curItem)) //Check to see if it is an operator
	{
	  int y = myStack.pop(); //If it is, pop a number from the stack and store it into a temporary variable
	  int x = myStack.pop(); //Pop the stack once more to get the second number and store it as another temporary
	  total = doMath(x, curItem, y); //Call the do math function and pass both temporaries and operator, then store the result in total variable 
	  myStack.push(total); //Push the total into  the stack
	}     
      else //If it nor operator nor number then get out of the loop
	error = true; //Set error equal to true so that it will exit out of the loop
      i++; //Increment the counter of the loop
    }while(!myStack.isEmpty()&&!error); //Stay inside the loop while it is still evaluating the expression and the stack is not empty
  int ans = myStack.pop(); //Pop the final result into a variable to display it
  if(!myStack.isEmpty()) //Check to make sure the stack is empty before displaying the result
    cout << "There is an error with the expression! \n"; //If stack is not empty then there is a syntax error with the expression
  else //Stack is empty and there is no sysntax error
    cout << "Answer: " << ans << endl; //Display the answer
  return 0;
  
}
  
bool isOperand(char ch) //return true if ch is an operand
{
  if(ch >= '0' && ch <= '9') //ch is an operand
    return true; //Return true to main function 
  else //ch is not an operand
    return false; //Return false to the main function
}

int charToInt(char ch) //convert a charcter to integer(if an item is a digit)
{
  return ch - 48; //Convert the  charcter type to intager type by subtracting the ascii value 
}

bool isOperator(char ch) //return true if it is an operator (+,-,*,/)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/') //ch is an operator
    return true; //Returns true affter checking if input was an operator
  else //ch is not an operator
    return false; //Returns false meaning input was not an operator
}

int doMath(int opr1, char opt, int opr2) //returns the result of opr1 opt opr2
{
  int total; //Intialize the total to return it later
  switch(opt) //Uses switch statement with the input being the operator that was transfered from main, store into total
    {
    case '+': total = opr1 + opr2; //If operator is + then it adds both numbers together, store into total
      break;
    case '-': total = opr1 - opr2; //If operator is - then subtracts second popped element from first popped element, store into total  
      break;
    case '*': total = opr1 * opr2; //If operator is * then it multiplies both numbers, store into total
      break;
    case '/': total = opr1 / opr2; //If operator is / then it divides first popped element by second popped element, store into total 
      break;
    }
  return total; //Return the result to the main 
}
