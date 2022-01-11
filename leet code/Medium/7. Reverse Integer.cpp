// https://leetcode.com/problems/reverse-integer/
// Difficulty : Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
//Memory Usage: 6.1 MB, less than 7.32% of C++ online submissions for Reverse Integer.

#include <iostream>

using namespace std;
#include <vector>
 int reverse(int x) {

	 if (x == 0)return 0;
	 if(x== -2147483648)return 0;
	 
	 int max_int = 2147483647;
	 int int_size = 10;
	 vector<int> ar(int_size, 0);
	 int positive = 1;
	 int output = 0;
	 int end = int_size-1;
	 int beg = 0;
	 long int multiply = 1;
	 long int temp;


	 if (x < 0) { x *= -1; positive = -1; }

	 for (int i =0 ;i< int_size;i++)
	 {
		 ar[i] = x % 10;
		 x = x / 10;
		 if (x == 0)break;
	 }
	
	 if (ar[int_size - 1] != 0)
	 {
		 for (int i = beg; i <= end; i++)
		 {
			 temp = (1000000000 / multiply);
			 temp = max_int / temp;
			 temp = temp % 10;
			 if (temp < ar[i])return 0;
			 else if (temp > ar[i]) break;
			 multiply *= 10;

		 }

		 multiply = 1;
	 }


	 for (int i = 0; i < int_size; i++) 
	 {
		 if (ar[int_size - 1 - i] != 0) {
			 end = int_size - 1 - i;
			 break;
		 }

	 }
	 for (int i = 0; i < int_size; i++)
	 {
		 if (ar[i] != 0) {
			 beg = i;
			 break;
		 }

	 }


	 for (int i = end; i >= beg; i--)
	 {
		 output = output + (ar[i] * multiply);
		 multiply *= 10;
	 }

	 return positive*output;

 }

int main()
{
	
	cout <<reverse(-2147483412);

}
