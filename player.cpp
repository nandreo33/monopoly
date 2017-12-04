#include <string>
#include <iostream>
#include <vector>
#include "property.h"
#include "player.h"

using namespace std;

Player::Player(string s) : name(s)
{
	balance = 1500;
	position = 0;
	jail_counter = 0;
	trade_balance = 0;
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

bool Player::is_group_owned(color_t c)
{
	int count = 0;
	int c_group_size;
	for (int i = 0; i < owned_properties.size(); i++)
	{
		if (owned_properties[i]->get_color().get_color_type() == c)
		{
			count++;
			c_group_size = owned_properties[i]->get_color().get_group_size();
		}
	}

	if (count == c_group_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::set_jail_counter(int i)
{
	jail_counter = i;
}

int Player::get_jail_counter()
{
	return jail_counter;
}

void Player::set_get_out_of_jail_free_card(bool b)
{
	get_out_of_jail_free_card = b;
}

bool Player::has_get_out_of_jail_free_card()
{
	return get_out_of_jail_free_card;
}

void Player::reset_owned_properties()
{
	for (int i = 0; i < owned_properties.size(); i++)
	{
		owned_properties[i]->reset();
	}
}

void Player::print_properties()
{
	if (owned_properties.size())
	{
		color_t color_buffer[] = {brown, light_blue, purple, orange, red, yellow, green, blue, railroad, utility};

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < owned_properties.size(); j++)
			{
				if (owned_properties[j]->get_color().get_color_type() == color_buffer[i])
				{
					cout << owned_properties[j]->get_name() << "\t\t" << owned_properties[j]->is_mortgaged() << "\t\t" << owned_properties[j]->get_num_buildings() << '\n';
				}
			}
		}
	}
}

// fix bad input!!!!!!!!!!!!!!!!!!

void Player::mortgage()
{

	if (owned_properties.size())
	{
		while(true){
			int response;
			cout << "\nEnter the number for the property you would like to mortgage or unmortgage, or 0 to exit\n";
			for (int i = 0; i < owned_properties.size(); i++)
			{
				cout << "0: exit\n";
				if (owned_properties[i]->is_mortgaged())
				{
					cout << i+1 << ": UNMORTGAGE " << owned_properties[i]->get_name();
					cout << "\t-$" << (owned_properties[i]->get_purchase_cost()*11/20) << '\n';
				}
				else if (!owned_properties[i]->is_mortgaged())
				{
					cout << i+1 << ": MORTGAGE " << owned_properties[i]->get_name();
					cout << "\t+$" << (owned_properties[i]->get_purchase_cost()/2) + ((owned_properties[i]->get_num_buildings() * owned_properties[i]->get_color().get_building_cost())/2) << '\n';
				}
			}

			cin >> response;
			cin.ignore(256,'\n');
			if (response == 0)
			{
				break;
			}
			else if (response > 0 && response <= owned_properties.size())
			{
				int i = response-1;
				if (owned_properties[i]->is_mortgaged())
				{
					owned_properties[i]->toggle_mortgage();
					subtract_money((owned_properties[i]->get_purchase_cost()*11/20));

				}
				else if (!owned_properties[i]->is_mortgaged())
				{
					owned_properties[i]->toggle_mortgage();
					owned_properties[i]->set_num_buildings(0);
					add_money((owned_properties[i]->get_purchase_cost()/2) + ((owned_properties[i]->get_num_buildings() * owned_properties[i]->get_color().get_building_cost()))/2);
				}
			}
			else
			{
				response = 0;
				cin.clear();
				cin.ignore(256,'\n');
				cout << "could not recognize response. try again.";
			}
		}
	}
	else
	{
		cout << "\nYou own no property\n";
	}
}


// fix this out if
void Player::build()
{
	while(true){
		int response;
		if (owned_properties.size())
		{
			cout << "\nEnter the number for the property you would like to build on, or 0 to exit\n";
			cout << "0: exit\n";
			for (int i = 0; i < owned_properties.size(); i++)
			{
				if (owned_properties[i]->is_buildable() && is_group_owned(owned_properties[i]->get_color().get_color_type()))
				{
					cout << i+1 << ": " << owned_properties[i]->get_name() << "\tnumber of buildings: " << owned_properties[i]->get_num_buildings();
					cout << "\t-$" << (owned_properties[i]->get_color().get_building_cost()) << '\n';
				}
			}
		}

		cin >> response;
		cin.ignore(256,'\n');
		if (response == 0)
		{
			break;
		}
		else if (response > 0 && response <= owned_properties.size())
		{
			int i = response-1;
			if (owned_properties[i]->is_buildable() 
				&& is_group_owned(owned_properties[i]->get_color().get_color_type()) 
				&& !(owned_properties[i]->is_mortgaged()) 
				&& owned_properties[i]->get_num_buildings() < 5)
			{
				owned_properties[i]->set_num_buildings(owned_properties[i]->get_num_buildings()+1);
			}
			else
			{
				cout << "cannot build on that property\n";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "could not recognize response. try again.";
		}
	}
}

//choose property to be traded
void Player::add_trade_property(Property* property)
{
	trade_properties.push_back(property);
}

//exchanges amount to be traded among players
void Player::set_trade_balance(int bal)
{
	trade_balance = bal;
}

void Player::execute_trade(Player* other_player)
{
	for (int i = 0; i < trade_properties.size(); i++)
	{
		trade_properties[i]->set_owner(other_player);
		other_player->add_property(trade_properties[i]);
	}

	for (int i = 0; i < other_player->trade_properties.size(); i++)
	{
		other_player->trade_properties[i]->set_owner(this);
		add_property(other_player->trade_properties[i]);
	}

	other_player->add_money(trade_balance);
	add_money(other_player->trade_balance);
}

void Player::reset_trade(Player* other_player)
{
	for (int i = 0; i < trade_properties.size(); i++)
	{
		add_property(trade_properties[i]);
	}

	for (int i = 0; i < other_player->trade_properties.size(); i++)
	{
		add_property(other_player->trade_properties[i]);
	}

	other_player->add_money(other_player->trade_balance);
	add_money(trade_balance);

	trade_properties.clear();
	other_player->trade_properties.clear();
	trade_balance = 0;
	other_player->trade_balance = 0;
}

void Player::trade(vector<Player*> players)
{
	int response;
	while(true){
		cout << "\nEnter the number for the player you would like to trade with, or 0 to exit\n";
		cout << "0: exit\n";
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i] != this)
			{
				cout << i+1 << ": " << players[i]->get_name() << "\n";
			}
		}

		cin >> response;
		cin.ignore(256,'\n');
		if (response == 0)
		{
			break;
		}
		else if (response > 0 && response <= players.size())
		{
			int i = response-1;
			if (players[i] != this)
			{
				Player* other_player = players[i];

				// offer props
				while(true){
					cout << "\nEnter the number for your property to add it to the trade, or 0 to go to the next step\n";
					cout << "0: next\n";
					for (int i = 0; i < owned_properties.size(); i++)
					{
						cout << i+1 << ": " << owned_properties[i]->get_name() << "\n";
					}

					cin >> response;
					cin.ignore(256,'\n');
					if (response == 0)
					{
						break;
					}
					else if (response > 0 && response <= owned_properties.size())
					{
						int i = response-1;
						add_trade_property(owned_properties[i]);
						remove_property(i);
					}
					else
					{
						cin.clear();
						cin.ignore(256,'\n');
						cout << "could not recognize response. try again.";
					}
				}

				// request props
				while(true){
					cout << "\nEnter the number for " << other_player->get_name() << "'s' property to add it to the trade, or 0 to go to the next step\n";
					cout << "0: next\n";
					for (int i = 0; i < other_player->owned_properties.size(); i++)
					{
						cout << i+1 << ": " << other_player->owned_properties[i]->get_name() << "\n";
					}

					cin >> response;
					cin.ignore(256,'\n');
					if (response == 0)
					{
						break;
					}
					else if (response > 0 && response <= other_player->owned_properties.size())
					{
						int i = response-1;
						other_player->add_trade_property(other_player->owned_properties[i]);
						other_player->remove_property(i);
					}
					else
					{
						cin.clear();
						cin.ignore(256,'\n');
						cout << "could not recognize response. try again.";
					}
				}

				// offer money
				while(true){
					cout << "\nEnter the an amount (up to $" << get_balance() << ") of YOUR money to add to the trade\n";
					cin >> response;
					cin.ignore(256,'\n');
					if (response == 0)
					{
						break;
					}
					else if (response > 0 && response <= get_balance())
					{
						set_trade_balance(response);
						subtract_money(response);
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(256,'\n');
						cout << "could not recognize response. try again.";
					}
				}

				// request money
				while(true){
					cout << "\nEnter the an amount (up to $" << other_player->get_balance() << ") of " << other_player->get_name() << "'s money to add to the trade\n";
					cin >> response;
					cin.ignore(256,'\n');
					if (response == 0)
					{
						break;
					}
					else if (response > 0 && response <= other_player->get_balance())
					{
						other_player->set_trade_balance(response);
						other_player->subtract_money(response);
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(256,'\n');
						cout << "could not recognize response. try again.";
					}
				}

				cout << "\nYour offer:\n";

				for (int i = 0; i < trade_properties.size(); i++)
				{
					cout << trade_properties[i]->get_name() << "\n";
				}

				cout << "$" << trade_balance << "\n\nFOR:\n";

				for (int i = 0; i < other_player->trade_properties.size(); i++)
				{
					cout << other_player->trade_properties[i]->get_name() << "\n";
				}

				cout << "$" << other_player->trade_balance << "\n";

				cout << other_player->get_name() << " do you accept?\n1: Yes\n2: No\n";


				while(true){
					cin >> response;
					cin.ignore(256,'\n');
					if (response == 1)
					{
						execute_trade(other_player);
						break;
					}
					else if (response == 2)
					{
						reset_trade(other_player);
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(256,'\n');
						cout << "could not recognize response. try again.";
					}
				}


			}
			else
			{
				cout << "cannot trade with that player\n";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "could not recognize response. try again.";
		}
	}
}

// trade_properties.push_back(owned_properties[num-1]);
// n1.remove_property(owned_properties[num-1]);
// n2.add_property(trade_properties[0]);
// trade_properties.pop_back();