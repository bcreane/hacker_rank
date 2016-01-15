#include <cmath>
#include <bitset>
#include <cstdio>
#include <limits>
#include <numeric>
#include <iostream>

int
main()
{
    size_t num_tests;
    std::cin >> num_tests;

    while (num_tests-- > 0) {
        uint32_t i;
        std::cin >> i;
        std::cout << (i ^ 0xffffffff) << std::endl;
    }

    return 0;
}

