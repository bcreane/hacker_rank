#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t
get_number_of_ones(const std::string& s)
{
    size_t number_of_ones(0);
    for (auto c : s) {
        if (c == '1')
            ++number_of_ones;
    }
    return number_of_ones;
}

std::string
or_of(const std::string& s1, const std::string& s2)
{
    std::string s(s1.length(), '0');
    for (size_t ndx = 0; ndx < s1.length(); ++ndx) {
        if (s1[ndx] == '1' || s2[ndx] == '1')
            s[ndx] = '1';
    }
    return s;
}

void
max_topics(const std::vector<std::string>& topics)
{
    size_t max_ones = 0;
    size_t pair_count = 0;
    for (size_t outer = 0; outer < topics.size()-1; ++outer) {
        for (size_t inner = outer+1; inner < topics.size(); ++inner) {
            const std::string s = or_of(topics[outer], topics[inner]);
            size_t count = get_number_of_ones(s);
            if (count > max_ones) {
                max_ones = count;
                pair_count = 1;
            } else if (count == max_ones) {
                pair_count++;
            }
        }
    }
    std::cout << max_ones << std::endl << pair_count << std::endl;
}

int main()
{
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::string> topics(n);
    for (std::size_t ndx = 0; ndx < n; ndx++){
       std::cin >> topics[ndx];
    }
    
    max_topics(topics);

    return 0;
}

