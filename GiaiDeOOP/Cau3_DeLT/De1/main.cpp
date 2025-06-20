#include <bits/stdc++.h>
using namespace std;

class TamLi {
protected:
    int c;
public:
    void setChiSo(int c) {
        this->c = c;
    }
    virtual string outputRes() = 0; 
    virtual ~TamLi() {} 
};

class O : public TamLi {
public:
    string outputRes() override {
        if (c >= 0 && c <= 30) return "Truyen danh gia O thap";
        else if (c >= 70) return "Truyen danh gia O cao";
        return "Khong xac dinh ro";
    }
};

class C : public TamLi {
public:
    string outputRes() override {
        if (c >= 0 && c <= 30) return "Truyen danh gia C thap";
        else if (c >= 70) return "Truyen danh gia C cao";
        return "Khong xac dinh ro";
    }
};

class E : public TamLi {
public:
    string outputRes() override {
        if (c >= 0 && c <= 30) return "Truyen danh gia E thap";
        else if (c >= 70) return "Truyen danh gia E cao";
        return "Khong xac dinh ro";
    }
};

class A : public TamLi {
public:
    string outputRes() override {
        if (c >= 0 && c <= 30) return "Truyen danh gia A thap";
        else if (c >= 70) return "Truyen danh gia A cao";
        return "Khong xac dinh ro";
    }
};

class N : public TamLi {
public:
    string outputRes() override {
        if (c >= 0 && c <= 30) return "Truyen danh gia N thap";
        else if (c >= 70) return "Truyen danh gia N cao";
        return "Khong xac dinh ro";
    }
};

class Person {
protected:
    vector<TamLi*> t;
public:
    void input();
    void output();
    void saveData(string);
    ~Person();  
};

void Person::saveData(string s) {
    for (int i = 0; i < s.size(); i += 4) {
        char ch = s[i];
        string tk = string(1, s[i + 1]) + string(1, s[i + 2]);
        int c = stoi(tk);
        switch (ch) {
            case 'O': t[0]->setChiSo(c); break;
            case 'C': t[1]->setChiSo(c); break;
            case 'E': t[2]->setChiSo(c); break;
            case 'A': t[3]->setChiSo(c); break;
            case 'N': t[4]->setChiSo(c); break;
        }
    }
}

void Person::input() {
    string s;
    cout << "Nhap chuoi danh gia tam ly (vi du: O70C65E55A40N20): ";
    cin >> s;

    t.resize(5);
    t[0] = new O;
    t[1] = new C;
    t[2] = new E;
    t[3] = new A;
    t[4] = new N;

    saveData(s);
}

void Person::output() {
    cout << "\n--- Ket qua danh gia tam ly ---\n";
    cout << "O: " << t[0]->outputRes() << endl;
    cout << "C: " << t[1]->outputRes() << endl;
    cout << "E: " << t[2]->outputRes() << endl;
    cout << "A: " << t[3]->outputRes() << endl;
    cout << "N: " << t[4]->outputRes() << endl;
    cout << "-------------------------------\n";
}

Person::~Person() {
    for (auto &p : t) delete p;
}

class Community {
protected:
    vector<Person*> a;
    int n;
public:
    void input();
    void output();
    ~Community(); // để giải phóng bộ nhớ
};

void Community::input() {
    cout << "Nhap so nguoi can danh gia: ";
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap du lieu cho nguoi thu " << i + 1 << ":\n";
        a[i] = new Person;
        a[i]->input();
    }
}

void Community::output() {
    cout << "\n===== Ket qua danh gia toan bo =====\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nNguoi thu " << i + 1 << ":\n";
        a[i]->output();
    }
}

Community::~Community() {
    for (auto &p : a) delete p;
}

int main() {
    Community c;
    c.input();
    c.output();
    return 0;
}
