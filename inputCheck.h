/*Checks gender, yes/no answer, and numbers */
/*Implemented by: David Garcia              */
#include <iostream>
using namespace std; 

char getLetter(string);
char getResponse(string);
char YNResp(string);
int getNumbersInRange(int , int , string);

char getLetter(string msg)
{
  string input;
  cin >> input;
  while(input.length() != 1 || !isalpha(input[0]))
    {
      cout << msg;
      cin >> input;
    }
  return input[0];
}

char getResponse(string msg)
{
  char ch;
  ch = getLetter(msg);

  while(toupper(ch) != 'M' && toupper(ch) != 'F')
    {
      cout << msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}

char YNResp(string msg)
{
  char ch;
  ch = getLetter(msg);

  while(toupper(ch) != 'Y' && toupper(ch) != 'N')
    {
      cout << msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}

int getNumbersInRange(int low, int high, string msg)
{
  string input;
  bool nonNumber; //set to true if the user's input contains a non-digit character
  bool invalid;
  cin >> input;
 do
   {
     nonNumber = false;
     for(int i = 0; i < input.length(); i++)
       {
         if(isdigit(input[i]) == 0)
           {
             nonNumber = true;
           }
       }
     invalid = nonNumber || atoi(input.c_str()) > high || atoi(input.c_str()) < low;
     if(invalid)
       {
         cout << msg;
         cin >> input;
       }
   }while(invalid);
 //returning a valid integer between low and high
 return atoi(input.c_str());
}
