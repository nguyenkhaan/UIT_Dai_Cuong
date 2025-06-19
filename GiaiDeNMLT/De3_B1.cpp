//Thanh pho 2x2 
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    const int N = 5; 
    char a[N][N]; 
    for (int i = 0; i < 2; ++i) 
        for (int j = 0; j < 2; ++j) cin >> a[i][j]; 
    if (a[0][0] == '#' && a[1][1] == '#' && a[0][1] == '.' && a[1][0] == '.') {
        cout << "No"; 
        return; 
    }
    if (a[0][0] == '.' && a[1][1] == '.' && a[0][1] == '#' && a[1][0] == '#') {
        cout << "No"; 
        return; 
    }
    cout << "Yes"; 
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