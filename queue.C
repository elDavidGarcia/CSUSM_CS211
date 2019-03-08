//David Garcia
//CS211, Assignment 4
//Queue Class: C file 
#include <iostream>
using namespace std;
#include "queue.h"

Queue::Queue()//Queue constructor to set all intial privatre variables
{
  front = 0; //Points to the front element in queue, intialize to zero when starting because queue is empty
  rear = -1; //Points to last element in queue, initialize to -1 when starting because queue is empty
  count = 0; //Keeps track of number of elements in the queue, start at 0 because queue is empty
}

bool Queue::isEmpty() //Function returns true if is empty
{
  if(count == 0) //Count = 0 means queue is empty
    return true; //Return true if top is -1, stack is empty
  else
    return false; //If it's empty return false
}

bool Queue::isFull() //Function checks if the queue has reached maximum elements
{
  if(count == QSIZE) //If number of elements euals the size, means queue is empty 
    return true; //Return true if stack is full
  else
    return false; //Return false if stack is still not yet full
}

void Queue::add(el_t elem) //Function passes element inputed by user to queue
{
  if(isFull()) //Calls is full function, if is full do not add any more elements
    queueError("Queue is Full! "); //Queue is full call emergency exit route
  else
    {      
      rear = (rear+1)%QSIZE; //Add to rear but make it go to zero if it reaches the size of the queue so it wraps around
      el[rear] = elem; //Add inputed element into newly pointed space in queue
      count++; //Add to queue count to keep track of elements in queue
    }
}

el_t Queue::remove() //Function removes a element from queue and decrements the counter
{
  if(isEmpty()) //Check if the queue is empty
    queueError("Queue is Empty "); //If is empty call emergency exit routine
  else 
    {
      el_t e = el[front]; //Load out content in the front of the queue into e
      front = (front+1)%QSIZE; //Move front pointer by 1, but if front = queuue size then make it wrap around
      count--; //Decrement counter to keep track of number of elemnets in queue
      return e; //Return what was in the front of the queue
    }
}

el_t Queue::getFront() //Function returns element in the front of the queue
{
  if(isEmpty()) //Check if the queue is empty
    queueError("Queue is empty!"); //If it's empty call emergency exit routine
  else
    return el[front]; //Return the front element of the queue
}

void Queue::goToBack() //Function removes the front element and adds it to the rear
{

  if(isEmpty()) //Check if queue is empty
    queueError("Queue is empty!"); //If it's empty then call emergency exit routine
  else
    add(remove()); //Remove an element from the queue and add it by calling the remove function, that returns elemt that was added inside the add function 
}

int Queue::getSize() //Function returns the count which is the size of the queue
{
  return count; 
}

/*void Queue::displayAll() //Function displays all the elements in the stack, comment out for game.C
{
  if(isEmpty()) //Check if queue is empty
    queueError("Queue is empty!"); //If queue is empty call emergency exit routine
  else
    {
      int x = front, y = (rear+1)%QSIZE; //Set front and rear equal to variables to not move the front and rear pointers
      cout << "\nThe content of the queue is: \n";
      do
	{
	  el_t e = el[x]; //Load out one of the elements into a variable e
	  cout << e << " "; //Display the element that was put into e
	  x = (x+1)%QSIZE; //Add to x (front), if it reaches size then make it wrap around
	}while(x != y); //As long as front does not equal rear + 1
    }
}
*/
void Queue::queueError(string msg) //Backup error function that ends the program if called
{
  cout << msg << endl; //Display the error message that was passed on when calling the function
  exit(1); //Ends program
}
