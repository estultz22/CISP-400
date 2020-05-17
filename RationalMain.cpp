/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 3
March 11, 2020
*/

#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
  Rational r(5, 6), r2(10, 15);

  cout << "r = " << r << ", r2 = " << r2 << endl;

  cout << "\n(r + r2): " << r + r2;
  cout << "\n(r += 1): ";
  r += 1;
  cout << r;
  cout << "\n(r++): " << r++ << endl;

  cout << "\n(r - r2): " << r - r2;
  cout << "\n(r -= 1): ";
  r -= 1;
  cout << r;
  cout << "\n(r--): " << r-- << endl;

  cout << "\n(r * r2): " << r * r2;
  cout << "\n(r *= 3): ";
  r *= 3;
  cout << r << endl;

  cout << "\n(r / r2): " << r / r2;
  cout << "\n(r /= 3): ";
  r /= 3;
  cout << r << endl;

  cout << "-r = " << -r << endl;

  for (unsigned i = 0; i < 6; ++i) cout << "\n(r.pow(" << i << ")): " << r.pow(i);
  cout << endl;

  cout << r << " > " << 4;
  (r > 4) ? cout << " True\n" : cout << " False\n";

  return 0;
}

