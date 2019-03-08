/*************************************//*\\*************************************/
/*                                    car.C                                    */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <iostream>
using namespace std;
#include <string>
#include "car.h"

Car::Car(string mk, string md, int yr, string cl, int mi, int xPos, int yPos)
{
  make = mk;
  model = md;
  year = yr;
  color = cl;
  miles = mi;
  x = xPos;
  y = yPos;
}  

string Car::getMake()const
{
  return make;
}

string Car::getModel()const
{
  return model;
}

int Car::getYear()const
{
  return year;
}

string Car::getColor()const
{
  return color;
}

int Car::getMiles()const
{
  return miles;
}

int Car::getX()const
{
  return x;
}

int Car::getY()const
{
  return y;
}

int Car::goUp(int block)
{
  y = y + block;
  miles = miles + block;
  return y;
}

int Car::goDown(int block)
{
  y = y - block;
  miles = miles + block;
  return y;
}

int Car::goRight(int block2)
{
  x = x + block2;
  miles = miles + block2;
  return x;
}

int Car::goLeft(int block2)
{
  x = x - block2;
  miles = miles + block2;
  return x;
}

void Car::repaint(string newColor)
{
  color = newColor;
}

