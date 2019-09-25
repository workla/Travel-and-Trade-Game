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

#include "game.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "space.hpp"
#include "northAmerica.hpp"
#include "southAmerica.hpp"
#include "asia.hpp"
#include "europe.hpp"
#include "africa.hpp"
#include "oceania.hpp"
#include "antarctica.hpp"
#include "checkIfRangedInt.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/****************************************************************************
 * Constructor
 ***************************************************************************/
Game::Game()
{
    //make countries
    //set visa fees for countries with level 2 visas
    usa = new NorthAmerica("United States", 1, "Welcome home!", true);
    canada = new NorthAmerica("Canada", 1, 
        "Welcome to Canada, the land of maple syrup.", false);
    mexico = new NorthAmerica("Mexico", 1, 
        "Welcome to Mexico, the home of the Day of the Dead.", false);
    bahamas = new NorthAmerica("The Bahamas", 1, 
        "Welcome to the beautiful Bahama beaches.", false);
    costaRica = new NorthAmerica("Costa Rica", 1, 
        "Welcome to Costa Rica, the land of tropical rainforests.", false);
    venezuela = new SouthAmerica("Venezuela", 3, 
        "Welcome to Venezuela, rich in plant and wildlife diversity.", false);
    peru = new SouthAmerica("Peru", 2, 
        "Welcome to Peru, the home of Machu Picchu.", false);
    peru->setVisaFee(0);
    brazil = new SouthAmerica("Brazil", 3, 
        "Welcome to Brazil, home of Carnival.", true);
    chile = new SouthAmerica("Chile", 1, 
        "Welcome to Chile, home of Easter Island.", false);
    argentina = new SouthAmerica("Argentina", 1, 
        "Welcome to Argentina, home of the tango.", false);
    antarcticaCountry = new Antarctica("Antarctica", 1, 
        "Welcome to the South Pole, Antarctica.", true);
    england = new Europe("England", 1, 
        "Welcome to England. The queen is happy to have you.", true);
    denmark = new Europe("Denmark", 1, 
        "Welcome to Denmark, home of the Little Mermaid.", false);
    france = new Europe("France", 1, 
        "Welcome to France.  Enjoy some cheese and a baguette.", false);
    spain = new Europe("Spain", 1,
        "Welcome to Spain, the land of tapas and the flamenco.", false);
    germany = new Europe("Germany", 1, 
        "Welcome to Germany, home of Oktoberfest.", false);
    switzerland = new Europe("Switzerland", 1, 
        "Welcome to the magnificent Swiss Alps.", false);
    italy = new Europe("Italy", 1, 
        "Welcome to Italy. Have some pizza and pasta.", false);
    morocco = new Africa("Morocco", 1, 
        "Welcome to Morocco, home of exotic spices and the Sahara Desert.", 
        false);
    egypt = new Africa("Egypt", 2, 
        "Welcome to Egypt, home of the pyramids.", false);
    egypt->setVisaFee(25);
    nigeria = new Africa("Nigeria", 3, 
        "Welcome to Nigeria, the largest oil producer in Africa.", false);
    kenya = new Africa("Kenya", 2, 
        "Welcome to Kenya.  Take a safari to enjoy the natural habitat.", 
        false);
    kenya->setVisaFee(51);
    southAfrica = new Africa("South Africa", 1, 
        "Welcome to South Africa, home of Nelson Mandela.", true);
    russia = new Asia("Russia", 3, 
        "Welcome to Russia. Have a vodka.", false);
    india = new Asia("India", 3, 
        "Welcome to India, the home of the Taj Mahal.", false);
    mongolia = new Asia("Mongolia", 1, 
        "Welcome to Mongolia, home of Genghis Khan.", false);
    china = new Asia("China", 3, 
        "Welcome to China, home of the Great Wall.", true);
    cambodia = new Asia("Cambodia", 2, 
        "Welcome to Cambodia, home of Angkor Wat.", false);
    cambodia->setVisaFee(30);
    vietnam = new Asia("Vietnam", 3, 
        "Welcome to Vietnam, home of Halong Bay.", false);
    indonesia = new Asia("Indonesia", 2, 
        "Welcome to Indonesia. Enjoy our beaches and volcanoes.", false);
    indonesia->setVisaFee(35);
    australia = new Oceania("Australia", 3, 
        "Welcome to Australia, home of the Great Barrier Reef.", true);
    newZealand = new Oceania("New Zealand", 1, 
        "Welcome to New Zealand, home of far more sheep than people.", false);

    //set up pointers to each other to create linked space
    //nullptr in a direction means there is ocean
    usa->north = canada;
    usa->south = mexico;
    usa->east = bahamas;
    usa->west = nullptr;
    canada->north = nullptr;
    canada->south = usa;
    canada->east = nullptr;
    canada->west = nullptr;
    bahamas->north = nullptr;
    bahamas->south = costaRica;
    bahamas->east = nullptr;
    bahamas->west = usa;
    mexico->north = usa;
    mexico->south = nullptr;
    mexico->east = costaRica;
    mexico->west = nullptr;
    costaRica->north = bahamas;
    costaRica->south = venezuela;
    costaRica->east = nullptr;
    costaRica->west = mexico;
    venezuela->north = costaRica;
    venezuela->south = peru;
    venezuela->east = nullptr;
    venezuela->west = nullptr;
    peru->north = venezuela;
    peru->south = chile;
    peru->east = brazil;
    peru->west = nullptr;
    brazil->north = nullptr;
    brazil->south = argentina;
    brazil->east = nullptr;
    brazil->west = peru;
    argentina->north = brazil;
    argentina->south = nullptr;
    argentina->east = nullptr;
    argentina->west = chile;
    chile->north = peru;
    chile->south = nullptr;
    chile->east = argentina;
    chile->west = nullptr;
    antarcticaCountry->north = nullptr;
    antarcticaCountry->south = nullptr;
    antarcticaCountry->east = nullptr;
    antarcticaCountry->west = nullptr;
    england->north = nullptr;
    england->south = nullptr;
    england->east = france;
    england->west = nullptr;
    denmark->north = nullptr;
    denmark->south = france;
    denmark->east = germany;
    denmark->west = nullptr;
    france->north = denmark;
    france->south = spain;
    france->east = switzerland;
    france->west = england;
    spain->north = france;
    spain->south = morocco;
    spain->east = italy;
    spain->west = nullptr;
    germany->north = nullptr;
    germany->south = switzerland;
    germany->east = russia;
    germany->west = denmark;
    switzerland->north = germany;
    switzerland->south = italy;
    switzerland->east = india;
    switzerland->west = france;
    italy->north = switzerland;
    italy->south = egypt;
    italy->east = nullptr;
    italy->west = spain;
    morocco->north = spain;
    morocco->south = nigeria;
    morocco->east = egypt;
    morocco->west = nullptr;
    egypt->north = italy;
    egypt->south = kenya;
    egypt->east = nullptr;
    egypt->west = morocco;
    nigeria->north = morocco;
    nigeria->south = nullptr;
    nigeria->east = kenya;
    nigeria->west = nullptr;
    kenya->north = egypt;
    kenya->south = southAfrica;
    kenya->east = nullptr;
    kenya->west = nigeria;
    southAfrica->north = kenya;
    southAfrica->south = nullptr;
    southAfrica->east = nullptr;
    southAfrica->west = nullptr;
    russia->north = nullptr;
    russia->south = india;
    russia->east = mongolia;
    russia->west = germany;
    mongolia->north = nullptr;
    mongolia->south = china;
    mongolia->east = nullptr;
    mongolia->west = russia;
    india->north = russia;
    india->south = nullptr;
    india->east = china;
    india->west = switzerland;
    china->north = mongolia;
    china->south = cambodia;
    china->east = nullptr;
    china->west = india;
    cambodia->north = china;
    cambodia->south = vietnam;
    cambodia->east = nullptr;
    cambodia->west = nullptr;
    vietnam->north = cambodia;
    vietnam->south = indonesia;
    vietnam->east = nullptr;
    vietnam->west = nullptr;
    indonesia->north = vietnam;
    indonesia->south = australia;
    indonesia->east = nullptr;
    indonesia->west = nullptr;
    australia->north = indonesia;
    australia->south = nullptr;
    australia->east = newZealand;
    australia->west = nullptr;
    newZealand->north = nullptr;
    newZealand->south = nullptr;
    newZealand->east = nullptr;
    newZealand->west = australia;

    //connect airport pointers to correct spot in linked board
    usaAirport = usa; 
    brazilAirport = brazil;
    antarcticaAirport = antarcticaCountry;
    australiaAirport = australia; 
    chinaAirport = china; 
    englandAirport = england; 
    southAfricaAirport = southAfrica;

    //start user in us
    userLocation = usa;

    //fill passport with falses because no countries visited yet
    for(int i = 0; i < 7; i++)
    {
        passport[i] = false;
    }

    //set country count to zero because nothing visited yet
    numOfCountries = 0;

    //set initial money count
    wallet = 3500;

    //set day counter to zero to 1 to start first day
    dayCounter = 1;
}

