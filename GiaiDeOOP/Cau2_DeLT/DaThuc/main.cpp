/**Viet chuong trinh nhap vao hai da thuc. Thuc hien cai dat >>, <<, +, - hai da thuc vua nhap vao */ 
#include <bits/stdc++.h>
using namespace std; 
class DaThuc 
{
    protected: 
        int n; //Bac cua da thuc 
        vector<int> a; 
    public: 
        friend istream& operator >> (istream&, DaThuc&); 
        friend ostream& operator << (ostream&, DaThuc); 
        friend DaThuc operator +(DaThuc&, DaThuc&); 
}; 
istream& operator >> (istream& in, DaThuc &a) 
{
    cout << "Nhap bac cua da thuc: "; cin >> a.n; 
    a.a.resize(a.n + 1, 0); 
    int q;  
    cout << "Nhap so luong don thuc muon nhap vao: "; 
    cin >> q; 
    while (q--) 
    {
        int bac, heso; 
        cin >> heso >> bac; 
        if (bac <= a.n) a.a[bac] += heso; 
    }
    return in; 
} 
ostream& operator<<(ostream& out, DaThuc dt) 
{
    bool isFirst = 1; 
    for (int i = dt.n; i >= 0; --i) 
    {
        int hs = dt.a[i]; 
        if (hs == 0) continue; 
        if (isFirst) {
            if (hs < 0) out << "-"; 
            isFirst = 0; 
        } 
        else out << ((hs > 0) ? "+" : "-"); 
        int abs_hs = abs(hs); 
        if (i == 0) out << abs_hs; 
        else if (i == 1) out << abs_hs << "*x"; 
        else out << abs_hs << "*x^" << i; 
    }
    if (isFirst) out << "0"; 
    return out; 
}
DaThuc operator +(DaThuc &a, DaThuc &b) 
{
    int n = max(a.n , b.n); 
    DaThuc c; 
    c.n = n; 
    c.a.resize(n + 1); 
    for (int i = min(a.n , b.n); i >= 0; --i) c.a[i] = a.a[i] + b.a[i];  
    for (int i = min(a.n , b.n) + 1; i <= a.n; ++i) c.a[i] += a.a[i]; 
    for (int i = min(a.n, b.n) + 1; i <= b.n; ++i) c.a[i] += b.a[i]; 
    return c;     
}
int main() 
{
    DaThuc a; 
    DaThuc b; 
    cout << "\nNHAP GIA TRI DA THUC THU 1: \n"; cin >> a; 
    cout << "\nNHAP GIA TRI DA THUC THU 2: \n"; cin >> b; 
    cout << "\nDA THUC THU 1: " << a; 
    cout << "\nDA THUC THU 2: " << b; 
    cout << "\nKET QUA THUC HIEN PHEP CONG HAI DA THUC: " << a + b;
}