/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MusclePowered.h"

#ifndef SHANTY_H_ECS_
#define SHANTY_H_ECS_

class Shanty: public MusclePowered
{
  unsigned _num_berths;

  public:
    Shanty();
    Shanty(double, double, double, const char* name, unsigned seats, unsigned berths);
    Shanty(const char *name);
    virtual ~Shanty();

    void Set_Num_Berths(unsigned);
    unsigned Get_Num_Berths() const;

    virtual void Propulsion_Maintenance ( );
    virtual void Emergency_Procedures ( );
    virtual void Display() const;

};

#endif

