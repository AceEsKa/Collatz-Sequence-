#pragma once
#include <charconv>
#include <string>

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
};