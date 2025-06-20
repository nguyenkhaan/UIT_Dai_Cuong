#pragma once 
#include <bits/stdc++.h>
using namespace std; 

class Product; 
class Customer; 
class Shop; 
class CD; 
class Picture; 
class Bill; 
class Date; 

class Date 
{
    protected: 
        int day, month, year; 
    public: 
        void input() {
            cout << "Nhap ngay - thang - nam (cach nhau bang 1 khoang trang): "; cin >> day >> month >> year; 
        } 
        void output() {
            cout << day << '/' << month << '/' << year << endl; 
        }
}; 
class Customer 
{
    protected: 
        int customerID; 
        string customerName; 
        string phone; 
    public: 
        void customerInput(); 
        void customerOutput(); 
        int getID() {
            return this->customerID; 
        } 
        void setID(int x) {
            this->customerID = x; 
        }
}; 
class Product 
{
    protected: 
        int ms; //Ma so 
        double price; //Gia ban 
        string title; //Tieu de 
    public: 
        virtual void productInput();  
        virtual void productOutput();  
        double getPrice() {
            return this->price; 
        } 
        void setPrice() {
            this->price = price; 
        }
}; 
class CD : public Product 
{
    protected: 
        string singerName; 
        string producerName; 
    public: 
        void productInput() override; 
        void productOutput() override;  
}; 
class Picture : public Product 
{
    protected: 
        double w,h; 
        string artistName; 
    public: 
        void productInput() override; 
        void productOutput() override; 
}; 
class Bill 
{
    protected: 
        int billID; 
        Customer kh; 
        Date date;   //Ngay lap hoa don 
        double totalPrice; //Tong gia tien cua hoa don 
        int n; //So luong san pham trong hoa don 
        vector<Product*> pr; //Danh sach san pham  
    public: 
        void billInput(); 
        void blllOutput(); 
        void TotalAll(); 
        double getTotal() {
            return this->totalPrice; 
        }
        Customer getKH() {
            return this->kh; 
        }
}; 
class Shop 
{
    protected: 
        int m; 
        vector<Bill*> h; 
        double income = 0; 
        map<int, double> khp;   //Tong so tien mua cua khach hang theo ID 
        map<int , Customer> khi; //Thong tin khach hang 
    public: 
        void shopInput(); 
        void shopOutput();  
        void calcIncome(); 
        double getIncome() {
            return this->income; 
        }
        void calcCustomerIncome(); 
        Customer findMax(); 
}; 