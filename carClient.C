/*************************************//*\\*************************************/
/*                                  carClient.C                                */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <iostream>
using namespace std;

#include "car.h"
void print(const Car& c);

int main()
{
  Car celica("Toyota", "Celica", 2016, "White", 0, 0, 0);
  Car civic("Honda", "Civic", 2008, "Black", 20000, 2, 2);

  celica.goUp(3);
  civic.goDown(1);
  celica.goRight(2);
  civic.goLeft(5);

  print(celica);
  print(civic);

  celica.repaint("Red");
  print(celica);
  return 0;
}

void print(const Car& c)
{
  cout << c.getColor() << " " << c.getMake() << " " << c.getModel() << " (" << c.getYear() << ") is at location (" 
       << c.getX() << ", " << c.getY() << ") with " << c.getMiles() << " miles. " << endl;
}
