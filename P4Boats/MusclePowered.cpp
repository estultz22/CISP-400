/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "MusclePowered.h"
#include <iostream>

using namespace std;

MusclePowered::MusclePowered()
:Boat(), _msdt(UKMUDT), _num_seats(1)
{
  Set_Hull_Type(DISPLACEMENT);
}

MusclePowered::MusclePowered(double disp, double len, double beam,
const char* name, MUSCLE_DRIVE_TYPE msdt, unsigned num_seats)
:Boat(disp, len, beam, DISPLACEMENT, name), _msdt(msdt), _num_seats(num_seats)
{
  _check_seats();
}

MusclePowered::MusclePowered(const char* name)
:Boat(name), _msdt(UKMUDT), _num_seats(1)
{
  Set_Hull_Type(DISPLACEMENT);
}

MusclePowered::~MusclePowered() {}

void MusclePowered::Set_Muscle_Drive_Type (MUSCLE_DRIVE_TYPE msdt)
{
  _msdt = msdt;
}

MUSCLE_DRIVE_TYPE MusclePowered::Get_Muscle_Drive_Type() const
{
  return _msdt;
}

void MusclePowered::Set_Num_Seats(unsigned num_seats)
{
  _num_seats = num_seats;
  _check_seats();
}

unsigned MusclePowered::Get_Num_Seats() const
{
  return _num_seats;
}

void MusclePowered::Propulsion_Maintenance ( )
{
        cout <<endl<<"Propulsion Maintenance for muscle powered vessel \"" << Get_Name() <<"\""
             << endl<< "   Wash and repair the sails"<<endl
             << "   Lubricate the winches" << endl
             << "   Inspect and belay the halyards and sheets"<<endl;
}

void MusclePowered::Emergency_Procedures ( )
{
        Boat::Emergency_Procedures();
        cout <<endl<< "   Reef the sails" << endl
             << "   Slack the sheets" << endl
             << "   Bear away" << endl;
}

void MusclePowered::Display() const
{
        Boat::Display();
        cout << "   Muscle Drive Type: ";
        switch(_msdt)
        {
                case UKMUDT: cout << "UKMUDT"; break;
                case PADDLE: cout << "Paddle"; break;
                case OAR: cout << "Oar"; break;
                case POLE: cout << "Pole"; break;
                case SWEEP: cout << "Sweep"; break;
                default: cout << "Unknown";
        }
        cout << endl << "   Number of Seats: ";
        cout << Get_Num_Seats();

        cout << endl;
}

void MusclePowered::_check_seats()
{
  if (_num_seats > 2) _num_seats = 2;
}
