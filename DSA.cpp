#include "DSA.h"

//reverse of array
void DSA::R_arr(int arr[], int n )
{
	int start = 0, end = n - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

// max min of array
void DSA::Min_max_arr()
{
	int i, j, min_idx;
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
			std::swap(arr[min_idx], arr[i]);
		}
	}
	std::cout << "Smallest Element :"<<arr[0] << "\nLargest Element:"<<arr[n-1];
}

//sum of two numbers
void DSA::Two_sum()
{
	int arr[] = {3,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;
	int i, j;
	int temp_indx, temp_indx2;
	for (i = 0; i < n; i++)
	{
		temp_indx = i;
		//std::cout << arr[temp_indx] << "i ";
		for (j = i + 1; j < n; j++)
		{
			temp_indx2 = j;
			if (arr[temp_indx] + arr[temp_indx2] == k)
			{
				std::cout << "indeies:" << i << " indices:" << j << '\n';
			}
			else
			{
				break;
			}
		}
	}
}

std::vector<int> DSA::Two_sum_vector(std::vector<int>& nums, int target)
{
	{
		std::vector<int> results;
		int temp_indx, temp_indx2;
		for (size_t i = 0; i < nums.size(); i++)
		{
			temp_indx = i;
			//std::cout << arr[temp_indx] << "i ";
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				temp_indx2 = j;
				if (i == j)
				{
					continue;
				}
				else
				{
					int sum = nums[temp_indx] + nums[temp_indx2];
					if (sum == target)
					{
						if (results.size() < 2)
						{

							results.push_back(i);
							results.push_back(j);
							std::cout << "indeies:" << i << " indices:" << j << '\n';
						}
						else
						{
							break;
						}
					}
					else
					{
						continue;
					}
				}
				return results;
			}
		}
		return results;
	}
}

void DSA::Rev_Exution()
{
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	R_arr(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	std::cout << '\n';
}

void DSA::Pub_Excute_fun()
{
	DSA daa;
	daa.Two_sum();
}

