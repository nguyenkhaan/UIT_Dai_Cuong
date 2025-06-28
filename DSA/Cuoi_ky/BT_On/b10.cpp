
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
void PrintLevel(TREE T, int x, int &level) 
{
    level = -1; 
    if (T == NULL) return; 
    queue<TNODE*> q; 
    queue<TNODE*> sq; 
    int h = height(T); 
    q.push(T); 
    for (int i = 0; i < h; ++i) 
    {
        while (q.size()) {
            TNODE *k = q.front(); q.pop(); 
            if (k->key == x) {
                level = i; 
                return; 
            }
            if (k->pLeft) sq.push(k->pLeft); 
            if (k->pRight) sq.push(k->pRight); 
        } 
        q = sq; 
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

