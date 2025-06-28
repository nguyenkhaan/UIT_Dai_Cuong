#include <bits/stdc++.h>
using namespace std; 
struct ListNode 
{
    int val;  
    ListNode* next = NULL; 
}; 
ListNode* tail = NULL; 
ListNode* makeNode(int x) 
{
    ListNode *p = new ListNode; 
    p->val = x; 
    return p; 
}
void addTail(ListNode* &head, int x) 
{
    if (head == NULL) {
        head  = makeNode(x); 
        return; 
    } 
    ListNode *p = makeNode(x); 
    ListNode* temp_hea = head; 
    while (temp_hea->next) temp_hea = temp_hea->next; 
    temp_hea->next = p; 
}
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL; 
    ListNode* ans = NULL; 
    while (head) 
    {
        int k = head->val; 
        cout << k << endl; 
        int d = 1; 
        head = head->next;
        while (head && k == head->val) {
            ++d; 
            head = head->next; 
        }
        if (d == 1) addTail(ans , k); 
    }
    return ans; 
} 
signed main() 
{
    ListNode* head = nullptr; 
    addTail(head, 1); addTail(head , 2); addTail(head, 3); addTail(head, 3); 
    addTail(head, 4); addTail(head, 4); addTail(head, 5); 
    ListNode* ans = deleteDuplicates(head); 
    while (ans) {
        cout << ans->val << ' '; 
        ans = ans->next;
    }
}