//Lo to
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define An UwU
#define         fast    ios::sync_with_stdio(false), cin.tie(0)
#define       all(x)    x.begin(), x.end()
const int maxn = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9; 
pair<int,int> index(int a[][4], int x) 
{
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) if (a[i][j] == x) return {i , j}; 
    return {-1 , -1}; 
}
void loto(int f[][4], int a[][4]) 
{
    int n; 
    cin >> n; 
    for (int i = 0; i < n; ++i) 
    {
        int x;  cin >> x; 
        pair<int,int> pos = index(a,x); 
        if (pos.first != -1 && pos.second != -1) f[pos.first][pos.second] = 1; 
    }
} 
bool win(int f[][4]) 
{
    for (int i = 0; i < 3; ++i) {
        bool ok = true; 
        for (int j = 0; j < 3; ++j) if (f[i][j] == 0) {
            ok = false; 
            break; 
        } 
        if (ok) return true; 
    }
    for (int j = 0; j < 3; ++j) { 
        bool ok = true; 
        for (int i = 0; i < 3; ++i) if (f[i][j] == 0) {
            ok = false; 
            break; 
        }
        if (ok) return true;
    }
    if (f[0][0] == 1 && f[1][1] == 1 && f[2][2] == 1) return true; 
    if (f[1][2] == 1 && f[1][1] == 1 && f[2][1] == 1) return true;  
    return false; 
}
void solve()
{
    //freopen("input.inp" ,"r", stdin);
    //freopen("brute_out.out","w",stdout); 
    const int N = 4; 
    int a[4][4]; 
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) cin >> a[i][j]; 
    int f[4][4]; 
    memset(f,0,sizeof(f)); 
    loto(f,a); 
    if (win(f)) cout<<"Yes"; 
    else cout <<"No"; 
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