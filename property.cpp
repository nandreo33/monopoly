#include <string>
#include <iostream>
#include "property.h"

using namespace std;

const int Rents[] = {
                  10,30,160,250,
                  20,60,320,450,
                  30,90,400,550,
                  40,100,450,600,
                  50,150,625,750,
                  60,180,700,900,
                  70,200,750,950,
                  80,220,800,1000,
                  90,250,875,1050,
                  100,300,925,1100,
                  110,330,975,1150,
                  120,360,1025,1200,
                  130,390,1100,1275,
                  150,450,1200,1400,
                  175,500,1300,1500,
                  200,600,1700,2000
                  };

Property::Property(int b_r, bool is_b, string name, ColorGroup col) :
    base_rent(base_rent), name(name), color(col)
{
  num_buildings = 0;
  buildable = is_b;
  mortgaged = false;
  owner = 0;
};

int Property::get_num_buildings() const
{
  return num_buildings;
};

// ##############################
// should this pass by reference?
// ##############################
ColorGroup Property::get_color() const
{
  return color;
};

bool Property::is_buildable() const
{
  return buildable;
};

string Property::get_name() const
{
  return name;
}

void Property::mortgage()
{
  if (!mortgaged)
  {
    mortgaged = true;
  }
  else
  {
    throw ("error! already mortgaged");
  }
}

// ##############################
// is this right??
// ##############################
void Property::add_building()
{
  if (is_buildable())
  {
    if (num_buildings >= 5)
    {
      throw ("add_building() error - property full");
    }
    else if (num_buildings < 0)
    {
      throw ("add_building() error - property has negative buildings");
    }
    else
    {
      num_buildings++;
    }
  }
}

int Property::get_rent() const
{
  if (get_color().get_color_type() == railroad)
  {
    return 50*get_owner().num_owned_railroads();
  }
  else if (get_color().get_color_type() == utility)
  {
    //####################
    // implement this
    //####################
  }
  else if (base_rent == 35)
  {
    return (Rents[100+num_buildings-1]);
  }
  else if (base_rent == 50)
  {
    return (Rents[104+num_buildings-1]);
  }
  else
  {
    return (Rents[((base_rent-2)%2) + num_buildings - 1]);
  };
}

void Property::set_owner(Player* player)
{
  owner = player;
}

int* Property::get_owner() const
{
  if (owner == 0)
  {
    cout << "unowned!";
    return 0;
  }
  else
  {
    return owner;
  }
}

void Property::do_action(Player* active_player)
{
  if (get_owner())
  {
    cout << "\nYou landed on " << get_name();
    cout << "\n" << get_owner().get_name() << " owns this property";
    cout << "\nYou owe them: $" << get_rent();
    cout << "\nPress enter to pay\n";
    cin.ignore();
    active_player.subtract_money(get_rent());
    get_owner().add_money(get_rent());

    // ###################
    // bankruptcy check ! ! !
    // ###################
  }
  else
  {
    int response = 0;
    cout << "\nYou landed on " << get_name();
    cout << "\nIt costs " << get_color().get_purchase_cost();

    if (active_player.get_balance() < get_color().get_purchase_cost())
    {
      cout << "\nWould you like to purchase it?\n1: Yes\n2: No\n";

      while (true)
      {
        cin << response;
        if (response == 1)
        {
          (*active_player).subtract_money(get_rent());
          set_owner(active_player);
          add_property(active_player);
          break;
        }
        else if (response == 2)
        {
          break;
        }
        else
        {
          response = 0;
          cout << "could not recognize response. try again.\n";
          continue;
        }
      }

    }
    else
    {
      cout << "\nYou don't have enough money to purchase it. Press enter to continue";
      cin.ignore();
    }
  }
}