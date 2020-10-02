#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        string s;
        long long int sum = 0;
        cin>>s;
        for(int i=0; i<s.length(); i++)
        {
            int f = int(s[i]) - int('0');
            sum = sum + f;
        }
        cout<<sum<<"\n";
        //cout<<s.length()<<"\n";
    }
}