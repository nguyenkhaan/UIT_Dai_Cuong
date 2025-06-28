
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
NODE* SeparateHead(LIST &);
void Merge_Partition(LIST &, LIST &, LIST&);
void Merge_2_Sorted_LL_decending(LIST&, LIST&, LIST&);
void mergesort_decending(LIST &);
void SelectionSort_Decending(LIST &);
void Decending(LIST &);
int main() {
    LIST L;

    int n;
    cin >> n ;
    NhapDS(L, n);

    Decending(L);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}
NODE* CreateNode(SINHVIEN x) {
	NODE* p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void CreateEmptyList(LIST &L){
    L.pHead=L.pTail=NULL;
}
void AddTail(LIST& l, NODE* p){
	if (l.pHead == NULL)	{
		l.pHead = l.pTail = p;
		return;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}
void NhapDS(LIST &L, int n) {
    SINHVIEN sv;
    CreateEmptyList(L);
    for(int i=0; i<n; i++) {
        NhapSinhVien(sv);
        AddTail(L, CreateNode(sv));
    }
}
void XuatDS(LIST L) {
    if(L.pHead==NULL) {cout << "Empty List."; return;}
	NODE* p = L.pHead;
    while (p) {
        XuatSinhVien(p->key);
        cout << endl;
        p = p->pNext;
    }
}
void Decending(LIST &L) 
{
    if (L.pHead == NULL) return; 
    for (NODE *i = L.pHead; i; i = i->pNext) {
        for (NODE *j = i->pNext; j ; j = j ->pNext) if (i->key.MASV <= j->key.MASV) {
            SINHVIEN t = i->key; 
            i->key = j->key; 
            j->key = t; 
        }
    }
}
