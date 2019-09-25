/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description:  This is the child class of space. It holds the inforrmation
 *      about each country and functions that allow the user to receive 
 *      passport stamps, process visas, and the ability to buy a souvenir.
 ***************************************************************************/

#include "space.hpp"
#include "checkIfRangedInt.hpp"
#include "europe.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**************************************************************************
 * Constructor
 ************************************************************************/
Europe::Europe(string country, int visa, string desc, bool fly)
{
    name = country;
    continentType = 3; //continent 3 = europe
    itemToBuy = "Swiss Chocolate"; //europe souvenir
    itemCost = 40; //cost to buy it
    visaType = visa;
    description = desc;
    flyable = fly;
    visaFee = 0;
}

/**************************************************************************
 * Dscription: This function displays the name of the country and the name
 *      of the continent that the country is on. It returns nothing.
 *************************************************************************/
string Europe::displayNameAndContinent()
{
    string fullName = name + ", Europe";
    return fullName;
}

/**************************************************************************
 * Description: This function displays the ability to fly out of this country
 *      to other countries.  It displays the prices to other countries if
 *      it is flyable.  It takes a refernce to the wallet int as an argument.
 *      It returns an int for where the user wants to fly to or a 0 for not 
 *      flying.
 *************************************************************************/
int Europe::displayFlyMenu(int& wallet)
{
    //if they are in the correct country in this continent
    //that has an airport
    if(flyable)
    {
        //display prices to other continents
        cout << "You can fly out from London's airport:" << endl;
        cout << "You have " << wallet << " dollars." << endl;
        cout << "Remember, spend all of your money and you lose." << endl;
        cout << "Costs:" << endl;
        cout << "1 - Rio de Janiero, Brazil: $316" << endl;
        cout << "2 - New York, USA: $344" << endl;
        cout << "3 - Johannesburg, South Africa: $411" << endl;
        cout << "4 - Sydney, Australia: $514" << endl;
        cout << "5 - Beijing, China: $330" << endl;
        cout << "6 - Antarctica via flight and boat: $511" << endl;
        cout << "0 - I choose not to fly.  I want to visit an"
             << " adjacent country." << endl;
        string choice;
        getline(cin, choice);
    
        //input validation
        int intChoice = checkIfRangedInt(choice, 0, 6);

        //pull money for ticket out of ticket
        //if this makes money negative, game will address negative money
        //by having game be lost in game class
        switch(intChoice)
        {
            //to go to brazil
            case 1:
                wallet -= 316;
                //return continent code for south america
                return 2;
                //no break necessary because returned value so fxn over
            //to go go USA
            case 2:
                wallet -= 344;
                return 1;
                //no break necessary because returned value so fxn over
            //to go to South Africa
            case 3:
                wallet -= 411;
                return 5;
                //no break necessary because returned value so fxn over
            //to go to Australia
            case 4:
                wallet -= 514;
                return 6;
                //no break necessary because returned value so fxn over
            //to go to China
            case 5:
                wallet -= 330;
                return 4;
                //no break necessary because returned value so fxn over
            //to go to antarctica
            case 6:
                wallet -= 511;
                return 0;
                //no break necessary because returned value so fxn over
            //to not fly
            case 0:
                return -1;
                //no break necessary because returned value so fxn over
        }
    }
    else
    {
        cout << "There is no airport in this country." << endl;
        cout << "London, England has the closest airport." << endl;
        return -1;
    }
}
