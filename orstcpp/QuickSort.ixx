module;
#include<vector>
#include <span>
export module QuickSort;

void quickSort(std::span<int> io)
{
	if (io.size() <= 1)
		return;
	else if (io.size() == 2)
	{
		if (io.front() > io.back())
			std::swap(io.front(), io.back());
		return;
	}
	int pivot = io.front();
	int l{ 0 }, r{ static_cast<int>(io.size()) };
	for (int i = 0; i < io.size(); ++i)
	{
		auto& cur = io[i];
		if (cur > pivot)
		{
			std::swap(cur, io[--r]);
		}
		else
		{
			l++;
		}
	}
	std::swap(io.front(), io[l - 1]);
	quickSort(io.subspan(0, l));
	quickSort(io.subspan(r));
}

export namespace quick_sort
{
	auto sort(std::vector<int> const& input) -> std::vector<int>
	{
		std::vector result(input);
		// 2, 3, 1
		quickSort(std::span(result));
		return result;
	}
}