#include <bits/stdc++.h>
using namespace std; 
class Company; 
class Topic; 
class TruyenHinh; 
class DienAnh; 
class Prize;  

class Prize 
{
    protected: 
        int type; 
    public:  
        void inputPrize() {
            cout << "Nhap loai gia thuong: 1. Quoc gia, 2. Khu vuc, 3. Quoc te: "; cin >> type; 
        }
        double getBonus() {
            switch(type) 
            {
                case 1: return 10000; 
                case 2: return 20000; 
                case 3: return 50000; 
            }
        }
}; 
class Company 
{
    protected: 
        int n; 
        vector<Topic*> a; 
    public: 
        void inputTopic(); 
        void outputTopic(); 
        double getTotalKinhPhi(); 
        void xuatMucDo(); 
}; 
class Topic 
{
    protected: 
        int id; 
        string name; 
        string authorName; 
        int nmember; 
        int year; 
        double doanhthu; 
    public: 
        virtual void  topicInput() {}; 
        virtual void topicOutput() {}; 
        virtual double getKinhPhi() {}; 
        virtual int getFamous() {}; 
}; 
class TruyenHinh : public Topic 
{
    protected: 
        int ncountries; 
        double doanhthu; 
    public: 
        void topicInput() override; 
        void topicOutput() override; 
        double getKinhPhi() override; 
};  
class DienAnh : public Topic 
{
    protected: 
        int nepisodes; 
        vector<Prize> a; 
        int m; 
        double kinhPhi = 0; 
    public: 
        void topicInput(); 
        void topicOutput(); 
        int getFamous(); //Do do thanh cong cua phim 
        double getKinhPhi() {}; 
}; 