/*************************************//*\\*************************************/
/*                                   price.h                                   */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <iostream> 
using namespace std;

class Price
{
 private:
  int dollar;
  int cent;

 public:
  Price();
  Price (int, int);
  Price operator+(const Price&);
  Price operator-(const Price&);
  int getDollar() const;
  int getCent() const;
};
