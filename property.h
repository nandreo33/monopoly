#include <string>
#include <iostream>
#include "space.h"
#include "color.h"

class Property : public Space
{
private:
  const int base_rent;
  int num_buildings;
  bool buildable;
  bool mortgaged;
  Player* owner;        // this will be an error? include Player at compile time?
  const string name;
  const ColorGroup color;    // should this pass by reference? does it matter?
public:
  int get_rent() const;
  int get_num_buildings() const;
  ColorGroup get_color() const;
  bool is_buildable() const;
  string get_name() const;
  void mortgage();
  void add_building();
  void set_owner(Player* player);
  Player* get_owner() const;
  void do_action(Player* active_player);
  Property(int b_r, bool is_b, string name, ColorGroup col);
};
