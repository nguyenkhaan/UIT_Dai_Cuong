#include <bits/stdc++.h>
using namespace std; 
const int INF = 1e9; 
class HoiVien 
{
    protected: 
        string name; 
        int id; 
        int year; 
        int totalBooks;  
        int hours;  
        int isMuon;     
    public: 
        void input(); 
        void inputHours(); 
        virtual int getPhiDichVu() {}; 
        int getHours() {
            return this->hours; 
        }
        virtual double averageMoreBooks() {}; 
        void output(); 
}; 
class Prenium : public HoiVien 
{
    protected: 
        int phiMuonSach = 0; 
        int muonToiDa = INF; 
        int phiThietBi = 0; 
        int phiThanhVien = 1000; 
    public: 
        int getPhiDichVu() override; 
        double averageMoreBooks() override; 
}; 
class Basic : public HoiVien 
{
    protected: 
        int phiThanhVien = 300; 
        int phiThietBi = 20; 
        int phiMuonSach = 5;  
        int muonToiDa = 10;
    public: 
        int getPhiDichVu() override; 
        double averageMoreBooks() override; 
}; 
class UuDai : public HoiVien 
{  
    protected: 
        int phiThanhVien = 0; 
        int phiThietBi = 10; 
        int phiMuonSach = 3; 
        int muonToiDa = 5; 

    public: 
        int getPhiDichVu() override; 
        double averageMoreBooks() override; 
}; 
class Library 
{
    protected: 
        vector<HoiVien*> a; 
        int n;  
        int moreBooksBasic = 0; 
        int moreBooksPrenium = 0; 
        int moreBooksUuDai = 0; 
    public: 
        void input(); 
        int tinhPhiDichVu(); 
        HoiVien* maxHours(); 
        void countTotalAverageBooks(); 
        double averageMoreBooks(int type); 
        int countBasic(); 
        int countUuDai(); 
}; 