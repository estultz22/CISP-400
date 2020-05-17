/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 5
April 15, 2020
*/

#include "Boat.h"
#include "CabinCruiser.h"
#include "Shanty.h"
#include "Kayak.h"
#include "Ski.h"


using namespace std;

#ifndef MARINA_H_ECS
#define MARINA_H_ECS

const unsigned MARINA_SIZE = 20;
const unsigned BOAT_NAME_SIZE = 15;

class Marina
{
  Boat *_marina[MARINA_SIZE];
  unsigned _num_boats;

  void _add_boat();
  void _emergency();
  void _propulsion();
  void _display();

  //private member functions here
  public:
    Marina();
    ~Marina();
    void Run();

};


#endif
