#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        long int y, x, k, n;
        int f=0;
        cin>>y>>x>>k>>n;
        y = y - x;
        for(int u=0; u<n; u++)
        {
            long int b, p;
            cin>>b>>p;
            if(b>=y and p<=k)
            {
                f++;
            }
        }
        if(f==0)
        cout<<"UnluckyChef\n";
        else
        cout<<"LuckyChef\n";
    }
}