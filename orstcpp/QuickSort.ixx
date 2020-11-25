module;
#include <vector>
export module QuickSort;

// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
int partition(std::vector<int>& io, int lo, int hi)
{
	int pivot = io[(lo + hi) / 2];
	int i = lo - 1, j = hi + 1;
	while (true)
	{
		do
		{
			i = i + 1;
		} while (io[i] < pivot);

		do
		{
			j--;
		} while (io[j] > pivot);
		if (i >= j)
			return j;
		std::swap(io[i], io[j]);
	}
}

void quickSort(std::vector<int>& io, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(io, lo, hi);
		quickSort(io, lo, p);
		quickSort(io, p + 1, hi);
	}
}

export namespace quick_sort
{
	auto sort(std::vector<int> const& input) -> std::vector<int>
	{
		std::vector result(input);
		// 2, 3, 1
		quickSort(result, 0, result.size() - 1);
		return result;
	}
}