#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>

int
main()
{
    size_t num_elems = 0;
    std::cin >> num_elems;

    std::vector<int> v;
    v.resize(num_elems);

    while (num_elems-- > 0) {
        int i;
        std::cin >> i;
        v[num_elems] = i;
    }

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

