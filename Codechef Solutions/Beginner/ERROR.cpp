#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--)
	{
	    string s;
	    cin>>s;
	    if(s.length()<3)
	    cout<<"Bad"<<"\n";
	    else
	    {
	        int f=0;
	        for(int i=0; i<s.length()-2; i++)
	        {
	            if(s[i]=='1' and s[i+1]=='0' and s[i+2]=='1')
	            {
	                f++;
	                break;
	            }
	            else if(s[i]=='0' and s[i+1]=='1' and s[i+2]=='0')
	            {
	                f++;
	                break;
	            }
	        }
	        if(f>0)
	        cout<<"Good\n";
	        else
	        cout<<"Bad\n";
	    }
	}
}
