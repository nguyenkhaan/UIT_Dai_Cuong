
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};
int len = 0; 
NODE *makeNode(int x) 
{
    NODE *p = new NODE; 
    p->info = x; 
    p->pNext = NULL; 
    return p; 
}
void addTail(LIST &L, int x) 
{
    if (L.pHead == NULL) {
        L.pHead = L.pTail = makeNode(x); 
        return; 
    }  
    NODE *p = makeNode(x); 
    L.pTail->pNext = p; 
    L.pTail = p; 
}
void CreateEmptyList(LIST &L) 
{
    L.pHead = L.pTail = NULL; 
} 

void CreateList(LIST &L) 
{
    int x; cin >> x; 
    while (x != -1) 
    {
        addTail(L, x); 
        ++len; 
        cin >> x; 
    }
}
int searchXget_nth_node_from_tail(NODE *head, int k) 
{
    int index = len - k + 1; 
    if (index > len || index < 1) {
        // cout << -1; 
        return -1; 
    } 
    NODE *p = head; 
    for (int i = 0; i < index - 1; ++i) p = p->pNext; 
    return p->info; 
}
int main() {
    LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	std::cin >> k;
	cout << searchXget_nth_node_from_tail(L.pHead, k);

    return 0;
}
