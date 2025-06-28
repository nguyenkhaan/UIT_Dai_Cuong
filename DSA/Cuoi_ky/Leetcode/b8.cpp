//https://leetcode.com/problems/recover-binary-search-tree/description/?envType=problem-list-v2&envId=binary-tree

//Idea: Duyet NLR roi sau do chinh sua la duoc 
#include <bits/stdc++.h>
using namespace std; 

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };     
class Solution {
    public:
    
    TreeNode* findMin(TreeNode* root) 
    { 
        if (root == NULL) return NULL; 
        int mi = root->val;  
        stack<TreeNode*> st; 
        TreeNode *ans = root; 
        while (root || st.size()) 
        {
            while (root != NULL) {
                st.push(root); 
                root = root->left; 
            } 
            TreeNode* curr = st.top(); st.pop(); 
            if (curr->val < mi) {
                mi = curr->val; 
                ans = curr; 
            }
            root = curr->right; 
        }
        return ans; 
    } 
    TreeNode* findMax(TreeNode* root) 
    {
        if (root == NULL) return NULL; 
        int ma = root->val; 
        TreeNode* ans = root; 
        stack<TreeNode*> st; 
        while (st.size() || root) 
        {
            while (root != NULL) {
                st.push(root); 
                root = root->left; 
            } 
            TreeNode *curr = st.top(); st.pop(); 
            if (curr->val > ma) {
                ma = curr->val; 
                ans = curr; 
            } 
            root = curr->right; 
        }
        return ans; 
    }
    void recoverTree(TreeNode* root) {
        if (root == NULL) return; 
        stack<TreeNode*> st; 
        TreeNode *curr = root; 
        st.push(root); 
        while (st.size()) 
        {
            TreeNode *u = st.top(); st.pop(); 
            TreeNode* a = findMax(u->left); 
            TreeNode* b = findMin(u->right);  
            if (a && b && a->val > b->val) {swap(a->val , b->val); return;}
            if (a && a->val > u->val) { swap(a->val, u->val); return; }
            if (b && b->val < u->val) { swap(b->val, u->val); return; } 
            if (u->right) st.push(u->right); 
            if (u->left) st.push(u->left); 
        }
        
    }
    };