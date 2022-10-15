/*
 * Harrison Sun (sun.har@northeastern.edu & hlsun@mit.edu)
 * 
 * Files: "main.cpp" "RomanToInt.cpp" "RomanToInt.h"
 * This header file defines the class RomanToInt, which converts Roman numerals to integers.
 */

#pragma once

#include <iostream>
#include <string>

class RomanToInt
{
public:
	// constructor
	RomanToInt(std::string input);
private:
	// The roman numeral to convert
	std::string roman;
	// The integer to return
	int value {0};
	// convert the roman numeral to an integer
	void convert();
	// check in input
	int Check();
	// print the output
	void print();
};
