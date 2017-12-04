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
	virtual void space_action(Player* active_player,int die_one, int die_two) { cout << "You landed on " << get_name() << "\n";};
	virtual string get_name() { return name;};
	Space(string s) : name(s) {};
};

#endif