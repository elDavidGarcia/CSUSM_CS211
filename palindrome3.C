//palindrome3
#include <iostream>
using namespace std;
#include "LL.h"

void createLL(const string , LList&);
bool palindrome(LList&, const string);

int main()
{
  LList l1;
  string s;

  cout << "Enter a palindrome: ";
  getline(cin, s);

  createLL(s, l1);
  if(palindrome(l1, s))
    cout << s << " is a palindrome!\n";
  else
    cout << s << " is not a palindrome!\n";
  return 0;
}

void createLL(const string s, LList& l1)
{
  for(int i = 0; i < s.size(); i++)
    {
      if(isalpha(s[i]))
        l1.addRear(toupper(s[i]) - 48);
    }
}

bool palindrome(LList& list1, const string s)
{
  for(int i = 0; i < s.size(); i++)
    {
      if(isalpha(s[i]) && ((toupper(s[i])-48) != list1.deleteRear()))
	{
	  return false;
	}
    }
  return true;
}
