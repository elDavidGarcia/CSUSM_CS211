/*****************//*\\*****************/
/*             fibonacci.C             */
/*IMPLEMENTED BY: David Garcia         */
/*CLASS: CS 211, Assig 2               */
/*DUE DATE:3/7/2016                    */
/***************************************/
#include <iostream>
#include <time.h>
using namespace std;
#include "inputCheck.h"

const int CLOCKSPERSEC = 60;

int fib(int); //The recursive function that calculates the fubanacci number at position entered

int main()
{
  clock_t start, end, start2, end2; //Intialize variables for the calculation of the time
  int pos, x = 0, y = 1, total = 0; //Pos is numbered entered; x,y, total are used to calculate the non-recursive function of fibonacci
  cout << "Enter a number: "; //Ask for input
  cin >> pos; //Store input into pos
  while(pos < 0 || pos > 46) //The program will not work with numbers less than 0 or greater than 46
    {
      cout << "Cannot calculate numbers less than 0 or greater than 46.\nRe-enter number: ";
      cin >> pos;
      }
  start2 = clock(); //Start the timer for first calaculation
  if(pos == 0) //If the position entered is 0 then the fibonacci number is 0
    y = 0; //Set y equal to zero insted of 1
  else //Input is greater than zero so calculate fibonacci number
    {
      for(int i = 0; i < pos - 1; i++) //Use a foor loop to calculate the fibonacci number, stops when counter is 1 less than input
	{
	  total = x + y; //Add x and y and store result into total variable
	  x = y; //Now x holds the last number in the sequence
	  y = total; //Y holds the current number int the sequence
	}
    }
  end2 = clock(); //Stop the timer
  cout << "---------------------------------------------";
  cout << "\nNon-recursive solution: \n"; 
  cout << "Elasped time: " << (end2-start2)/double(CLOCKSPERSEC)*1000 << " milliseconds\n"; //Calculate the time and convert it to milliseconds, display time it took
  cout << "Fibonnaci number at position " << pos << " is " << y << endl; //Display the number that is at position entered
  start = clock(); //Start the timer for recursive function
  int fbNum = fib(pos); //Call the recursive funcion and store the the number returned into varaible fbNum
  end = clock(); //Stop the timer for recursive functiom
  cout << "---------------------------------------------";
  cout << "\nRecursive solution: \n";
  cout << "Elasped time: " << (end-start)/double(CLOCKSPERSEC)*1000 << " milliseconds\n"; //Calculate the time and convert it to milliseconds, display time it took 
  cout << "Fibonnaci number at position " << pos << " is " << fbNum << endl; //Display the number that is at position entered, by recursive function
  return 0;
}

int fib(int pos) //Calculates the fibonacci number at a entered position, position is passed in parameters
{
  if(pos <= 1) //If position is less than or equal to 1 then it returns position
    return pos; //Returns position to function that called fib
  else  //Still needs further calculations to find number at position entered
    return fib(pos-2) + fib(pos-1); //Function calls itself twice so that through math of the returned positions it can calculate fionacci number at entered position
}
