#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputfile("PTIT.in");
    ofstream outputfile("PTIT.out");

    string line;
    while (getline(inputfile, line))
    {
        outputfile << line << endl;
    }

    
    inputfile.close();
    outputfile.close();


    return 0;
}