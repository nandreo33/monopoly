#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "player.cpp"
#include "property.cpp"
#include "specialspace.cpp"

using namespace std;

int roll_d6()
{
	return rand()%6 + 1;	
}

int main()
{
	Space* gameboard[39];
	vector<Player*> players;

	int die_one;
	int die_two;

	Player* active_player;

	int board_size;

	// create colors
	// ColorGroup(int building_cost, int num_properties, color_t color)

	ColorGroup Brown(50,2,brown);
	ColorGroup LightBlue(50,3,light_blue);
	ColorGroup Purple(100,3,purple);
	ColorGroup Orange(100,3,orange);
	ColorGroup Red(150,3,red);
	ColorGroup Yellow(150,3,yellow);
	ColorGroup Green(200,3,green);
	ColorGroup Blue(200,2,blue);
	ColorGroup Utility(0,2,utility);
	ColorGroup Railroad(0,4,railroad);

	// create Properties (in board)
	// Property(int purhcase_cost, int base_rent, bool is_buildable, string name, ColorGroup color);

	gameboard[0] = new Space("Go");
    gameboard[1] = new Property(60, 2, true, "Mediterranean Ave", Brown);
    gameboard[2] = new CardSpace("Community Chest");
    gameboard[3] = new Property(60, 4, true, "Baltic Ave", Brown);
    gameboard[4] = new IncomeTaxSpace();
    gameboard[5] = new Property(200, 0, false, "Reading Railroad", Railroad);
    gameboard[6] = new Property(100, 6, true, "Oriental Avenue", LightBlue);
    gameboard[7] = new CardSpace("Chance");
    gameboard[8] = new Property(100, 6, true, "Vermont Avenue", LightBlue);
    gameboard[9] = new Property(120, 8, true, "Connecticut Avenue", LightBlue);
    gameboard[10] = new Space("Jail");
    gameboard[11] = new Property(140, 10, true, "St. Charles Place", Purple);
    gameboard[12] = new Property(150, 0, false, "Electric Company", Utility);
    gameboard[13] = new Property(140, 10, true, "States Avenue", Purple);
    gameboard[14] = new Property(160, 12, true, "Virginia Avenue", Purple);
    gameboard[15] = new Property(200, 0, false, "Pennsylvania Railroad", Railroad);
    gameboard[16] = new Property(180, 14, true, "St. James Place", Orange);
    gameboard[17] = new CardSpace("Community Chest");
    gameboard[18] = new Property(180, 14, true, "Tennessee Avenue", Orange);
    gameboard[19] = new Property(200, 16, true, "New York Avenue", Orange);
    gameboard[20] = new Space("Free Parking");
    gameboard[21] = new Property(220, 18, true, "Kentucky Avenue", Red);
    gameboard[22] = new CardSpace("Chance");
    gameboard[23] = new Property(220, 18, true, "Indiana Avenue", Red);
    gameboard[24] = new Property(240, 20, true, "Illinois Avenue", Red);
    gameboard[25] = new Property(200, 25, false, "B. & O. Railroad", Railroad);
    gameboard[26] = new Property(260, 22, true, "Atlantic Avenue", Yellow);
    gameboard[27] = new Property(260, 22, true, "Ventnor Avenue", Yellow);
    gameboard[28] = new Property(150, 0, false, "Water Works", Utility);
    gameboard[29] = new Property(280, 24, true, "Marvin Gardens", Yellow);
    gameboard[30] = new GoToJailSpace();
    gameboard[31] = new Property(300, 26, true, "Pacific Avenue", Green);
    gameboard[32] = new Property(300, 26, true, "North Carolina Avenue", Green);
    gameboard[33] = new CardSpace("Community Chest");
    gameboard[34] = new Property(320, 28, true, "Pennsylvania Avenue", Green);
    gameboard[35] = new Property(200, 0, false, "Short Line", Railroad);
    gameboard[36] = new CardSpace("Chance");
    gameboard[37] = new Property(350, 35, true, "Park Place", Blue);
    gameboard[38] = new LuxuryTaxSpace();
    gameboard[39] = new Property(400, 50, true, "Boardwalk", Blue);

	// create players
	// Player(string name)
	//#####################
	// empty name?
	//#####################

    // filter input
    int num_players;
    cout << "How many players?\n";
    cin >> num_players;

    for (int i = 1; i < num_players+1; i++)
    {
    	string name;
    	cout << "Enter Player " << i << "'s name: ";
    	cin >> name;
    	players.push_back(new Player(name));
    }

    cin.ignore(256,'\n');

	// intialize things?
	board_size = 40;
	active_player = players[0];

	int players_index = 0;

	srand(time(0));

	while(true){

		cout << "\n" << active_player->get_name() << "'s turn --------------------------------\n";
		cout << "You are on " << gameboard[active_player->get_position()]->get_name() << " with $" << active_player->get_balance() << "\n";
		cout << "Press enter to roll\n";

		cin.ignore(256,'\n');

		die_one = roll_d6();
		die_two = roll_d6();

		active_player->move(die_one+die_two,board_size);

		gameboard[active_player->get_position()]->space_action(active_player,die_one,die_two);

		int response;

		while (true)
		{
			cout << "\nNext action?:\n1: Build\n2: Trade\n3: Mortgage\n4: Print my status\n5: Pass turn\n";
			cin >> response;
			if (response == 1)
			{
				
			}
			else if (response == 2)
			{
				
			}
			else if (response == 3)
			{
				// implement this
			}
			else if (response == 4)
			{
				cout << "\n" << active_player->get_name();
				cout << ":\nYou are on " << gameboard[active_player->get_position()]->get_name() << " with $" << active_player->get_balance() << "\n";
				cout << "Owned Propeties:\tmortgaged?\tbuildings?\n";
				active_player->print_properties();
			}
			else if (response == 5)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "could not recognize response. try again.";
			}
		}

		cin.clear();
		cin.ignore(256,'\n');

		// increment players

		players_index++;
		if (players_index >= players.size())
		{
			players_index = 0;
		}
		active_player = players[players_index];
	}
}