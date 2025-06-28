//https://leetcode.com/problems/rotate-list/?envType=problem-list-v2&envId=linked-list
#include <bits/stdc++.h>
using namespace std; 
struct ListNode 
{
    int val; 
    ListNode* next = NULL; 
}; 
ListNode *makeNode(int x) 
{
    ListNode *p = new ListNode; 
    p->val = x; 
    return p; 
} 
void addHead(ListNode* &head, int x)
{
    if (head == NULL) {
        head = makeNode(x); 
        return;  
    } 
    ListNode *p = makeNode(x); 
    p->next = head; 
    head = p; 
} 
void addTail(ListNode *&head, int x) 
{
    if (head == NULL) {
        head = makeNode(x); 
        return; 
    }  
    ListNode *temp_head = head; 
    while (temp_head->next) temp_head = temp_head->next; 
    temp_head->next = makeNode(x); 
}
int len(ListNode *head) 
{
    int d = 0; 
    while (head) {
        head = head->next; 
        ++d; 
    } 
    return d; 
}
ListNode* splitTail(ListNode* &head)   //Ham thuc hien tach node cuoi cua Linked list 
{
    if (head == NULL) return NULL; 
    if (head->next == NULL) {
        ListNode *p = head; 
        head = NULL; 
        return p; 
    }
    ListNode *t_head = head; 
    while (t_head->next->next) t_head = t_head->next; 
    ListNode *p = t_head->next; 
    p->next = NULL; 
    t_head->next = NULL; 
    return p; 
}
ListNode* rotateRight(ListNode* head, int k) {
    ListNode *ans = head; 
    int d = len(head); 
    k %= d; 
    if (k == 0) return ans; 
    queue<ListNode*> q; 
    for (int i = 1; i <= k; ++i) {
        ListNode *sp = splitTail(ans); 
        // cout << sp->val << ' '; 
        q.push(sp); 
    } 
    
    while (q.size()) 
    {
        ListNode* f = q.front(); q.pop(); 
        addHead(ans , f->val); 
    }  
    return ans; 
}
signed main() 
{
    ListNode *root = NULL; 
    int k = 2; 
    addTail(root, 1); addTail(root, 2); addTail(root, 3); addTail(root, 4); addTail(root, 5); 
    ListNode* ans = rotateRight(root, k); 
    while (ans) {
        cout << ans->val << ' '; 
        ans = ans->next; 
    }
}