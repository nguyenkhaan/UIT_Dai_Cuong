#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define An UwU
#define fast ios::sync_with_stdio(false), cin.tie(0)
#define all(x) x.begin(), x.end()
#define console(a) cout<<a<<endl
#define countt(a, k) upper_bound(a.begin(), a.end(), k) - a.begin()
#define For(a,b,c) for (a = b; a <= c; ++a)
#define square(a) 1 << a
#define upp(a) a *= 2 
#define dow(a) a /= 2 
#define cunique(a) a.erase(unique(a.begin(), a.end()), a.end())
template<typename T>
void compress(vector<T>& a)
{
    vector<T> b = a;
    sort(all(b));
    cunique(b);
    for (T& x : a)
        x = std::lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
const int N = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int n,m; 
    cin >> n >> m; 
    vector<int> a(n);  
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    map<int , int> mp; 
    for (int i = 0; i < n; ++i) mp[a[i] % m]++; 
    int mi = INF; 
    for (auto [x , y] : mp) if (y != 1) mi = min(mi , y - 1); 
    for (auto[x , y] : mp) if (mi == y- 1) cout << x << ' '; 
}
signed main()
{
    fast;
    solve(); 
}
/*
*   /\_/\
*   (=._.)
*   / > \>
*/