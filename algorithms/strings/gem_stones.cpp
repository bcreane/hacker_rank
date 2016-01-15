#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>

namespace {
    typedef std::unordered_map<char, bool> CHash_t;

    void
    get_map_of_chars(const std::string& s, CHash_t& cp)
    {
        for (auto c:s) {
            cp[c] = true;
        }
    }
}

int
main()
{
    std::size_t num_strings = 0;

    std::cin >> num_strings;
    std::cin.ignore(2, '\n');

    // intersection_of_strings contains ongoing intersection of sets of 
    // characters in strings processed so far.
    CHash_t intersection_of_strings;

    for (size_t ndx = 0; ndx < num_strings; ++ndx) {
        std::string s;
        std::getline(std::cin, s);

        if (ndx == 0) {
            get_map_of_chars(s, intersection_of_strings);
        } else {
            CHash_t cp;

            get_map_of_chars(s, cp);

            for (auto& c : intersection_of_strings) {
                if (!cp[c.first]) {
                    c.second = false;   // not present in most recent string
                }
            }
        }
    }

    size_t num_gem_stones = 0;
    for (const auto& c : intersection_of_strings) {
        if (c.second) {
            ++num_gem_stones;
        }
    }
    std::cout << num_gem_stones << std::endl;

    return 0;
}

