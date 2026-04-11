#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> DFS(vector<vector<int>> A, int n, int index)
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
                A[temp][i] = A[i][temp] = 0;
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

bool option1(vector<vector<int>> &A, int n, int index)
{
    stack<int> save;
    vector<bool> visited(n, false);

    save.push(index);
    visited[index] = true;
    
    while (save.size() != 0)
    {
        int temp = save.top();
        bool check = false;
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                save.push(i);
                visited[i] = true;
                check = true;
                break;
            }
        }
        if (!check)
        {
            save.pop();
        }
    }

    for (auto &&i : visited)
    {
        if (!i) return false;
    }
    return true;
}

void submit()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    int option;
    cin >> option;
    int n;
    cin >> n;
    int k = 1;
    if (option == 2) cin >> k;
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1) deg[i]++;
        }
    }
    
    
    vector<int> ans;
    
    if (option == 1)
    {
        if (!option1(A, n, 0))
        {
            cout << 0;
            return;
        }
        
        int oddCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] % 2 != 0)
            {
                oddCount++;
            }
        }
        
        if (oddCount == 0) cout << 1; 
        else if (oddCount == 2) cout << 2;
        else cout << 0;
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