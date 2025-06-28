//Cai dat thuat toan merge sort
#include <bits/stdc++.h>
using namespace std; 
struct Date 
{
    int day,month,year; 
    void input() {
        cin >> day >> month >> year; 
    }
}; 
struct Hocsinh 
{
    string name; 
    int id; 
    double score; 
    char gender; 
    Date date; 
    double toan,li,hoa; 
    void input() 
    {
        cin >> id; cin.ignore(); 
        getline(cin, name); 
        date.input(); 
        cin >> gender; 
        cin >> toan >> li >> hoa; 
    }
}; 
void merge(vector<Hocsinh> &a, int l, int mid, int r) 
{
    int i = l,j = mid + 1; 
    vector<Hocsinh> b; 
    while (i <= l && j <= r) 
    {

    }
}
void merge_sort(vector<Hocsinh> &a, int l, int r) 
{
    if (l < r) 
    {
        int mid = (l + r) / 2; 
        merge_sort(a, l, mid); 
        merge_sort(a, mid + 1, r);
        merge(a,l,mid,r); 
    }
}
void solve() 
{
    int n; 
    cin >> n; 
    vector<Hocsinh> a(n); 
    for (int i = 0; i < n; ++i) a[i].input(); 
    merge_sort(a,0,n - 1); 
} 
signed main() 
{
    solve(); 
}