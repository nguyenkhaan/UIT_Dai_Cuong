//Cycle Detection - Su dung MAP 
#include <bits/stdc++.h>
using namespace std; 
int increase(vector<int> a, int &n, map<int,int> mp) 
{
    vector<int> b(a.begin(), a.end()); 
    int ans = 0; 
    sort(b.begin(), b.end()); 
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
        int idx = mp[b[i]]; 
        swap(a[i], a[idx]); 
        mp[a[i]] = i; 
        mp[a[idx]] = idx; 
        ++ans; 
    }
    return ans; 
}
int decrease(vector<int> a, int &n, map<int,int> mp) 
{
    vector<int> b(a.begin(), a.end()); 
    int ans = 0; 
    sort(b.begin(), b.end(), greater<int>()); 
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
        // cout << a[i] << ' ' << b[i] << endl; 
        int idx = mp[b[i]]; 
        swap(a[i], a[idx]); 
        mp[a[i]] = i; 
        mp[a[idx]] = idx; 
        ++ans; 
    }
    return ans; 
}
void solve() 
{
    int n; 
    cin >> n; 
    vector<int> a(n); 
    map<int, int> mp; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        mp[a[i]] = i; 
    } 
    int ans1 = increase(a, n, mp); 
    int ans2 = decrease(a, n, mp); 
    cout << min(ans1, ans2); 
}
signed main() 
{
    solve(); 
}
