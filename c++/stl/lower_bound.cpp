#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int
main() 
{
    std::vector<int> v;
    size_t num_elems;
    std::cin >> num_elems;
    while (num_elems-- > 0) {
        int i; std::cin >> i;
        v.push_back(i);
    }
    std::sort(v.begin(), v.end());  // just in case

    size_t num_queries;
    std::cin >> num_queries;
    while (num_queries-- > 0) {
        int i; std::cin >> i;

        std::vector<int>::iterator low;
        low = std::lower_bound (v.begin(), v.end(), i);
        size_t pos = low - v.begin();
        if (*low == i) {
            std::cout << "Yes " << pos + 1 << std::endl;
        } else {
            std::cout << "No " << pos + 1 << std::endl;
        }
    }

    return 0;
}

