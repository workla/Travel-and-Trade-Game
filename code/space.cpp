/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description:  This is the parent class for all of the continent child
 *      classes.  The class is an abstract class.  It holds the inforrmation
 *      about each country and functions that allow the user to receive 
 *      passport stamps, process visas, and the ability to buy a souvenir.
 ***************************************************************************/

#include "space.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**************************************************************************
 * Constructor
 ************************************************************************/
Space::Space()
{
}

/**************************************************************************
 * Dscription: getters and setters
 *************************************************************************/
string Space::getItemToBuy()
{
    return itemToBuy;
}
int Space::getContinentType()
{
    return continentType;
}
int Space::getItemCost()
{
    return itemCost;
}
string Space::getDescription()
{
    return description;
}
string Space::getName()
{
    return name; 
}
bool Space::getFlyable()
{
    return flyable;
}
int Space::getVisaType()
{
    return visaType;
}
void Space::setVisaFee(int fee)
{
    visaFee = fee;
}
int Space::getVisaFee()
{
    return visaFee;
}

/**************************************************************************
 * Description:  This function displays and processes visa entry requirements
 *      for this country.  It takes no arguments and returns an int to know
 *      what type of visa process occurred.  Type 1 means the traveller
 *      successfully entered.  2 means entered but needs to pay $100. 3 means
 *      the traveller needed to arrive with a visa and needs to try to bribe
 *      their way in.
 ***************************************************************************/
int Space::processVisa()
{
    cout << endl;
    cout << description << endl;
    if(visaType == 1)
    {
        cout << "Congrats!  There is no visa required.  You may enter." << endl;
        return 1;
    }
    else if(visaType == 2)
    {
        cout << "Good news!" << endl;
        cout << "A visa is required but can be purchased here"
             << " at your destination." << endl;
        cout << "The visa costs " << visaFee << " dollars." << endl;
        return 2;
    }
    else if(visaType == 3)
    {
        cout << "Uh oh! Poor planning has led to you entering a country" << endl;
        cout << " that requires a visa be processed before arriving." << endl;
        cout << "Please try bartering with the passport processor." << endl;
        cout << endl;
        cout << "Quick! Look in your backpack for what you can trade"
             << " for entry!" << endl;
        return 3;
    }
}
