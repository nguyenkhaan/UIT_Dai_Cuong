//Binary_search 2: Tim kiem nhi phan chuoi 
#include <bits/stdc++.h>
using namespace std;
#define An UwU
#define       all(x)    x.begin(), x.end()
#define console(a) cout<<a<<endl
int d = 0; 
int binary_search(int l, int r, vector<string> &a, string &x) 
{
    while (l <= r) 
    {
        ++d; 
        int m = (l + r) / 2; 
        if (a[m] > x) r = m - 1; 
        else if (a[m] < x) l = m + 1; 
        else return m; 
    }
    return -1; 
}
void solve()
{ 
    int n; 
    cin >> n;   
    vector<string> a(n); 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    string x; 
    cin >> x; 
    int ans = binary_search(0, n - 1, a, x); 
    if (ans == -1) console(-1); 
    else {
        console(ans); 
        console(d); 
    }
}
signed main()
{

    solve(); 
}