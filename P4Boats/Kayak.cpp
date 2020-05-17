/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 4
April 15, 2020
*/

#include "Kayak.h"

Kayak::Kayak()
:MusclePowered(), _whitewater(false)
{
  Set_Muscle_Drive_Type(PADDLE);
  Set_Hull_Type(DISPLACEMENT);
  Set_Num_Seats(1);
}

Kayak::Kayak(double disp, double len, double beam, const char* name, unsigned seats, bool whw)
:MusclePowered(disp, len, beam, name, PADDLE, seats), _whitewater(whw)
{
  Set_Hull_Type(DISPLACEMENT);
}

Kayak::Kayak(const char *name)
:MusclePowered(name), _whitewater(false)
{
  Set_Muscle_Drive_Type(PADDLE);
  Set_Num_Seats(1);
  Set_Hull_Type(DISPLACEMENT);
}

Kayak::~Kayak() {}

void Kayak::Set_Whitewater(bool whw)
{
  _whitewater = whw;
}

bool Kayak::Get_Whitewater()
{
  return _whitewater;
}

void Kayak::Propulsion_Maintenance ( )
{
        MusclePowered::Propulsion_Maintenance();
        cout << "   Lubricate the centerboard mechanism" << endl;
}
void Kayak::Emergency_Procedures ( )
{
        cout <<endl<<"Emergency procedures for trailer sailer \""<< Get_Name() <<"\""
             <<endl<< "   Retract the keel"<<endl
             << "   Put the boat on the trailer"<<endl
             << "   Get away from the water"<<endl;
}
void Kayak::Display() const
{
        MusclePowered::Display();
        cout << "   This boat ";
        cout << ((_whitewater)? "can be used on whitewater" : "cannot be used on whitewater")<<endl;
}


