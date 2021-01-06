
#include "workerthread.h"

workerthread area_and_index(std::vector<int> k, std::vector<int> k_rev, double k_len)
{

	//double my_max, my_rev_max;
	std::vector<int> iterative_max_vector, iterative_rev_max_vector, min_of_sum_index_array;

	for (int i = 1; i < k_len + 1; i++)
	{
		auto my_max = *std::max_element(k.begin(), k.begin() + i) * i;
		iterative_max_vector.push_back(my_max);

		auto my_rev_max = *std::max_element(k_rev.begin(), k_rev.end() - i) * (k_len - i);
		iterative_rev_max_vector.push_back(my_rev_max);
	}

	// add the iterative max vectors and put into the iterative_max_vector
	std::transform(iterative_max_vector.begin(), iterative_max_vector.end(), iterative_rev_max_vector.begin(), iterative_max_vector.begin(), std::plus<int>());

	auto min_of_sum = std::min_element(iterative_max_vector.begin(), iterative_max_vector.end());
	//auto min_of_sum_index = std::distance(iterative_max_vector.begin(), min_of_sum);

	for (int i = 0; i < k_len; i++) {
		if (iterative_max_vector[i] == *min_of_sum) {
			//auto min_of_sum_index = i;
			min_of_sum_index_array.push_back(i);
		};
	};

	workerthread builtworker;
	builtworker.minimum_element = *min_of_sum;

	builtworker.minimum_element_index = min_of_sum_index_array;

	return builtworker;
};


