#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
public:
    string name, lop, birth;
    float GPA;

    friend std::ostream& operator<<(std::ostream& os, const SinhVien& p);
    friend std::istream& operator>>(std::istream& is, SinhVien& p);
};

istream& operator>>(istream& is, SinhVien& obj)
{
    getline(is, obj.name);
    is >> obj.lop >> obj.birth >> obj.GPA;

    if (obj.birth.size() == 8)
    {
        obj.birth = "0" + obj.birth.substr(0, 2) + "0" + obj.birth.substr(2);
    }
    else
    {
        if (obj.birth[0] =='0')
        {
            obj.birth = obj.birth.substr(0, 3) +  "0" + obj.birth.substr(3);
        }
        else
        {
            obj.birth = "0" + obj.birth;
        }
        
    }

    return is;
}

ostream& operator<<(ostream& os, const SinhVien& obj)
{
    os << "B20DCCN001 " << obj.name << " " << obj.lop << " " << obj.birth << " " << setprecision(2) << fixed << obj.GPA;
    return os;
}

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}