#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// std::string::npos

bool
substring_match(const std::string& s, std::size_t start_pos, const std::string& p)
{
    return p == s.substr(start_pos, p.length());
}

bool
is_grid_present(const std::vector<std::string>& G,
                const std::vector<std::string>& P)
{
    const std::size_t pattern_height = P.size();

    for (size_t grid_row = 0; grid_row < G.size()-pattern_height+1; ++grid_row) {
        std::size_t pattern_ndx = G[grid_row].find(P[0]);
        while (pattern_ndx != std::string::npos) {
            bool found = true;
            for (size_t pattern_row = 1; pattern_row < pattern_height && found; ++pattern_row) {
                if (!substring_match(G[grid_row+pattern_row], pattern_ndx, P[pattern_row])) {
                    found = false;
                }
            }
            if (found)
                return true;
            pattern_ndx = G[grid_row].find(P[0], pattern_ndx+1);
        }
    }
    
    return false;
}

int main()
{
    size_t num_tests;
    std::cin >> num_tests;

    while (num_tests-- > 0) {
        int R;
        int C;
        std::cin >> R >> C;
        std::vector<std::string> G(R);
        for (std::size_t ndx = 0; ndx < R; ndx++) {
           std::cin >> G[ndx];
        }
  
        int r;
        int c;
        std::cin >> r >> c;
        std::vector<std::string> P(r);
        for (std::size_t ndx = 0; ndx < r; ndx++) {
           std::cin >> P[ndx];
        }

        bool present = is_grid_present(G, P);
        std::cout << (present ? "YES" : "NO") << std::endl;
    }

    return 0;
}


