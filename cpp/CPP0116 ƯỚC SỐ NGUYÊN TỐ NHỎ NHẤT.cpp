#include <bits/stdc++.h>
using namespace std;

int first_num(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            return i;
        }
        
    }
    return num;
}

vector<int> check()
{
    vector<int> out(10001);
    out[0] = out[1] = 1;

    for (int i = 2; i <= 10001; i++)
    {
        out[i] = first_num(i);
    }
    
    return out;
}

void submit(vector<int> A)
{
    int n, count = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cout << A[i+1] << " ";
    }
    
    
    
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();

    vector<int> A = check();
    
    while (so_bo_test--)
    {
        submit(A);
    }

    return 0;
}