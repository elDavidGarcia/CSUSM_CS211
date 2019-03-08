//David Garcia
//CS211 Assignment 7
//dictionary.C - client file
/***************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#include "LL_T.h"

//Prototypes
void buildLL(LL<string>&);
void removeBadWords(LL<string>&);
void outputToFile(LL<string>&);

int main()//Main function, nothing special here 
{
  LL<string> l;

  buildLL(l);
  removeBadWords(l);
  outputToFile(l);
  cout << "Dictionary program has run succesfully! :) \n";
  return 0;
}

//PURPOSE: Builds a linked list from file 
//PARAMS: Linked list to be modified(by reference)
//ALGORITHHM: Gets data from a txt file, stores in in a linked list
//            while lowercasing all letters and deleting punctuation
void buildLL(LL<string>& list)
{
  string s; //String to get info from file
  ifstream fin; //For use when refering to inFile
  fin.open("essay.txt"); //Open desired file
 
  fin >> s; //Store string in variable
  while(fin) //While their is something in the file
    {
      for(int i = 0; i < s.size(); i++) //For the length of the string
	{
	  if(!isalpha(s[i]))      //If its not a character erase it
            s.erase(s.begin()+i);
	  else if(isalpha(s[i]))
	    s[i] = tolower(s[i]); //Push lowercased charcter back into the string
	}
      if(!list.search(s)) //If the word doesnt exist
	list.addInOrderAscend(s); //Add it in ascending order to linked list
      fin >> s;
    }
  fin.close(); //Close the file
}

//PURPOSE: Deletes a specific element from list
//PARAMS: Linked list to be modified(by reference)
//ALGORITHHM: Checks search to see if word is in the list, deletes all the bad words
//            uses bad word file
void removeBadWords(LL<string>& list)
{
  string bad; //String to contain bad word
  ifstream fin;
  fin.open("bad.txt"); //Open file
  
  fin >> bad; //Put a bad word into the string variable
  while(fin)
    {
      while(list.search(bad)) //Search for the word in delete node
	list.deleteNode(bad); //When found delete the word, repeat if necessary
      fin >> bad;
    }
  fin.close(); //Close file
}

//PURPOSE: Outputs strings into files
//PARAMS: Linked list to be modified(by reference)
//ALGORITHHM: Uses functions in fstream and functions in LL.C
//            to output the stroongs into their seperate files
//            files alphabetically organizing them
void outputToFile(LL<string>& list)
{
  string s, s2; //Strings that shall be used
  ofstream fout;
 
  s = list.deleteFront(); //Pop the first element into string 1
  string fileName = "./dictionary/?.txt"; // . means the current directory.
  fileName[13] = toupper(s[0]); //Replacing ? with T
  fout.open(fileName.c_str()); //opens T.txt in the .dictionary. directory under the
                               //current directory.
  fout << s << " "; //Pass the first element into corresponding file
  
  while(!list.isEmpty()) 
    {
      s2 = list.deleteFront(); //Pop a element into string 2
      if(s2[0] != s[0]) //If the second string's first letter not equal to first's
	{
	  fout.close(); //Close current file and open next
	  string fileName = "./dictionary/?.txt"; // . means the current directory.
	  fileName[13] = toupper(s2[0]); //Replacing ? with T
	  fout.open(fileName.c_str()); //opens T.txt in the .dictionary. directory under the 
	                               //current directory.
	}
      fout << s2 << " "; //Pass the second element into the file
      s = s2; //Set the second element as the previous element
    }
  fout.close(); //close file
}
