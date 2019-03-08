//Header goes here
#include <iostream>
#include <string>
using namespace std;

int getNumbersInRange(int, int, string);

int main()
{
  cout << "Enter your score (0 to 100): ";
  int score = getNumbersInRange(0, 100, "Re-enter: ");
  cout << score << endl;
  return 0;
}

int getNumbersInRange(int low, int high, string msg)
{
  string input;
  bool nonNumber; //set to true if the user's input contains a non-digit character
  bool invalid;
  cin >> input;
 do
   {

     //reset something at the beginning of each loop
     nonNumber = false;
     //check each character in "input" and if a non-digit character is found, set "nonNumber" to true
     for(int i = 0; i < input.length(); i++)
       {
	 if(isdigit(input[i]) == 0)
	   {
	     nonNumber = true;
	   }
       }
     //if one of the following 3 conditions is true, "input" is invalid, then “invalid” is set to true. If all the conditions
     //fail, “input” is valid, then “invalid” is set to false.
     // 1. "nonNumber" is true ("input" contains a non-digit character.) e.g. 1@0
     // 2. the number is less than the bottom boundary. e.g. -1 (if low is 0)
     // 3. the number is larger than the top boundary. e.g. 101 (if high is 100)
     invalid = nonNumber || atoi(input.c_str()) > high || atoi(input.c_str()) < low;
     //if “invalid” is true, ask for a new input
     if(invalid) //same as invalid == true
       {
	 cout << msg;
	 cin >> input;
       }
   }while(invalid);
 //returning a valid integer between low and high
 return atoi(input.c_str());
}
