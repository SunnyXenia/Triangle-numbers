#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

int max(const int& n1, const int& n2)
{
	return (n1 > n2) ? n1 : n2;
}


int max_iter(const int& n1, const int& n2)
{
	if (n1 > n2)
		return 0;
	else
		return 1;
}

int main()
{
	std::fstream file("bigTriangle.txt");

	if (!file.good())
		std::cout << "Smth wrong with the file" << std::endl;

	else
	{
		std::vector<int> vector_nums;

		while (!file.eof())
		{
			int num;
			file >> num;
			vector_nums.push_back(num);
		}

		int current_line = 2;
		int start_of_line = 0;
	    
		for (int i = 1; i < vector_nums.size(); ++i)
		{
			if (i == start_of_line + current_line - 1)
			{
				vector_nums[i] += vector_nums[start_of_line];
			}
			else if (i == start_of_line + 2 * current_line - 2)
			{
				vector_nums[i] += vector_nums[start_of_line + current_line - 2];
				start_of_line += current_line - 1;
				++current_line;
				
			}
			else
			{
				int n1 = vector_nums[i - current_line];
				int n2 = vector_nums[i - current_line + 1];

				vector_nums[i] += max(n1, n2);
				
			}
			
		}
		
		int biggest_sum = vector_nums[vector_nums.size() - 1];

		for (int i = vector_nums.size() - 1; i > vector_nums.size() - current_line; --i)
		{
			if (vector_nums[i] > biggest_sum)
				biggest_sum = vector_nums[i];
		}
		
		std::cout << "Biggest sum = " << biggest_sum << std::endl;
	}

	system("pause");
	return 0;
}