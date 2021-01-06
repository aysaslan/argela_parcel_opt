#include "randnumgen.h"

randgen randomgenerator()
{
	//create a random device
	//Mersenne Twister Engine creates healthier rv.s
	//std::rand generates rv up to 2^16=32768, so use mt
	std::vector<int> k_vector;

	std::random_device rd;
	std::mt19937 gen(rd());


	//Create a distribution for n and k
	std::uniform_int_distribution<> n_distribution(1, 100000);
	std::uniform_int_distribution<> k_distribution(1, 10000);


	auto n_blocknumber = n_distribution(gen);

	for (int i = 1; i < n_blocknumber + 1; i++) { // create the random k vector
		k_vector.push_back(k_distribution(gen));  //which has n element
	};

	randgen randomlygenerate; // call a structure for an ability to return both n and k vector 
	randomlygenerate.myk_vector = k_vector;
	randomlygenerate.myn_blocknumber = n_blocknumber;

	return randomlygenerate;

};
//
//std::vector<int> randnumgen::get_myk_vector()
//{
//	return myk_vector;
//}
//
//double randnumgen::get_myn_blocknumber()
//{
//	return myn_blocknumber;
//}

