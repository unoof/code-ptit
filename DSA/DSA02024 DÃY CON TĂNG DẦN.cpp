#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
bool cmp(vector<int> &A, vector<int> &B)
{
    string s1 = "", s2 = "";
    for (auto &&i : A)
    {
        s1 += to_string(i) + " ";
    }
    for (auto &&i : B)
    {
        s2 += to_string(i) + " ";
    }
    return s1 < s2;
}

void recursion(vector<int> &A, vector<bool> &placed, int start, int end ,int pre_placed, int count)
{
    if (start == end)
    {
        return;
    }
    
    for (int j = 0; j < 2; j++)
    {
        if (A[start] > A[pre_placed])
        {
            if (j == 1)
            {
                placed[start] = j;
                count++;
                pre_placed = start;
            }
        }
        else if (j == 1)
        {
            return;
        }
        
        if (start == end-1)
        {
            if (count >= 2)
            {
                vector<int> B;
                for (int i = 0; i < end; i++)
                {
                    if (placed[i])
                    {
                        B.push_back(A[i]);
                    }
                }
                ans.push_back(B);
            }
        }
        else
        {
            recursion(A, placed, start+1, end, pre_placed, count);
        }
        if (j == 1)
        {
            placed[start] = false;
        }
        
    }
}

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    vector<pair<int,int>> B(n);

    for (int i = 0; i < n; i++)
    {
        B[i].first = A[i], B[i].second = i;
    }
    sort(B.begin(), B.end());
    
    for (auto &&i : B)
    {
        vector<bool> placed(n, 0);
        placed[i.second] = true;
        recursion(A, placed, i.second+1, n, i.second, 1);
    }
    
    sort(ans.begin(), ans.end(), cmp);
    
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}