//Giao dich
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 1e12; 
const int MOD = 1e9 + 7;
const int INF = 1e9; 
int binary_search(int l, int r, vector<int> &a, vector<int> &b) 
{
    int ans = -1; 
    while (l <= r) 
    {
        int mi = (l + r) / 2; 
        int cnt1 = 0 , cnt2 = 0; 
        for (int i = 0; i < a.size(); ++i) if (mi >= a[i]) ++cnt1; 
        for (int i = 0; i < b.size(); ++i) if (mi <= b[i]) ++cnt2; 
        if (cnt1 >= cnt2) {
            ans = mi; 
            r = mi - 1; 
        } else l = mi + 1; 
    }
    return ans; 
}
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int m,n; 
    cin >> n >> m; 
    vector<int> a(n , 0); 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    vector<int> b(m , 0); 
    for (int i =0; i < m; ++i) cin >> b[i]; 
    int ans = binary_search(0,maxn,a,b); 
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