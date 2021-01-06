#pragma once
#include <thread>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <future>



struct workerthread {
	double minimum_element{};
	std::vector<int> minimum_element_index;
};

workerthread area_and_index(std::vector<int> k, std::vector<int> k_rev, double k_len);
