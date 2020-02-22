/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 2
February 26, 2020
*/

#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
  Rational test(10, 8);
  Rational test2(20, 8);

  test.add(test2);
  test.display();

  test.sub(test2);
  test.display();

  test.mult(test2);
  test.display();

  test.div(test2);
  test.display();

  return 0;
}
