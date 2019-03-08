//David Garcia
//CS211 Assignment 6
//LList- aplication file
/***************************************************/
#include <iostream>
using namespace std;
#include "LL_T.h"

//Prototypes
void createLL(const string , LL<int>&);
bool palindrome(LL<int>&, const string);

int main()
{
  LL<int> l; //Declare a linked listed l
  string s; //String for input
  
  cout << "Enter a palindrome: ";
  getline(cin, s); //Get sentence from user
  
  createLL(s, l); //Create a linked list, pass linked list and string 
  if(l.isEmpty()) //Check if linked list has any elements
    cout << "No words where inputed! \n";
  else
    {
      if(palindrome(l, s)) //If return true then string is a palindrome
	cout << s << " is a palindrome!\n";
      else //False means string was not a palindrome
	cout << s << " is not a palindrome!\n";
    }
  return 0;
}

//Parameters: String input and linked list(by refrence)
//Purpose: Store  string into linked list
void createLL(const string s, LL<int>& l)
{
  for(int i = 0; i < s.size(); i++) //As long as i is less than string size
    {
      if(isalpha(s[i])) //If character is part of alphabet
        l.addRear(toupper(s[i])); //Add it to rear of LList (Make all chars uppercase)
    }
}

//Parameters: String input and linked list(by refrence)
//Purpose: Check if string input it a palindrome, return true or false
bool palindrome(LL<int>& list, const string s)
{
  for(int i = 0; i < s.size(); i++) //As long as i is less than string size
    {
      //Check capatilized alphabetic charcters of string to llist content
      if(isalpha(s[i]) && toupper(s[i]) != list.deleteRear())// Use delete rear so it reverses content
	return false; //The charcters of string were not equal to reverse characters of llist
    }
  return true; //Charcters of string were all equal to reverse characters of llist
}
