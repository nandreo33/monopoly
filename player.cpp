#include <string>
#include <iostream>
#include <vector>
#include "property.hpp"
#include "player.hpp"

using namespace std;

Player::Player(string s) : name(s)
{
    balance = 1500;
    position = 0;
    jail_counter = 0;
}

string Player::get_name() const
{
    return name;
}

int Player::get_balance() const
{
    return balance;
}

int Player::get_position() const
{
    return position;
}

void Player::add_money(int amt)
{
    balance += amt;
}

void Player::subtract_money(int amt)
{
    balance -= amt;
    
    //################
    // bankruptcy check?
    //################
}

void Player::move(int amt, int board_size)
{
    position += amt;
    
    if (position >= board_size)
    {
        add_money(200);
        position -= board_size;
        cout << "You passed Go and collected $200. Your new balance is " << get_balance() << '\n';
    }
}

void Player::move_to_position(int pos)
{
    position = pos;
}

void Player::add_property(Property* property)
{
    owned_properties.push_back(property);
}

void Player::remove_property(int index)
{
    string prop_name = owned_properties[index]->get_name();
    
    owned_properties.erase(owned_properties.begin() + index);
    //does this work?
    
    vector<Property*>::const_iterator iter, end;
    
    for (iter = owned_properties.begin(), end = owned_properties.end(); iter != end; iter++)
    {
        if ((*iter)->get_name() == prop_name)
        {
            throw ("remove_property() error - property might not have been removed");
        }
    }
}

int Player::num_owned_railroads() const
{
    // maybe error check this?
    
    int result;
    
    vector<Property*>::const_iterator iter, end;
    
    for (iter = owned_properties.begin(), end = owned_properties.end(); iter != end; iter++)
    {
        if ((*iter)->get_color().get_color_type() == railroad)
        {
            result++;
        }
    }
    
    return result;
}

int Player::num_owned_utilities() const
{
    // maybe error check this too?
    
    int result;
    
    vector<Property*>::const_iterator iter, end;
    
    for (iter = owned_properties.begin(), end = owned_properties.end(); iter != end; iter++)
    {
        if ((*iter)->get_color().get_color_type() == utility)
        {
            result++;
        }
    }
    
    return result;
}

int Player::num_owned_buildings() const
{
    int result;
    
    vector<Property*>::const_iterator iter, end;
    
    for (iter = owned_properties.begin(), end = owned_properties.end(); iter != end; iter++)
    {
        result += (*iter)->get_num_buildings();
    }
    
    return result;
}

void Player::set_jail_counter(int i)
{
    jail_counter = i;
}

int Player::get_jail_counter() const
{
    return jail_counter;
}
