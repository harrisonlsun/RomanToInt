/*
 * Harrison Sun (sun.har@northeastern.edu & hlsun@mit.edu)
 *
 * Files: "main.cpp" "RomanToInt.cpp" "RomanToInt.h"
 * This program converts roman numerals to integers.
 */
 
/*
 * This main function converts roman numerals to integers. If this program is called from the command line with additional arguments, it will take the first argument as the roman numeral to convert.
 * 
 * @param int argc: The number of arguments passed to this program.
 * @param char* argv[]: The arguments passed to this program.
 * 
 * @return int: 0 if the program runs successfully.
 */

#include "RomanToInt.h"

int main(int argc, char* argv[])
{
	// create a string
	std::string input{};
	// check if there are additional arguments
	if (argc > 1)
	{
		// convert the first argument to a string
		input = argv[1];
		std::cout << "Input accepted from terminal. The input is: " << input << std::endl;
	}
	// else ask for an input
	else
	{
		std::cout << "Please enter a roman numeral: ";
		std::cin >> input;
	}

	// convert the input to an integer and print it to the terminal
	RomanToInt roman{ input };
	
	return 0;
}