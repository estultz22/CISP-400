/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 3
March 11, 2020
*/

#ifndef RATIONAL_H_ECS_
#define RATIONAL_H_ECS_

#include <iostream>

using namespace std;

class Rational

{
  long long _p;

  long long _q;

  //private member functions as needed
  void _verify();

public:

  Rational( );  // 0:1

  Rational( long long P, long long Q = 1 );

  Rational ( const Rational& );

  void display() const; //delete after finishing whole project

  Rational& operator= (const Rational&);

  Rational& operator+= (const Rational&);

  Rational& operator-= (const Rational&);

  Rational& operator*= (const Rational&);

  Rational& operator/= (const Rational&);



  friend ostream& operator<< (ostream&, const Rational&);

  friend istream& operator>> (istream&, Rational&);

  // operator>> must read what operator<< writes



  Rational operator+ (const Rational&) const; //[1]

  Rational operator+ (long long) const;

  friend Rational operator+ (long long, const Rational&);

  Rational operator- (const Rational&) const;

  Rational operator- (long long) const;

  friend Rational operator- (long long, const Rational&);

  Rational operator* (const Rational&) const;

  Rational operator* (long long) const;

  friend Rational operator* (long long, const Rational&);

  Rational operator/ (const Rational&) const;

  Rational operator/ (long long) const;

  friend Rational operator/ (long long, const Rational&);



  bool operator== (const Rational&) const; //[2] implement this one

  bool operator== (long long) const;

  friend bool operator== (long long, const Rational&);

  bool operator!= (const Rational&) const;

  bool operator!= (long long) const;

  friend bool operator!= (long long, const Rational&);

  bool operator> (const Rational&) const; // implement this one

  bool operator> (long long) const;

  friend bool operator> (long long, const Rational&);

  bool operator< (const Rational&) const;

  bool operator< (long long) const;

  friend bool operator< (long long, const Rational&);

  bool operator>= (const Rational&) const;

  bool operator>= (long long) const;

  friend bool operator>= (long, const Rational&);

  bool operator<= (const Rational&) const;

  bool operator<= (long long) const;

  friend bool operator<= (long long, const Rational&);



  Rational operator++ (int); //post

  Rational operator-- (int); //post

  Rational& operator++ (); //pre

  Rational& operator-- (); //pre

  Rational operator- () const;

  Rational operator+ () const;



  Rational pow( unsigned exp ) const; //returns (*this)exp



  Rational inverse() const;

};

#endif // RATIONAL_H
