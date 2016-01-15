#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int max_res = INT_MIN;
    
    for (int outer = l; outer <= r; ++outer) {
        for (int inner = l; inner <= r; ++inner) {
            max_res = std::max(max_res, outer ^ inner);
        }
    }
    return max_res;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}

