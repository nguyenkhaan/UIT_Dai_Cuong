//ID: 001 
#include <iostream> 
#include <vector> 
using namespace std; 
struct Mp {
    string id; 
    int x; 
    Mp() {}; 
    Mp(string id, int x) {
        this->id = id; 
        this->x = x; 
    }
}; 
void Tron(vector<string> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void TronSapXep(vector<string> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        TronSapXep(arr, left, mid);
        TronSapXep(arr, mid + 1, right);

        Tron(arr, left, mid, right);
    }
}
/*---------------------------------------------*/
void TronMp(vector<Mp> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Mp> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].x > rightArr[j].x) {
            arr[k] = leftArr[i];
            i++;
        } 
        else if (leftArr[i].x < rightArr[j].x) {
            arr[k] = rightArr[j];
            j++;
        } 
        else { 
            if (leftArr[i].id.size() != rightArr[j].id.size()) 
                arr[k] = (leftArr[i].id.size() < rightArr[j].id.size()) ? leftArr[i] : rightArr[j];
            else 
                arr[k] = (leftArr[i].id < rightArr[j].id) ? leftArr[i] : rightArr[j];
            (arr[k].id == leftArr[i].id) ? i++ : j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void TronSapXepMp(vector<Mp> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        TronSapXepMp(arr, left, mid);
        TronSapXepMp(arr, mid + 1, right);
        TronMp(arr, left, mid, right);
    }
}

void solve() 
{
    int n; 
    cin >> n; 
    vector<string > a(n); 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    if (n == 1) {
        cout << a[0] << ' ' << 1; 
        return; 
    }
    TronSapXep(a, 0, n - 1); 
    vector<Mp> b; 
    int d = 1; 
    for (int i = 1; i < n; ++i) 
    {
        if (a[i] != a[i - 1]) {
            Mp tk(a[i - 1], d); 
            b.push_back(tk); 
            d = 1; 
        }
        else ++d; 
        if (i == a.size() - 1) {
            Mp tk(a[i], d); 
            b.push_back(tk); 
        }
    } 
    TronSapXepMp(b, 0, b.size() - 1); 
    for (int i = 0; i < b.size(); ++i) cout << b[i].id << ' ' << b[i].x << endl; 
} 
signed main() 
{
    solve(); 
}