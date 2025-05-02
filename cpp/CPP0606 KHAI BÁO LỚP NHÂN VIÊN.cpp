#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
public:
    string name, gender, birth, address, tax, sign_date;

    friend std::ostream& operator<<(std::ostream& os, const NhanVien& p);
    friend std::istream& operator>>(std::istream& is, NhanVien& p);
};

istream& operator>>(istream& is, NhanVien& obj)
{
    getline(is, obj.name);
    is >> obj.gender >> obj.birth;
    is.ignore();
    getline(is, obj.address);
    is >> obj.tax >> obj.sign_date;
    return is;
}

ostream& operator>>(ostream& os, const NhanVien& obj)
{
    os << "00001 " << obj.name << " " << obj.gender << " " << obj.birth << " " << obj.address << " " << obj.tax << " " << obj.sign_date;
    return os;
}

int main(){
    NhanVien a;
    cin >> a;
    cout >> a;
    return 0;
}