/***************************************************************************
 * Description:  This function plays the game.  It takes no arguments and
 *      returns nothing.  It will play until the user runs out of steps or
 *      money.
 **************************************************************************/
void Game::playGame()
{
    //start by introducing game rules
    //set background story up
    cout << endl << endl;
    cout << "Well hello, excited traveller.  I hear you want to travel the "
         "world?" << endl;
    cout << "Well, it is your lucky day.  I am about to give you the trip of"
         " a lifetime..." << endl;
    cout << "but everything comes with a catch!" << endl << endl;
    cout << "I am giving you $" << wallet << " and " << MAX_DAYS << " days to ";
    cout << "complete your travelling adventure." << endl;
    cout << "You win this trip only if you spend my money wisely." << endl;
    cout << "To win, you must travel to all 7 continents within the ";
    cout << MAX_DAYS << " days." << endl;
    cout << "You earn bonus points for the total number of countries travelled"
         " to." << endl;
    cout << "The game is over when you run out of time or money." << endl;
    cout << "BUT, I have no time to waste, so you must start today," << endl;
    cout << "without any visa documents." << endl;
    cout << "So choose which countries you go to wisely, as each country you "
         << "enter that" << endl;
    cout << "requires a visa will kick you out." << endl << endl;
    cout << "I am not completely mean though.  I have given you enough" << endl;
    cout << "extra money and a backpack to pick up ";
    cout << "souvenirs along the way." << endl;
    cout << "Use the souvenirs to barter with visa agents for entry into"
         " their country." << endl;
    cout << "Choose your souvenirs wisely as you can only carry so much" << endl;
    cout << "and not all souvenirs are equally enticing." << endl << endl;
    cout << "Each day, you can either:" << endl;
    cout << " - spend the day travelling to an adjacent country" << endl;
    cout << " - pay to fly to a different continent" << endl;
    cout << "     (only 7 airports exist, one on each continent)" << endl;
    cout << " - spend a day shopping for souvenirs" << endl << endl;

    //give user the chance to read instructions, and ask if ready to play 
    //to move to displaying map
    cout << "Are you ready for your adventure?" << endl;
    cout << "Enter 1 to start or 2 to quit." << endl;
    string choice;
    getline(cin, choice);
    //input validation
    while(choice != "1" && choice != "2")
    {
        cout << "ERROR - invalid input - please only enter a 1 or 2" << endl;
        getline(cin, choice);
    }
    //if statement to quit if they got scared and don't want to play
    if(choice == "2")
    {
        cout << "Already scared....wow, you are not the traveller I thought"
             " you were." << endl;
        cout << "Please leave." << endl;
        return;
    }
    else
    {
        //starting in USA so north america checked off
        cout << "Ready are you?  Well, let me start you off with your" << endl;
        cout << "first passport stamp!  North America - check!" << endl;
        passport[1] = true;
    
        cout << endl;
        cout << "Now, let's take a look at the map:" << endl;
    }

    //start rounds until either out of time or money
    while(wallet > 0 && dayCounter <= MAX_DAYS)
    {
        //display map
        displayMap();

        //display day
        cout << "Day " << dayCounter << ":" << endl;

        //display current location
        cout << "You are currently in ";
        cout << userLocation->displayNameAndContinent();
        cout << "." << endl;
        
        //display your wallet
        cout << "You currently have " << wallet << " dollars left." << endl;
        
        //display number of things in backpack
        //change from plural to singular for 1 item
        if(backpack.size() == 1)
        {
            cout << "Your backpack currently has " << backpack.size();
            cout << " item in it." << endl;
        }
        else
        {
            cout << "Your backpack currently has " << backpack.size();
            cout << " items in it." << endl;
        }

        bool didDailyTask = false; //will keep track that they did something
        
        while(!didDailyTask)
        {
            //run menu of options what to do
            int menuChoice = menu();
            
            //process choices
            //if chose to move to adjacent space
            if(menuChoice == 1)
            {
                didDailyTask = moveToAdjacent();
            }
            else if(menuChoice == 2)
            {
                didDailyTask = fly();
            }
            else if(menuChoice == 3)
            {
                didDailyTask = buySomething();
            }
            else
            {
                //set diddailytask to true to pop out of while loop
                didDailyTask = true;

                cout << "Quitting already? Let's look at your stats:" << endl;
                
                //set day counter to max days + 1 to push out of while loop
                //and not do any more days.  This will move to final rundown
                dayCounter = MAX_DAYS + 1;
            }
        }
    }

    //now that days are over or money is gone, let's look at results
    cout << endl;
    cout << "===========" << endl;
    cout << "RESULTS" << endl;
    cout << "===========" << endl;
    cout << "You ended with " << wallet << " dollars." << endl;
    
    //display if ran out of money
    if(wallet <=0)
    {
        cout << "You ran out of money and were sent home." << endl;
    }

    //display if ran out of time
    if(dayCounter > MAX_DAYS)
    {
        cout << "You ran out of time." << endl;
    }

    //count if all seven continents visited
    int passportCounter = 0;
    for(int i = 0; i < 7; i++)
    {
        if(passport[i] == true)
        {
            passportCounter++;
        }
    }

    //display winning if passport counter shows all 7 continents visited
    if(passportCounter == 7)
    {
        cout << "Congrats! You visited all 7 countries!" << endl;
        cout << "You win!" << endl;
        cout << "Now let's look at bonus points for number of"
             " countries visited:" << endl;
        cout << " - " << numOfCountries << " countries" << endl;
    }
    //display losing stats if not all 7 continents visited
    else
    {
        cout << "Sorry, you didn't visit all 7 continents! You lose." << endl;
        cout << " Number of Continents visited: " << passportCounter << endl;
        cout << " Number of Countries visited: " << numOfCountries << endl;
    }

    return;
}

