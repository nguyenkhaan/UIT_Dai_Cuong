#include <bits/stdc++.h>
using namespace std;
#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    const int N = 100; 
    int m,n; 
    cin >> m >> n;  
    int a[N][N];
    int mi = 1e15; 
    int ans = 0; 
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j) cin >> a[i][j]; 
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j) mi = min(mi , a[i][j]); 
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j) ans += (a[i][j] - mi); 
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