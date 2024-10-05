#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initial unsorted data
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Build a max heap
    std::make_heap(data.begin(), data.end());
    std::cout << "After make_heap: ";
    for (int n : data) std::cout << n << ' ';
    std::cout << '\n';

    // Insert a new element
    data.push_back(7);
    std::push_heap(data.begin(), data.end());
    std::cout << "After push_heap(7): ";
    for (int n : data) std::cout << n << ' ';
    std::cout << '\n';

    // Remove the largest element
    std::pop_heap(data.begin(), data.end());
    int largest = data.back();
    data.pop_back();
    std::cout << "After pop_heap: ";
    for (int n : data) std::cout << n << ' ';
    std::cout << "\nLargest element: " << largest << '\n';

    // Check if it's still a heap
    if (std::is_heap(data.begin(), data.end()))
        std::cout << "Data is still a heap.\n";
    else
        std::cout << "Data is no longer a heap.\n";

    // Sort the heap
    std::sort_heap(data.begin(), data.end());
    std::cout << "After sort_heap: ";
    for (int n : data) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
