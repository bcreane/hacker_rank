#include <cmath>
#include <bitset>
#include <cstdio>
#include <limits>
#include <numeric>
#include <iostream>
#include <vector>

int
main()
{
    size_t num_tests;
    std::cin >> num_tests;

    while (num_tests-- > 0) {
        size_t array_len;
        std::cin >> array_len;

        std::vector<uint32_t> numbers;

        while (array_len-- > 0) {
            uint32_t i;
            std::cin >> i;
            numbers.push_back(i);
        }

        uint32_t res = 0;
        if ((numbers.size() & 1) == 1) {
            for (size_t ndx = 0; ndx < numbers.size(); ndx += 2) {
                res ^= numbers[ndx];
            }
        }

        std::cout << res << std::endl;
    }

    return 0;
}

