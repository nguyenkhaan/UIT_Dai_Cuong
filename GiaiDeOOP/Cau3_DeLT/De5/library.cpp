#include "library.hpp" 
using namespace std; 
void HoiVien::input() 
{
    cout << "Nhap ma so the: "; cin >> id; 
    cin.ignore(); 
    cout << "Nhap ho va ten: "; getline(cin , name); 
    cout << "Nhap nam sinh: "; cin >> year; 
} 
void HoiVien::output() 
{
    cout << "\nSo the: " << id; 
    cout << "\nHo va ten: " << name; 
    cout << "\nNam sinh: " << year; 
}
void HoiVien::inputHours() 
{
    cout << "Co su dung thiet bi khong: "; cin >> isMuon; 
    if (isMuon) 
    {
        cout << "Nhap so gio muon: "; cin >> hours; 
    } 
    else hours = 0; 
    cout << "Nhap so sach da muon: "; cin >> totalBooks; 
}
int Prenium::getPhiDichVu() 
{
    return 0; 
} 
int Basic::getPhiDichVu() 
{
    int ans = 0; 
    if (hours) ans += phiThietBi; 
    if (totalBooks <= 10) return ans; 
    return ans + (totalBooks - 10) * phiMuonSach; 
}  
int UuDai::getPhiDichVu() 
{
    int ans = 0; 
    if (hours) ans += phiThietBi; 
    if (totalBooks <= 5) return ans; 
    return ans + (totalBooks - 5) * phiMuonSach; 
}
double Prenium::averageMoreBooks() {
    return 0; 
} 
double Basic::averageMoreBooks() {
    int ans = totalBooks - 10; 
    return max(0 , ans); 
} 
double UuDai::averageMoreBooks() {
    int ans = totalBooks - 5; 
    return max(0 , ans); 
}
void Library::input() 
{
    cout << "Nhap so luong the hoi vien: "; 
    cin >> this->n; 
    cout << ">>>Bat dau nhap danh sach the hoi vien: " << endl; 
    a.resize(n); 
    for (int i = 0; i < n; ++i) {
        int type; 
        cout << "Nhap loai the: (1. Prenium, 2. Basic, 3. Uu dai): ";  cin >> type; 
        switch (type)
        {
            case 1: a[i] = new Prenium; break;  
            case 2: a[i] = new Basic;  break; 
            case 3: a[i] = new UuDai;  break;  
            default: cout << "Thong tin nhap vao khong hop le: "; break; 
        }
        a[i]->input(); a[i]->inputHours(); 
    }
} 
int Library::countBasic() 
{
    int ans = 0; 
    for (int i = 0; i < n; ++i) 
        if (dynamic_cast<Basic*>(a[i])) ++ans; 
    return ans; 
}
int Library::countUuDai() 
{
    int ans = 0; 
    for (int i = 0; i < n; ++i) 
        if (dynamic_cast<UuDai*>(a[i])) ++ans; 
    return ans; 
}
int Library::tinhPhiDichVu() 
{
    int ans = 0; 
    for (int i = 0; i < n; ++i) ans += a[i]->getPhiDichVu(); 
    return ans; 
}
HoiVien* Library::maxHours() 
{
    int ma = 0; 
    int pos = -1; 
    for (int i = 0; i < n; ++i) if (ma < a[i]->getHours()) {
        ma = a[i]->getHours(); 
        pos = i; 
    } 
    return a[pos]; 
} 
void Library::countTotalAverageBooks() 
{
    for (int i = 0; i < n; ++i) 
    {
        if (dynamic_cast<Basic*>(a[i])) ++moreBooksBasic; 
        else if (dynamic_cast<UuDai*>(a[i])) ++moreBooksUuDai; 
        else ++moreBooksPrenium; 
    }
}
double Library::averageMoreBooks(int type) 
{
    if (type == 1) {
        int count = countBasic();
        return count == 0 ? 0 : (double)moreBooksBasic / count;
    } else {
        int count = countUuDai();
        return count == 0 ? 0 : (double)moreBooksUuDai / count;
    }
}
