#include "header.hpp" 
using namespace std; 
void Customer::customerInput() 
{
    cout << "Nhap ma khach hang: "; cin >> customerID; 
    cin.ignore(); 
    cout << "Nhap ho va ten: "; getline(cin , customerName); 
    cout << "So dien thoai: "; cin >> phone; 
}; 
void Customer::customerOutput() 
{
    cout << "\nMa khach hang: " << customerID; 
    cout << "\nHo va ten khach hang: " << customerName; 
    cout << "\nSo dien thoai: " << phone; 
}
void Product::productInput() 
{
    cout << "Nhap ma san pham: "; cin >> ms;  
    cin.ignore(); 
    cout << "Ten san pham: "; getline(cin , title); 
    cout << "Nhap gia ban: "; cin >> price; 
}
void CD::productInput() 
{
    Product::productInput(); 
    cin.ignore(); 
    cout << "Nhap ten ca si: "; getline(cin, singerName); 
    cout << "Nhap ten nha san xuat: "; getline(cin , producerName); 
}
void Picture::productInput() 
{
    Product::productInput(); 
    cin.ignore(); 
    cout << "Nhap kich thuoc (w , h): "; cin >> w >> h; 
    cin.ignore(); 
    cout << "Nhap ten hoa si: "; getline(cin , artistName); 
}
void Product::productOutput() 
{
    cout << "\nMa san pham: " << ms; 
    cout << "\nTieu de: " << title; 
    cout << "\nGia ban: " << price; 
}
void CD::productOutput() 
{
    Product::productOutput(); 
    cout << "\nTen ca si: " << singerName; 
    cout << "\nTen nha san xuat: " << producerName; 
}
void Picture::productOutput() 
{
    Product::productOutput(); 
    cout << "\nDai x Rong: " << w << 'x' << h; 
    cout << "\nHoa si: " << artistName; 
}
void Bill::billInput() 
{
    cout << "Nhap ma hoa don: "; cin >> billID; 
    cout << "Nhap thong tin khach hang: " << endl; 
    kh.customerInput(); 
    cout << "Ngay lap hoa don: "; date.input(); 
    cout << "Nhap so luong san pham: "; cin >> n; 
    pr.resize(n); 
    for  (int i = 0; i < n; ++i) 
    {
        int type; 
        cout << "Nhap loai hang hoa: (1. CD, 2. Picture): "; cin >> type; 
        switch (type)
        {
            case 1: pr[i] = new CD; break;
            case 2: pr[i] = new Picture; break;
            default: cout << "Invalid"; break; 
        }
        pr[i]->productInput(); 
    }
}
void Bill::blllOutput() 
{
    cout << "\nMa hoa don: " << billID; 
    cout << "\nThong tin khach hang: " << endl; 
    kh.customerOutput(); 
    cout << "\nNgay lap hoan don: "; date.output(); 
    cout << "\nTHONG TIN SAN PHAM" << endl; 
    for (int i = 0; i < n; ++i) {
        pr[i]->productOutput(); 
        cout << endl; 
    }
}
void Bill::TotalAll() 
{
    for (int i = 0; i < n; ++i) totalPrice += pr[i]->getPrice(); 
}
void Shop::shopInput() 
{
    cout << "Nhap so luong hoa don quan li: "; cin >> m; 
    h.resize(m); 
    for (int i = 0; i < m; ++i) {
        h[i] = new Bill; 
        h[i]->billInput(); 
    }
    //Tinh thu nhap cho cua hang: 
}
void Shop::calcIncome() 
{
    for (int i = 0; i < m; ++i) h[i]->TotalAll(); 
    for (int i = 0; i < m; ++i) income += h[i]->getTotal(); 
}
void Shop::calcCustomerIncome() 
{
    for (int i = 0; i < m; ++i) 
    {
        Customer p = h[i]->getKH(); 
        int id = p.getID(); 
        khp[id] += h[i]->getTotal(); 
        khi[id] = p;  
    }
}
void Shop::shopOutput() 
{
    cout << "DANH SACH HOA DON: " << endl; 
    for (int i = 0; i < m; ++i) h[i]->blllOutput(); 
}
Customer Shop::findMax() 
{
    double cost = 0; 
    int index = -1; 
    for (auto [x , y] : khp) if (cost < y) {
        cost = y; 
        index = x; 
    }
    return khi[index]; 
}
