/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 5
April 15, 2020
*/

#include "Marina.h"
#include <iostream>
using namespace std;

//helper function prototypes
void displayMenu();
unsigned getInt();
void displayAddBoatMenu();

enum BOATS {CABINCRUISER = 1, KAYAK, SHANTY, SKI};

Marina::Marina()
:_num_boats(0)
{
  for (unsigned i = 0; i < MARINA_SIZE; ++i) *(_marina + i) = NULL;
}

Marina::~Marina()
{
  for (unsigned i = 0; i < MARINA_SIZE; ++i) delete *(_marina + i);
}

void Marina::Run()
{
  unsigned input;

  do
  {
    displayMenu();
    input = getInt();

    switch (input)
    {
      case 1: _add_boat(); break;
      case 2: _emergency(); break;
      case 3: _propulsion(); break;
      case 4: _display(); break;
      default: break;
    }
  } while (input < 5);
}

void Marina::_add_boat()
{
  unsigned in;
  char name[BOAT_NAME_SIZE];
  bool new_name;

  do
  {
    displayAddBoatMenu();
    in = getInt();
    new_name = false;

    switch (in)
    {
      case CABINCRUISER:
        _marina[_num_boats++] = new CabinCruiser(); new_name = true; break;
      case KAYAK:
        _marina[_num_boats++] = new Kayak(); new_name = true; break;
      case SHANTY:
        _marina[_num_boats++] = new Shanty(); new_name = true; break;
      case SKI:
        _marina[_num_boats++] = new Ski(); new_name = true; break;
      default: break;
    }

    if (new_name)
    {
      cout << "\nWhat's the name of your boat?: ";
      cin.ignore();
      cin.getline(name, '\n');
      (*(_marina + (_num_boats - 1)))->Set_Name(name);
    }
  } while (in < 5);
}

void Marina::_emergency()
{
  if (_num_boats == 0) cout << "\nThere are currently no boats in the marina.\n";
  else for (unsigned i = 0; i < _num_boats; ++i) (*(_marina + i))->Emergency_Procedures();
}

void Marina::_propulsion()
{
  if (_num_boats == 0) cout << "\nThere are currently no boats in the marina.\n";
  else for (unsigned i = 0; i < _num_boats; ++i) (*(_marina + i))->Propulsion_Maintenance();
}

void Marina::_display()
{
  if (_num_boats == 0) cout << "\nThere are currently no boats in the marina.\n";
  else for (unsigned i = 0; i < _num_boats; ++i) (*(_marina + i))->Display();
}

//Auxillary functions
void displayMenu()
{
  cout << "1.Place a new Boat into the Marina\n"
       << "2.Display Emergency Procedures for each boat in the Marina.\n"
       << "3.Display Propulsion Maintenance for each boat in the Marina\n"
       << "4.Display all of the Boats in the Marina.\n"
       << "5. Exit the simulation.\n";
}

void displayAddBoatMenu()
{
  cout << "1.Cabin Cruiser\n"
       << "2.Kayak\n"
       << "3.Shanty\n"
       << "4.Ski\n"
       << "5.Cancel/Done\n";
}

unsigned getInt()
{
  unsigned input;
  cin >> input;
  return input;
}
