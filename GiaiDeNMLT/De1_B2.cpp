//Mua qua
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
    vector<int> a(n); 
    map<int,int> mp; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        mp[a[i]]++;
    } 
    int total = n*(n - 1)*(n - 2) / 6; 
    int k = 0; 
    for (auto [x,y] : mp) {
        if (y >= 2) k += y*(y - 1)*(n - y) / 2; 
        if (y >= 3) k += y*(y - 1) *(y - 2) / 6; 
    }
    cout << total - k; 
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