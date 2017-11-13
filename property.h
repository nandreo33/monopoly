#include <string>
#include <iostream>

class Property : public Space
{
private:
  int base_rent;
  int num_buildings:
  bool is_buildable;
  bool mortgaged;
  Player* owner; // this will be an error? include Player at compile time?
  Color color; // how does this work
public:
  void build();
  void do_action();
  int get_rent();
  int get_num_buildings();
  void add_building();
  Color get_color(); //enum color where?
  bool buildable();
  Player* get_owner(); // again, where do I include Player?
  void set_owner(Player* player);
  bool mortgage();
}
