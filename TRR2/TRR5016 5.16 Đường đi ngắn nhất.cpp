#include <bits/stdc++.h>
using namespace std;


void floyd_warshall(vector<vector<int>> &A, int n, ofstream &f2)
{
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && A[i][j] != int(10000))
            {
                next[i][j] = j;
            }
        }
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int max_dist = 0;
    int max_i = -1, max_j = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && A[i][j] < 1e4) {
                if (A[i][j] > max_dist) {
                    max_dist = A[i][j];
                    max_i = i; max_j = j;
                }
            }
        }
    }

    if (max_i != -1)
    {
        f2 << max_i+1 << " " << max_j+1 << " ";
        f2 << A[max_i][max_j] << endl;
        f2 << max_i+1 << " ";
        int k = max_i;
        while (next[k][max_j] != max_j)
        {
            f2 << next[k][max_j]+1 << " ";
            k = next[k][max_j];
        }
        f2 << max_j+1;
    }
    else
    {
        f2 << 0;
    }
    
}

void submit()
{
    ifstream f1("DN.INP");
    ofstream f2("DN.OUT");
    if (!f1) return;
    int n;
    f1 >> n;

    
    vector<vector<int>> A(n, vector<int>(n, int(10000)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            f1 >> temp;

            if (temp != 0 || i == j) A[i][j] = temp;
        }
    }

    floyd_warshall(A, n, f2);
    f1.close(); f2.close();
}

int main()
{
    submit();
    return 0;
}