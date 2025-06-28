//https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=linked-list
#include <bits/stdc++.h>
using namespace std; 
struct ListNode 
{
    int data; 
    ListNode *next = NULL; 
}; 
ListNode* makeNode(int x) {
    ListNode *p = new ListNode; 
    p->data = x; 
    return p; 
}
void addTail(ListNode* &head, int x) 
{
    if (head == NULL) {
        head = makeNode(x); 
        return; 
    }  
    ListNode* temp_head = head; 
    while (temp_head->next) temp_head = temp_head->next; 
    temp_head->next = makeNode(x); 
} 
int len(ListNode* head) 
{
    int d = 0; 
    while (head) {
        ++d; 
        head = head->next; 
    } 
    return d; 
} 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = NULL; 
    int d1 = len(l1); 
    int d2 = len(l2); 
    for (int i = 1; i <= max(d1 , d2) - d1; ++i) addTail(l1 , 0); 
    for (int i = 1; i <= max(d1 , d2) - d2; ++i) addTail(l2, 0); 
    ListNode *h1 = l1; 
    ListNode *h2 = l2; 
    int t = 0; 
    while (h1 && h2) 
    {
        int s = h1->data + h2->data + t; 
        t = 0; 
        if (s >= 10) {
            t = s/10; 
            s %= 10; 
        } 
        addTail(ans , s); 
        h1 = h1->next; h2 = h2->next; 
    } 
    if (t != 0) addTail(ans , t); 
    return ans; 
}  
void solve() 
{
    ListNode *l1 = NULL; 
    ListNode *l2 = NULL; 
    addTail(l1 , 2); addTail(l1 , 4); addTail(l1, 3); 
    addTail(l2, 5); addTail(l2, 6); addTail(l2, 4); 
    ListNode *ans = addTwoNumbers(l1 , l2); 
    ListNode* head = ans; 
    while (head) {
        cout << head->data << ' '; 
        head = head->next; 
    }
}
signed main() 
{
    solve(); 
}