/*************************************//*\\*************************************/
/*                                 priceClient.C                               */
/*IMPLEMENTED BY: David Garcia                                                 */
/*CLASS: CS 211                                                                */
/*DUE DATE: 02/23/2016                                                         */
/*******************************************************************************/
#include <iostream>
using namespace std;
#include "price.h"

int main()
{
  Price p1(2, 50);
  Price p2(3, 75);
  Price total = p1 + p2;
  
  cout << "The total price is " << total.getDollar() << "." << total.getCent() << endl;
  return 0;
}
