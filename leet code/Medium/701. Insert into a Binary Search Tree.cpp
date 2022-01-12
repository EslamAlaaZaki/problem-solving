// https://leetcode.com/problems/insert-into-a-binary-search-tree
// Difficulty : Medium
// Runtime: 139 ms, faster than 20.35% of C++ online submissions for Insert into a Binary Search Tree.
// Memory Usage: 56.8 MB, less than 80.92% of C++ online submissions for Insert into a Binary Search Tree.

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

TreeNode* insertIntoBST(TreeNode* root, int val) {

    if (root == nullptr) return new TreeNode(val);
    if(root->val>val)
    {
        if (root->left==nullptr)
        {
             
            root->left= new TreeNode(val);
            return root;
            
        }
        else
        {
            insertIntoBST(root->left, val);
            return root;
        }
    }
    else
    {
        if (root->right == nullptr)
        {

            root->right = new TreeNode(val);
            return root;

        }
        else
        {
            insertIntoBST(root->right, val);
            return root;
        }

    }

}