#include <iostream>
#include <cmath>

using namespace std;
struct point 
{
    double a, b , c; 
    void input() {
        cin >> a >> b >> c; 
    }
}; 
struct node 
{
    point data; 
    node *next = NULL; 
}; 
struct list 
{
    node *head = NULL; 
    node *tail = NULL; 
}; 
node *makeNode(point x) {
    node *p = new node; 
    p->data = x; 
    return p; 
} 
void addTail(list &l, point x) 
{
    if (l.head == nullptr) {
        l.head = l.tail = makeNode(x); 
        return; 
    } 
    node *p = makeNode(x); 
    l.tail->next = p; 
    l.tail = p; 
}
int n,m; 
void createList(list &l) 
{
    cin >> n; 
    for (int i = 0; i < n; ++i) 
    {
        point x; x.input(); 
        addTail(l, x); 
    }
}
int Find(list &l, point x) 
{
    node *head = l.head; 
    for (int i = 0; i < n; ++i) 
    {
        point k = head->data; 
        if (k.a == x.a && k.b == x.b && k.c == x.c) return i; 
        head = head->next; 
    }
    return -1; 
}
void run() 
{ 
    list l; 
    createList(l); 
    cin >> m; 
    for (int i = 0; i < m; ++i) 
    { 
        point x; x.input(); 
        int ans = Find(l, x); 
        if (ans == -1) cout << "KHONG" << endl; 
        else cout << ans << endl; 
    }
}
int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}


