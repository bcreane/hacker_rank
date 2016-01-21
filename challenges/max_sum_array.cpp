#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * You are given an array A of N integers. You need to find the contiguous
 * subarray of the maximum sum in A. The subarray should not contain the
 * number 0. Please find the maximum sum that is possible.
 *
 * Note 1: The subarray can also be empty. 
 * Note 2: The answer will fit in 32 bit-signed integer.
 *
 * Input Format
 *
 * The first line contains the integer N. The next line contains N
 * integers representing the numbers in the array.
 *
 * Constraints
 *  1≤N≤105 
 *  −106≤Ai≤106
 *
 * Output Format
 *  Output a single line representing the maximum sum that can be obtained.
 *
 * Sample Input
 *  5   
 *  3 4 0 1 2
 * 
 * Sample Output
 *  7
 *
 * Explanation
 *
 *  The subarray with the maximum sum that doesn't contain a 0 is 3, 4.
 *  Hence, the sum is 7.
 */

int
max_sum(const std::vector<int>& v)
{
    int max_ending_here = 0;
    int max_so_far = 0;
    int max_previous_subarray = 0;

    for (auto i : v) {
        if (i != 0) {
            max_ending_here = std::max(0, max_ending_here + i);
            max_so_far = std::max(max_so_far, max_ending_here);
        } else {
            max_previous_subarray = std::max(max_so_far, max_previous_subarray);
            max_ending_here = max_so_far = 0;
        }
    }

    return std::max(max_so_far, max_previous_subarray);
}

int main()
{
    std::vector<int> v;
    size_t num_elems;
    std::cin >> num_elems;
    while (num_elems-- > 0) {
        int i; std::cin >> i;
        v.push_back(i);
    }

    std::cout << max_sum(v) << std::endl;
    
    return 0;
}

