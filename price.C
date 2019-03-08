/*************************************//*\\*************************************/
/*                                   price.C                                   */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
using namespace std;
#include "price.h"

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c)
{
  dollar = d;
  cent = c;
}

Price Price::operator+(const Price& another)
{
  int tdollar = this->dollar + another.dollar;
  int tcent = this->cent + another.cent;
  if(tcent >= 100)
    {
      tcent = tcent-100;
      tdollar = tdollar + 1;
    }

  Price t(tdollar, tcent);
  return t;
}

Price Price::operator-(const Price& another)
{
  int p1 = this->dollar * 100 + this->cent;
  int p2 = another.dollar * 100 + another.cent;
  int diff;

  if(p1 >= p2)
    {
      diff = p1 - p2;
      Price diffOB(diff/100, diff%100);
      return diffOB;
    }
  else
    {
      Price negOB(-99999, -99999);
      return negOB;
    }
}

int Price::getDollar() const
{
  return dollar;
}

int Price::getCent() const
{
  return cent;
}

