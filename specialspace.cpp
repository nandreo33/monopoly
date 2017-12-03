#include <string>
#include <iostream>
#include <algorithm>
#include "specialspace.h"

using namespace std;

CardSpace::CardSpace(string name) : name(name), Space(name)
{
	for (int i = 0; i < 16; i++)
	{
		deck[i] = i;
	}
	shuffle_deck();
}

string CardSpace::get_name()
{
	return name;
}

void CardSpace::shuffle_deck()
{
	random_shuffle(&deck[0],&deck[15]);
}

int CardSpace::draw_card()
{
	int result = deck[0];

	for (int i = 1; i < 16; i++)
	{
		deck[i-1] = deck[i];
	}

	deck[15] = result;

	return result;
}

void CardSpace::space_action(Player* active_player, int die_one, int die_two)
{
	int pos = active_player->get_position();

	if (pos == 2 || pos == 17 || pos == 33)
	{
		community(active_player);
	}
	else if (pos == 7 || pos == 22 || pos == 36)
	{
		chance(active_player);
	}
	else
	{
		throw ("CardSpace space_action() error");
	}
}

void CardSpace::community(Player* active_player)
{
	cout << "You landed on Community Chest\nPress enter to draw a card\n";

	cin.ignore(256,'\n');

	int card = draw_card();

	switch(card)
	{
		case 0:	
			cout << "Advance to Go. Collect $200";
			active_player->move_to_position(0);
			active_player->add_money(200);
			break;
		case 1:	
			cout << "Bank error in your favor--Collect $200";
			active_player->add_money(200);
			break;
		case 2:	
			cout << "Doctor's fee--Pay $50";
			active_player->subtract_money(50);
			break;
		case 3:	
			cout << "From sale of stock you get $50";
			active_player->add_money(50);
			break;
		case 4:	
			cout << "Get Out of Jail Free";
			// ###############
			// how do i implement this
			// ###############
			break;
		case 5:	
			cout << "Go to Jail--Go directly to jail--Do not pass Go--Do not collect $200";
			active_player->move_to_position(10);
			active_player->set_jail_counter(3);
			break;
		case 6:	
			cout << "Holiday Fund matures--Receive $100";
			active_player->add_money(100);
			break;
		case 7:	
			cout << "Income tax refund--Collect $20";
			active_player->add_money(20);
			break;
		case 8:	
			cout << "It is your birthday--Collect $10";
			active_player->add_money(10);
			break;
		case 9:	
			cout << "Life insurance matures--Collect $100";
			active_player->add_money(100);
			break;
		case 10:	
			cout << "Pay hospital fees of $100";
			active_player->subtract_money(100);
			break;
		case 11:	
			cout << "Pay school fees of $150";
			active_player->subtract_money(150);
			break;
		case 12:	
			cout << "Receive $25 consultancy fee";
			active_player->add_money(25);
			break;
		case 13:	
			cout << "You have won second prize in a beauty contest--Collect $10";
			active_player->add_money(10);
			break;
		case 14:	
			cout << "You inherit $100";
			active_player->add_money(100);
			break;
		case 15:
			cout << "You are assessed for street repairs--$40 per house";
			active_player->subtract_money(active_player->num_owned_buildings()*40);
			break;
	}
	cout << "\n";
}

