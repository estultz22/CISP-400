/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 2
February 26, 2020
*/

#ifndef _RATIONAL_H_

#define _RATIONAL_H_

#include <iostream>

using namespace std;

class Rational

{
  int _p;

  int _q;

  void _verify();


public:

  Rational();

  Rational(int P, int Q = 1);

  void display() const; // _p:_q

  void add(const Rational&);

  void sub(const Rational&);

  void mult(const Rational&);

  void div(const Rational&);

};

#endif
