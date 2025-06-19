//Trung Tuyen
//Hầu hết các bài mà mình ghi quay lui trong File bài tập đều chì có 1 motip chung là dùng dãy nhị phân để thể hiện việc 
//lựa chọn thôi. Ví dụ: 1 mảng A có 5 phần tử thì liệt kê tất cả dãy nhị phân có 5 kí số 00000 đến 11111 (quay lui) 
//VD xét dãy 00110 thì binary[2] = 1, binary[3] = 1 ta sẽ tạo đươc 1 tập hợp con {a[2] , a[3]}
#include <bits/stdc++.h>
using namespace std;  
#define int long long 
int n,m,k; 
vector<string> binary; 
void Try(int i, string &s) 
{
    if (i == n) {
        binary.push_back(s); 
        return; 
    }
    for (int j = 0; j <= 1; ++j) {
        s += (j + '0'); 
        Try(i + 1, s); 
        s.erase(s.size() - 1, 1); 
    }
} 
void inp(int h[][20], vector<int> &c) 
{
    cin >> n >> m >> k; 
    int col = 0, row = 0; 
    for (int i = 0; i < n; ++i) 
    {
        int x; cin >> x; 
        c.push_back(x); 
        for (int j = 0; j < m; ++j) cin >> h[row][j]; 
        ++row;
    }
}
void solve() 
{
    const int N = 20; 
    int h[N][N]; 
    vector<int> c; 
    inp(h,c); 
    string s = ""; 
    Try(0, s); 
    int mi = 1e13; 
    for (auto choice : binary) 
    {
        vector<int> know(m , 0); 
        int cost = 0; 
        for (int i = 0; i < choice.size(); ++i) if (choice[i] == '1') {
            cost += c[i]; 
            for (int j = 0; j < m; ++j) know[j] += h[i][j]; 
        }
        bool ok = true; 
        for (int i = 0; i < m; ++i) if (know[i] < k) {
            ok = false; 
            break; 
        }
        if (ok) mi = min(mi , cost); 
    }
    if (mi == 1e13) cout <<-1; 
    else cout << mi << endl; 
}
signed main() 
{
    solve(); 
}