/****************************************************************************
 * Description:  This function displays the menu of choices the user has each
 *      day.  It takes no arguments and returns an integer for which menu
 *      option was chosen.
 ***************************************************************************/
int Game::menu()
{
    string choice;

    //display options for  the day and get input
    cout << endl;
    cout << "What would you like to do today?" << endl;
    cout << "1 - move to an adjacent location" << endl;
    cout << "2 - look at prices to fly to a different continent" << endl;
    cout << "3 - spend the day shopping for a souvenir" << endl;
    cout << "4 - Quit" << endl;
    getline(cin, choice);
    
    //input validation
    int intChoice = checkIfRangedInt(choice, 1, 4);
    
    //return choice
    return intChoice;
}

/***************************************************************************
 * Description: This function is used to buy something.  It takes no arguments
 *      and returns a bool that is true if something was bought and false if
 *      nothing was bought and therefore should move tback to doing something
 *      else for the day.
 ***************************************************************************/
bool Game::buySomething()
{
    //display where you are and what is for sale
    cout << endl << endl;
    cout << "You are in " << userLocation->displayNameAndContinent();
    cout << "." << endl;

    cout << "For Sale on this continent: " 
         << userLocation->getItemToBuy() << endl;
    cout << "Cost: " << userLocation->getItemCost() << " dollars" << endl;

    //ask if the user wants to buy
    cout << endl;
    cout << "Would you like to buy one?" << endl;
    cout << " Enter 1 for yes or 2 for no:" << endl;
    string choice;
    getline(cin, choice);

    //input validation
    while(choice != "1" && choice != "2")
    {
        cout << "ERROR - please only enter a 1 or 2:" << endl;
        getline(cin, choice);
    }

    //convert to int
    int intChoice = std::stoi(choice);
    
    //if choose to buy
    if(intChoice == 1)
    {
        //look to see if backpack is already full
        if(backpack.size() == MAX_BACKPACK)
        {
            cout << endl;
            cout << "Your backpack is already full. You cannot get any more."
                 << endl;
            //return false because didn;t buy anything
            return false;
        }
        else
        {
            //put item in bottom of backpack
            backpack.push(userLocation->getContinentType());
            cout << endl;
            cout << userLocation->getItemToBuy() << " is now in your backpack."
                 << endl;

            //take money out of wallet
            wallet -= userLocation->getItemCost();

            //it took a day to buy stuff
            dayCounter++;

            //return that they successfully bought something
            return true;
        }
    }
    else
    {
        //return that they chose not to buy anything
        return false;
    }
}

