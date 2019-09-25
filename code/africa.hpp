/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description:  This is the child class of space. It holds the inforrmation
 *      about each country and functions that allow the user to receive 
 *      passport stamps, process visas, and the ability to buy a souvenir.
 ***************************************************************************/
#ifndef AFRICA_HPP
#define AFRICA_HPP

#include "space.hpp"
#include "checkIfRangedInt.hpp"
#include <string>

using std::string;

class Africa: public Space
{
private:
public:
/**************************************************************************
 * Constructor
 ************************************************************************/
    Africa(string country, int visa, string desc, bool fly);

/**************************************************************************
 * Dscription: This function makes a string of the name of the country and 
 *      the name of the continent that the country is on. It returns the 
 *      string.
 *************************************************************************/
    virtual string displayNameAndContinent();

/**************************************************************************
 * Description: This function displays the ability to fly out of this country
 *      to other countries.  It displays the prices to other countries if
 *      it is flyable.  It takes a refernce to the wallet int as an argument.
 *      It returns an int for where the user wants to fly to or a 0 for not 
 *      flying.
 *************************************************************************/
    virtual int displayFlyMenu(int& wallet);
};

#endif
