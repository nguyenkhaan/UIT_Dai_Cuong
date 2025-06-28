//Wall - lớp cô thương 
#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
#define An UwU
#define all(a) a.begin(), a.end() 
int binary_search(int l, int r, vector<int> &a, vector<int> &b) 
{
    int ans = -1; 
    while (l <= r) 
    {
        int mi = (l + r) / 2; 
        int i = 0, j = 0; 
        vector<int> c(all(a)); 
        while (i < c.size() && j < b.size()) {
            if (c[i] >= mi) {
                ++i; 
                continue;
            }
            while (c[i] + b[j] < mi && j < b.size()) ++j; 
            if (j >= b.size()) break; 
            c[i] += b[j]; 
            ++i;   ++j; 
        }
        bool ok = 1, isq = 0; 
        for (int t = 0; t < c.size(); ++t) {
            ok &= (c[t] >= mi);
            if (c[t] == mi) isq = 1; 
        } 
        if (ok) {
            ans = max(ans, mi); 
            l = mi + 1; 
        }
        else r = mi - 1; 
    }
    return ans; 
}
void solve() 
{
    int n,m; 
    cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    cin >> m; 
    vector<int> b(m); 
    for (int i = 0; i < m; ++i) cin >> b[i]; 
    const int N = 1e15; 
    int ans = binary_search(0, N, a, b); 
    int d = 0; 
    for (int i = 0; i < n; ++i) if (a[i] < ans) ++d; 
    cout << ans << ' ' << d << endl; 
    int j = 0; 
    for (int i = 0; i < n; ++i) if (a[i] < ans) {
        int pos1 = i + 1; 
        while (j < b.size() && b[j] + a[i] < ans) ++j; 
        int pos2 = (j + 1); 
        cout << pos1 << ' ' << pos2 << endl; 
        ++j; 
    }
}
signed main() 
{
    solve(); 
}