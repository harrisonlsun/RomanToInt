/*
 * Harrison Sun (sun.har@northeastern.edu & hlsun@mit.edu)
 *
 * Files: "main.cpp" "RomanToInt.cpp" "RomanToInt.h"
 * This file defines the class RomanToInt, which converts Roman numerals to integers.
 */

#include "RomanToInt.h"


 /*
  * RomanToInt::RomanToInt(std::string input)
  *
  * This is the constructor for the class RomanToInt. It takes a string as input and stores it in the private variable roman. If the roman is valid, it converts it to an integer and prints it.
  *
  * @param std::string input: This is the input string from the function call.
  *
  * @return N/A
  */

RomanToInt::RomanToInt(std::string input)
{
    // set the roman to the input
    roman = input;
    // print the roman
    std::cout << "The input is: " << roman << std::endl;
    // check the roman
    // if the check is not 0, the roman is invalid
    if (Check() == 0)
    {
        // convert the roman
        convert();
        // print the output
        print();
    }
}

/*
 * int RomanToInt::convert()
 *
 * This function converts the roman numeral to an integer. It returns the integer.
 *
 * @param N/A
 *
 * @return int: The integer that the roman numeral represents.
 */

void RomanToInt::convert()
{
    // cycle through the characters in the string
    for (int i = 0; i < roman.size(); ++i)
    {
        if (roman[i] == 'I')
        {
            if (roman[i + 1] == 'V' || roman[i + 1] == 'X')
            {
                --value;
            }
            else
            {
                ++value;
            }
            continue;
        }
        else if (roman[i] == 'V')
        {
            value += 5;
            continue;
        }
        else if (roman[i] == 'X')
        {
            if (roman[i + 1] == 'L' || roman[i + 1] == 'C')
            {
                value -= 10;
            }
            else
            {
                value += 10;
            }
            continue;
        }
        else if (roman[i] == 'L')
        {
            value += 50;
            continue;
        }
        else if (roman[i] == 'C')
        {
            if (roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                value -= 100;
            }
            else
            {
                value += 100;
            }
            continue;
        }
        else if (roman[i] == 'D')
        {
            value += 500;
            continue;
        }
        else if (roman[i] == 'M')
        {
            value += 1000;
            continue;
        }
    }
}

/*
 * int RomanToInt::Check()
 *
 * This function checks if the roman numeral is valid. It returns 0 if the roman is valid and 1 if the roman is invalid.
 *
 * @param N/A
 *
 * @return int: 0 if the roman is valid and 1 if the roman is invalid.
 */

int RomanToInt::Check()
{
    for (int i = 0; i < roman.size(); ++i)
    {
        if (roman[i] == 'I' || roman[i] == 'V' || roman[i] == 'X' || roman[i] == 'L' || roman[i] == 'C' || roman[i] == 'D' || roman[i] == 'M')
            continue; // check next character
        /* The for loop will not continue beyond the above if statement unless an invalid character is found */
        std::cout << "Invalid character: " << roman[i] << std::endl;
        return -1; // return -1 if invalid character
    }
	
	// The valid combinations of roman numerals is that I can only be placed before I, V, and X; X can only be placed before L and C; C can only be placed before D and M.
    for (int i = 0; i < roman.size(); ++i)
    {
        if (roman[i] == 'I')
        {
            if (roman[i + 1] == 'L' || roman[i + 1] == 'C' || roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'I' can only be placed before 'V' and 'X'." << std::endl;
                return -1;
            }
            if (roman[i + 1] == 'I' && roman[i + 2] == 'I' && roman[i + 3] == 'I')
            {
				std::cout << "This is an invalid combination of roman numerals. 'I' can only be placed up to 3 times in a row." << std::endl;
				return -1;
            }
            if ((roman[i + 1] == 'I' && roman[i + 2] == 'V') || (roman[i + 1] == 'I' && roman[i + 2] == 'X'))
            {
                std::cout << "This is an invalid combination of roman numerals. 'II' cannot be subtracted." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'V')
        {
            if (roman[i + 1] == 'V' || roman[i + 1] == 'X' || roman[i + 1] == 'L' || roman[i + 1] == 'C' || roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'V' can only be followed by 'I'." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'X')
        {
            if (roman[i + 1] == 'I' || roman[i + 1] == 'V' || roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'X' can only be placed before 'L' and 'C'." << std::endl;
                return -1;
            }
            if (roman[i + 1] == 'X' && roman[i + 2] == 'X' && roman[i + 3] == 'X')
            {
                std::cout << "This is an invalid combination of roman numerals. 'X' can only be placed up to 3 times in a row." << std::endl;
                return -1;
            }
            if ((roman[i + 1] == 'X' && roman[i + 2] == 'L') || (roman[i + 1] == 'X' && roman[i + 2] == 'C'))
            {
                std::cout << "This is an invalid combination of roman numerals. 'XX' cannot be subtracted." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'L')
        {
            if (roman[i + 1] == 'L' || roman[i + 1] == 'C' || roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'L' can only be followed by 'I' 'V' and 'X'." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'C')
        {
            if (roman[i + 1] == 'I' || roman[i + 1] == 'V' || roman[i + 1] == 'X' || roman[i + 1] == 'L')
            {
                std::cout << "This is an invalid combination of roman numerals. 'C' can only be placed before 'D' and 'M'." << std::endl;
                return -1;
            }
            if (roman[i + 1] == 'C' && roman[i + 2] == 'C' && roman[i + 3] == 'C')
            {
                std::cout << "This is an invalid combination of roman numerals. 'C' can only be placed up to 3 times in a row." << std::endl;
                return -1;
            }
            if ((roman[i + 1] == 'C' && roman[i + 2] == 'D') || (roman[i + 1] == 'C' && roman[i + 2] == 'M'))
            {
                std::cout << "This is an invalid combination of roman numerals. 'CC' cannot be subtracted." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'D')
        {
            if (roman[i + 1] == 'D' || roman[i + 1] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'D' cannot be followed by 'D' or 'M'." << std::endl;
                return -1;
            }
            continue;
        }
        else if (roman[i] == 'M')
        {
            if (roman[i + 1] == 'M' && roman[i + 2] == 'M' && roman[i + 3] == 'M')
            {
                std::cout << "This is an invalid combination of roman numerals. 'M' can only be placed up to 3 times in a row." << std::endl;
                return -1;
            }
        }
    }
	
    return 0;
}

/*
 * void RomanToInt::print()
 *
 * This function prints the integer equal to the roman.
 *
 * @param N/A
 *
 * @return N/A
 */

void RomanToInt::print()
{
    std::cout << "The input roman was: " << roman << ".\n";
    std::cout << "The integer form is: " << value << ".\n";
}