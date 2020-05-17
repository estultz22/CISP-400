/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include <iostream>
#include "Ski.h"
#include "CabinCruiser.h"
#include "Kayak.h"
#include "Shanty.h"

using namespace std;

int main()
{

  Ski a;
  CabinCruiser b;
  Kayak c;
  Shanty d;

  a.Set_Name("Bob");
  a.Display();
  cout << a.Get_Barefoot_Pole();

  b.Set_Name("Ted");
  b.Display();

  c.Set_Name("Phil");
  c.Display();

  d.Set_Name("Jim");
  d.Display();
  return 0;
}
