#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string>

int
main()
{
    std::size_t num_tests = 0;
    std::cin >> num_tests;

    while (num_tests-- > 0) {
        uint64_t lower, upper;
        std::cin >> lower >> upper;
        size_t num_perfect_squares = floor(std::sqrt(upper))-ceil(std::sqrt(lower))+1;
        std::cout << num_perfect_squares << std::endl;
    }
    
    return 0;
}

