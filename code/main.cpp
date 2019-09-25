/******************************************************************************
 * Author: Lauren Work
 * Date: 10 June 2019
 * Description: This is the main program for the traveller game.  This program
 *      allows a user to travel the world and collect passport stamps from
 *      each continent.  The user will collect souvenirs, barter with visa
 *      agents, and spend money to fly or move around the world.
 ***************************************************************************/

#include "game.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    //seed srand
    int seed = time(0);
    srand(seed);

    //make game
    Game travelGame;

    //run game
    travelGame.playGame();

    return 0;
}

