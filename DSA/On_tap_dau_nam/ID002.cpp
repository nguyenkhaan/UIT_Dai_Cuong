#include <bits/stdc++.h>
using namespace std;
#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
#define console(a) cout<<a<<endl
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int n,x; 
    cin >> n >> x;  
    vector<int> a(n); 
    for (auto &i : a) cin >> i; 
    sort(all(a)); 
    int l = 0, r = n - 1; 
    int ans = 0;  
    while (l < r) 
    {
        if (a[l] + a[r] <= x) {
            // cout << a[l] << ' ' << a[r] << endl; 
            ans = max(ans, a[l] + a[r]); 
            ++l; 
        }
        else if (a[l] + a[r] > x) --r; 
    }
    console(ans); 
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