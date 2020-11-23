module;
#include <vector>
export module InsertionSort;

export namespace insertion_sort 
{
	auto sort(std::vector<int> const& input)
	{
		std::vector result(input);
		int i = 1;
		while (i < result.size())
		{
			int j = i;
			while (j > 0 && result[j - 1] > result[j])
			{
				std::swap(result[j - 1], result[j]);
				j--;
			}
			i++;
		}
		return result;
	}
}