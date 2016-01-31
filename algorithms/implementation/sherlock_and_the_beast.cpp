#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::string
get_decent_number(size_t n)
{
    if (n < 3 || n == 4 || n == 7)
        return "-1";
    else if (n == 5)
        return "33333";

    size_t num_threes(0);
    switch (n % 3) {
    case 0:
        break;
    case 1:
        num_threes = 10;
        break;
    case 2:
        num_threes = 5;
        break;
    }

    const size_t num_fives = n - num_threes;
    const std::string fives(num_fives, '5');
    const std::string threes(num_threes, '3');

    return fives+threes;
}

int main()
{
    size_t num_tests;
    std::cin >> num_tests;
    while (num_tests-- > 0) {
        size_t n;
        std::cin >> n;
        std::cout << get_decent_number(n) << std::endl;
    }

    return 0;
}

