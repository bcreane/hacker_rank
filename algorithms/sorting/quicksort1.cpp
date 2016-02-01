#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

void
partition(std::vector<int>& ar)
{
    std::vector<int> first, last;
    for (auto i : ar) {
        if (i < ar[0]) {
            first.push_back(i);
        } else {
            last.push_back(i);
        }
    }
    for (auto i : first)
        std::cout << i << " ";
    for (auto i : last)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(void)
{
    std::vector <int> ar;

    int num_elems;
    std::cin >> num_elems;
    
    while (num_elems-- > 0) {
        int tmp; std::cin >> tmp;
        ar.push_back(tmp); 
    }

    partition(ar);
   
    return 0;
}

