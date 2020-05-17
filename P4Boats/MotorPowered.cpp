/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MotorPowered.h"
#include <iostream>

using namespace std;

MotorPowered::MotorPowered()
:Boat(), _ft(UKFT), _mdt(UKMODT), _motor_manual("None")
{
  Set_Hull_Type(DISPLACEMENT);
}

MotorPowered::MotorPowered(double disp, double len, double beam,
const char* name, FUEL_TYPE ft, MOTOR_DRIVE_TYPE mdt, char *mtrManual)
:Boat(disp, len, beam, DISPLACEMENT, name), _ft(ft), _mdt(mdt), _motor_manual(mtrManual)
{}

MotorPowered::MotorPowered(const char* name)
:Boat(name), _ft(UKFT), _mdt(UKMODT)
{
  Set_Hull_Type(DISPLACEMENT);
}

MotorPowered::~MotorPowered() {}

void MotorPowered::Set_Fuel_Type( FUEL_TYPE ft )
{
  _ft = ft;
}

FUEL_TYPE MotorPowered::Get_Fuel_Type() const
{
  return _ft;
}

void MotorPowered::Set_Motor_Drive_Type( MOTOR_DRIVE_TYPE mdt )
{
  _mdt = mdt;
}

MOTOR_DRIVE_TYPE MotorPowered::Get_Motor_Drive_Type() const
{
  return _mdt;
}

char *MotorPowered::Get_Motor_Manual() const
{
  return _motor_manual;
}

void MotorPowered::Set_Motor_Manual( char *mmnl)
{
   _motor_manual = mmnl;
}

void MotorPowered::Propulsion_Maintenance ( )
{
        cout <<endl<<"Propulsion Maintenance for motor powered vessel \"" << Get_Name() <<"\""
             << endl<< "   Wash and repair the sails"<<endl
             << "   Lubricate the winches" << endl
             << "   Inspect and belay the halyards and sheets"<<endl;
}

void MotorPowered::Emergency_Procedures ( )
{
        Boat::Emergency_Procedures();
        cout <<endl<< "   Reef the sails" << endl
             << "   Slack the sheets" << endl
             << "   Bear away" << endl;
}

void MotorPowered::Display() const
{
        Boat::Display();
        cout << "   Fuel Type: ";
        switch(_ft)
        {
                case UKFT: cout << "UKFT"; break;
                case DIESEL: cout << "Diesel"; break;
                case GASOLINE: cout << "Gasoline"; break;
                case ELECTRIC: cout << "Electric"; break;
                default: cout << "Unknown";
        }
        cout << endl << "   Motor Drive Type: ";
        switch(_mdt)
        {
                case UKMODT: cout << "UKMODT"; break;
                case INBOARD: cout << "Inboard"; break;
                case OUTBOARD: cout << "Outboard"; break;
                case IOBOARD: cout << "Ioboard"; break;
                default: cout << "Unknown";
        }
        cout << endl << "   Motor Manual: ";
        cout << _motor_manual;
        cout << endl;
}
