module;
#include <vector>
export module SelectionSort;

export namespace selection_sort
{
	auto sort(std::vector<int> const& input)
	{
		std::vector result(input);
		for (int i = 0; i < result.size(); ++i)
		{
			int jMin = i;
			for (int j = i + 1; j < result.size(); ++j)
			{
				if (result[j] < result[jMin]) 
				{
					jMin = j;
				}
			}
			if (jMin != i) 
			{
				std::swap(result[i], result[jMin]);
			}
		}
		return result;
	}
}