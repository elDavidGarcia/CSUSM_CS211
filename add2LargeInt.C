//David Garcia
//CS 211 - assignment 5
//Add 2 Large integers client file
#include <iostream>
#include <string>
using namespace std;
#include "LL_T.h"

void createReverse(LL<int> &list, string num);
void addTwo(LL<int> &l1, LL<int> &l2, LL<int> &sum);

int main()
{
  string n1, n2; //Numbers to be inputed by user
  LL<int> l1; 
  LL<int> l2;
  LL<int> sum; //List 
  //Get inputs from user
  cout << "Enter number 1: ";
  cin >> n1;
  cout << "Enter number 2: ";
  cin >> n2;

  //Get inputs and make them into lqueue in reverse order
  createReverse(l1, n1);
  createReverse(l2, n2);

  //Display the euation with revered numbers
  l1.displayAll();
  cout << " + ";
  l2.displayAll();
  cout << " = ";
  addTwo(l1, l2, sum);
  sum.displayAll();

  //Display equation with numbers in the right order
  cout << endl << n1 << " + " << n2 << " = ";
  sum.printAllReverse();
  cout << endl;
  return 0;
}

//PURPOSE: Gets a string number and puts it into a linked queue
//PARAMS: Pass the linked list and the string number
void createReverse(LL<int> &list, string num)
{
  char x;
  int i = num.length() - 1, e; //Counter and element variable
  while(i != -1)
    {
      x = num[i]; //Convert string to char
      e = x - 48; //Convert char to int
      list.addRear(e); //Pass element to linked queue
      i--; //Decrement counter
    }
}

//PURPOSE: Sums up two linked queue and stores result into third linked queue
//PARAMS: Two linked queues that have elements, one linked queue where the sum goes
void addTwo(LL<int> &l1, LL<int> &l2, LL<int> &sum)
{
  int x, y, z = 0, r = 0; //Set variables for elements, sum, and remainder
  while(!l1.isEmpty() || !l2.isEmpty() || r == 1)
    {
      //If no more elements in linked queue 1 pass zero, else pass element
      if(l1.isEmpty())
	x = 0;
      else
	x = l1.deleteFront();

      //If no more elements in linked queue 2 pass zero, else pass element
      if(l2.isEmpty())
	y = 0;
      else
	y = l2.deleteFront();
 
      //Add the first element, second element, and remainder; store in sum
      z = x + y + r;
      r = 0; //Re-set remainder to zero 
      if(z > 9) //Check if sum is greater than 9 in case a remainder is needed
	{
	  z = z - 10; //Subtract 10 if sum is greater than 9
	  r = 1; //Add 1 to remainder
	}
      sum.addRear(z); //Add element to sum linked queue 
    }
} 

