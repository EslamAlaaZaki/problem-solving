// https://leetcode.com/problems/container-with-most-water
// Difficulty : Medium
// Runtime: 894 ms, faster than 5.04% of C++ online submissions for Container With Most Water.
// Memory Usage: 59 MB, less than 79.71% of C++ online submissions for Container With Most Water.
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& height,int val , int index)
{
	int i = 0;
	int j = height.size() - 1;
	while((index-i)>(j-index))
	{
		if (height[i] >= val) return i;
		i++;
	}
	while ((index - i) < (j - index))
	{
		if (height[j] >= val) return j;
		j--;
	}

	while ((i!=index) && (j!=index))
	{
		if (height[j] >= val) return j;
		if (height[i] >= val) return i;
		if (i < index)i++;
		if (j > index) j--;
		

	}

	return index;
}

int maxArea(vector<int>& height) {
	int area ;
	int max_area = 0;
	int _height;
	int temp;
	int n = height.size();
	for (int i = 0; i < n; i++)
	{
		    temp = find(height, height[i], i);
			_height = ((temp - i) < 0) ? (i - temp) : (temp - i);
			area = height[i] * _height;
			max_area = (area > max_area) ? area : max_area;
		

	}
	return max_area;

}
int main()
{

	vector<int> height = { 2, 3, 4, 5, 18, 17, 6 };
	cout << maxArea(height);
	


}

