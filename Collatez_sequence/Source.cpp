#include <iostream>
#include <string>
#include <vector>
#include "AllocationCounter.cpp"
#include <charconv>
#include "Storage.cpp"
#include "CSequence.cpp"
#include "UserInput.cpp"
#include "VerifyInput.cpp"
#include "print.cpp"



int main()
{
	std::string n;
	do
	{
		n = std::move(GetUserInput());
	}while (!VerifyInput(n));

	Csequence csequence;
	csequence.MakeCollatzSequence(n);

	Storage v = std::move(csequence.getCsequence());
	print(v.RetDivisions(), v.RetMultyplications(), v.RetMaxNumber());


	std::cout << std::endl << s_AllocCount << " allocations" << std::endl;
	std::cout << bytesAllocated << " bytes total" << std::endl;

	return 0;
}