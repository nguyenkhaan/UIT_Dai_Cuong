#include <bits/stdc++.h>
using namespace std; 
#define int long long 
const int N = 10000; 
void solve() 
{
    int n; 
    cin >> n; 
    vector<pair<int,bool>> a; 
    for (int i = 0; i < n; ++i) 
    {
        int x,y; 
        cin >> x >> y; 
        a.push_back({x , 1}); 
        a.push_back({x + y , 0}); 
    }
    int user = 0; 
    sort(a.begin() , a.end()); 
    vector<int> b; 
    for (int i = 0; i < a.size(); ++i) 
    {
        if (a[i].second == 1) ++user; 
        else --user; 
        b.push_back(user); 
    } 
  //  for (int i = 0; i < b.size(); ++i) cout << a[i].first <<' '; 
    vector<int> D(n + 1 , 0); 
    int l_p = 0; 
    for (int i = 1; i < b.size(); ++i) if (b[i] != b[l_p]) {
        D[b[l_p]] += a[i].first - a[l_p].first; 
        l_p = i; 
    }
    for (int i = 1; i <= n; ++i) cout << D[i] <<' '; 
}
signed main() 
{
    solve(); 
}