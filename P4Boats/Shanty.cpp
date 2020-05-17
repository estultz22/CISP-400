/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "Shanty.h"

Shanty::Shanty()
:MusclePowered(), _num_berths(1)
{
  Set_Muscle_Drive_Type(SWEEP);
  Set_Hull_Type(DISPLACEMENT);
  Set_Num_Seats(1);
}

Shanty::Shanty(double disp, double len, double beam, const char* name, unsigned seats, unsigned berths)
:MusclePowered(disp, len, beam, name, PADDLE, seats), _num_berths(berths)
{
  Set_Hull_Type(DISPLACEMENT);
}

Shanty::Shanty(const char *name)
:MusclePowered(name), _num_berths(1)
{
  Set_Muscle_Drive_Type(SWEEP);
  Set_Num_Seats(1);
  Set_Hull_Type(DISPLACEMENT);
}

Shanty::~Shanty() {}

void Shanty::Set_Num_Berths(unsigned berths)
{
  _num_berths = berths;
}

unsigned Shanty::Get_Num_Berths() const
{
  return _num_berths;
}

void Shanty::Propulsion_Maintenance ( )
{
        MusclePowered::Propulsion_Maintenance();
        cout << "   Lubricate the centerboard mechanism" << endl;
}

void Shanty::Emergency_Procedures ( )
{
        cout <<endl<<"Emergency procedures for Shanty \""<< Get_Name() <<"\""
             <<endl<< "   Retract the keel"<<endl
             << "   Put the boat on the trailer"<<endl
             << "   Get away from the water"<<endl;
}
void Shanty::Display() const
{
        MusclePowered::Display();
        cout << "   This boat ";
        cout << "has " << _num_berths << " berths." << endl;
}


