//https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std; 
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans; 
    multiset<int, greater<int>> st; 
    for (int i = 0; i < k; ++i) st.insert(nums[i]); 
    ans.push_back(*st.begin()); 
    for (int L = 1, R = L + k - 1; R < nums.size(); ++L) {
        st.erase(nums[L - 1]); 
        st.insert(nums[R]); 
        // for(auto x : st) cout << x <<' '; cout << endl; 
        // cout << nums[L - 1] << ' ' << nums[R] << endl; 
        ans.push_back(*st.begin()); 
    }
    return ans; 
} 
void solve() 
{
    int k; 
    int n; cin >> n >> k; 
    vector<int> a(n); 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    vector<int> ans = maxSlidingWindow(a , k); 
    for (auto x : ans) cout << x << ' '; 
}
signed main() 
{
    solve(); 
}