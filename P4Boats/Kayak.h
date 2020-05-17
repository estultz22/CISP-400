/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MusclePowered.h"

#ifndef KAYAK_H_ECS_
#define KAYAK_H_ECS_

class Kayak: public MusclePowered
{
  bool _whitewater;

  public:
    Kayak();
    Kayak(double, double, double, const char*, unsigned, bool);
    Kayak(const char *name);
    virtual ~Kayak();

    void Set_Whitewater(bool);
    bool Get_Whitewater();

    virtual void Propulsion_Maintenance ( );
    virtual void Emergency_Procedures ( );
    virtual void Display() const;

};

#endif

