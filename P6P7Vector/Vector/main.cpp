/*
Elijah Stultz
CISP 400, MW, 3:00pm
Programming Project 6
May 13, 2020
*/

#include <iostream>
#include "Vector.h"
#include <fstream>

using namespace std;

int main()
{
  Vector<int> test;
  Vector<int> test1;
  ofstream fout("test.txt", ios::out | ios::binary);
  ifstream fin("test.txt", ios::in | ios::binary);

  for (unsigned i = 0; i < 16; ++i)
  {
    test += i;
  }

  /*Vector<int> test3(0);
  Vector<int> *test4 = new Vector<int>;

  test3 = test;

  cout << test3;
  test3.Insert(3);
  test3.Insert(2, -1);
  *test4 += 4;
  cout << test4;

  for (unsigned i = 0, len = test3.Length(); i < len; ++i) cout << test3[i] << "\n";
*/

  test.write(fout);
  fout.close();
  test1.read(fin);
  fin.close();

  cout << test;
  cout << test1;

  cout << "\n\nwe're still good!!";
  return 0;
}
