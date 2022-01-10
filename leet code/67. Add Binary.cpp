#include <iostream>
// https://leetcode.com/problems/add-binary/
using namespace std;

char sum(char a, char b, char& carr)
{
	char output = (char)(a + b + carr - 96);
	if(output=='0' || output == '1') 
	{
		carr = '0';
		return output;
	}
	else if(output == '2')
	{
		carr = '1';
		return '0';
	}
	else
	{
		carr = '1';
		return '1';
	}
}

string Fun(string a , string b)
{
	char carr = '0';
	string output="";
	int size = (a.length() > b.length()) ? a.length() : b.length();
	for (int i=0 ;i<size;i++)
	{
		if ((i < a.length()) && (i < b.length()))
		{
			output = sum(a[a.length()-i-1] , b[b.length() - i - 1] , carr)+ output;
		}
		else if((i < a.length()))
		{
			output = sum(a[a.length() - i - 1], '0', carr) + output;
		}
		else
		{
			output = sum('0', b[b.length() - i - 1], carr) + output;
		}

	}
	if (carr == '1') { return '1' + output; }
	return output;
}

int main()
{
	cout << Fun("00001","11110");

}