/****************************************************************************
 * Description: This function attempts to move the user to one of the
 *      adjacent spaces.  It will return true if they succesfully moved or if 
 *      they tried to move but got kicked back.  It returns false if they
 *      chose not to try to move. It takes no arguments.
 **************************************************************************/
bool Game::moveToAdjacent()
{
    //get countries around you
    string nor, sou, eas, wes;
    if(userLocation->north == nullptr)
    {
        nor = "Ocean - Cannot go here";
    }
    else
    {
        nor = userLocation->north->displayNameAndContinent();
    }

    if(userLocation->south == nullptr)
    {
        sou = "Ocean - Cannot go here";
    }
    else
    {
        sou = userLocation->south->displayNameAndContinent();
    }

    if(userLocation->east == nullptr)
    {
        eas = "Ocean - Cannot go here";
    }
    else
    {
        eas = userLocation->east->displayNameAndContinent();
    }

    if(userLocation->west == nullptr)
    {
        wes = "Ocean - Cannot go here";
    }
    else
    {
        wes = userLocation->west->displayNameAndContinent();
    }
    
    //ocean marker because cannot go in ocean
    bool inOcean = true;

    //while loop to stop from moving in the ocean
    while(inOcean)
    {
        //set marker to know that user picked to go to a country
        //display adjacent countries
        cout << endl << endl;
        cout << "Who is around you?" << endl;
        cout << "1 - North of you: " << nor << endl;
        cout << "2 - South of you: " << sou << endl;
        cout << "3 - East of you: " << eas << endl;
        cout << "4 - West of you: " << wes << endl;
        cout << "Enter an integer 1-4 for where you want to go" << endl;
        cout << "   or enter a 5 to not move to an adjacent space:" << endl;
        string choice;
        getline(cin, choice);

        //input validation
        int intChoice = checkIfRangedInt(choice, 1, 5);

        switch(intChoice)
        {
            case 1:
                //if else for ocean
                if(userLocation->north == nullptr)
                {
                    cout << endl;
                    cout << "You cannot go in the ocean.  Try again:" << endl;
                    inOcean = true;
                }
                else
                {
                    inOcean = false;
                    
                    //check visa of new place, and attempt to get through
                    //and move
                    attemptToVisa(userLocation->north);

                    //daycounter
                    dayCounter++;
                }
                break;
            case 2:
                //if else for ocean
                if(userLocation->south == nullptr)
                {
                    cout << endl;
                    cout << "You cannot go in the ocean.  Try again:" << endl;
                    inOcean = true;
                }
                else
                {
                    inOcean = false;

                    //check visa of new place, and attempt to get through
                    //and move
                    attemptToVisa(userLocation->south);

                    //daycounter
                    dayCounter++;
                }
                break;
            case 3:
                //if else for ocean
                if(userLocation->east == nullptr)
                {
                    cout << endl;
                    cout << "You cannot go in the ocean.  Try again:" << endl;
                    inOcean = true;
                }
                else
                {
                    inOcean = false;

                    //check visa of new place, and attempt to get through
                    //and move
                    attemptToVisa(userLocation->east);

                    //daycounter
                    dayCounter++;
                }
                break;
            case 4:
                //if else for ocean
                if(userLocation->west == nullptr)
                {
                    cout << endl;
                    cout << "You cannot go in the ocean.  Try again:" << endl;
                    inOcean = true;
                }
                else
                {
                    inOcean = false;

                    //check visa of new place, and attempt to get through
                    //and move
                    attemptToVisa(userLocation->west);

                    //daycounter
                    dayCounter++;
                }
                break;
            case 5:
                return false;
        }
    }

    return true;
}
/***************************************************************************
 * Description:  This function attempts to process a visa and move.  It takes
 *      a reference to the pointer to the new location as an argument and 
 *      returns nothing.
 ***************************************************************************/
