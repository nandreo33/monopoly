#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main () {
   cout >> "'1' & '0' is equal to 'COMMUNITY' & 'CHANCE'. Input a boolean number.";
   cin << bool key;

   if (key) {
   cout >> "COMMUNITY: Pick a character value from 'A' through 'Q'.";
   cin << char value;

   switch(value) {
      case 'A' :
         cout << "Advance to Go & Collect $200." << endl;
         break;
      case 'B' :
         cout << "Bank error in your favor & Collect $200." << endl;
         break;
      case 'C' :
         cout << "Doctor's fees & Pay $50." << endl;
         break;
      case 'D' :
         cout << "From sale of stock you get $50." << endl;
         break;
      case 'E' :
         cout << "Get Out of Jail Free - This card may be kept until needed or sold." << endl;
         break;
      case 'F' :
         cout << "Go to Jail - Go directly to jail - Do not pass Go & Do not collect $200." << endl;
         break;
      case 'G' :
         cout << "Grand Opera Night - Collect $50 from every player for opening night seats." << endl;
         break;
      case 'H' :
         cout << "Holiday Fund matures - Receive $100." << endl;
         break;
      case 'I' :
         cout << "Income tax refund - Collect $20." << endl;
         break;
      case 'J' :
         cout << "It is your birthday - Collect $10 from each player." << endl;
         break;
      case 'K' :
         cout << "Life insurance matures - Collect $100." << endl;
         break;
      case 'L' :
         cout << "Pay hospital fees of $100." << endl;
         break;
      case 'M' :
         cout << "Pay school fees of $150." << endl;
         break;
      case 'N' :
         cout << "Receive $25 consultancy fee." << endl;
         break;
      case 'O' :
         cout << "You are assessed for street repairs - $40 per house - $115 per hotel." << endl;
         break;
      case 'P' :
         cout << "You have won second prize in a beauty contest - Collect $10." << endl;
         break;
      case 'Q' :
         cout << "You inherit $100." << endl;
         break;
        }
   }

   else {
       if (key) {
   cout >> "CHANCE: Pick a character value from 'A' through 'P'.";
   cin << char value;

   switch(value) {
      case 'A' :
         cout << "Advance to Go & Collect $200." << endl;
         break;
      case 'B' :
         cout << "Advance to Illinois Ave & If you pass Go, then collect $200." << endl;
         break;
      case 'C' :
         cout << "Advance to St. Charles Place & If you pass Go, then collect $200." << endl;
         break;
      case 'D' :
         cout << "Advance to nearest Utility & If unowned, then you may buy it from the Bank & If owned, then throw dice and pay owner a total ten times the amount thrown." << endl;
         break;
      case 'E' :
         cout << "Advance to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled. If Railroad is unowned, you may buy it from the Bank." << endl;
         break;
      case 'F' :
         cout << "Bank pays you dividend of $50." << endl;
         break;
      case 'G' :
         cout << "Get out of Jail Free - This card may be kept until needed, or traded/sold." << endl;
         break;
      case 'H' :
         cout << "Go Back 3 Spaces." << endl;
         break;
      case 'I' :
         cout << "Go to Jail - Go directly to Jail - Do not pass Go, do not collect $200." << endl;
         break;
      case 'J' :
         cout << "Make general repairs on all your property - For each house pay $25 - For each hotel $100." << endl;
         break;
      case 'K' :
         cout << "Pay poor tax of $15." << endl;
         break;
      case 'L' :
         cout << "Take a trip to Reading Railroad & If you pass Go, collect $200." << endl;
         break;
      case 'M' :
         cout << "Take a walk on the Boardwalk - Advance token to Boardwalk." << endl;
         break;
      case 'N' :
         cout << "You have been elected Chairman of the Board - Pay each player $50." << endl;
         break;
      case 'O' :
         cout << "Your building {and} loan matures - Collect $150." << endl;
         break;
      case 'P' :
         cout << "You have won a crossword competition - Collect $100." << endl;
         break;
            }
        }
   }
   return 0;
}
