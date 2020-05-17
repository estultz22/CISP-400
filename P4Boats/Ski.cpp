/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "Ski.h"

Ski::Ski()
:MotorPowered(), _barefoot_pole(false)
{
  Set_Fuel_Type(GASOLINE);
  Set_Motor_Drive_Type(OUTBOARD);
  Set_Hull_Type(PLANING);
}

Ski::Ski(double disp, double len, double beam, const char* name, char *mtrmnl, bool bfp)
:MotorPowered(disp, len, beam, name, GASOLINE, OUTBOARD, mtrmnl), _barefoot_pole(bfp)
{
  Set_Hull_Type(PLANING);
}

Ski::Ski(const char *name)
:MotorPowered(name), _barefoot_pole(false)
{
  Set_Fuel_Type(GASOLINE);
  Set_Motor_Drive_Type(OUTBOARD);
  Set_Hull_Type(PLANING);
}

Ski::~Ski() {}

void Ski::Set_Barefoot_Pole(bool bfp)
{
  _barefoot_pole = bfp;
}

bool Ski::Get_Barefoot_Pole()
{
  return _barefoot_pole;
}

void Ski::Propulsion_Maintenance ( )
{
        MotorPowered::Propulsion_Maintenance();
        cout << "   Lubricate the centerboard mechanism" << endl;
}
void Ski::Emergency_Procedures ( )
{
        cout <<endl<<"Emergency procedures for ski vessel\""<< Get_Name() <<"\""
             <<endl<< "   Retract the keel"<<endl
             << "   Put the boat on the trailer"<<endl
             << "   Get away from the water"<<endl;
}
void Ski::Display() const
{
        MotorPowered::Display();
        cout << "   This boat ";
        cout << ((_barefoot_pole)? "has a barefoot pole" : "does not have a barefoot pole")<<endl;
}


