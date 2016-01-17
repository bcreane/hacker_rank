#include <vector>
#include <iostream>

void
printArray(const std::vector<int>& ar)
{
    for (const auto& i : ar)
        std::cout << i << " ";
    std::cout << std::endl;
}

void
insertionSort(std::vector<int>& ar)
{
    for (std::size_t outer = 1; outer < ar.size(); ++outer) {
        int i = ar[outer];
        std::size_t ndx = outer - 1;
    
        while (ar[ndx] > i) {
            ar[ndx+1] = ar[ndx];
            --ndx;
        }
        ar[ndx+1] = i;
        printArray(ar);
    }
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

