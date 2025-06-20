#include "library.hpp" 
using namespace std; 
void HoiVien::input() 
{
    cout << "Nhap ho va ten: "; cin >> name; 
    cout << "Nhap ma so the: "; cin >> id; 
    cout << "Nhap nam sinh: "; cin >> year; 
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
    int n; cin >> n; 
    cout << "Nhap danh sach the hoi vien: "; 
    for (int i = 0; i < n; ++i) {
        int type; 
        cout << "Nhao loai the: (1. Prenium, 2. Basic, 3. Uu dai)";  cin >> type; 
        switch (type)
        {
            case 1: a[i] = new Prenium; break;  
            case 2: a[i] = new Basic;  break; 
            case 3: a[i] = new UuDai;  break;  
            default: cout << "Thong tin nhap vao khong hop le: "; break; 
        }
        a[i]->input(); 
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
