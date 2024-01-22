#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AllocationCounter.cpp"
#include <charconv>
#include "Storage.cpp"

void print(int& divisions, int& multyplications, std::string& MaxNumber)
{
	std::cout << "Number of 3k+1 operations: " << multyplications << std::endl;
	std::cout << "Number of 2k operations: " << divisions << std::endl;
	std::cout << "Max number: " << MaxNumber << std::endl;
}
