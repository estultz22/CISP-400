/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MotorPowered.h"

#ifndef SKI_H_ECS_
#define SKI_H_ECS_

class Ski: public MotorPowered
{
  bool _barefoot_pole;

  public:
    Ski();
    Ski(double, double, double, const char*, char *, bool);
    Ski(const char *name);
    virtual ~Ski();

    void Set_Barefoot_Pole(bool);
    bool Get_Barefoot_Pole();

    virtual void Propulsion_Maintenance ( );
    virtual void Emergency_Procedures ( );
    virtual void Display() const;

};

#endif
