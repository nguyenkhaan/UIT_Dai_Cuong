
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
bool search(HASHTABLE &h, int key) 
{
    for (int i = 0; i < h.M; ++i) 
    {
        int index = HF_LinearProbing(h , i , key); 
        if (h.table[index].key == key && h.table[index].flag == OCCUPIED) return 1; 
        else if (h.table[index].flag == EMPTY) return 0; 
    } 
    return 0; 
}
void insert(HASHTABLE &h, int key) 
{
    if (search(h , key)) return; 
    for (int i = 0; i < h.M; ++i) 
    {
        int index = HF_LinearProbing(h , i , key); 
        
        if (h.table[index].flag != OCCUPIED) {
            h.table[index].flag = OCCUPIED; 
            h.table[index].key = key; 
            h.n++; 
            return; 
        }
    }
}
void remove(HASHTABLE &h, int key) 
{
    for (int i = 0; i < h.M; ++i) 
    {
        int index = HF_LinearProbing(h , key , i); 
        if (h.table[index].flag == OCCUPIED && h.table[index].key == key) {
            h.table[index].flag = DELETED; 
            h.n--; 
            return;
        }
        else if (h.table[index].flag == EMPTY) return; 
    }
}
void CreateHashTable(HASHTABLE &h) 
{
    cin >> h.M; 
    h.n = 0; 
    h.table = new NODE[h.M]; 
    for (int i = 0; i < h.M; ++i) h.table[i].flag = EMPTY; 
    int q; cin >> q; 
    while (q--) 
    {
        int a,b; cin >> a >> b; 
        if (a == 1 && (h.n + 1)* 10 <= h.M * 7)  
        {
            insert(h , b); 
        } 
        else {
            remove(h , b); 
        } 
    }
}
void Traverse(HASHTABLE &h) 
{
    for (int i = 0; i < h.M; ++i) 
    {
        cout << i << " --> "; 
        if (h.table[i].flag == EMPTY) cout << "EMPTY\n"; 
        else if (h.table[i].flag == DELETED) cout << "DELETED\n"; 
        else cout << h.table[i].key << endl; 
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
