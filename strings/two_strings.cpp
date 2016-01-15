#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>

/*
 * You are given two strings, A and B. Find if there is
 * a substring that appears in both A and B.
 *
 * Input Format
 *  Several test cases will be given to you in a single file.
 *  The first line of the input will contain a single integer
 *  T, the number of test cases.
 *
 *  Then there will be T descriptions of the test cases. Each
 *  description contains two lines. The first line contains
 *  the string A and the second line contains the string B.
 *
 * Output Format
 *  For each test case, display YES (in a newline), if there
 *  is a common substring. Otherwise, display NO.
 *
 * Constraints
 *  All the strings contain only lowercase Latin letters.
 *  1<=T<=10
 *  1<=|A|,|B|<=105
 *
 * Sample Input
 *  2
 *  hello
 *  world
 *  hi
 *  world
 *
 * Sample Output
 *  YES
 *  NO
 */

namespace {
    typedef std::unordered_map<char, bool> CHash_t;

    CHash_t
    get_char_freq(const std::string& s)
    {
        CHash_t cp;
        for (const auto& c:s) {
            cp[c] = true;
        }

        return cp;
    }

    bool
    common_substring(const std::string& s1, const std::string& s2)
    {
        CHash_t h1 = get_char_freq(s1), h2 = get_char_freq(s2);
        for (const auto& c : h1) {
            if (std::min(c.second, h2[c.first]) > 0)
                return true;
        }
        return false;
    }
}

int
main()
{
    std::size_t num_tests = 0;

    std::cin >> num_tests;

    while (num_tests-- > 0) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        std::cout << (common_substring(s1, s2) ? "YES" : "NO") << std::endl;
    }

    return 0;
}

