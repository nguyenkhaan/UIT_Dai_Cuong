#pragma once 
#include <bits/stdc++.h>
using namespace std; 

class Topic; 
class Newspaper; 
class HoiNghi; 
class Mangazine; 
class Author; 
class Date 
{
    protected: 
        int day, month, year; 
    public: 
        void input() {
            cin >> day >> month >> year; 
        } 
        void output() {
            cout << day << '/' << month << '/' << year << endl; 
        }
}; 
class Author 
{
    protected: 
        int authorID; //ma giang vien 
        string authorName; //ten giang vien 
        double soTiet = 0; //so tet nghien cuu 
        string phone; 
        string subject; 
    public: 
        void authorInput(); 
        void authorOuput(); 
        int getAuthorID() {
            return this->authorID; 
        }
        double getTiet() {
            return this->soTiet; 
        } 
        void setTiet(double x) {
            this->soTiet = x; 
        }
}; 
class Newspaper  
{
    protected: 
        int paperID; 
        Author* mainAuthor = new Author; 
        int m; //So luong tac gia 
        vector<Author*> au; //Danh sach tac gia 
        string DOI; 
        int year; 
        double soTiet = 0; //so tiet nghien cuu 
        int dm; //1 : Tap chi, 2: HOi nghi 
    public: 
        virtual void paperInput(); 
        virtual void paperOutput(); 
        int getDM() {
            return this->dm; 
        } 
        void setDM(int x) {
            this->dm = x; 
        }
        void setSoTiet(double x) {
            soTiet = x; 
        } 
        double getSoTiet() {
            return this->soTiet; 
        }
        void attachSoTiet(); 
        double getTietNghienCuuIndex(int); 
}; 
class Mangazine : public Newspaper 
{
    protected: 
        int type; // ISI, Scopus, Non-Index 
    public: 
        void paperInput() override; 
        void paperOutput() override; 
};  
class HoiNghi : public Newspaper 
{
    protected: 
        bool isRanking; //thuoc bang xep hang hay khong 
    public: 
        void paperInput()override; 
        void paperOutput() override; 
};
class Topic 
{
    protected: 
        int n; //So luong bai bao da dang ki se cong bo 
        int N; //so luong bai bao thuc te da cong bo 
        vector<Newspaper*> bb; 
        int topicID; //Ma de tai 
        string topicName; 
        Date date; 
        int time; //Thoi gian thuc hien 
        int d1 = 0; //Tap chi 
        int d2 = 0; //Hoi nghi 
        map<int, Author> authors; //Quan li cac giang vien 
    public: 
        void topicInput(); 
        void topicOutput(); 
        double tietNghienCuu();   
        bool isNghiemThu(); 
}; 