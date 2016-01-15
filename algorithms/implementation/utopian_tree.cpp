#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int num_tests;
    cin >> num_tests;
    
    while (num_tests-- > 0) {
        std::size_t cycles;
        cin >> cycles;
        
        std::size_t height = 1;
        for (std::size_t cycle = 0; cycle < cycles; ++cycle) {
            if ((cycle & 1) == 1){
                height *= 2;
            } else {
                height += 1;
            }
        }
        std::cout << height << std::endl;
    }
    
    return 0;
}

