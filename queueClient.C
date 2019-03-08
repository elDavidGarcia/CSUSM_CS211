//David Garcia
//CS211, Assignment 4
//Queue Class: Client file
#include <iomanip> //For cout 
#include "inputCheck.h" //To use getNumbersInRange()
using namespace std;
#include "queue.h" //Header file

void menu(); //Function holds menu for user

int main()
{
  el_t elem; //Declare element of the el_t class, This allows changing of variable easy
  int ans; //Answer the user inputs from keyboard
  Queue q; //Declare the queue name
  do //Start do-while
    {
      menu(); //Call menu function to diplay the menu for the user
      ans = getNumbersInRange(1, 7, "Invalid input! Re-enter:"); //Make sure input is between 1 and 7(# of items in menu)
      switch(ans) //Switch that uses the answer inputed by user
	{
	case 1: //User inputs 1
	  if(q.isFull()) //Check if queue is full, want to push another element and not get a segmentaion fault
	    cout << "Queue is full! \n";
	  else //There is space int the queue so add new element 
	    {
	      cout << "Enter an element: ";
	      cin >> elem; //Get new element from user to add to queue
	      q.add(elem); //Call add function inside queue.C to add element to queue
	    }
	  break; //end case 1
	case 2:
	  if(q.isEmpty()) //Check if queue is empty, want to remove element 
            cout << "Queue is empty! \n";
          else //Queue has elements inside so remove front element
	    cout << q.remove() << " has been removed from the queue."; //Display the element that was removed, call remove
	  break; //End case 2
	case 3:
	  if(q.isEmpty()) //Check if queue is empty, want to display front element 
            cout << "Queue is empty! \n";
          else //There are elements in queue 
	    cout << "The front element is " << q.getFront() << endl; //Display the front element, call getFront
	  break; //End case 3
	case 4:
	  if(q.isEmpty()) //Check if queue is empty, trying to move fron element to rear
            cout << "Queue is empty! \n"; 
          else //There is elements in the queue
	    {
	      q.goToBack(); //Call go to back function to put front element in the rear
	      cout << "Front element has been moved to rear. \n";
	    }
	  break; //End case 4
	case 5:
	  if(q.isEmpty()) //Check if queue is empty, trung to get size of queue
            cout << "Queue is empty! \n";
          else
	    cout << "The size of the queue is " << q.getSize() << endl; //Diplay number of elements in queue, call getSize
	  break; //End case 5
	case 6:
	  if(q.isEmpty()) //Check if queue is empty, trying to diplay elements in queue
            cout << "Queue is empty! \n";
          else
	    q.displayAll(); //Call displayAll(), Displays all elemets in queue
	  break; //End case 6
	};
    }while(ans != 7); //"Case 7" end the program 
  return 0;
}

void menu() //Function displays menu for user and asks to enter choice, uses cout to display 
{
  cout << "\n-------------------------------------------\n"
       << "1. Add new element \n"
       << "2. Remove an element \n"
       << "3. Check the front element \n"
       << "4. Put first element in rear \n"
       << "5. Get the number of elements in the queue \n"
       << "6. Display all elements in the queue \n"
       << "7. Quit Program \n"
       << "\nEnter a choice: ";
}    
//End of Client file
