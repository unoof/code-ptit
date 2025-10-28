#include <bits/stdc++.h>
using namespace std;

void sorting(vector<int> &A, int start, int mid, int end)
{
    int n1 = mid-start+1;
    int n2 = end-mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = A[start+i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = A[mid+1+i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &A, int start, int end)
{
    if (start < end)
    {
        int mid = (start+end)/2;
        merge_sort(A, start, mid);
        merge_sort(A, mid+1, end);
        sorting(A, start, mid, end);
    }
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    merge_sort(A, 0, n-1);
    for (auto &&i : A) cout << i << " ";

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