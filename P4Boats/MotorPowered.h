/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "Boat.h"
using namespace std;

#ifndef MOTOR_POWERED_H_ECS_
#define MOTOR_POWERED_H_ECS_

enum FUEL_TYPE {UKFT, DIESEL, GASOLINE, ELECTRIC};
enum MOTOR_DRIVE_TYPE {UKMODT, INBOARD, OUTBOARD, IOBOARD};


class MotorPowered: public Boat
{
  FUEL_TYPE _ft;
  MOTOR_DRIVE_TYPE _mdt;
  char* _motor_manual;

  public:
    MotorPowered ();
    MotorPowered (double disp, double len, double beam, const char* name,
                  FUEL_TYPE ft, MOTOR_DRIVE_TYPE mdt, char* mtrManual);
    MotorPowered (const char* name);
    virtual ~MotorPowered ();

    void Set_Fuel_Type (FUEL_TYPE);
    FUEL_TYPE Get_Fuel_Type () const;

    void Set_Motor_Drive_Type (MOTOR_DRIVE_TYPE);
    MOTOR_DRIVE_TYPE Get_Motor_Drive_Type () const;

    void Set_Motor_Manual (char *);
    char* Get_Motor_Manual () const;

    virtual void Propulsion_Maintenance ();
    virtual void Emergency_Procedures ();
    virtual void Display() const;
};

#endif
