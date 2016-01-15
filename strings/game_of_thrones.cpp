#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>

namespace {
    bool
    is_odd(size_t i)
    {
        return (i & 1) == 1;
    }

    /*
     * Returns true if the given string can be rearranged to
     * be an anagram.
     */
    bool
    can_make_palindrome(const std::string& s)
    {
        if (s.length() < 3)
            return true;

        std::unordered_map<char, size_t> char_frequency;
        for (auto c : s) {
            char_frequency[c]++;
        }

        size_t odd_count = 0;
        for (auto it = char_frequency.begin(); it != char_frequency.end(); ++it) {
            if (is_odd(it->second)) {
                if (++odd_count > 1)
                    return false;
            }
        }

        return true;
    }
}

int
main()
{
	std::string s;

    std::cin >> s;
    std::cout << (can_make_palindrome(s) ? "YES" : "NO") << std::endl;

    return 0;
}

