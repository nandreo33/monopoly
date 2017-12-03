#include <string>
#include <iostream>

#ifndef SPACE_H
#define SPACE_H

using namespace std;

class Player;

class Space 
{
protected:
	const string name;
public:
	virtual void space_action(Player* active_player,int die_one, int die_two) { cout << "ERROR: called space_action() on space\n";};
	virtual string get_name() { return name;};
	Space(string s) : name(s) {};
};

#endif