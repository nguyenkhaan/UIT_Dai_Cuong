#include "library.hpp" 
using namespace std; 
int main() 
{
    Topic c; 
    c.topicInput();
    c.topicOutput(); 
    double ans = c.tietNghienCuu(); 
    if (ans == 0) cout << "\nKhong co thong tin giang vien trong nghien cuu"; 
    else cout << ans << endl; 
    if (c.isNghiemThu()) cout << "\nDu dieu kien nghiem thu"; 
    else cout << "\nKhong du dieu kien nghiem thu"; 
}