void Game::attemptToVisa(Space*& attemptedDest)
{

    //get try for a visa
    int visaDone = attemptedDest->processVisa();
    
    if(visaDone == 1)
    {
        //if free to move, just move
        userLocation = attemptedDest;

        //put passport stamp in
        int stampSpot = attemptedDest->getContinentType();
        passport[stampSpot] = true;

        //add to country counter
        numOfCountries++;
    }
    else if(visaDone == 2)
    {
        //if type two visa, take money for visa and move
                        
        //process any visas fees
        wallet -= attemptedDest->getVisaFee();
    
        userLocation = attemptedDest;
        
        //put passport stamp in
        int stampSpot = attemptedDest->getContinentType();
        passport[stampSpot] = true;

        //add to country counter
        numOfCountries++;
    }
    else if(visaDone == 3)
    {
        //if need to barter to try to get in
        //run try to barter until backpack empty or successful
        bool successfulBarter = false;
        
        //message if backpack is empty
        if(backpack.size() == 0)
        {
            cout << endl;
            cout << "Your backpack is empty!  You came with nothing to trade.";
            cout << endl;
            cout << "You have been kicked out and lost a day of travel!" << endl;
            return;
        }

        while(!successfulBarter && (backpack.size() != 0))
        {
            successfulBarter = attemptToBarter();
        }
        if(successfulBarter)
        {
            //process a move because successfully bartered
            userLocation = attemptedDest;
        
            //put passport stamp in
            int stampSpot = attemptedDest->getContinentType();
            passport[stampSpot] = true;

            //add to country counter
            numOfCountries++;
        }
        else
        {
            //process failure of barter
            cout << endl;
            cout << "You have failed to barter with the visa official" << endl;
            cout << "and now your backpack is empty." << endl;
            cout << "You are getting kicked out of this country and" << endl;
            cout << "being sent back to your last country." << endl;
            cout << "This whole process also cost you a day of travel." << endl;
        }
    }
}

