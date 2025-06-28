#include <bits/stdc++.h> 
using namespace std; 
const int N = 10; 
bool visited[N]; 
int d = 0; 
bool laCapSoCong(int a, int b, int c) {
    // int arr[3] = {a, b, c};
    // sort(arr, arr + 3);  
    if (b - a == c - b) return true; 
    return false; 
}
void back_track(int i, vector<int> &a, vector<int> &ans) 
{
    if (i == 6) 
    {
        bool check = laCapSoCong(ans[0] , ans[1], ans[2]) && laCapSoCong(ans[2], ans[3], ans[4]) && laCapSoCong(ans[4], ans[5], ans[0]); 
        // 
        if (check) {
            ++d; 
            for (auto x : ans) cout << x << ' '; cout << endl; 
        }
        return; 
    } 
    for (int j = 0; j < a.size(); ++j) if (!visited[j])
    {
        ans.push_back(a[j]); 
        visited[j] = true; 
        back_track(i + 1, a , ans); 
        ans.pop_back(); 
        visited[j] = false; 
    }
}
void solve() 
{
    vector<int> a; 
    for (int i = 21; i <= 29; ++i) a.push_back(i); 
    fill(visited , visited + N, false); 
    vector<int> ans; 
    back_track(0 , a , ans); 
    cout << d << endl; 
}
signed main() 
{
    solve(); 
}