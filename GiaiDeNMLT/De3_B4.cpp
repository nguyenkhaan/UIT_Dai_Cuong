//To mau
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
const int N = 100; 
char a[N][N];  
void inp(int &m, int &n, int &age) 
{
    cin >> m >> n >> age; 
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j) cin >> a[i][j]; 
} 
void Try(int i, int &n, string &s, vector<string> &choice) 
{
    if (i == n) {
        choice.push_back(s); 
        return; 
    }
    for (int j = 0; j <= 1; ++j) {
        s += (j + '0'); 
        if (i < n) Try(i + 1 , n , s , choice); 
        s.erase(s.size() - 1 , 1); 
    }
}
int count(string &row, string &col, int &m, int &n, int &age)  
{
    int d = 0; 
    for (int i = 0; i < m; ++i) if (row[i] == '0') {
        for (int j = 0; j < n; ++j) if (col[j] == '0') {
            if (a[i][j] == '#') ++d; 
        }
    }
    if (d == age) {
       // cout << row << ' '<< col << endl; 
        return 1; 
    }
    return 0; 
}
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    int m,n,age; 
    inp(m,n,age); 
    vector<string> row; 
    string s = ""; 
    Try(0,m,s,row); 
    s = ""; 
    vector<string> col; 
    Try(0,n,s,col); 
    int ans = 0; 
    
    for (auto r : row) {
        for (auto c : col) {
            ans += count(r,c,m,n,age); 
        }
    }
    cout << ans; 
    //  for (auto c : col) cout << c<<endl; 
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