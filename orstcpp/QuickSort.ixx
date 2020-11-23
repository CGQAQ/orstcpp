module;
#include<vector>
export module QuickSort;

export namespace quick_sort
{
	auto sort(std::vector<int> const& input) -> std::vector<int>
	{
		std::vector result(input);
		if (result.size() <= 1)
			return result;
		else if (result.size() == 2)
		{
			if (result.front() > result.back())
				std::swap(result.front(), result.back());
			return result;
		}
		int pivot = result.front();
		int l{ 0 }, r{ static_cast<int>(result.size()) };
		for (int i = 0; i < result.size(); ++i)
		{
			auto& cur = result[i];
			if (cur > pivot)
			{
				std::swap(cur, result[--r]);
			}
			else
			{
				l++;
			}
		}
		std::swap(result.front(), result[l-1]);
		// 2, 3, 1
		auto lr = sort(std::vector(result.begin(), std::next(result.begin(), l)));
		auto rr = sort(std::vector(std::next(result.begin(), r), result.end()));
		lr.insert(lr.end(), rr.begin(), rr.end());
		return lr;
	}
}