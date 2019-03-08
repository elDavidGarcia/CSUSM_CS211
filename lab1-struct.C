#include <iostream>
using namespace std; 

//######### DO NOT forget about the prototypes. You should know where to place them.  ############

//Declare a struct called "student" with id, name, gender, major and age
????????????

//If you want to change the maximum number of students, change the number in one place.
const int MAX = 20;

int main()
{
  //delare an array of students with size MAX.
  ????????????

  int num; //the number of students
  
  //call the getStuData function to fill the array with students' information 
  ????????????????
  

    int look; //The id the user is looking for
    cout << "Enter the id you are looking for: ";
    cin >> look;

    //Find a student with that id and display the information about that student. If no student has the id, show an appropriate message.
    ??????  findID(????????????);
  
    if(?????????) 
      displayStu(????????)
      else
	cout << "No student with id " << look << " was found" << endl;

    //find the youngest and oldest ages by calling findYoungOld and output those ages
  ?????????????????????????????

      return 0;
}

//This function loads students' data into the array and returns the number of students. 
?????  getStuData(?????) 
{

  //fill the array with students' information entered from the keyboard - use the while loop
  ??????????




  //fill the unused slots with the default values  
  student Default = {0, " ", ' ', " ", 999}; //defalut values

  for(??????                   )
    {
      s[?????? ] = Default;
    }   

  //return the number of students
  ??????????
    }

/* This function searches through the array to find the student with the id the user is looking for.
   The user is asked to enter the id she is looking for in the main. 
   Return the index or -1 if not found. */
???? findID(????   )
{
  
  
}

/*This function will be passed one student struct and display all the information (name, gender, major and age) about that student.*/
????? displayStu( ????????)
{

  
}

/*This function will return the youngest and oldest ages */
??????  findYoungOld( ???????? )
{

  
}
