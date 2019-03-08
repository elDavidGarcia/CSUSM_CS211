/*************************************//*\\*************************************/
/*                                studentClient.C                              */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector> 
using namespace std;
#include "student.h"
#include "inputCheck.h"

void showMenu();
void addStudentsFromFile(vector<Student>& v);
void addOneStudent(vector<Student>& v);
void printAllStudents(const vector<Student>& v);
void addCourseToStudent(vector<Student>& v);
void dropCourseFromStudent(vector<Student>& v);

int main()
{
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
  vector<Student> v;  //declare a vector of students  
  int choice;

  do
  {
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNumbersInRange(1, 6, "Invalid choice. Enter 1 through 6: ");

    switch(choice)
      {
      case 1:
	  addStudentsFromFile(v);
	  break;
      case 2:
          addOneStudent(v);
	  break;
      case 3:
	  printAllStudents(v);
	   cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	break;
      case 4:
	addCourseToStudent(v);
	break;
      case 5:
	dropCourseFromStudent(v);
	break;
      case 6:
	cout << "Ending the program ..............." << endl;
      }
  }while(choice != 6);


  cout << "\n *** TEST: the number of students at the end is " << Student::getNumStu() << endl;

  return 0;
}

 void showMenu()
 {
   cout << "\n*****************************************************************" << endl;
   cout << "1: Add students from a file" << endl;
   cout << "2: Add one student" << endl;
   cout << "3: Print all students" << endl;
   cout << "4: Add a course to a student" << endl;
   cout << "5: drop a course from a student" << endl;
   cout << "6: End the program" << endl;
 }

//This function adds students from an input file
//e.g. for input file (for each student, first last gen)
//  Mike Smith M
//  Kathy Ross F
void addStudentsFromFile(vector<Student>& v)
{
  string fileName;

  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(fileName.c_str()); //open the file

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      string fn, ln;
      char gn;
   
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  Student s(fn, ln, gn);//create a new student with the data from input
	  v.push_back(s); //add it to the vector
	  fin >> fn >> ln >> gn; //read the next student
	}
    }
}

//This function adds one student to the vector.
void addOneStudent(vector<Student>& v)
{
      string fn, ln;
      char gn;

      cout << "Enter the student's first name: ";
      cin >> fn;
      cout << "Enter the student's last name: ";
      cin >> ln;
      cout << "Enter the student's gender: ";
      gn = getResponse("Invalid input. Enter M or F: ");

      Student s(fn, ln, gn); //create a new student with the data from the user's input
      v.push_back(s); //add the new student to the vector
}
 
//Print the information about all the students
void printAllStudents(const vector<Student>& v)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << right << setw(10) << "Fee" << left << setw(10) << "  Courses" << endl; 

  //Go through each student in the vector
  for(int n = 0; n < v.size(); n++)
    {
      cout << setw(10) << v[n].getId() << setw(10) << v[n].getFirstName() << setw(10) << v[n].getLastName() << right << setw(7) << v[n].getDollar() << ".";
      
      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
      if(v[n].getCent() < 10)
	cout << "0";
      cout << v[n].getCent();
      
      //show all courses the student is enrolled in
      cout << left << "  ";
      vector<int> co = v[n].getCourses(); //get the vector of courses for this student
      for(int c = 0; c < co.size(); c++)
        cout << setw(6) << co[c];
      
      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
void addCourseToStudent(vector<Student>& v)
{
  bool found;
  int n = -1, index = 0, k = -1;
  
  cout << "Enter the student id: ";
  int id = getNumbersInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumbersInRange(1, 99999, "Invalid CRN. Enter the CRN: ");
  
  while(index < v.size() && !found)
    {
      if(v[index].getId() == id)
        {
          found = v[index].addCourse(crn);
          n = index;
        }
      
      index ++;
    }
  if(!found && index == v.size() && n == -1)
    cout << "No matching ID! \n";
  else if(found)
    {
      v[n].chargeFee(50, 10);
      cout << crn << " has been added to " << v[n].getFirstName() << endl;
    }
  else if(!found)
    cout << "Student is alrady enrolled in " << crn << endl;
}
//drop a course from a student
//reduct $50.10 from the student's balance
void dropCourseFromStudent(vector<Student>& v)
{
  bool found;
  int n = -1, index = 0;  
  
  cout << "Enter the student id: ";
  int id = getNumbersInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumbersInRange(1, 99999, "Invalid CRN. Enter the CRN: ");
  
  while(index < v.size() && !found)
    {
      if(v[index].getId() == id)
        {
          found = v[index].dropCourse(crn);
          n = index;
        }

      index ++;
    }
  if(!found && index == v.size() && n == -1)
    cout << "No matching ID! \n";
  else if(found)
    {
      v[n].reduceFee(50, 10);
      cout << crn << " has been dropped from " << v[n].getFirstName() << endl;
    }
  else if(!found)
    cout << "Student is not enrolled in " << crn << endl;
}
