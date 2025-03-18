#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, m;
    cin >> n >> m;

    set<int> arr1;
    set<int> arr2;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr1.insert(a);
    }
    
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        arr2.insert(a);
    }
    
    vector<int> unionResult;
    vector<int> intersectionResult;

    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(unionResult));

    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersectionResult));

    for (int num : unionResult)
    {
        cout << num << " ";
    }

    cout << endl;
    
    for (int num : intersectionResult)
    {
        cout << num << " ";
        
    }
    
    cout << endl;
    return;
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