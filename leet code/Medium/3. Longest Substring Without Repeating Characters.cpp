// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty : Medium
// Runtime: 12 ms, faster than 73.84% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 8.9 MB, less than 37.54% of C++ online submissions for Longest Substring Without Repeating Characters.

#include <iostream>

using namespace std;

 #include <unordered_set> 
 /*
 int lengthOfLongestSubstring(string s)
 {
	 unordered_set<char> temp;
	 int count = 0;
	 int out=0;
	 int beg = 0;
	 for(int i=0;i<s.length();i++)
	 {
		 if (temp.find(s[i]) == temp.end()) 
		 {
			 temp.insert(s[i]);
			 if (count == 0) beg = i;
			 count++; 
			 
		 }
		 else
		 {
			 temp.clear();
			 out=(count>out)?count:out;
			 i = beg;
			 count = 0;
		 }
	 }
	 return (count > out) ? count : out;
	 
 }*/

 int lengthOfLongestSubstring(string s)
 {
	 unordered_set<char> temp;
	 int out = 0;
	 int beg = 0;
	 for (int i = 0; i < s.length(); i++)
	 {
		 if (temp.find(s[i]) == temp.end())
		 {
			 temp.insert(s[i]);

		 }
		 else
		 {
			 out = ((i-beg) > out) ? (i - beg) : out;
			 for(int j=beg;j<i;j++)
			 {

				 
				 if (s[j] == s[i])
				 {
					 beg = j + 1;
					 break;
				 }
				 temp.erase(s[j]);
			     
			 }
			 
			 
		 }
	 }
	 return out = (( s.length()- beg) > out) ? ( s.length()-beg ) : out;
 }
 
int main()
{
	cout << lengthOfLongestSubstring("pwwkew");


}