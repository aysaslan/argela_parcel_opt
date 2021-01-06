// ArgelaParcelOptimization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include <future>
#include <vector>
#include <thread>
#include "randnumgen.h"
#include "workerthread.h"

int main(int argc, char* argv[]) {

    double n;
    std::vector<int> k_padded{};
    std::vector<int> k_padded_rev{};
    //std::chrono::steady_clock::time_point start_time, end_time;

    if (argc == 1) {  // if no arg is given, then generate random variables for n and k
        randgen randomlyays;
        auto get_randomlyays = randomgenerator();
        n = get_randomlyays.myn_blocknumber;
        k_padded = get_randomlyays.myk_vector;
    }

    else {  // if the k vector is given i.e. test cases
        n = argc - 1; // the first element is the header of the .exe file
        for (int i = 1; i < n + 1; i++) {
            k_padded.push_back(atoi(argv[i])); // asci to integer
        }
    }

    std::cout << "the length of the arg is : " << n << "\n";
    k_padded.push_back(0); // a flexible vector for max_of_k_rev
    k_padded_rev = k_padded;
    std::reverse(k_padded_rev.begin(), k_padded_rev.end());

    auto start_time = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto aysslicing = std::async(std::launch::async, area_and_index, k_padded, k_padded_rev, n);
    auto ays = aysslicing.get();
    auto end_time = std::chrono::high_resolution_clock::now().time_since_epoch();


    auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(end_time - start_time);
    auto durationmili = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();

    if (ays.minimum_element == (*std::max_element(k_padded.begin(), k_padded.end()) * n)) {
        std::cout << "ONE BOX SHOULD BE USED!!! " << "\n";
    }


    std::cout << std::fixed;
    std::cout << "proces time : " << durationmili << " microseconds" << "\n";
    std::cout << "total_area = " << ays.minimum_element << "\n";
    std::cout << "slicing index = ";
    for (auto i : ays.minimum_element_index) {
        std::cout << i << " ";
    };
    std::cout << "\n" << "\n";


};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
