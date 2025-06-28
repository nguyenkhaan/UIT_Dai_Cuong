#include <bits/stdc++.h>
using namespace std;
#define An UwU
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    string s; 
    getline(cin, s); 
    int n = s.size();
    int maxLen = 0;
    for (int len = n; len >= 1; len--) {
        if (isPalindrome(s, n - len, n - 1)) {
            maxLen = len;
            break;
        }
    }
    int last = s.size() - maxLen - 1; 
    for (int i = last; i >= 0; --i) cout << s[i]; 
}

//