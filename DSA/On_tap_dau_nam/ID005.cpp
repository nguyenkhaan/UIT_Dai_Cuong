//Lop co thuong 
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define An UwU
bool canReach(int mi, int a, int k, int b, int m, int n) {
    unsigned long long workA = mi / k; 
    unsigned long long workB = mi / m; 
    unsigned long long total = mi * (a + b) * 1LL;
    if (workA > 0) total -= workA * a;
    if (workB > 0) total -= workB * b;

    return total >= n;
}

int binary_search(int l, int r, int a, int k, int b, int m, int n) {
    int ans = -1;
    while (l <= r) {
        int mi = l + (r - l) / 2; 
        if (canReach(mi, a, k, b, m, n)) {
            ans = mi;
            r = mi - 1;
        } else {
            l = mi + 1;
        }
    }
    return ans;
}

void solve() {
    int a, k, b, n, m;
    cin >> a >> k >> b >> m >> n;
    
    int low = 0, high = 2 * (n / min(a, b)); 
    int ans = binary_search(low, high, a, k, b, m, n);
    
    cout << ans;
}

signed main() {
    solve();
}