#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>


int
main()
{
    std::set<int> s;
    
    std::size_t num_queries;
    std::cin >> num_queries;
    while (num_queries-- > 0) {
        int cmd, arg; std::cin >> cmd >> arg;
        
        switch (cmd) {
        case 1: {       // add
            s.insert(arg);
            break;
        }
        case 2: {
            s.erase(arg);
            break;
        }
        case 3: {
            bool is_present = s.find(arg) != s.end();
            std::cout << (is_present ? "Yes" : "No") << std::endl;
            break;
        }
        }
    }
    
    return 0;
}

