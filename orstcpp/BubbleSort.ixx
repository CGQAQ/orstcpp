module;
#include <vector>
export module BubbleSort;

export namespace bubble_sort
{
	// sort vector in place
	auto sort(std::vector<int> const& input)
	{
		std::vector result(input);
		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			for (size_t i = 1; i < result.size(); i++)
			{
				auto& left = result[i - 1];
				auto& right = result[i];
				if (left > right) 
				{
					std::swap(left, right);
					swapped = true;
				}
			}
		}
		return result;
	}
}