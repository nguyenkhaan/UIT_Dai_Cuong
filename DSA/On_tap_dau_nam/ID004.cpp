#include <bits/stdc++.h>
using namespace std;
#define int long long
#define       all(x)    x.begin(), x.end()
#define An UwU
#define console(a) cout<<a<<endl
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
void solve()
{
    int n,k; 
    cin >> n >> k;  
    vector<int> a(n); 
    map<int,int> mp; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        mp[a[i]]++; 
    }
    int f_team = 0, s_team = 0; 
    for (auto [x,y] : mp)  
        if (y == 1) ++f_team; 
        else ++s_team; 
    if (2*k <= f_team + s_team + s_team && 2*k >= f_team + s_team) console("YES"); 
    else console("NO"); 
}
signed main()
{
    solve(); 
}
