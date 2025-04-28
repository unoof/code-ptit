#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
public:
    string msv, name, lop, birth;
    float GPA;

    void nhap()
    {
        getline(cin, name);
        getline(cin, lop);
        getline(cin, birth);
        cin >> GPA;

        if (birth.size() == 8)
        {
            birth = "0" + birth.substr(0, 2) + "0" + birth.substr(2);
        }
        else
        {
            if (birth[0] =='0')
            {
                birth = birth.substr(0, 3) +  "0" + birth.substr(3);
            }
            else
            {
                birth = "0" + birth;
            }
            
        }
    }

    void xuat()
    {
        cout << "B20DCCN001 " << name << " " << lop << " " << birth << " " << setprecision(2) << fixed << GPA;        
    }
};


int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}