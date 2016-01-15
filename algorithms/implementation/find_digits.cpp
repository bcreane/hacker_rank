#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t
num_digits(int n)
{
    int d(n);
    size_t cnt = 0;
        
    while (d) {
        int rem = d % 10;
        
        if (rem && (n % rem == 0))
            cnt++;

        d /= 10;
    }
    return cnt;
}

int
main()
{
    std::size_t num_tests = 0;
    cin >> num_tests;
    while (num_tests-- > 0) {
        int n;
        cin >> n;
        std::cout << num_digits(n) << std::endl;
    }
    
    return 0;
}

