#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

namespace {
    /*
     * Given a string containing characters A and B only, change
     * the string there are only different consecutive  characters.
     * To do this, you are allowed to delete the characters in the
     * string. Return the minimum number of required deletions.
     *
     * Input Format
     *  The first line contains an integer T, i.e. the number of
     *  test cases. The next T lines contain a string each.
     *
     * Output Format
     *  For each test case, print the minimum number of deletions
     *  required.
     *
     * Constraints
     *  1≤T≤10 
     *  1≤ length of string ≤105
     *
     * Sample Input
     *  5
     *  AAAA
     *  BBBBB
     *  ABABABAB
     *  BABABA
     *  AAABBB
     *
     * Sample Output
     *  3
     *  4
     *  0
     *  0
     *  4
     *
     * Explanation
     *  AAAA ⟹ A, 3 deletions
     *  BBBBB ⟹ B, 4 deletions
     *  ABABABAB ⟹ ABABABAB, 0 deletions
     *  BABABA ⟹ BABABA, 0 deletions
     *  AAABBB ⟹ AB, 4 deletions because to convert it to AB we need to delete 2 A's and 2 B's
     *
     */
    size_t
    num_deletions(const std::string& s)
    {
        if (s.length() < 2)
            return 0;

        size_t num_deletions = 0;
        char last_char = s[0];
        for (size_t ndx = 1; ndx < s.length(); ++ndx) {
            if (s[ndx] == last_char) {
                ++num_deletions;
            } else {
                last_char = s[ndx];
            }
        }

        return num_deletions;
    }
}

int
main()
{
    std::size_t num_tests = 0;
	std::string s;

    std::cin >> num_tests;
    std::cin.ignore(2, '\n');

    while(num_tests-- > 0) {
        std::getline(std::cin, s);
        std::cout << num_deletions(s) << std::endl;
    }

    return 0;
}

