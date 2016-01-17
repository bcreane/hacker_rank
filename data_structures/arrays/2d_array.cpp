#include <vector>
#include <climits>
#include <iostream>

/*
 * Given a 6×6 2D Array, A:
 * 
 * 1 1 1 0 0 0
 * 0 1 0 0 0 0
 * 1 1 1 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 *
 * We can find 16 hourglasses in A; we define an hourglass in A
 * to be a subset of values with indexes falling in this pattern
 * in A's graphical representation:
 * 
 *  a b c
 *    d
 *  e f g
 *
 * The sum of an hourglass is the sum of the values within it.
 * 
 * Your task is to calculate the sum of every hourglass in some 2D
 * Array, A, and print the largest value (maximum of the sums) as
 * your answer.
 * 
 * Input Format
 * 
 *   There are 6 lines of input, where each line contains 6
 *   space-separated integers describing 2D Array A; every value
 *   in A will be in the inclusive range of −9 to 9.
 * 
 *   Constraints 
 *   −9≤A[i][j]≤9 
 *   0≤i,j≤5
 *
 * Output Format:
 * 
 *   Print the largest (maximum) hourglass sum found in A.
 * 
 */

int
calc_hg(const std::vector< std::vector<int> >& arr, std::size_t x, std::size_t y)
{
    return arr[y-1][x-1] + arr[y-1][x] + arr[y-1][x+1] + 
                           arr[y][x] +
           arr[y+1][x-1] + arr[y+1][x] + arr[y+1][x+1];
}

int
main()
{
    std::vector< std::vector<int> > arr(6, std::vector<int>(6));
    for (std::size_t y = 0; y < 6; y++) {
       for (std::size_t x = 0; x < 6; x++) {
           std::cin >> arr[y][x];
       }
    }

    int max_hg = INT_MIN;
 
    for (std::size_t y = 1; y < 5; y++) {
        for (std::size_t x = 1; x < 5; x++) {
            max_hg = std::max(calc_hg(arr, x, y), max_hg);
        }
    }

    std::cout << max_hg << std::endl;
    
    return 0;
}

