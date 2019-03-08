/*************************************//*\\*************************************/
/*                                    car.h                                    */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <string>
using namespace std;

class Car
{
 private:
  string make;
  string model;
  int year;
  string color;
  int miles;
  int x;
  int y;

 public:
  Car(string, string, int, string, int, int, int);
  string getMake() const;
  string getModel() const;
  int getYear() const;
  string getColor() const;
  int getMiles() const;
  int getX() const;
  int getY() const;
  int goUp(int y);
  int goDown(int y);
  int goRight(int x);
  int goLeft(int x);
  void display();
  void repaint(string color);
};
