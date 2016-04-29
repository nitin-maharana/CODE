/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Finding the first & last occurance of a number in a sorted array.

#include <iostream>
#include <vector>

using namespace std;

int findFirstOccurance(vector<int>& input, int find)
{
	int low, high, mid, result;

	low = 0;
	high = input.size()-1;

	result = -1;

	while(low <= high)
	{
		mid = low + (high - low) / 2;

		if(input[mid] == find)
		{
			result = mid;
			high = mid-1;
		}
		else if(find > input[mid])
			low = mid+1;
		else
			high = mid-1;
	}

	return result;
}

int findLastOccurance(vector<int>& input, int find)
{
	int low, high, mid, result;

	low = 0;
	high = input.size()-1;

	result = -1;

	while(low <= high)
	{
		mid = low + (high - low) / 2;

		if(input[mid] == find)
		{
			result = mid;
			low = mid+1;
		}
		else if(find > input[mid])
			low = mid+1;
		else
			high = mid-1;
	}

	return result;
}

int main(void)
{
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(5);
	

	cout << "First Occurance : " << findFirstOccurance(input, 3) << endl;
	cout << "Last Occurance : " << findLastOccurance(input, 3) << endl;

	return 0;
}