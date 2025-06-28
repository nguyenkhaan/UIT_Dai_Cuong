//Cai dat cac thao tac voi cay BST 
//https://leetcode.com/problems/delete-node-in-a-bst/description/ (Xóa node)
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left = NULL; 
    TreeNode *right = NULL; 
}; 
void removeNode(TreeNode* &root, int k) 
{
    if (root == NULL) return; 
    if (root->val > k) removeNode(root->left , k); 
    else if (root->val < k) removeNode(root->right , k); 
    else 
    {
        if (root->left == NULL && root->right == NULL) {
            root = NULL; 
            return; 
        } 
        TreeNode *child = NULL; 
        TreeNode *parent = root; 
        if (root->right) 
        {
            child = root->right; 
            while (child->left) 
            { 
                parent = child; 
                child = child->left; 
            }
            swap(root->val , child->val); 
            if (root == parent) root->right = child->right; 
            else parent->left = child->right; 
        }
        else 
        {
            child = root->left; 
            while (child->right) 
            {
                parent = child; 
                child = child->right; 
            } 
            swap(root->val , child->val); 
            if (root == parent) root->left = child->left; 
            else parent->right = child->left; 
        }
    }
}
TreeNode* makeNode(int x) 
{
    TreeNode *p = new TreeNode; 
    p->val = x; 
    return p; 
} 
void insert(TreeNode* &root, int x) 
{
    if (root == NULL) {
        root = makeNode(x); 
        return; 
    }
    if (x > root->val) insert(root->right , x); 
    else if (x < root->val) insert(root->left , x); 
}
bool search(TreeNode* root, int x) 
{
    if (root == NULL) return false; 
    else if (x < root->val) return search(root->left , x); 
    else if (x > root->val) return search(root->right , x); 
    return true; 
}
int main() 
{

}