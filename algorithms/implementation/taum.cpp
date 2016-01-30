#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

int
main()
{
    size_t num_tests;
    std::cin >> num_tests;
    while (num_tests-- > 0) {
        size_t b, w;
        std::cin >> b >> w;
        
        int black_cost, white_cost, conv_cost;
        std::cin >> black_cost >> white_cost >> conv_cost;
        
        int bc = std::min(black_cost, white_cost+conv_cost);
        int wc = std::min(white_cost, black_cost+conv_cost);
        
        std::cout << (b * bc) + (w * wc) << std::endl;
    }

    return 0;
}

