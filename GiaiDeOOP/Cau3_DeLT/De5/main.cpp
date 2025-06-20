#include "library.hpp"
using namespace std; 
int main() 
{
    Library l; 
    l.input(); 
    cout << "\nTONG SO PHI DICH VU: " << l.tinhPhiDichVu(); 
    cout << "\nHoi vien su dung thiet bi nhieu gio nhat: " << endl; 
    HoiVien *p = l.maxHours(); 
    p->output(); 
    l.countTotalAverageBooks(); 
    cout << "\nSo sach muon them ngoai gio voi the Co ban: " << l.averageMoreBooks(1); 
    cout << "\nSo sach muon them ngoai gio voi the Uu dai: " << l.averageMoreBooks(2); 
    
}