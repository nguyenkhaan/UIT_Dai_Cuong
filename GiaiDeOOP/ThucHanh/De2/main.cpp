#include "header.hpp" 
using namespace std; 
int main() 
{
    Company c; 
    c.inputTopic(); 
    cout << "\nTONG KINH PHI SAN XUAT CUA CONG TY: " << c.getTotalKinhPhi(); 
    cout << "\nPHIM THEO TUNG CAP DO: "; 
    c.xuatMucDo(); 
}