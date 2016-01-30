#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void
print_grid(const std::vector<std::string>& grid)
{
    for (auto r : grid)
        std::cout << r << std::endl;
}

bool
is_cavity(const std::vector<std::string>& grid, size_t row, size_t col)
{
    const char d = grid[row][col];

    return                            d > grid[row-1][col-0] &&                           
           d > grid[row+0][col-1] &&                            d > grid[row+0][col+1] &&
                                      d > grid[row+1][col-0];
}

std::vector<std::string>
mark_cavities(const std::vector<std::string>& grid)
{
    std::vector<std::string> cavity(grid);

    const size_t n = grid.size();
    if (n < 3)
        return cavity;

    for (size_t row = 1; row < n - 1; ++row) {
        for (size_t col = 1; col < n - 1; ++col) {
            if (is_cavity(grid, row, col)) {
                cavity[row][col] = 'X';
            }
        }
    }

    return cavity;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<std::string> grid(n);

    for (size_t ndx = 0; ndx < n; ndx++) {
       std::cin >> grid[ndx];
    }
    
    std::vector<std::string> cavity = mark_cavities(grid);
    print_grid(cavity);

    return 0;
}

