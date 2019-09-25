/***************************************************************
 * Author: Lauren Work
 * Date: 9 May 2019
 * Description:  This function takes a string and checks if it is an int.  
 *      If it is not, it will prompt the user to enter an int and continue 
 *      this loop until an int is entered.  The function also checks if 
 *      the entry is within the range given as two int arguments.  The 
 *      function then returns the int.
 ****************************************************************/
#ifndef CHECKIFRANGEDINT_HPP
#define CHECKIFRANGEDINT_HPP

#include <string>

using std::string;

/*****************************************************************
 * Description:  This function takes a string and checks if it is an int.  
 *      If it is not, it will prompt the user to enter an int and continue 
 *      this loop until an int is entered.  The function also checks if 
 *      the entry is within the range given as two int arguments.  The 
 *      function then returns the int.
 ****************************************************************/
int checkIfRangedInt(string stringToCheck, int lowestInt, int highestInt);

#endif
