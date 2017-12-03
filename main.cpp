//
//  main.cpp
//  monopoly main
//
//  Created by Spencer Comora on 11/28/17.
//  Copyright © 2017 Spencer Comora. All rights reserved.
//

#include <iostream>
#include"ColorGroup.hpp"


using namespace std;

int roll_dice(){
    //int rollCount = 0;
  //  bool* doubles;
    int die1;
    int die2;
    srand(time(0));
    for(int i = 0; i < 1; i++){
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        cout <<"First Roll: "<< die1<< " Second Roll: "<< die2<<endl;
        if (die1 == die2)
        {
            *doubles = true;
            rollCount++;
            if (rollCount == 2){
                //player goes to jail
            }
            else roll_dice();
        }
    }
    cout<<endl;
    return die1+die2;
};


int main()
{
    
    //initializing players
    int numPlayers = 0;
    cout << "Enter number of players: ";
    cin >> numPlayers;
    player players[numPlayers];
    
    for (int i = 0; i < numPlayers; i++)
    {
        string name;
        cout << "Enter player " << (i + 1) << " name: ";
        cin >> name;
        players[i] = new player(name,1500,0,0,false);
    }
    
    //initializing ColorGroups
    ColorGroup colorgroups[10];
    colorgroups[0] = new ColorGroup(60, 50, 2, brown);
    colorgroups[1] = new ColorGroup(100, 50, 3, light_blue);
    colorgroups[2] = new ColorGroup(140, 100, 3, purple);
    colorgroups[3] = new ColorGroup(180, 100, 3, orange);
    colorgroups[4] = new ColorGroup(220, 150, 3, red);
    colorgroups[5] = new ColorGroup(260, 150, 3, yellow);
    colorgroups[6] = new ColorGroup(300, 200, 3, green);
    colorgroups[7] = new ColorGroup(350, 200, 2, blue);
    colorgroups[8] = new ColorGroup(200, 0, 4, railroad);
    colorgroups[9] = new ColorGroup(150, 0, 2, utility);
    
    //initializing gameboard
    Space gameboard[40];
    gameboard[0] = GoSpace;
    gameboard[1] = new Property(2, 60, true, "Mediterranean Ave", brown);
    gameboard[2] = new card;
    gameboard[3] = new Property(4, 60, true, "Baltic Ave", brown);
    gameboard[4] = //INCOME TAX;
    gameboard[5] = new Property(25, true, "Reading Railroad", railroad);
    gameboard[6] = new Property(6, 100, true, "Oriental Avenue", light_blue);
    gameboard[7] = new card; //chance??
    gameboard[8] = new Property(6, 100, true, "Vermont Avenue", light_blue);
    gameboard[9] = new Property(8, 120, true, "Connecticut Avenue", light_blue);
    gameboard[10] = //jail
    gameboard[11] = new Property(10, 140, true, "St. Charles Place", purple);
    gameboard[12] = new Property //utility, rent depends on dice
    gameboard[13] = new Property(10, 140, true, "States Avenue", purple);
    gameboard[14] = new Property(12, 160, true, "Virginia Avenue", purple);
    gameboard[15] = new Property(25, true, "Pennsylvania Railroad", railroad);
    gameboard[16] = new Property(14, 180, true, "St. James Place", orange);
    gameboard[17] = //community chest
    gameboard[18] = new Property(14, 180, true, "Tennessee Avenue", orange);
    gameboard[19] = new Property(16, 200, true, "New York Avenue", orange);
    gameboard[20] = //free parking
    gameboard[21] = new Property(18, 220, true, "Kentucky Avenue", red);
    gameboard[22] = //chance
    gameboard[23] = new Property(18, 220, true, "Indiana Avenue", red);
    gameboard[24] = new Property(20, 240, true, "Illinois Avenue", red);
    gameboard[25] = new Property(25, true, "B. & O. Railroad", railroad);
    gameboard[26] = new Property(22, 260, true, "Atlantic Avenue", yellow);
    gameboard[27] = new Property(22, 260, true, "Ventnor Avenue", yellow);
    gameboard[28] = //utility; depends on dice roll
    gameboard[29] = new Property(24, 280, true, "Marvin Gardens", yellow);
    gameboard[30] = //go to jail
    gameboard[31] = new Property(26, 300, true, "Pacific Avenue", green);
    gameboard[32] = new Property(26, 300, true, "North Carolina Avenue", green);
    gameboard[33] = //community chest
    gameboard[34] = new Property(28, 320, true, "Pennsylvania Avenue", green);
    gameboard[35] = new Property(25, true, "Short Line", railroad);
    gameboard[36] = //chance
    gameboard[37] = new Property(35, 350, true, "Park Place", blue);
    gameboard[38] = //luxury tax
    gameboard[39] = new Property(50, 400, true, "Boardwalk", blue);
    
    
    
    //playerPos + diceRoll
    
    
    //while each player's balance is greater than zero, keep the game going
    
    for (int i = 0; i < numPlayers; i++)
    {
        int option = 0;
        string propertyName;
        cout << "Player " << (i + 1) << " turn. " << endl;
        
        cout << "1. Roll dice" << endl;
        cout << "2. Build houses" << endl << endl;
        cout << "Enter an option: ";
        cin >> option;
        
        switch (option)
        {
            case 1: roll_dice();
                players[i].move_to_position(roll_dice() + players[i].position);
                
                
                
                break;
            case 2: cout << "Enter property name: ";
                cin >> propertyName;
                
        }
        
        
        
        
    }
    

    return 0;
}
