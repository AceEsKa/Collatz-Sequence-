#pragma once
#include <iostream>
#include <string>
class Storage
{
private:
	std::string MaxNumber;
	int divisions;
	int multyplications;
public:
	Storage() 
	{
		divisions = 0;
		multyplications = 0;
		MaxNumber = "0";
	}

	Storage(std::string &number, int &n1,int &n2)
	{
		divisions = n1;
		multyplications = n2;
		MaxNumber = std::move(number);
	}

	int& RetDivisions()
	{
		return divisions;
	}

	int& RetMultyplications()
	{
		return multyplications;
	}

	std::string& RetMaxNumber()
	{
		return MaxNumber;
	}

};