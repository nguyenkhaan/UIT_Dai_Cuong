#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
#define An UwU
void solve() 
{
    int n; 
    cin >> n; 
    vector<int> a(n); 
    for (auto &i : a) cin >> i; 
    if (n == 2) {
        cout << abs(a[0] - a[1]) << endl; 
        return;
    }
    if (n == 3) {
        sort(a.begin(), a.end()); 
        cout << a[n - 1] - a[0]<< endl; 
        return; 
    } 
    sort(a.begin(), a.end()); 
    cout << a[n - 1] - a[0] + a[n - 2] - a[1] << endl; 
} 
signed main() 
{
    int t; 
    cin >> t; 
    while (t--) solve(); 
}