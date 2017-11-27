// adding player.cpp
#include <iostream>
#include "player.h"

//retrieves the name of the player
string player::getName(){
return name;
}
//retrieves the balance of the player
int player::get_balance(){
return balance;
}
//retrieves the current position of player
int player::getPosition(){
return position;
}
//retrieves the size of property
int player::getProperty_size(){
return property_size;
}
//add funds to player's balance
void player::add_money(int amount){
balance+=amount;
}
//subtract's money from player's balance
void player::subtract_money(int amount){
balance-=amount;
}
//moves the player around the board
void player::moves(int amount){
position+=amount;
if(position>=40){
  position = position%40;
}
}
//move's player to specific position
void player::move_to_position( int pos ){
position = pos;
}
//defines player
player::player(string s, int i, int n, int o, bool b){
name =s;
balance = i;
position = n;
property_size= o;
in_jail=b;
};
//decrements the property by size by 1
void player::remove_property( int index){
property_size-=1;
if(property_size<0)
    property_size=0;

}
int main(){
    string na;
    int bal;
     int pos;
     int prop;
      bool jail;
      int f;

player person1(na, bal, pos, prop, jail);
player person2(na, bal, pos, prop, jail);
player person3(na, bal, pos, prop, jail);
player person4(na, bal, pos, prop, jail);
player person5(na, bal, pos, prop, jail);
player person6(na, bal, pos, prop, jail);
player person7(na, bal, pos, prop, jail);
player person8(na, bal, pos, prop, jail);

return 0;}
