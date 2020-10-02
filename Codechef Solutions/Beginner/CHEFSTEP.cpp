#include <bits/stdc++.h>
using namespace std;
int main(){
int q;
cin>>q;
while(q--)
{
    long long int n, k;
    cin>>n>>k;
    string s="";
    long long int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]%k == 0)
        s += "1";
        else
        s += "0";
    }
    cout<<s<<"\n";
}}