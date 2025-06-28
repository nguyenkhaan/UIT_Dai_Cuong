
#include <iostream>
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
int count(TREE T) 
{
    if (!T) return 0; 
    int k = 1 + count(T->pLeft) + count(T->pRight); 
    return k; 
}
void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T) 
{
    if (T) 
    {
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pLeft); 
        int L = count(T->pLeft); 
        int R = count(T->pRight); 
        if (L - R == 1) cout << T->key << ' '; 
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pRight); 
    }
}
void CreateTree(TREE &T) 
{
    int x; cin >> x; 
    while (x != -1) {
        insert(T , x); 
        cin >> x; 
    }
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

	return 0;
}
