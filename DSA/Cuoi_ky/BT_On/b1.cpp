
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define MAXN 200000

void Nhap(int *arr, int &n){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void findMinDiffPairs(int a[], int n) 
{
    sort(a , a + n); 
    int mi = abs(a[1] - a[0]); 
    for (int i = 1; i < n; ++i) if (abs(a[i] - a[i - 1]) < mi) mi = abs(a[i] - a[i - 1]); 
    int d = 0; 
    for (int i = 1; i < n; ++i) if (abs(a[i] - a[i - 1]) == mi) ++d; 
   // cout << d << endl; 
    for (int i = 1; i < n; ++i) if (abs(a[i] - a[i - 1]) == mi) cout << a[i - 1] << ' ' << a[i] << endl; 
}


int main() {
    int arr[MAXN], n;
    Nhap(arr, n);

    findMinDiffPairs(arr, n);

    return 0;
}
