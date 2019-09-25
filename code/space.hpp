/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description:  This is the parent class for all of the continent child
 *      classes.  The class is an abstract class.  It holds the inforrmation
 *      about each country and functions that allow the user to receive 
 *      passport stamps, process visas, and the ability to buy a souvenir.
 ***************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

using std::string;

class Space
{
protected:
    string name;
    int continentType;
    string itemToBuy;
    int itemCost;
    int visaType;
    string description;
    bool flyable;
    int visaFee;
public:
    Space* north;
    Space* south;
    Space* east;
    Space* west;
/**************************************************************************
 * Constructor
 ************************************************************************/
    Space();

/**************************************************************************
 * Dscription: getters and setters
 *************************************************************************/
    string getItemToBuy();
    int getContinentType();
    int getItemCost();
    string getDescription();
    string getName();
    bool getFlyable();
    int getVisaType();
    void setVisaFee(int fee);
    int getVisaFee();

/**************************************************************************
 * Dscription: This function makes a string for the name of the country and 
 *      the name of the continent that the country is on. It returns the 
 *      string.
 *************************************************************************/
    virtual string displayNameAndContinent() = 0;

/**************************************************************************
 * Description: This function displays the abilit to fly out of this country
 *      to other countries.  It displays the prices to other countries if
 *      it is flyable.  It returns a bool for whether the country was
 *      flyable or not.
 *************************************************************************/
    virtual int displayFlyMenu(int& wallet) = 0;

/**************************************************************************
 * Description:  This function displays and processes visa entry requirements
 *      for this country.  It takes no arguments and returns an int to know
 *      what type of visa process occurred.  Type 1 means the traveller
 *      successfully entered.  2 means entered but needs to pay $100. 3 means
 *      the traveller needed to arrive with a visa and needs to try to bribe
 *      their way in.
 ***************************************************************************/
    int processVisa();
};

#endif
