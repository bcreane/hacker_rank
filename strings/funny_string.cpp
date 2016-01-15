#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
#include <cmath>

namespace {

    /*
     * is_funny_string() returns true if string s is "funny."
     * Suppose you have a string S with length N. String R is
     * the reverse of string S. String S is funny if:
     *      |Si−Si−1|=|Ri−Ri−1| is true for every i from 1 to N−1.
     *
     * For example:
     *  acxz    zxca
     *
     *  c-a == x-z -> 1-0 == 2-3
     *  x-c == c-x -> 2-1 == 1-2
     *  z-x == a-c -> 3-2 == 0-1
     */

    bool is_funny_string(const std::string& s)
    {
        for (size_t ndx = 1; ndx < s.size(); ++ndx) {
            if (std::abs(s[ndx] - s[ndx-1]) !=
                std::abs(s[s.length()-ndx-1] - s[s.length()-ndx]))
                    return false;
        }
        return true;
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
        std::cout << (is_funny_string(s) ? "Funny" : "Not Funny") << std::endl;
    }

    return 0;
}

