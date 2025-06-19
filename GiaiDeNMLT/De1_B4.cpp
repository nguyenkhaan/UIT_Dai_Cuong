//Cat banh 
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 361; 
const int MOD = 1e9 + 7;
const int INF = 1e9; 
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int n; 
    cin >> n; 
    vector<int> a(n); 
    for (auto &i : a) cin >> i; 
    int deg[maxn]; 
    memset(deg,0,sizeof(deg)); 
    deg[0] = 1; 
    deg[360] = 1; 
    int d = 0; 
    for (int i = 0; i < n; ++i) 
    {
        d += a[i]; 
        if (d > 360) d = d % 360; 
        deg[d] = 1; 
    }
    vector<int> calc; 
    for (int i = 0; i < maxn; ++i) 
    {
        if (deg[i] == 1) calc.push_back(i); 
    }
    int ans = 0; 
    for (int i = 1; i < calc.size(); ++i) ans = max(ans,calc[i] - calc[i-1]); 
    cout<<ans<<endl; 
}
signed main()
{
    fast;
    solve(); 
}
/*   /\_/\
*   ( = ._.) AC di, Meow 
*   / >  \>
*/