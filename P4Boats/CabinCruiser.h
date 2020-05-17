/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MotorPowered.h"

#ifndef CABIN_CRUISER_H_ECS_
#define CABIN_CRUISER_H_ECS_

class CabinCruiser: public MotorPowered
{
  bool _flying_bridge;

  public:
    CabinCruiser();
    CabinCruiser(double, double, double, const char*, char *, bool);
    CabinCruiser(const char *name);
    virtual ~CabinCruiser();

    void Set_Flying_Bridge(bool);
    bool Get_Flying_Bridge();

    virtual void Propulsion_Maintenance ( );
    virtual void Emergency_Procedures ( );
    virtual void Display() const;

};

#endif

