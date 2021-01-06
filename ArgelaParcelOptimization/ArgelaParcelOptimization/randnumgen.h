#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>


struct randgen  // call a structure for an ability to return both n and k vector 
{
	std::vector<int> myk_vector;
	double myn_blocknumber{};
};
randgen randomgenerator();