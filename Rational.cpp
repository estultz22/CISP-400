/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 3
March 11, 2020
*/

#include "Rational.h"
#include <iostream>

using namespace std;

int gcd(int, int);

Rational::Rational()
:_p(0), _q(1)
{}

Rational::Rational(long long P, long long Q)
:_p(P), _q(Q)
{
  _verify();
}

Rational::Rational(const Rational& r)
:_p(r._p), _q(r._q)
{}

Rational& Rational::operator=(const Rational& r)
{
  if (this == &r) return *this;

  _p = r._p;
  _q = r._q;

  return *this;
}

Rational& Rational::operator+=(const Rational& r)
{
 //assuming parameter r is a verified rational number
  Rational num = r;
  //cross-multiplies numer with denom and adds numers
  _p *= num._q;
  num._p *= _q;
  _q *= num._q;
  _p += num._p;

  //verify and reduce new number
  _verify();

  return *this;
}

Rational& Rational::operator-=(const Rational& r)
{
  return operator+=(-r);
}

Rational& Rational::operator*=(const Rational& ra)
{
  _p *= ra._p;
  _q *= ra._q;

  _verify();

  return *this;
}

Rational& Rational::operator/=(const Rational& ra)
{
  //dividing two rational numbers (a/b)/(c/d) is the same as (a/b) * (d/c)
  if (ra._p != 0) return operator*=(ra.inverse());
  return *this;
}



ostream& operator<<(ostream& os, const Rational& ra)
{
  os << ra._p << ":" << ra._q;
  return os;
}

istream& operator>>(istream& is, Rational& ra)
{
  long long p, q;
  char c;

  is >> p >> c >> q;
  ra = Rational(p, q);

  return is;
}



Rational Rational::operator+(const Rational& ra) const
{
  return Rational(*this) += ra;
}

Rational Rational::operator+(long long a) const
{
  return Rational(*this) += Rational(a);
}

Rational operator+(long long a, const Rational& ra)
{
  return Rational(a) += ra;
}

Rational Rational::operator-(const Rational& ra) const
{
  Rational rn(_p, _q);
  return rn -= ra;
}

Rational Rational::operator-(long long a) const
{
  Rational rn = *this;
  return rn.operator+=(-a);
}

Rational operator-(long long a, const Rational& ra)
{
  return Rational(a) -= ra;
}

Rational Rational::operator*(const Rational& ra) const
{
  return Rational(*this) *= ra;
}

Rational Rational::operator*(long long a) const
{
  Rational rn = *this;
  return rn *= a;
}

Rational operator*(long long a, const Rational& ra)
{
  return Rational(a) *= ra;
}

Rational Rational::operator/(const Rational& ra) const
{
  return Rational(*this) /= ra;
}

Rational Rational::operator/(long long a) const
{
  return Rational(*this) /= a;
}

Rational operator/(long long a, const Rational& ra)
{
  return Rational(a) /= ra;
}



bool Rational::operator==(const Rational& ra) const
{
  return (_p == ra._p && _q == ra._q);
}

bool Rational::operator==(long long a) const
{
  return (*this) == Rational(a);
}

bool operator==(long long a, const Rational& ra)
{
  return Rational(a) == ra;
}

bool Rational::operator!=(const Rational& ra) const
{
  return !((*this) == ra);
}

bool Rational::operator!=(long long a) const
{
  return !((*this) == Rational(a));
}

bool operator!= (long long a, const Rational& ra)
{
  return !(Rational(a) == ra);
}

bool Rational::operator>(const Rational& ra) const
{
  long long p1 = _p * ra._q;
  long long p2 = _q * ra._p;

  return p1 > p2;
}

bool Rational::operator>(long long a) const
{
  return (*this) > Rational(a);
}

bool operator>(long long a, const Rational& ra)
{
  return Rational(a) > ra;
}

bool Rational::operator<(const Rational& ra) const
{
  return !((*this) > ra) && !((*this) == ra);
}

bool Rational::operator<(long long a) const
{
  return (*this) < Rational(a);
}

bool operator<(long long a, const Rational& ra)
{
  return Rational(a) < ra;
}

bool Rational::operator>= (const Rational& ra) const
{
  return (*this) > ra || (*this) == ra;
}

bool Rational::operator>= (long long a) const
{
  return (*this) >= Rational(a);
}

bool operator>= (long a, const Rational& ra)
{
  return Rational(a) >= ra;
}

bool Rational::operator<=(const Rational& ra) const
{
  return (*this) < ra || (*this) == ra;
}

bool Rational::operator<= (long long a) const
{
  return (*this) <= Rational(a);
}

bool operator<= (long long a, const Rational& ra)
{
  return Rational(a) <= ra;
}

Rational Rational::operator++ (int)//post
{
  Rational r(*this);
  r += 1;
  return r;
}

Rational Rational::operator-- (int)//post
{
  Rational r(*this);
  r -= 1;
  return r;
}

Rational& Rational::operator++ ()//pre
{
  *this += 1;
  return *this;
}

Rational& Rational::operator-- ()//pre
{
  *this -= 1;
  return *this;
}

Rational Rational::operator-() const
{
  return Rational(*this) * -1;
}

Rational Rational::operator+ () const
{
  return *this;
}


Rational Rational::pow( unsigned exp ) const //returns (*this)exp
{
  if (exp == 0) return 1;
  else return Rational(*this) * pow(exp - 1);
}


// returns the multiplicative inverse of *this;
Rational Rational::inverse() const
{
  return Rational(_q, _p);
}

void Rational::_verify()
{
  if (_q <= 0)
  {
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

  _q /= _gcd;
  _p /= _gcd;

}

//Euclid's gcd algorithm
int gcd(int a, int b)
{
  if (b == 0)
     return a;
  else
     return gcd(b, a % b);
}
