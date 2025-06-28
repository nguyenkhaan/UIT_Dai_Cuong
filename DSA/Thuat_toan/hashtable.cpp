
#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
void insert(HASHTABLE &h, int x) 
{
    if ((1 + h.n) * 10 >= 7 * h.M) return; 
    for (int i = 0; i < h.M; ++i) 
    {
        int index = HF_LinearProbing(h , x , i); 
        if (h.table[index].key == x) return; 
        if (h.table[index].flag != OCCUPIED) {
            h.table[index].flag = OCCUPIED; 
            h.n++; 
            h.table[index].key = x; 
            return; 
        }
    }
}
void remove(HASHTABLE &h, int x) 
{
    for (int i = 0; i < h.M; ++i) 
    {
        int index = HF_LinearProbing(h , x , i); 
        // if (h.table[index].flag == EMPTY) return; 
        if (h.table[index].flag == OCCUPIED && h.table[index].key == x) {
            h.table[index].flag = DELETED; 
            h.n--; 
            return; 
        }
    }
}
void Traverse(HASHTABLE h) 
{
    for (int i = 0; i < h.M; ++i) 
    {
        if (h.table[i].flag == EMPTY) cout << "EMPTY" << endl; 
        else if (h.table[i].flag == DELETED) cout << "DELETED" << endl; 
        else cout << h.table[i].key << endl; 
    }
}
void CreateHashTable(HASHTABLE &h) 
{
    cin >> h.M; 
    int q; cin >> q; 
    h.n = 0;
    h.table = new NODE[10000]; 
    for (int i = 0; i < h.M; ++i) h.table[i].flag = EMPTY; 
    while (q--) 
    {
        int a,b;
        cin >> a >> b; 
        if (a == 1) insert(h, b); 
        else remove(h, b); 
    }
}

void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
