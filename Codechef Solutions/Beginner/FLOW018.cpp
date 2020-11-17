#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int p=0; p<q; p++)
    {
        long long int n, fact=1;
        cin>>n;
        for(int i=1; i<=n; i++)
        fact = fact * i;
        cout<<fact<<"\n";
    }
}