#include <string>
#include <iostream>
#include "space.h"

class Player;

class CardSpace : public Space
{
private:
  const string name;
  int deck[16]; 
public:
  string get_name();
  void space_action(Player* active_player, int die_one, int die_two);
  void community(Player* active_player);
  void chance(Player* active_player);
  void shuffle_deck();
  int draw_card();
  CardSpace(string name);
};

class LuxuryTaxSpace : public Space
{
public:
  string get_name();
  void space_action(Player* active_player, int die_one, int die_two);
  LuxuryTaxSpace() : Space("Luxury Tax") {}
};

class IncomeTaxSpace : public Space
{
public:
  string get_name();
  void space_action(Player* active_player, int die_one, int die_two);
  IncomeTaxSpace() : Space("Income Tax") {}
};

class GoToJailSpace : public Space
{
public:
  public:
  string get_name();
  void space_action(Player* active_player, int die_one, int die_two);
  GoToJailSpace() : Space("Go To Jail") {}
};