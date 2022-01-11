// https://leetcode.com/problems/zigzag-conversion/
// Difficulty : Medium
//Runtime: 71 ms, faster than 10.31% of C++ online submissions for Zigzag Conversion.
//Memory Usage: 51.3 MB, less than 5.98% of C++ online submissions for Zigzag Conversion.

#include <iostream>

using namespace std;


 string convert(string s, int numRows) {

	 if (numRows == 1)return s;

	 vector<string>A(numRows, "");
	 int s_len = s.length();
	 string out = "";
	 int index = 0;
	 bool increas = true;
	 for (int i = 0; i <s_len ; i++)
	 {
		 A[index % numRows]= A[index % numRows]+s[i];
		 if (increas)index++;
		 else index--;
		 if (index == numRows) 
		 {
			 increas = !increas; 
			 index=index-2;
		 }
		 if(index == -1)
		 {
			 increas = !increas;
			 index = index + 2;
		 }
	 }

	 for (int i = 0; i < numRows; i++) out = out + A[i];
	 return out;
 }
 
int main()
{
	
	cout << convert("PAYPALISHIRING",4);

}
