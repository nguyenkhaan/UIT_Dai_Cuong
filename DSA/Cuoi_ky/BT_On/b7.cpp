
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}

void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}
int Height(TREE t) 
{
    if (!t) return 0; 
    int a = 1 + Height(t->pLeft); 
    int b = 1 + Height(t->pRight); 
    return max(a , b); 
}
bool IsCompleteBST(TREE T) 
{
    queue<TNODE*> q; 
    queue<TNODE*> sq; 
    string s = ""; 
    int h = Height(T); 
    if (T == NULL) return 1; 
    q.push(T); 
    for (int i = 0; i < h; ++i) 
    {
        int d = 0; 
        while (q.size()) 
        {
            TNODE *k = q.front(); q.pop(); 
            if (i == h - 1) {
                if (k) s += "1"; 
                else s += "0"; 
            }
            if (k != NULL) {
                ++d; 
                if (k->pLeft) sq.push(k->pLeft); 
                else sq.push(NULL); 
                if (k->pRight) sq.push(k->pRight); 
                else sq.push(NULL); 
            }
        }
        if (i != h - 1 && d != (1 << i)) {
            // cout << i << ' ' << d << endl; 
            // cout << 1; 
            return 0; 
        }
        else if (i == h - 1) 
        {
            if (d == (1 << i)) return 1; 
            // cout << s << endl; 
            for (int i = 1; i < s.size(); ++i) if (s[i- 1] == '0' && s[i] == '1') return 0;  
        }
        q = sq; 
        while (sq.size()) sq.pop(); 
    }
    return 1; 
}



int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsCompleteBST(T);

	return 0;
}
