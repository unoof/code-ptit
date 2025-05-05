#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string num1, num2;

    cin >> num1 >> num2;

    deque<int> total;
    
    if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2))
    {
        swap(num1, num2);
    }

    int i = num1.size() - 1, k = num2.size() - 1, past = 0;

    

    while (i >= 0 || k >= 0 || past)
    {
        int d1;
        if (i >= 0)
        {
            d1 = num1[i] - '0';
        }
        else
        {
            d1 = 0;
        }
        
        int d2;
        if (k >= 0)
        {
            d2 = num2[k] - '0';
        }
        else
        {
            d2 = 0;
        }
        
        int sum = d1 - d2 + past;

        if (sum < 0)
        {
            past = -1;
            sum = 10 + sum;
        }
        else
        {
            past = 0;
        }
        

        total.push_front(sum % 10);
        i--; 
        k--;
    }

    
    
    for (auto &&i : total)
    {
        cout << i;
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