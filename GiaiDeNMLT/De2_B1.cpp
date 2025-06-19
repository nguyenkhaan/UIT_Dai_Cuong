//Xoa dong cot tu ma tran A de thu duoc ma tran B
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int N = 11; 
const int MOD = 1e9 + 7;
const int INF = 1e9; 
int m,n,h,k; 
int a[N][N]; 
int b[N][N]; 
void inp(int a[][N], int &m, int &n) 
{
    cin >> m >> n; 
    for (int i = 0; i < m; ++i)  
        for (int j = 0; j < n; ++j) cin >> a[i][j]; 
}
int count(string &s) 
{
    int d = 0; 
    for (int i = 0; i < s.size(); ++i) if (s[i] == '1') ++d; 
    return d; 
}
void Try(int i, int &n, int &require, string &s, vector<string> &choice) 
{
    if (i == n) {
        if (count(s) == require) choice.push_back(s); 
        return; 
    }
    for (int j = 0; j <= 1; ++j) 
    {
        s += (j + '0'); 
        if (i < n) Try(i + 1, n , require ,s , choice); 
        s.erase(s.size() - 1, 1);
    }
}
bool ok(int sub[][N]) 
{
    for (int i = 0; i < h; ++i) 
        for (int j = 0; j < k; ++j) if (b[i][j] != sub[i][j]) return 0; 
    return 1; 
}
bool make_submatrix(int sub[][N], string &row, string &col) 
{
    int r = 0, c = 0; 
    for (int i = 0; i < m; ++i) if (row[i] == '1') {
        for (int j = 0; j < n; ++j) if (col[j] == '1') sub[r][c++] = a[i][j]; 
        ++r; 
        c = 0; 
    }
    if (ok(sub)) return true; 
    return false; 
}
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
 
    inp(a,m,n); 
    inp(b,h,k); 
    string s = ""; 
    vector<string> row; 
    Try(0,m,h,s,row); 
    vector<string> col; 
    s = ""; 
    Try(0,n,k,s,col); 
    for (auto r : row) 
    {
        for (auto c : col) {
            int sub[N][N]; 
            if (make_submatrix(sub , r , c)) {
                cout << "Yes"; 
                return; 
            }
        }
    }
    cout << "No"; 
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