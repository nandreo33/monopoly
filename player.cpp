// adding player.cpp
/*
defines different action methods for dealing with player
*/

#include <iostream>
#include "monopoly.h"

//retrieves the name of the player
string player::get_name(){
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
player::player( string s, int i, int n, int b){
name =s;
balance = i;
position = n;
in_jail=b;
};

void player::add_property(Property* property){
owned_properties.push_back(property);
}

//removes property from vector of owned properties
void player::remove_property(Property* property){
    Property* temp;
for(unsigned int i=0; i<owned_properties.size();i++){
    if(owned_properties[i]==property){
        temp = owned_properties[i];
        owned_properties[i] = owned_properties[owned_properties.size()-1];
        owned_properties[owned_properties.size()-1]= temp;
        owned_properties.pop_back();
    }
    else if(owned_properties[i]==property){
        owned_properties.pop_back();
     }
  }
}

//prints list of properties
void player::print_properties(){
     for(unsigned int i=0; i<owned_properties.size();i++){
        if(i!=owned_properties.size())
            cout<<owned_properties[i]<<" ";
        else  cout<<i+1<<": "<<owned_properties[i]<<endl;
     }
}

//retrieves number of railroad player owns
int player::num_owned_railroads(){
    int n =0;
  for(unsigned int i=0; i<owned_properties.size();i++){
//        if(owned_properties[i].get_color().get_color_type==railroad)
            n+=1;
        return n;}
}

//retrieves number of utilities player owns
int player::num_owned_utilities(){
    int n =0;
    for(unsigned int i=0; i<owned_properties.size();i++){
      // if(owned_properties[i].get_color().get_color_type==utilities)
            n+=1;
        return n;
    }
}

//choose property to be traded
void player::choose_property( unsigned int num, player n1, player n2){
 if(num >=0 && num<= owned_properties.size()-1&& num_buildings==0){
        trade_properties.push_back(owned_properties[num-1]);
        n1.remove_property(owned_properties[num-1]);
        n2.add_property(trade_properties[0]);
        trade_properties.pop_back();
        }
  }

//exchanges amount to be traded among players
void player::trade_money(int amount, player n1, player n2){
    if(amount<0){
        amount*=-1;
        n1.subtract_money(amount);
        n2.add_money(amount);
    }
    else if(amount>0)
        {
        n1.add_money(amount);
        n2.subtract_money(amount);
    }
    else
        cout<<"no money exchanged! "<<endl;
}



return 0;}
