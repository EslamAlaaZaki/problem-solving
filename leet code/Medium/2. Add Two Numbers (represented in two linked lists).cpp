// https://leetcode.com/problems/add-two-numbers/
// Difficulty : Medium
// Runtime: 12 ms, faster than 99.65% of C++ online submissions for Add Two Numbers.
//Memory Usage: 70.8 MB, less than 97.50% of C++ online submissions for Add Two Numbers.

#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 int sum(int a ,int b, int &carr)
 {
	 int out = (a + b + carr) % 10;
	 carr = (a + b + carr) / 10;
	 return out;
 }
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	 ListNode* a1 = l1;
	 ListNode* a2 = l2;
	 ListNode* out;
	 short n1=1;
	 short n2=1;
	 short size;
	 int carr = 0;
	 while (a1->next != nullptr) {n1++; a1 = a1->next;}
	 while (a2->next != nullptr) { n2++; a2 = a2->next; }
	 out = (n1 > n2) ? l1 : l2;
	 size= (n1 > n2) ? n1 : n2;
	 a1 = l1;
	 a2 = l2;
	 for (int i = 0; i < size; i++)
	 {
		 if ((i < n1) && (i < n2))
		 {
			 out->val= sum(a1->val, a2->val, carr);
			 if (i != (size - 1))
			 {
				 out = out->next;
				 a1 = a1->next;
				 a2 = a2->next;
			 }
		 }
		 else if ((i < n1))
		 {
			 out->val = sum(a1->val, 0, carr);
			 if (i != (size - 1))
			 {
				 out = out->next;
				 a1 = a1->next;
			 }
		 }
		 else
		 {
			 out->val = sum(0, a2->val, carr);
			 if (i != (size - 1))
			 {
				 out = out->next;
				 a2 = a2->next;
			 }
		 }
		
	 }
	 
	 if (carr >0) 
	 {
		 ListNode * temp =new ListNode(carr);
		 out->next = temp; 
	 }
	 out = (n1 > n2) ? l1 : l2;
	 return out;


 }
 
int main()
{
	/*
	[9,9,9,9,9,9,9]
	[9,9,9,9]
	*/
	ListNode A(9);
	ListNode B(9);
	ListNode C(9);
	ListNode D(9);
	ListNode E(9);
	ListNode F(9);
	ListNode G(9);
	A.next = &B;
	B.next = &C;
	C.next = &D;
	D.next = &E;
	E.next = &F;
	F.next = &G;

	ListNode H(9);
	ListNode I(9);
	ListNode J(9);
	ListNode K(9);
	H.next = &I;
	I.next = &J;
	J.next = &K;
	
	ListNode* out = addTwoNumbers(&A, &B);
	while (out->next !=nullptr)
	{
		cout << out->val;
		out = out->next;
	}
	


}
