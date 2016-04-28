/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Finding the number of inversions in an array.
//Modified Merge Sort. Divide & Conquer.

#include <iostream>

using namespace std;

int modifiedMerge(int *input, int l, int mid, int r)
{
	int n1, n2, result;

	result = 0;
	n1 = mid - l + 1;
	n2 = r - mid;

	int *left, *right;

	left = new int[n1];
	right = new int[n2];

	for(int i = 0, j = l; i < n1; i++, j++)
		left[i] = input[j];

	for(int i = 0, j = mid+1; i < n2; i++, j++)
		right[i] = input[j];

	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
			input[k++] = left[i++];
		else
		{
			input[k++] = right[j++];
			result += (n1-i);
		}
	}

	while(i < n1)
		input[k++] = left[i++];

	while(j < n2)
		input[k++] = right[j++];

	delete[] left;
	delete[] right;

	return result;
}

int modifiedMergeSort(int *input, int l, int r)
{
	if(l >= r)
		return 0;

	int mid, result = 0;

	mid = l + (r - l) / 2;

	result += modifiedMergeSort(input, l, mid);
	result += modifiedMergeSort(input, mid+1, r);
	result += modifiedMerge(input, l, mid, r);

	return result;
}

int main(void)
{
	int input[5] = {5,4,3,2,1};

	cout << modifiedMergeSort(input, 0, 4) << endl;

	return 0;
}