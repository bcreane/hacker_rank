#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
void
print_heap(const std::vector<int>& heap)
{
    for (auto i : heap)
        std::cout << i << ", ";
    std::cout << std::endl;
}

int
main()
{
    size_t num_queries;
    std::cin >> num_queries;
    std::vector<int> heap;
    
    while (num_queries-- > 0) {
        int cmd, v;
        std::cin >> cmd;
        
        switch(cmd) {
        case 1:     // add
            std::cin >> v;
            heap.push_back(v);
            break;
        case 2: {   // delete
            std::cin >> v;

            bool done = false;
            std::vector<int>::iterator i = heap.begin();
            while (!done && i != heap.end()) {
                if (*i == v) {
                    heap.erase(i);
                    done = true;
                }
                i++;
            }
            break;
        }
        case 3:     // print min element
            std::make_heap(heap.begin(), heap.end());
            std::cout << heap.back() << std::endl;
            break;
        }
    }
    
    return 0;
}

