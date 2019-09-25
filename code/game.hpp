/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description: The game function runs the map game.  It holds the backpack
 *      stack for the user to hold their souvenirs.  It holds the 3 linked
 *      lists that cover all seven continents.  The seven pointers to the 3
 *      linked lists represent the seven places a player can fly to.  A 
 *      pointer to the current location of the user is also there.  It will
 *      have a passport array of bools to keep track of continents visited.
 *      It will have a stamp counter to keep track of number of countries
 *      visited.  It will keep track of steps taken and money spent from
 *      a wallet.
 ***************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <stack>
#include "space.hpp"

using std::string;

class Game
{
private:
    std::stack<int> backpack; //holds souvenirs with type saved as diff ints
    bool passport[7]; //holds true if continent visited and false if not
    int numOfCountries; //counts number of countries visited
    int wallet; //holds money user has
    int dayCounter; //holds number of days passed
    const int MAX_DAYS = 20; //game ends after 30 days
    const int MAX_BACKPACK = 5; //holds max number of items backpack can hold
    Space* usaAirport; //pointer to node in nor and sou amer linked list
    Space* brazilAirport; //pointer to node in nor and sou amer linked list
    Space* antarcticaAirport; //pointer to node in antarctice linked list
    Space* australiaAirport; //pointer to asia/euro/africa oceania linked list
    Space* chinaAirport; //pointer to asia/euro/africa/ocenia linked list
    Space* englandAirport; //pointer to asia/euro/africa/oceania linked list
    Space* southAfricaAirport; //pointer to asia/euro/africa/oceania linked list
    Space* userLocation; //pointer to where user is on lists
    Space* usa, *canada, *mexico, *bahamas, *costaRica;//all the countries
    Space* venezuela, *peru, *brazil, *chile, *argentina;
    Space* antarcticaCountry;
    Space* england, *denmark, *france, *spain, *germany, *switzerland, *italy;
    Space* morocco, *egypt, *nigeria, *kenya, *southAfrica;
    Space* russia, *india, *mongolia, *china, *cambodia, *vietnam, *indonesia;
    Space* australia, *newZealand;

public:
/****************************************************************************
 * Constructor
 ***************************************************************************/
    Game();

/***************************************************************************
 * Description:  This function plays the game.  It takes no arguments and
 *      returns nothing.  It will play until the user runs out of steps or
 *      money.
 **************************************************************************/
    void playGame();

/****************************************************************************
 * Description:  This function displays the menu of choices the user has each
 *      day.  It takes no arguments and returns an integer for which menu
 *      option was chosen.
 ***************************************************************************/
    int menu();

/***************************************************************************
 * Description: This function is used to buy something.  It takes no arguments
 *      and returns a bool that is true if something was bought and false if
 *      nothing was bought and therefore should move tback to doing something
 *      else for the day.
 ***************************************************************************/
    bool buySomething();

/****************************************************************************
 * Description: This function attempts to move the user to one of the
 *      adjacent spaces.  It will return true if they succesfully moved or if 
 *      they tried to move but got kicked back.  It returns false if they
 *      chose not to try to move. It takes no arguments.
 **************************************************************************/
    bool moveToAdjacent();

/***************************************************************************
 * Description:  This function attempts to process a visa and move.  It takes
 *      a reference to the pointer to the new location as an argument and 
 *      returns nothing.
 ***************************************************************************/
    void attemptToVisa(Space*& attemptedDest);

/****************************************************************************
 * Description: This function attempt to barter with a visa official for
 *      entry into the country.  Because you are panicked, you quickly grab
 *      whatever is on the top of the backpack first and work your way down.
 *      The function takes no arguments and returns a bool of true if
 *      successful or false if not.
 ***************************************************************************/
    bool attemptToBarter();

/***************************************************************************
 * Description: This function displays the fly options and attempts to fly to
 *      another continent.  It takes no arguments and returns true if they
 *      flew and successfully moved and false if they didn't buy a ticket.
 **************************************************************************/
    bool fly();

/****************************************************************************
 * Description:  This function outputs to the console a "map".  It takes no
 *      arguments and returns nothing.  It simply provides a schematic so that
 *      it is easier for the user to visualize where they are.
 ***************************************************************************/
    void displayMap();

/***************************************************************************
 * Destructor
 **************************************************************************/
    ~Game();
};

#endif
