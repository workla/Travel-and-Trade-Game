/***************************************************************
 * Author: Lauren Work
 * Date: 9 May 2019
 * Description:  This function takes a string and checks if it is an int.
 *      If it is not, it will prompt the user to enter an int and continue 
 *      this loop until an int is entered.  The function also checks if 
 *      the entry is within the range given as two int arguments.  The 
 *      function then returns the int.
 ****************************************************************/
//adapted from improvements on my previous homework submissions

#include "checkIfRangedInt.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/*****************************************************************
 * Description:  This function takes a string and checks if it is an int.
 *      If it is not, it will prompt the user to enter an int and continue 
 *      this loop until an int is entered.  The function also checks if 
 *      the entry is within the range given as two int arguments.  The 
 *      function then returns the int.
 ****************************************************************/
int checkIfRangedInt(string stringToCheck, int lowestInt, int highestInt)
{
    bool notDesiredInputFlag; //turns true if not digit or not in range
    int convertedString = 0; //will be result after string converted to int
    int stringSize = stringToCheck.size(); 
    //test for digit adapted from 
    //https://www.quora.com/How-do-I-write-a-simple-code-to-validate-numeric-inputs-in-C++
    do
    {
        //set flag to 0 so that if relooping we start over with a fresh 0 for flag
        notDesiredInputFlag = false;
        int negativeCount = 0;

        //to loop through whole string
        for(int i=0; i<stringSize; i++)
        {
            //if statement that happens if a nondigit is encountered
            if(!isdigit(stringToCheck[i]) && stringToCheck[i] != '-')
            {
                //change flag to force retesting of input
                notDesiredInputFlag = true;
            }
            else if(stringToCheck[i] == '-')
            {
                negativeCount++;
            }
        }
        
        //check if negative sign is in wrong place
        if(negativeCount == 1 && stringToCheck[0] != '-')
        {
            notDesiredInputFlag = true;
        }

        //check if too many '-', only allowed 0-1
        if(negativeCount > 1)
        {
            //if multiple negative signs in string, then not an int
            notDesiredInputFlag = true;
        }
        
        //if string is empty, turn on flag
        if(stringSize == 0)
        {
            notDesiredInputFlag = true;
        }
        
        //check to see if string number is larger than what can get held in int
        //adapted from
        //https://stackoverflow.com/questions/18534036/checking-the-int-limits-in-stoi-function-in-c
        if(!notDesiredInputFlag)
        {
            //trying to convert
            //if not successful because int doesn't fit, then flag
            try
            {
                convertedString = stoi(stringToCheck);
            }
            catch(std::invalid_argument& e)
            {
                notDesiredInputFlag = true;
            }
            catch(std::out_of_range& e)
            {
                notDesiredInputFlag = true;
            }
        }

        //if the entry is an integer from above, 
        //check if the entry is within the provided range.
        //This paragraph can be removed for reuse if you just want to 
        //check for all unsigned ints with no range beyond that.
        if(!notDesiredInputFlag)
        {
            if((convertedString < lowestInt) || (convertedString > highestInt))
            {
                notDesiredInputFlag = true;
            }
        }

        //if the string wasn't desired input, prompt user for a new entry
        if(notDesiredInputFlag)
        {
            cout << "Invalid Entry.  Please enter an integer only and" 
                << " that integer must fall between " << lowestInt << " and "
                << highestInt << ":" << endl;
            getline(cin, stringToCheck);
            stringSize = stringToCheck.size();
        }
    }while(notDesiredInputFlag);//will reloop to check new entry if last entry was nondigit
    
    //return int covnersion from string
    return convertedString;
}
