#include <string>
#include <iostream>
#include "color.h"

class Property : public Space
{
private:
  const int base_rent;
  int num_buildings:
  const bool is_buildable;
  bool mortgaged;
  // Player* owner; // this will be an error? include Player at compile time?
  ColorGroup color;
public:
  int get_rent() const;
  int get_num_buildings() const;
  void add_building();
  ColorGroup get_color() const; //enum color where?
  bool is_buildable() const;
  // Player* get_owner() const; // again, where do I include Player?
  // void set_owner(Player* player);
  bool mortgage();
  void do_action();
}
