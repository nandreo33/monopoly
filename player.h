#include <string>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Property;

class Player
{
private:
    const string name;
    int balance;
    int position;
    int jail_counter;
    vector<Property*> owned_properties;
public:
    string get_name() const;
    int get_balance() const;
    int get_position() const;
    int get_jail_counter() const;
    void add_money(int amt);
    void subtract_money(int amt);
    void move(int amt, int board_size);
    void move_to_position(int pos);
    void add_property(Property* property);
    void remove_property(int index);
    int num_owned_railroads() const;
    int num_owned_utilities() const;
    int num_owned_buildings() const;
    void set_jail_counter(int i);
    
    Player(string s);
};

#endif
