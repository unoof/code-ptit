#include <bits/stdc++.h>
using namespace std;

bool check_same_num(vector<int> A)
{
    int save = A[0];
    for (int i = 1; i < 3; i++)
    {
        if (A[i] != save)
        {
            return false;
        }
        
    }
    
    if (A[3] != A[4])
    {
        return false;
    }
    return true;
}

bool check_8_6(vector<int> A)
{
    for (auto &&i : A)
    {
        if (i != 6 && i != 8)
        {
            return false;
        }
        
    }
    return true;
}

bool check_up_num(vector<int> A)
{
    int past = A[0];
    for (int i = 1; i < 5; i++)
    {
        if (past+1 != A[i])
        {
            return false;
        }
        past = A[i];
    }
    return true;
}

void submit()
{
    string num;
    cin >> num;
    
    vector<int> A;
    for (int i = (int)num.size() - 1; i >= 0 && A.size() < 5; i--)
    {
        if (isdigit(num[i]))
        {
            A.push_back(num[i] - '0');
        }
    }

    reverse(A.begin(), A.end());
    
    
    if (check_same_num(A) || check_8_6(A) || check_up_num(A))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}