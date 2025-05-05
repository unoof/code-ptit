#include <bits/stdc++.h>
using namespace std;

struct Product
{
    int mmh;
    string name, group;
    float money_in, money_out, stonk;
};

bool compare(Product& a, Product& b)
{
    return a.stonk > b.stonk;
}

void nhap(Product ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin.ignore();

        ds[i].mmh  = i+1;
        getline(cin, ds[i].name);
        getline(cin, ds[i].group);
        cin >> ds[i].money_in >> ds[i].money_out;
        ds[i].stonk = ds[i].money_out - ds[i].money_in;
    }
}

void sapxep(Product ds[], int n)
{
    sort(ds, ds+n, compare);
}

void in(Product ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ds[i].mmh << " " << ds[i].name << " " << ds[i].group << " " << setprecision(2) << fixed << ds[i].stonk;
        cout << endl;
    }
    
}

int main(){
    struct Product ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds,N);
    in(ds, N);
    return 0;
}