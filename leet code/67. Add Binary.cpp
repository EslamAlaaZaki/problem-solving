
// https://leetcode.com/problems/add-binary/
#include <iostream>

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
	string * output;
	int size;
	if (a.length() > b.length()) 
	{
		size = a.length();
		output = &a;
	}
	else 
	{ 
		size = b.length();
		output = &b;
	}
	for (int i=0 ;i<size;i++)
	{
		if ((i < a.length()) && (i < b.length()))
		{
			(*output)[size-i-1] = sum(a[a.length()-i-1] , b[b.length() - i - 1] , carr);
		}
		else if((i < a.length()))
		{
			(*output)[size - i - 1] = sum(a[a.length() - i - 1], '0', carr) ;
		}
		else
		{
			(*output)[size - i - 1] = sum('0', b[b.length() - i - 1], carr) ;
		}

	}
	if (carr == '1') { return '1' + *output; }
	return *output;
}

int main()
{
	
	cout << Fun("11","1");

}
