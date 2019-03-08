//palindrome
#include <iostream>
using namespace std;
#include "LL.h"

void createLL(const string , LList&);
bool palindrome(LList&, LList&);

int main()
{
  LList l1, l2;
  string s; 

  cout << "Enter a palindrome: ";
  getline(cin, s);

  createLL(s, l1);
  createLL(s, l2);
  if(palindrome(l1, l2))
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
	l1.addRear(toupper(s[i]));
    }
}

bool palindrome(LList& list1, LList& list2)
{
  while(!list1.isEmpty())
    {
      if(list1.deleteRear() != list2.deleteFront())
	return false;
    }
  return true;
}
  
