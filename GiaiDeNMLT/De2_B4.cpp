#include <bits/stdc++.h>
using namespace std;
#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
int divisor(int x) 
{
    int d = 0; 
    for (int i = 1; i*i <= x; ++i) if (x % i == 0) {
        if (i == x / i) ++d; 
        else d += 2; 
    }
    return d; 
}
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int n; 
    cin >> n; 
    int ans = 0; 
    vector<int> a(n + 1, 0); 
    for (int u = 1; u <= n - 1; ++u) 
    {
        int v = n - u; 
        if (a[u] == 0) a[u] = divisor(u); 
        if (a[v] == 0) a[v] = divisor(v); 
        ans += (a[u] * a[v]); 
    }
    cout << ans; 
}
signed main()
{
    fast;
    solve(); 

}
/*   /\_/\
*   (= ._.)
*   / >  \>
*/