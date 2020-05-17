/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "Boat.h"

#ifndef MUSCLE_POWERED_H_ECS_
#define MUSCLE_POWERED_H_ECS_

enum MUSCLE_DRIVE_TYPE {UKMUDT, PADDLE, OAR, POLE, SWEEP};


class MusclePowered: public Boat
{
  MUSCLE_DRIVE_TYPE _msdt;
  unsigned _num_seats;
  void _check_seats();

  public:
    MusclePowered ();
    MusclePowered (double disp, double len, double beam, const char* name,
                  MUSCLE_DRIVE_TYPE msdt, unsigned seats);
    MusclePowered (const char* name);
    virtual ~MusclePowered ();

    void Set_Muscle_Drive_Type (MUSCLE_DRIVE_TYPE);
    MUSCLE_DRIVE_TYPE Get_Muscle_Drive_Type () const;

    void Set_Num_Seats (unsigned);
    unsigned Get_Num_Seats () const;

    virtual void Propulsion_Maintenance ();
    virtual void Emergency_Procedures ();
    virtual void Display() const;
};

#endif
