//Cap khoa ma hoa 
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxN = 1e6; 
vector<int> prime(maxN , 1); 
void sang(int L, int  R)
{
	for(int i = 2; i*i <= R; ++i) {
        int square = i * i; 
		for(int j = max(square , (L + square - 1) / square * square); j <= R; j += i*i) prime[j - L] = 0;
    }
}
void solve() 
{
    int L,R; 
    cin >> L >> R; 
    sang(L,R); 
    auto gcd = [](auto &&self, int a, int b) -> int {
        if (b == 0) return a; 
        else return self(self,b,a%b); 
    }; 
    int d = 0; 
    for (int x = L; x <= R; ++x) 
    {
        for (int y = x + 1; y <= R; ++y) if (prime[x - L] && prime[y - L] && gcd(gcd,x,y) == 1) ++d; 
    } 
    cout<<d; 
}
signed main()  
{
    solve(); 
}