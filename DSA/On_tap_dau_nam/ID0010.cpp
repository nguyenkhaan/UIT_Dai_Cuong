#include <bits/stdc++.h>
using namespace std; 
int n,x,y; //5-> (5/2) -> (6/2 af 6/2 - 1)
#define int long long 
void make_array(vector<long double> &a, int l, int r, int x = -1) 
{  
    if (l >= r - 1|| l < 0 || r < 0) return; 
    int len = (r - l + 1); 
    if (len & 1) 
    {
        int m = (l + r) / 2; 
        a[m] = (a[r]/2.0 + a[l]/2.0); 
        make_array(a, l, m); 
        make_array(a, m, r); 
    } 
    else {
        int m = (l + r) / 2; 
        a[m] = a[m + 1] = (a[r]/2.0 + a[l]/2.0); 
        make_array(a, l, m); 
        make_array(a, m + 1, r); 
    }
}
void solve() 
{
    cin >> n >> x >> y; 
    vector<long double> a(n); 
    a[0] = x; 
    a[n - 1] = y; 
    if (n == 2) {
        cout << a[0] << '\n' << a[n - 1]; 
        return; 
    }
    make_array(a, 0, n - 1); 
    for (int i  = 0; i < n; ++i) cout << setprecision(16) << a[i] << endl; 
} 
signed main() 
{
    solve(); 
}