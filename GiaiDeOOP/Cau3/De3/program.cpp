#include "library.hpp" 
using namespace std; 
void Author::authorInput() 
{
    cout << "Ma giang vien: "; cin >> authorID; 
    cin.ignore(); 
    cout << "Ten giang vien: "; getline(cin , authorName); 
    cout << "So dien thoai: "; cin >> phone; 
    cout << "Chuyen nganh: "; cin >> subject; 
}
void Author::authorOuput() 
{
    cout << "\nMa giang vien: " << authorID; 
    cout << "\nTen giang vien: " << authorName; 
    cout << "\nSo dien thoai: " << phone; 
    cout << "\nChuyen nganh: " << subject; 
}
void Newspaper::paperInput() 
{
    cout << "\nNhap ma bai bao: "; cin >> paperID; 
    cout << "\nNhap lien ket DOI: "; cin >> DOI; 
    cout << "\nNhap thong tin tac gia chinh: "; mainAuthor->authorInput(); 
    cout << "\nNhap thong tin cac dong tac gia: "; 
    cout << "\nSo luong tac gia phu: "; cin >> m; 
    au.resize(m); 
    for (int i = 0; i < m; ++i) 
    {
        au[i] = new Author; 
        au[i]->authorInput(); 
    }
    cout << "\nNhap nam xuat ban: "; cin >> year; 
}
void Newspaper::paperOutput() 
{
    cout << "\nMa bai bao: " << paperID; 
    cout << "\nDOI: " << DOI; 
    cout << "\nTac gia chinh: "; mainAuthor->authorOuput(); 
    cout << "\nThong tin cac dong tac gia: "; 
    for (int i = 0; i < m; ++i) au[i]->authorOuput(); 
    cout << "\nNam xuat ban: " << year; 
}
void Newspaper::attachSoTiet() 
{
    mainAuthor->setTiet(0.5 * soTiet); 
    double k = (0.5 * soTiet) / m; 
    for (int i = 0; i < m; ++i) au[i]->setTiet(k); 
}
void Mangazine::paperInput() 
{
    Newspaper::paperInput(); 
    Newspaper::setDM(1); 
    cout << "Nhap loai tap chi (1. ISI, 2. Scopus, 3. Non-index): "; cin >> type; 
    switch (type)
    {
        case 1: Newspaper::setSoTiet(5000); break; 
        case 2: Newspaper::setSoTiet(2500); break; 
        case 3: Newspaper::setSoTiet(1000); break; 
    }
}
double Newspaper::getTietNghienCuuIndex(int index) 
{
    double ans = 0; 
    if (mainAuthor->getAuthorID() == index) ans += mainAuthor->getTiet(); 
    for (int i = 0; i < m; ++i) if (au[i]->getAuthorID() == index) ans += au[i]->getTiet(); 
    return ans; 
}
void Mangazine::paperOutput() 
{
    Newspaper::paperOutput(); 
    cout << "\nLoai tap chi: " << type << endl; 
}
void HoiNghi::paperInput() 
{
    Newspaper::paperInput(); 
    cout << "Danh muc hoi nghi duoc xep hang: (0: Co, 1 : Khong): "; cin >> isRanking; 
    if (isRanking) setSoTiet(650);   //Bang 65% so tiet nghien cuu theo qui dinh 
    else setSoTiet(325); 
}
void HoiNghi::paperOutput() 
{
    Newspaper::paperOutput(); 
    cout << "Xep hang hoi nghi: " << isRanking << endl; 
}
void Topic::topicInput()
{
    cout << "\nNhap ma de tai: "; cin >> topicID; 
    cin.ignore(); 
    cout << "\nNhap ten de tai: ";  getline(cin, topicName); 
    cout << "\nDate thuc hien: "; date.input(); 
    cout << "\nThoi gian thuc hien: "; cin >> time; 
    cout << "\nNhap so luong bai bao: "; cin >> n; 
    bb.resize(n); 
    for (int i = 0; i < n; ++i) 
    {
        int type;  
        cout << "Nhap loai bai bao: (1. Tap chi, 2. Hoi nghi): "; cin >> type; 
        switch (type)
        {
            case 1: bb[i] = new Newspaper; ++d1; break;
            case 2: bb[i] = new Mangazine; ++d2; break;
            default: cout << "Invalid..."; break; 
        }
        bb[i]->paperInput(); 
        bb[i]->attachSoTiet(); 
    }
    cout << "Nhap so luong bai bao thuc te da cong bo: "; cin >> N; 
}
void Topic::topicOutput() 
{
    cout << "\n------------------ THONG TIN DE TAI ------------------\n";
    cout << "Ma de tai: " << topicID << endl;
    cout << "Ten de tai: " << topicName << endl;
    cout << "Ngay thuc hien: "; date.output(); // Giả sử bạn đã có hàm date.output()
    cout << "Thoi gian thuc hien: " << time << " thang" << endl;
    cout << "So luong bai bao du kien dang ki: " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "\n--- Bai bao thu " << i + 1 << " ---\n";
        bb[i]->paperOutput();      // Giả sử bạn có hàm paperOutput() trong class Newspaper và Mangazine
    }
    cout << "\nSo bai bao loai du kien danh muc Tap chi: " << d1;
    cout << "\nSo bai bao loai du kiem danh muc Hoi nghi: " << d2;
    cout << "\nSo luong bai bao thuc te da cong bo thanh cong: " << N; 
    cout << "\n------------------------------------------------------\n";
}
double Topic::tietNghienCuu() 
{
    int index;  
    cout << "Nhap ma ID giang vien: "; cin >> index; 
    double ans = 0; 
    for (int i = 0; i < n; ++i) ans += bb[i]->getTietNghienCuuIndex(index); 
    return ans; 
}
bool Topic::isNghiemThu()
{
    return (N >= d1 && N >= d2); 
}