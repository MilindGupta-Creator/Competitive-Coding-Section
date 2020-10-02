#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--)
	{
	    int n, c=0;
	    cin>>n;
	    string s;
	    cin>>s;
	    for(int i=0; i<n; i++)
	    if(s[i]=='1')
	    c++;
	    long long ans=0;
	    for(int i=1; i<=c; i++)
	    ans += i;
	    cout<<ans<<"\n";
	}
}
