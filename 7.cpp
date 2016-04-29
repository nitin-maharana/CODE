/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Find how many times the sorted array is rotated anti-clockwise(No Duplicates).

#include <iostream>
#include <vector>

using namespace std;

int countRotation(vector<int>& input)
{
	int low, high, mid;
	int prev, next;

	low = 0;
	high = input.size()-1;

	while(low <= high)
	{
		if(input[low] <= input[high])
			return low;

		mid = low + (high - low) / 2;

		next = (mid + 1) % input.size();
		prev = (mid + input.size() - 1) % input.size();

		if(input[mid] <= input[prev] && input[mid] <= input[next])
			return mid;

		if(input[mid] <= input[high])
			high = mid-1;
		else
			low = mid+1;
	}

	return -1;
}

void print(vector<int>& input)
{
	cout << endl << "Input : ";

	for(int i : input)
		cout << i << " ";

	cout << endl << endl;
}

int main(void)
{
	vector<int> input;
	input.push_back(5);
	input.push_back(6);
	input.push_back(7);
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	
	print(input);

	cout << "Number of Rotation : ";

	cout << countRotation(input) << endl << endl;

	return 0;
}