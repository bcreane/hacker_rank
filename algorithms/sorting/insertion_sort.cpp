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
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void
printArray(const vector<int>& ar)
{
    for (const auto& i : ar)
        std::cout << i << " ";
    std::cout << std::endl;
}

void
insertionSort(vector<int>& ar)
{
    if (ar.size() < 3) {
        printArray(ar);
        return;
    }

    int i = ar[ar.size()-1];
    std::size_t ndx = ar.size()-2;
    
    while (ar[ndx] > i) {
        ar[ndx+1] = ar[ndx];
        printArray(ar);
        --ndx;
    }
    ar[ndx+1] = i;
    printArray(ar);
}

int
main(void)
{
    std::vector <int>  numbers;
    int num_elems;
    std::cin >> num_elems;

    for(int ndx = 0; ndx < num_elems; ndx++) {
        int tmp;
        std::cin >> tmp;
        numbers.push_back(tmp); 
    }

    insertionSort(numbers);
   
    return 0;
}

