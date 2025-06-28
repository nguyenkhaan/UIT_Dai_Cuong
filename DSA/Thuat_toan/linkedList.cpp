//Cai dat cac thao tac voi linked list 
#include <bits/stdc++.h>
using namespace std; 
struct ListNode 
{
    int val; 
    ListNode* next = NULL; 
};  
struct List 
{
    ListNode* head = NULL; 
    ListNode* tail = NULL; 
}; 
ListNode* makeNode(int x) 
{
    ListNode* p = new ListNode; 
    p->val = x; 
    return p; 
} 
void addHead(List &L, int x) 
{
    if (L.head == NULL) 
    {
        L.head = L.tail = makeNode(x); 
        return; 
    } 
    ListNode *p = makeNode(x); 
    p->next = L.head; 
    L.head = p; 
} 
void addTail(List &L, int x) 
{
    if (L.head == NULL) 
    {
        L.head = L.tail = makeNode(x); 
        return; 
    } 
    ListNode *p = makeNode(x); 
    L.tail->next = p; 
    L.tail = p; 
} 
void removeNode(List &L, int k) 
{
    if (L.head == NULL) return; 
    ListNode *head = L.head; 
    while (head && head->val != k) head = head->next; 
    if (head == NULL) return; 
    if (head == L.tail) {
        ListNode *temp = L.head; 
        while (temp->next->next) temp = temp->next; 
        temp->next = NULL; 
        return; 
    } 
    ListNode *p = head->next; 
    head->val = head->next->val; 
    head->next = head->next->next; 
    delete p; 
}  
int main() 
{
    List l; 
    addTail(l, 1); 
    addTail(l, 2); 
    addTail(l, 3); 
    addTail(l, 4); 
    addTail(l, 5); 
    removeNode(l, 3); 
    removeNode(l, 5); 
    ListNode *head = l.head; 
    while (head) {
        cout << head->val << ' '; 
        head = head->next; 
    }
}
