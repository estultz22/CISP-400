/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "CabinCruiser.h"

CabinCruiser::CabinCruiser()
:MotorPowered(), _flying_bridge(false)
{
  Set_Fuel_Type(DIESEL);
  Set_Motor_Drive_Type(INBOARD);
  Set_Hull_Type(SEMI_DISP);
}

CabinCruiser::CabinCruiser(double disp, double len, double beam, const char* name, char *mtrmnl, bool fb)
:MotorPowered(disp, len, beam, name, DIESEL, INBOARD, mtrmnl), _flying_bridge(fb)
{
  Set_Hull_Type(SEMI_DISP);
}

CabinCruiser::CabinCruiser(const char *name)
:MotorPowered(name), _flying_bridge(false)
{
  Set_Fuel_Type(DIESEL);
  Set_Motor_Drive_Type(INBOARD);
  Set_Hull_Type(SEMI_DISP);
}

CabinCruiser::~CabinCruiser() {}

void CabinCruiser::Set_Flying_Bridge(bool fb)
{
  _flying_bridge = fb;
}

bool CabinCruiser::Get_Flying_Bridge()
{
  return _flying_bridge;
}

void CabinCruiser::Propulsion_Maintenance ( )
{
        MotorPowered::Propulsion_Maintenance();
        cout << "   Lubricate the centerboard mechanism" << endl;
}
void CabinCruiser::Emergency_Procedures ( )
{
        cout <<endl<<"Emergency procedures for trailer sailer \""<< Get_Name() <<"\""
             <<endl<< "   Retract the keel"<<endl
             << "   Put the boat on the trailer"<<endl
             << "   Get away from the water"<<endl;
}
void CabinCruiser::Display() const
{
        MotorPowered::Display();
        cout << "   This boat ";
        cout << ((_flying_bridge)? "has a flying bridge" : "does not have a flying bridge")<<endl;
}


