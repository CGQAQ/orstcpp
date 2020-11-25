#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <random>

#define TEST 1

import BubbleSort;
import InsertionSort;
import SelectionSort;
import QuickSort;

int main()
{
	auto printResult = [](std::string name, int amount, std::vector<int> result) {
		std::cout << name << "(" << amount << "): ";
		std::ranges::for_each(
			result,
			[](auto n) {
				std::cout << n << ", ";
			});
		std::cout << std::endl;
	};

#if TEST==1
	int inputAmount[] = { 0, 10, 100 };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(-65535, 65535);
	for (auto i : inputAmount)
	{
		std::vector<int> numbers(i);
		for (auto& number : numbers)
		{
			number = distr(gen);
		}
		auto bubbleResult = bubble_sort::sort(numbers);
		auto insertionResult = insertion_sort::sort(numbers);
		auto selectionResult = selection_sort::sort(numbers);
		auto quickResult = quick_sort::sort(numbers);

		printResult("Bubble sort", i, bubbleResult);
		printResult("Insertion sort", i, insertionResult);
		printResult("Selection sort", i, selectionResult);
		printResult("Quick sort", i, quickResult);
	}
#endif
#if 0
	std::vector input = {1,2,5,4,3};
	auto quickResult = quick_sort::sort(input);
	printResult("quicksort", 5, quickResult);
#endif

	return 0;
}