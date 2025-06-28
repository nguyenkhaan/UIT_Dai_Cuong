
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* makeNode(int x) 
{
    TNODE *p = new TNODE; 
    p->key = x; 
    p->pLeft = p->pRight = NULL; 
    return p; 
}
void insert(TREE &T, int x) 
{
    if (!T) {
        T = makeNode(x); 
        return; 
    } 
    if (x > T->key) insert(T->pRight , x); 
    else if (x < T->key) insert(T->pLeft, x); 
    return; 
}
void CreateTree(TREE &T) 
{
    int x; cin >> x; 
    while (x != -1) {
        insert(T , x); 
        cin >> x; 
    }
}
int height(TREE T) 
{
    if (!T) return 0; 
    int a = 1 + height(T->pLeft); 
    int b = 1 + height(T->pRight); 
    return max(a , b); 
}
void PrintLevel(TREE T, int x, int level) 
{
    int h = height(T); 
    if (h == 0) return; 
    queue<TNODE*> q; 
    q.push(T);
    for (int i = 0; i < h; ++i) 
    {
        queue<TNODE*> sq; 
        while (q.size()) {
            TNODE *t = q.front(); q.pop(); 
            cout << t->key << ' '; 
            if (t->pLeft) sq.push(t->pLeft); 
            if (t->pRight) sq.push(t->pRight); 
        } 
        q = sq; 
        cout << endl; 
    }
}  

int main() {
	TNODE* T;
	int x, level=-1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}

