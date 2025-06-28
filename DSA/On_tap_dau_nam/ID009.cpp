#include <bits/stdc++.h>
using namespace std;
#define int long long
#define console(a) cout << a << endl
__int128 calc(__int128 mi, __int128 a, __int128 b) {
    return mi * (a - mi * 2) * (b - mi * 2);
}
__int128 trinity_search(__int128 l, __int128 r, __int128 a, __int128 b) {
    __int128 ans = -1;
    while (l <= r) {
        __int128 m1 = l + (r - l) / 3;
        __int128 m2 = r - (r - l) / 3;
        __int128 v1 = calc(m1, a, b);
        __int128 v2 = calc(m2, a, b);
        ans = max(ans, max(v1, v2));
        if (v1 < v2) l = m1 + 1;
        else r = m2 - 1;
    }
    return ans;
}
void print128(__int128 num) {
    if (num == 0) {
        cout << 0;
        return;
    }
    string res = "";
    while (num > 0) {
        res += char('0' + num % 10);
        num /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x <= 2 || y <= 2) {
        console(0);
        return;
    }
    __int128 r = min(x, y) / 2;
    __int128 ans = trinity_search(0, r, x,y); 
    print128(ans);
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
