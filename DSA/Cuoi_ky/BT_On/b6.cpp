
#include <iostream>

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
const int N = 10000; 
struct stack 
{
    TNODE* a[N]; 
    int top = -1; 
}; 
void Push(stack& st, TNODE* x) 
{
    st.a[++st.top] = x; 
}
void Pop(stack& st) 
{
    if (st.top == -1) return; 
    st.top--; 
}
const int UNDEFINED = 2384234324; 
TNODE* Top(stack &st) 
{
    if (st.top == -1) return NULL; 
    return st.a[st.top]; 
} 
bool isEmpty(stack &st) 
{
    return (st.top == -1); 
}
void PrintTree(TREE T) 
{
    stack st;
    if (T == NULL) {
        cout << "Empty Tree."; return; 
    }
    TNODE *root = T; 
    while (root|| !isEmpty(st)) 
    {
        while (root) {
            Push(st, root); 
            root = root->pLeft; 
        } 
        TNODE *k = Top(st); Pop(st); 
        cout << k->key << ' '; 
        root = k->pRight; 
    }
}
int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
