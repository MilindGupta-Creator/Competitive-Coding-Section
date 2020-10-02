#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int p=0; p<q; p++)
    {
        long long int a[3];
        for(int i=0; i<3; i++)
        {
            cin>>a[i];
        }
        sort(a, a+3);
        cout<<a[1]<<"\n";
    }
}