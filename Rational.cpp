/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 2
February 26, 2020
*/

#include "Rational.h"
#include <iostream>

int gcd(int, int);

Rational::Rational()
{
  this->_p = 0;
  this->_q = 1;
}

Rational::Rational(int P, int Q)
{
  this->_p = P;
  this->_q = Q;
}

void Rational::display() const
{
  cout << this->_p << ":" << this->_q << endl;
}

void Rational::add(const Rational& r)
{
  Rational num(r._p, r._q);
  int magicOne = 1, magicOne2 = 1, _gcd;

  num._verify();

  _gcd = gcd(num._q, this->_q);

  if (num._q > this->_q)
  {
    magicOne = num._q / _gcd;
    magicOne2 = _q / _gcd;

    //equalizes denominators to add correctly
    _p = _p * magicOne + num._p * magicOne2;
    _q *= magicOne;
  }
  else if (num._q < _q)
  {
    magicOne = this->_q / _gcd;
    magicOne2 = num._q / _gcd;

    _p = _p * magicOne2 + num._p * magicOne;
    _q *= magicOne2;
  }
  else _p += num._p;

  _verify();
}

void Rational::sub(const Rational& r)
{
  Rational num(r._p, r._q);
  int magicOne = 1, magicOne2 = 1, _gcd;

  num._verify();

  _gcd = gcd(num._q, this->_q);

  if (num._q > this->_q)
  {
    magicOne = num._q / _gcd;
    magicOne2 = _q / _gcd;

    _p = _p * magicOne - num._p * magicOne2;
    _q *= magicOne;
  }
  else if (num._q < _q)
  {
    magicOne = this->_q / _gcd;
    magicOne2 = num._q / _gcd;

    _p = _p * magicOne2 - num._p * magicOne;
    _q *= magicOne2;
  }
  else _p -= num._p;

  _verify();
}


void Rational::mult(const Rational& r)
{
  Rational num(r._p, r._q);

  num._verify();

  this->_p *= num._p;
  this->_q *= num._q;

  _verify();
}

void Rational::div(const Rational& r)
{
  Rational n(r._p, r._q);

  //dividing two rational numbers (a/b)/(c/d) is the same as (a/b) * (d/c)
  n._verify();

  this->_p *= n._q;
  this->_q *= n._p;

  _verify();
}

void Rational::_verify()
{
  if (_q <= 0)
  {
    //denominator cannot be zero
    if (_q == 0) _q = 1;
    //switch signs; pos/neg -> neg/pos
    else if (_q < 0)
    {
      _p *= -1;
      _q *= -1;
    }
  }
  //reduce
  int _gcd = gcd(_p, _q);

  if (_gcd < 0) _gcd *= -1;

  while (_p % _gcd == 0 && _q % _gcd == 0 && _gcd != 1)
  {
    _q /= _gcd;
    _p /= _gcd;
  }
}

//Euclid's gcd algorithm
int gcd(int a, int b)
{
  if (b == 0)
     return a;
  else
     return gcd(b, a % b);
}
