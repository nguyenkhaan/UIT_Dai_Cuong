#include "header.hpp"
using namespace std; 
int main() 
{
    Shop s; 
    s.shopInput(); 
    cout << "\nTHONG TIN CUA HANG" << endl; 
    s.shopOutput(); 
    s.calcIncome(); 
    s.calcCustomerIncome(); 
    cout << "\nTONG THU NHAP CUA HANG: " << endl; 
    cout << s.getIncome(); 
    cout << "THONG TIN KHACH HANG MUA NHIEU NHAT: "; 
    Customer c = s.findMax(); 
    c.customerOutput(); 
}