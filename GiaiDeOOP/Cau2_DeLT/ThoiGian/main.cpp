/**Viết chương trình nhập vào Giờ, Phút, Giây. Cài đặt toán tử >>, <<, ++, -- cho thời gian */ 
#include <bits/stdc++.h>
using namespace std; 
class Time 
{
    protected: 
        int hour, minute, second; 
    public: 
        Time() {}; 
        Time(int a, int b, int c) {
            this->hour = a; 
            this->minute = b; 
            this->second = c; 
        }
        friend istream& operator >> (istream&in, Time&); 
        friend ostream& operator << (ostream&out, Time); 
        friend Time operator ++(Time&); 
        friend Time operator --(Time&); 
}; 

istream& operator >> (istream& in, Time &t) 
{
    cout << "Nhap gio: "; cin >> t.hour; 
    cout << "Nhap phut: "; cin >> t.minute; 
    cout << "Nhap giay: "; cin >> t.second;  
    return in; 
} 
ostream& operator << (ostream&out, Time t) 
{
    cout << t.hour << " : " << t.minute << " : " << t.second << '\n';
    return out;  
}
Time operator ++ (Time &t) 
{
    ++t.second; 
    if (t.second >= 60) 
    {
        ++t.minute; 
        if (t.minute >= 60) {
            ++t.hour; 
            t.minute = 0; 
        } 
        t.second = 0; 
    }
    return t; 
}
Time operator -- (Time &t) 
{
    if (t.hour == 0 && t.second == 0 && t.minute == 0) return t; 
    --t.second; 
    if (t.second < 0) 
    {
        --t.minute; 
        if (t.minute < 0) {
            --t.second; 
            t.minute = 59; 
        } 
        t.second = 59; 
    }
    return t; 
}
int main() 
{
    Time t; 
    cin >> t; 
    cout << "THOI GIAN DA NHAP VAO LA: " << t; 
    cout << "\nTHOI GIAN SAU KHI TANG 1s: " << ++t; 
    cout << "\nTHOI GIAN SAU KHI GIAM 2s: "; 
    --t; --t; 
    cout << t; 
}