#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AllocationCounter.cpp"
#include <charconv>
#include "Storage.cpp"
std::string GetUserInput()
{
	//for sotring my natural number n form user input i choose string as storage variable as it has the potential size can be up to 2 147 483 647 
	//(at least thats the value of max_size for my system, can be less can be more depending on system)
	std::string UserInput;

	std::cin >> UserInput;
	std::cout << std::endl;

	return UserInput;
}