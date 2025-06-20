#include "header.hpp" 
using namespace std; 

void Topic::topicInput() 
{
    cout << "Nhap ma du an: "; cin >> id; 
    cin.ignore(); 
    cout << "Nhap ten phim: "; getline(cin , name); 
    cout << "Nhap tac gia chinh: "; getline(cin, authorName); 
    cout << "Nhap so dien vien tham gia: "; cin >> nmember; 
    cout << "Nhap nam phat hanh: "; cin >> year;  
} 
void Topic::topicOutput() 
{
    cout << "Ma du an: " << id << endl; 
    cout << "Ten du an: " << name << endl; 
    cout << "So thanh vien tham gia: " << nmember << endl;
    cout << "Tac gia chinh: " << authorName << endl; 
    cout << "Nam phat hanh: " << year << endl; 

}
void TruyenHinh::topicInput() 
{
    Topic::topicInput(); 
    cout << "Nhap so quoc gia phat hanh: "; cin >> ncountries; 
    
} 
void DienAnh::topicInput() 
{
    Topic::topicInput(); 
    cout << "Nhap so tap phim: "; cin >> nepisodes; 
    cout << "Nhap so uong giai thuong dat duoc: "; cin >> m; 
    a.resize(m); 
    for (int i = 0; i < m; ++i) a[i].inputPrize(); 
}
double TruyenHinh::getKinhPhi() 
{
    return doanhthu * 0.1 + ncountries * 5000; 
} 
double DienAnh::getKinhPhi() 
{
    for (int i = 0; i < m; ++i) kinhPhi += a[i].getBonus(); 
} 
int DienAnh::getFamous() 
{
    if (!m) return  0; //Khong thanh cong 
    if (m > 3) return 2; 
    return 1; 
}
void Company::inputTopic() 
{
    cout << "Nhap so luong du an: "; cin >> n; 
    a.resize(n); 
    for (int i = 0; i < n; ++i) 
    { 
        int type; 
        cout << "Nhap loai du an (1. Truyen hinh, 2. Dien anh): "; cin >> type;  
        switch (type)
        {
            case 1: a[i] = new TruyenHinh; break; 
            case 2: a[i] = new DienAnh; break; 
        } 
        a[i]->topicInput(); 
    }
}
double Company::getTotalKinhPhi() 
{
    double ans = 0; 
    for (int i = 0; i < n; ++i) ans += a[i]->getKinhPhi(); 
    return ans; 
}
void Company::xuatMucDo() 
{
    bool d = 0; 
    cout << "Danh sach phim khong thanh cong: " << endl; 
    for (int i = 0; i < n; ++i) if (dynamic_cast<DienAnh*>(a[i]) && a[i]->getFamous() == 0) {
        a[i]->topicOutput(); 
        d = 1; 
    } 
    if (!d) cout << "Khong co" << endl; 
    d = 0; 
    cout << "Danh sach phim thanh cong: " << endl; 
    for (int i = 0; i < n; ++i) if (dynamic_cast<DienAnh*>(a[i]) && (a[i]->getFamous() == 2 || a[i]->getFamous() == 1)) {
        a[i]->topicOutput(); 
        d = 1; 
    } 
    if (!d) cout << "Khong co" << endl; 
    d = 0; 
    cout << "Danh sach phim thanh cong xuat sac: " << endl; 
    for (int i = 0; i < n; ++i) if (dynamic_cast<DienAnh*>(a[i]) && a[i]->getFamous() > 3) {
        a[i]->topicOutput(); 
        d = 1; 
    } 
    if (!d) cout << "Khong co" << endl; 
    d = 0; 
}