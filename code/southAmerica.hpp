/****************************************************************************
 * Author: Lauren Work
 * Date: 5 June 2019
 * Description:  This is the child class of space. It holds the inforrmation
 *      about each country and functions that allow the user to receive 
 *      passport stamps, process visas, and the ability to buy a souvenir.
 ***************************************************************************/
#ifndef SOUTHAMERICA_HPP
#define SOUTHAMERICA_HPP

#include "space.hpp"
#include <string>

using std::string;

class SouthAmerica: public Space
{
private:
public:
/**************************************************************************
 * Constructor
 ************************************************************************/
    SouthAmerica(string country, int visa, string desc, bool fly);

/**************************************************************************
 * Dscription: This function makes the name of the country and the name
 *      of the continent that the country is on into and string and returns it.
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