/****************************************************************************
 * Description: This function attempt to barter with a visa official for
 *      entry into the country.  Because you are panicked, you quickly grab
 *      whatever is on the top of the backpack first and work your way down.
 *      The function takes no arguments and returns a bool of true if
 *      successful or false if not.
 ***************************************************************************/
bool Game::attemptToBarter()
{
    //access top item to know what you have to work with
    int item = backpack.top();

    //get a random number between 0 and 100
    //to compare to percent likelihood of a successful barter
    int randomChance = (rand() % 101);
    switch (item)
    {
        case 1:
            //display north america item
            cout << "You pulled out a Maple Syrup bottle." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on north america percent chance
            if(randomChance <= 70)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. Your bottle broke!" << endl;
                cout << "The broken bottle failed to impress the visa" << endl;
                cout << "official.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 2:
            //display south america item
            cout << "You pulled out alpaca wool." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on south america percent chance
            if(randomChance <= 50)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. Your wool had bugs!" << endl;
                cout << "The bug-filled wool failed to impress a visa" << endl;
                cout << "official.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 3:
            //display europe item
            cout << "You pulled out Swiss Chocolate." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on europe percent chance
            if(randomChance <= 60)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. The swiss chocolate melted.  It failed" << endl;
                cout << " to impress the visa official.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 4:
            //display asia item
            cout << "You pulled out a silk scarf." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on asia percent chance
            if(randomChance <= 80)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. Your silk scarf ripped.  It failed" << endl;
                cout << " to impress the visa official.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 5:
            //display africa item
            cout << "You pulled out Tanzanite." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on africa percent chance
            if(randomChance <= 90)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. Your tanzanite was fake." << endl;
                cout << "It failed to impress the visa official." << endl;
                cout << "Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 6:
            //display australia item
            cout << "You pulled out Vegemite." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on australia percent chance
            if(randomChance <= 10)
            {
                //display accepted message
                cout << "Congrats! The item impressed a visa official" << endl;
                cout << "and you get to enter the country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Vegemite! The visa officials hates vegemite" << endl;
                cout << "They refuses to let you in.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
        case 0:
            //display antarctica item
            cout << "You pulled out ice from Antarctica." << endl;

            //remove item from bag
            backpack.pop();

            //calc based on antarctica percent chance
            if(randomChance <= 95)
            {
                //display accepted message
                cout << "Congrats! Your item was so rare it impressed" << endl;
                cout << "the officials and you get to enter the" << endl;
                cout << "country!" << endl;
                //return true because successful
                return true;
            }
            else
            {
                //display failed message
                cout << "Uh Oh. The ice melted! The melted ice failed" << endl;
                cout << " to impress the visa official.  Try again." << endl;
                //return false because haven't been able to enter country
                return false;
            }
    }
}

/***************************************************************************
 * Description: This function displays the fly options and attempts to fly to
 *      another continent.  It takes no arguments and returns true if they
 *      flew and successfully moved and false if they didn't buy a ticket.
 **************************************************************************/
bool Game::fly()
{
    cout << endl;

    //run dervied class fly functions
    int flyResponse = userLocation->displayFlyMenu(wallet);

    cout << endl;

    //if user chose not to fly
    if(flyResponse == -1)
    {
        return false;
    }

    //otherwise handle that they are flying somewhere
    //each integer represents the continent code they are trying to fly to
    switch(flyResponse)
    {
        case 0:
            attemptToVisa(antarcticaAirport);
            break;
        case 1:
            attemptToVisa(usaAirport);
            break;
        case 2:
            attemptToVisa(brazilAirport);
            break;
        case 3:
            attemptToVisa(englandAirport);
            break;
        case 4:
            attemptToVisa(chinaAirport);
            break;
        case 5:
            attemptToVisa(southAfricaAirport);
            break;
        case 6:
            attemptToVisa(australiaAirport);
            break;
    }

    //return true because day was spent either getting to new place or
    //getting there and then getting kicked back
    return true;
}

/****************************************************************************
 * Description:  This function outputs to the console a "map".  It takes no
 *      arguments and returns nothing.  It simply provides a schematic so that
 *      it is easier for the user to visualize where they are.
 ***************************************************************************/
void Game::displayMap()
{
    //output to console and schematic of the three structures with linked data
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       |       |       |Denmark|Germany|Russia |Mongol.|       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|Canada |       |England|France |Switz. | India | China |       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|  USA  |Bahamas|       | Spain | Italy |       |Cambod.|       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|Mexico |C. Rica|       |Morocco| Egypt |       |Vietnam|       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       |Venez. |       |Nigeria| Kenya |       |Indon. |       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       | Peru  |Brazil |       |S. Afr.|       |Austrl.|N. Zea.|"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       | Chile |Argen. |       |       |       |       |       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       |       |       |       |       |       |       |       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl;
    cout << "|       |       |Antarc.|       |       |       |       |       |"
         << endl;
    cout << "-----------------------------------------------------------------"
         <<endl << endl;
}

/******************************************************************************
 * Destructor
 *****************************************************************************/
Game::~Game()
{
    //delete all dynamically allocated countries
    delete usa;
    delete canada;
    delete mexico;
    delete bahamas;
    delete costaRica;
    delete venezuela;
    delete peru;
    delete brazil;
    delete chile;
    delete argentina;
    delete antarcticaCountry;
    delete england;
    delete denmark;
    delete france;
    delete spain;
    delete germany;
    delete switzerland;
    delete italy;
    delete morocco;
    delete egypt;
    delete nigeria;
    delete kenya;
    delete southAfrica;
    delete russia;
    delete india;
    delete mongolia;
    delete china;
    delete cambodia;
    delete vietnam;
    delete indonesia;
    delete australia;
    delete newZealand;
}
