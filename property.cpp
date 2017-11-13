#include <string>
#include <iostream>
#include "property.h"

/*
class Property : public Space
{
private:
  int base_rent;
  int num_buildings:
  bool is_buildable;
  bool mortgaged;
  Player* owner; // this will be an error? include Player at compile time?
public:
  Color get_color(); //enum color where?
  bool buildable();
  Player* get_owner(); // again, where do I include Player?
  void set_owner(Player* player);
  bool mortgage();
  void do_action();
}
*/

int Property::get_rent()
{
// calculates and returns rent based on:
// base_rent
// num_buildings
// ColorGroup?
}

int Property::get_num_buildings()
{
  // check if buildable? does it have to?
  return num_buildings;
}

void Property::add_building()
{
// check if is buildable
// check if too many buildings?
// increment buildings
// how is this different from build()?
}

