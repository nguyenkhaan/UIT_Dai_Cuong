/**Tuong tu nhau bai Thoi Gian nhung cai dat voi ngay va thang */
#include <bits/stdc++.h>
using namespace std; 
int dayMax[] = {0, 31 , 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
bool isLeap(int y) 
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 1; 
    return 0; 
}
class Date 
{
    protected: 
        int day, month, year; 
    public: 
        friend istream& operator >> (istream&, Date&); 
        friend ostream& operator << (ostream&, Date&); 
        friend Date operator ++ (Date&); 
        friend Date operator -- (Date&); 
}; 
istream& operator >> (istream& in, Date &x) 
{
    cout << "Nhap ngay: "; in >> x.day; 
    cout << "Nhap thang: "; in >> x.month; 
    cout << "Nhap nam: "; in >> x.year; 
    return in; 
} 
ostream& operator << (ostream& out, Date& x) 
{
    out << x.day << '/' << x.month << '/' << x.year << endl; 
    return out; 
}
Date operator ++(Date &x) 
{
    int dm = dayMax[x.month]; 
    if (x.month == 2 && isLeap(x.year)) dm = 29; 
    ++x.day; 
    if (x.day > dm) 
    {
        ++x.month; 
        if (x.month > 12) {
            ++x.year; 
            x.month = 1; 
        } 
        x.day = 1; 
    }
    return x; 
}
Date operator -- (Date &x) 
{
    if (x.day == 1 && x.month == 1 && x.year == 1) return x; 
    --x.day; 
    if (x.day <= 0) 
    {
        --x.month; 
        if (x.month <= 0) {
            --x.year; 
            x.month = 12; 
        } 
        x.day = dayMax[x.month]; 
        if (x.month == 2 && isLeap(x.year)) x.day = 29; 
    }
    return x; 
}
int main() 
{
    Date d; 
    cout << "\nNHAP DU LIEU: "; cin >> d; 
    cout << "\nXUAT DU LIEU: " << d; 
    ++d; 
    cout << "\nSAU KHI TANG THEM 1 NGAY: " << d; 
    --d; --d; 
    cout << "\nSAU KHI GIAM DI 2 NGAY: " << d; 
}