void CardSpace::chance(Player* active_player)
{
	cout << "You landed on Chance\nPress enter to draw a card\n";

	cin.ignore(256,'\n');

	int card = draw_card();

	switch(card)
	{
		case 0:	
			cout << "Advance to Go. Collect $200";
			active_player->move_to_position(0);
			active_player->add_money(200);
			break;
		case 1:	
			cout << "Advance to Illinois Ave—If you pass Go, collect $200";
			if (active_player->get_position() > 24)
			{
				active_player->add_money(200);
			}
			active_player->move_to_position(24);
			break;
		case 2:	
			cout << "Advance to St. Charles Place – If you pass Go, collect $200";
			if (active_player->get_position() > 11)
			{
				active_player->add_money(200);
			}
			active_player->move_to_position(11);
			break;
		case 3:	
			cout << "Advance token to nearest Utility.";
			if (active_player->get_position() > 28 || active_player->get_position() < 12)
			{
				active_player->move_to_position(12);
			}
			else
			{
				active_player->move_to_position(28);
			}
			break;
		case 4:	
			cout << "Get Out of Jail Free";
			// ###############
			// how do i implement this
			// ###############
			break;
		case 5:	
			cout << "Go to Jail--Go directly to jail--Do not pass Go--Do not collect $200";
			active_player->move_to_position(10);
			active_player->set_jail_counter(3);
			break;
		case 6:	
			cout << "Advance token to the nearest Railroad";
			if (active_player->get_position() > 25 || active_player->get_position() < 5)
			{
				active_player->move_to_position(5);
			}
			else if (active_player->get_position() < 15)
			{
				active_player->move_to_position(15);
			}
			else if (active_player->get_position() < 25)
			{
				active_player->move_to_position(25);
			}
			else if (active_player->get_position() < 35)
			{
				active_player->move_to_position(35);
			}
			break;
		case 7:	
			cout << "Bank pays you dividend of $50";
			active_player->add_money(50);
			break;
		case 8:	
			cout << "Go Back 3 Spaces";
			if (active_player->get_position() < 3)
			{
				active_player->move_to_position(active_player->get_position()+37);
			}
			else
			{
				active_player->move_to_position(active_player->get_position()-3);
			}
			break;
		case 9:	
			cout << "Pay poor tax of $15";
			active_player->subtract_money(15);
			break;
		case 10:	
			cout << "Take a trip to Reading Railroad–If you pass Go, collect $200";
			if (active_player->get_position() > 5)
			{
				active_player->add_money(200);
			}
			active_player->move_to_position(5);
			break;
		case 11:	
			cout << "Take a walk on the Boardwalk–Advance token to Boardwalk";
			active_player->move_to_position(39);
			break;
		case 12:	
			cout << "You have been elected Chairman of the Board–Pay $50";
			active_player->subtract_money(50);
			break;
		case 13:	
			cout << "Your building and loan matures--Collect $150";
			active_player->add_money(150);
			break;
		case 14:	
			cout << "You have won a crossword competition--Collect $100";
			active_player->add_money(100);
			break;
		case 15:
			cout << "Make general repairs on all your property–For each house pay $25";
			active_player->subtract_money(active_player->num_owned_buildings()*25);
			break;
	}
	cout << "\n";
}

string LuxuryTaxSpace::get_name()
{
	return "Luxury Tax";
}

void LuxuryTaxSpace::space_action(Player* active_player, int die_one, int die_two)
{
	cout << "You landed on Luxury Tax\n";
	int response = 0;

	cout << "Press enter to pay $75\n";

	cin.ignore(256,'\n');

	active_player->subtract_money(75);
}

string IncomeTaxSpace::get_name()
{
	return "Income Tax";
}

void IncomeTaxSpace::space_action(Player* active_player, int die_one, int die_two)
{
	cout << "You landed on Income Tax\n";
	int response = 0;

	cout << "Would you like to pay 200 or 10\% of your net worth?\n1: $200\n2: 10\% of net worth\n";

	while (true)
	{
		cin >> response;
		cin.ignore();
		if (response == 1)
		{
			active_player->subtract_money(200);
			break;
		}
		else if (response == 2)
		{
			active_player->subtract_money(active_player->get_balance()/10);
			break;
		}
		else
		{
			response = 0;
			cout << "could not recognize response. try again.\n";
		}
	}
}

string GoToJailSpace::get_name()
{
	return "Go To Jail";
}

void GoToJailSpace::space_action(Player* active_player, int die_one, int die_two)
{
	cout << "You landed on Go To Jail\nPress enter to go to jail";
	int response = 0;

	cin.ignore(256,'\n');

	active_player->move_to_position(10);
	active_player->set_jail_counter(3);
}