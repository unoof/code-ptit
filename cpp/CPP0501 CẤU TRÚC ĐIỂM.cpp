#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
}pt;

void input(Point &a)
{
    cin >> a.x >> a.y;
}

double distance(Point &a1, Point &a2)
{
    return sqrt((a1.x - a2.x)*(a1.x - a2.x) + (a1.y - a2.y)*(a1.y - a2.y));
}

int main(){
    struct Point A, B;
    int t;
    cin>>t;
    while(t--){
        input(A); input(B);
        cout << fixed << setprecision(4) << distance(A,B) << endl;
    }
    return 0;
}