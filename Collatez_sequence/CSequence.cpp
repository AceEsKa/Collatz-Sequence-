#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AllocationCounter.cpp"
#include <charconv>
#include "Storage.cpp"

class Csequence
{
private:
	Storage csequence;
	std::string MaxNumber;
	int divisions;
	int multyplications;
public:
	bool VerifyInput(std::string& s)
	{
		int size = s.size();
		bool zero = false;
		if (s[0] - '0' == 0)
		{
			zero = true;
		}
		for (int i = 0; i < size; ++i)
		{
			if (s[i] - '0' > 9 || s[i] - '0' < 0)
			{
				return false;
			}
			else if (s[i] - '0' != 0)
			{
				zero = false;
			}
		}

		if (zero)
		{
			return false;
		}

		return true;
	}

	bool Greater(std::string& CurrentNumber, std::string& MaxNumTillNow)
	{
		if (CurrentNumber.size() > MaxNumTillNow.size())
		{
			return true;
		}
		else if (CurrentNumber.size() < MaxNumTillNow.size())
		{
			return false;
		}

		for (int i = 0; i < CurrentNumber.size(); ++i)
		{
			if (CurrentNumber[i] > MaxNumTillNow[i])
			{
				return true;
			}
			else if (CurrentNumber[i] < MaxNumTillNow[i])
			{
				return false;
			}
		}

		return false;
	}



	void MakeCollatzSequence(std::string& CurrentNumber)
	{
		MaxNumber = CurrentNumber;
		divisions = 0;
		multyplications = 0;
		int reminder;
		int product = 0;
		int MiddleStep;
		int size = CurrentNumber.size();
		int last = CurrentNumber[size - 1] - '0';

		while ((CurrentNumber[0] - '0') != 1 || size > 1)
		{
			last = CurrentNumber[size - 1] - '0';

			if (last % 2 == 0)
			{
				size = CurrentNumber.size();

				//if we devide number < 2 by 2 we will just get 0
				product = (CurrentNumber[0] - '0') / 2;
				reminder = (CurrentNumber[0] - '0') % 2;
				CurrentNumber[0] = product + '0';

				for (int it = 1; it <= size - 1; ++it)
				{

					MiddleStep = (reminder * 10 + (CurrentNumber[it] - '0'));
					product = MiddleStep / 2;
					reminder = MiddleStep % 2;

					CurrentNumber[it] = product + '0';
				}

				if (CurrentNumber[0] - '0' == 0)
				{
					CurrentNumber.erase(CurrentNumber.begin());
				}

				++divisions;
			}
			else
			{
				++multyplications;
				reminder = 1;
				for (int it = size - 1; it >= 0; --it)
				{
					product = (CurrentNumber[it] - '0') * 3 + reminder;
					//3k+1 only need to increment the last elemnt, in this case first since we are traversing it in reverse
					if (product > 9)
					{
						reminder = product / 10;
						product = product % 10;
					}
					else
					{
						reminder = 0;
					}
					CurrentNumber[it] = product + '0';
				}
				if (reminder > 0)
				{
					CurrentNumber.insert(CurrentNumber.begin(), reminder + '0');
				}
			}
			if (Greater(CurrentNumber, MaxNumber) == true)
			{
				MaxNumber = CurrentNumber;
			}
			size = CurrentNumber.size();
		}


		csequence = Storage(MaxNumber, divisions, multyplications);
	}

	Storage getCsequence()
	{
		return csequence;
	}
};