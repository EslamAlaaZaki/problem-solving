// https://leetcode.com/problems/string-to-integer-atoi
// Difficulty : Medium
// Runtime: 4 ms, faster than 61.22% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.9 MB, less than 89.15% of C++ online submissions for String to Integer (atoi).

#include <iostream>

using namespace std;



int char_to_int(char& a)
{
	switch (a)
	{
		case '0':return 0;
		case '1':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
		default:return -1;
	}

}

bool is_digit(char &a)
{
	return (a == '0') || (a == '1') || (a == '2') || (a == '3') || (a == '4') || (a == '5') || (a == '6') || (a == '7') || (a == '8') || (a == '9');
}

int max_or_min_int(int positive)
{
	
	if (positive == 1)return 2147483647;
	else return  -2147483648;
}

string parse_num(string& s, int& is_positive)
{
	int beg = 0;
	int end = s.length() - 1;
	int size = s.length();

	for(int i=0; i< size;i++)
	{
		beg = i;
		if (s[i] != ' ') break;
	}

	if (!is_digit(s[beg])&&((s[beg] =='-')|| (s[beg]=='+')))
	{
		if(s[beg] == '-')is_positive = -1;
		beg++;
	}

	for (int i = beg; i < size; i++)
	{
		beg = i;
		if (s[i] != '0') break;
	}
	
	if (!is_digit(s[beg]))return "";
	
	for (int i = beg; i < size; i++)
	{
		if (is_digit(s[i])) end = i;
		else break;
	}

	return s.substr(beg,end-beg+1);
}

int myAtoi(string s) {
	
	int max_int = 2147483647;
	int positive = 1;
	int output = 0;
	long int multiply = 1;
	long int temp;
	s = parse_num(s, positive);
	if (s == "")return 0;
	if(s.length()>10)
	{
		return max_or_min_int(positive);
	}
	if(s.length()==10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 9)
			{
				if(positive==1)
				{
					if (7 <= char_to_int(s[i]))return max_or_min_int(positive);
				}
				else
				{
					if (8 <= char_to_int(s[i]))return max_or_min_int(positive);
				}

			  break;
			}

			temp = (1000000000 / multiply);
			temp = max_int / temp;
			temp = temp % 10;
			if (temp < char_to_int(s[i]))return max_or_min_int(positive);
			else if (temp > char_to_int(s[i])) break;
			multiply *= 10;
			
		}

		multiply = 1;
	}

	for (int i = s.length()-1; i>=0; i--)
	{
		output = output + (char_to_int(s[i]) * multiply);
		multiply *= 10;
	}
	return positive * output;

}

int main()
{
	
	string s = "  0000000000012345678jhiugiwudhbh";
	cout << myAtoi(s)<< endl;
	


}
