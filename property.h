#include <string>
#include <iostream>
#include "space.h"
#include "color.h"

#ifndef PROP_H
#define PROP_H

class Player;

class Property : public Space
{
private:
  const int base_rent;
  int num_buildings;
  bool buildable;
  bool mortgaged;
  Player* owner;
  string name;
  ColorGroup color;
  const int purchase_cost;
public:
  int get_rent(int die_one, int die_two) const;
  int get_purchase_cost() const;
  int get_num_buildings() const;
  ColorGroup get_color() const;
  bool is_buildable() const;
  string get_name();
  bool is_mortgaged() const;
  void mortgage();
  void add_building();
  void set_owner(Player* player);
  Player* get_owner() const;
  void space_action(Player* active_player, int die_one, int die_two);
  Property(int p_c, int b_r, bool is_b, string s, ColorGroup col);
};

#endif