/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Print 2-D matrix in clockwise spiral order.

#include <iostream>
#include <vector>

using namespace std;

void printSpiral(vector<vector<int>>& input)
{
	int top, bottom, left, right, direction;

	top = left = 0;
	bottom = input.size()-1;
	right = input[0].size()-1;
	direction = 0;

	while(top <= bottom && left <= right)
	{
		if(direction == 0)
		{
			for(int i = left; i <= right; i++)
				cout << input[top][i] << " ";
			top++;
		}else if(direction == 1)
		{
			for(int i = top; i <= bottom; i++)
				cout << input[i][right] << " ";
			right--;
		}else if(direction == 2)
		{
			for(int i = right; i >= left; i--)
				cout << input[bottom][i] << " ";
			bottom--;
		}else
		{
			for(int i = bottom; i >= top; i--)
				cout << input[i][left] << " ";
			left++;
		}

		direction = (direction + 1) % 4;
	}

	return;
}

int main(void)
{
	int arr[] = {1,2,3,4};

	vector<vector<int>> input(4, vector<int>(arr, arr+4));

	printSpiral(input);

	cout << endl;

	return 0;
}