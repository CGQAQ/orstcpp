#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

import BubbleSort;
import InsertionSort;

int main()
{
	std::vector<int> numbers{ 4, 2, 3, 1 };
	auto printResult = [](std::string name, std::vector<int> result) {
		std::cout << name << ": ";
		std::ranges::for_each(
			result,
			[](auto n) {
				std::cout << n << ", ";
			});
		std::cout << std::endl;
	};

	auto bubbleResult = bubble_sort::sort(numbers);
	auto insertionResult = insertion_sort::sort(numbers);

	printResult("Bubble sort", bubbleResult);
	printResult("Insertion sort", insertionResult);

	return 0;
}