#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, d;
    cin>>n>>d;
    long long int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    long int c=0;
    for(int i=0; i<n-1; i++)
    {
        if(a[i+1]-a[i] <= d)
        {
            c++;
            i++;
        }
    }
    cout<<c<<"\n";
}