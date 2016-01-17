#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <sstream>

int
main()
{
    size_t num_elems = 0;
    std::cin >> num_elems;

    std::unordered_map<std::string, size_t> str_freqs;

    while (num_elems-- > 0) {
        std::string s;
        std::cin >> s;
        str_freqs[s]++;
    }

    size_t num_queries = 0;
    std::cin >> num_queries;

    while (num_queries-- > 0) {
        std::string s;
        std::cin >> s;
        std::cout << str_freqs[s] << std::endl;
    }

    return 0;
}

