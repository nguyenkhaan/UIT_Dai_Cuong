//https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=linked-list
#include <bits/stdc++.h>
using namespace std; 
struct ListNode 
{
    int val; 
    ListNode *next = NULL; 
}; 
ListNode* makeNode(int x) 
{
    ListNode *p = new ListNode; 
    p->val = x; 
    return p;  
} 
void addTail(ListNode* &head, int x) 
{
    if (head == NULL) {
        head = makeNode(x); 
        return; 
    } 
    ListNode *t_head = head; 
    while (t_head->next) t_head = t_head->next; 
    ListNode *p = makeNode(x); 
    t_head->next = p; 
} 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = NULL; 
    ListNode *l1 = list1; 
    ListNode *l2 = list2; 
    while (l1 && l2) 
    {
        if (l1->val <= l2->val) {
            addTail(ans , l1->val); 
            l1 = l1->next;
        } 
        else {
            addTail(ans , l2->val); 
            l2 = l2->next; 
        }
    }
    while (l1) {
        addTail(ans , l1->val); 
        l1 = l1->next; 
    } 
    while (l2) {
        addTail(ans , l2->val); 
        l2 = l2->next; 
    } 
    return ans; 
} 
signed main() 
{
    ListNode *l1 = NULL; 
    ListNode *l2 = NULL; 
    addTail(l1,1); addTail(l1 , 2); addTail(l1 , 4); 
    addTail(l2, 1); addTail(l2 , 3); addTail(l2 , 4);  
    ListNode* ans = mergeTwoLists(l1 , l2); 
    while (ans) {
        cout << ans->val << ' '; 
        ans = ans->next; 
    }
}
