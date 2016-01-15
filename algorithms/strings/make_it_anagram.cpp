#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>

/*
 * Alice recently started learning about cryptography
 * and found that anagrams are very useful. Two strings
 * are anagrams of each other if they have same character
 * set and same length. For example strings "bacdc" and
 * "dcbac" are anagrams, while strings "bacdc" and "dcbad"
 * are not.
 *
 * Alice decides on an encryption scheme involving 2 large
 * strings where encryption is dependent on the minimum number
 * of character deletions required to make the two strings
 * anagrams. She need your help in finding out this number.
 *
 * Given two strings (they can be of same or different
 * length) help her in finding out the minimum number of
 * character deletions required to make two strings anagrams.
 * Any characters can be deleted from any of the strings.
 *
 * Input Format 
 *  Two lines each containing a string.
 *
 * Constraints 
 *  1 <= Length of A,B <= 10000 
 *  A and B will only consist of lowercase latin letter.
 *
 * Output Format 
 *  A single integer which is the number of character deletions.
 *
 * Sample Input #00:
 *
 *  cde
 *  abc
 *
 * Sample Output #00:
 *  4
 * Explanation #00: 
 * We need to delete 4 characters to make both strings
 * anagram i.e. 'd' and 'e' from first string and 'b'
 * and 'a' from second string.
 */

namespace {
    typedef std::unordered_map<char, size_t> CHash_t;

    CHash_t
    get_char_freq(const std::string& s)
    {
        CHash_t cp;
        for (const auto& c:s) {
            cp[c]++;
        }
        return cp;
    }
}

int
main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    CHash_t h1 = get_char_freq(s1), h2 = get_char_freq(s2);
    size_t matching_chars = 0;

    for (const auto& c : h1) {
        matching_chars += std::min(h1[c.first], h2[c.first]);
    }

    std::cout << s1.length() + s2.length() - (matching_chars * 2) << std::endl;

    return 0;
}

