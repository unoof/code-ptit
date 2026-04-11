#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> DFS(vector<vector<int>> &A, int n, int index)
{
    stack<int> save;
    vector<int> ans;

    save.push(index);
    
    while (save.size() != 0)
    {
        int temp = save.top();
        bool check = false;
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1)
            {
                save.push(i);
                A[temp][i] = 0;
                check = true;
                break;
            }
        }
        if (!check)
        {
            save.pop();
            ans.push_back(temp);
        }
    }
    return ans;
}

bool option1(vector<int> &ans, int count)
{
    if (ans.size() == count+1)
    {
        if (ans[0] == ans[ans.size()-1])
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }
    }
    else
    {
        return false;
    }
    return true;
}

void submit()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int option;
    cin >> option;
    int n;
    cin >> n;
    int k = 1;
    if (option == 2) cin >> k;
    
    int count = 0;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1) count++;
        }
    }
    

    vector<int> ans;
    
    if (option == 1)
    {
        bool temp = false;
        for (int i = 0; i < n; i++)
        {
            ans = DFS(A, n, i);
            bool check = option1(ans, count);
            if (check)
            {
                temp = true;
                break;
            }
        }
        if (!temp) cout << 0;
    }
    else
    {
        ans = DFS(A, n, k-1);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i]+1 << " ";
        }
    }
}

int main()
{
    submit();
    return 0;
}