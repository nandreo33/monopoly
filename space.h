/*
 * space header file protects string name, and creates changeable do_action method
 *
 */

#include <string>
#include <iostream>

using namespace std;

class Space 
{
protected:
	const string name;
public:
	virtual void do_action(Player* active_player) { cout << "ERROR: called do_action() on space";};
	const string get_name() const { return name;};
};
