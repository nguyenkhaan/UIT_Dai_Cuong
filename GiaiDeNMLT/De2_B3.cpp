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
    int n; 
    cin >> n; 
    vector<int> a(n + 1 , 0); 
    vector<int> p(n + 1, 0); 
    p[0] = 0; 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        p[i] = p[i - 1] + a[i]; //prefix sum 
    }
    int ans = 0; 
    for (int i = 1; i <= n; ++i) 
    {
        int temp = p[n] - p[i]; 
        ans += ((temp % MOD) * (a[i] % MOD)) % MOD; //Dong du
    }
    cout << ans % MOD; 
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