//August Long Challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    //taking input//
	ll t;
	cin>>t;
	while(t--)
   {
       //taking inputs
   	ll n,chefP,mi=INT_MAX,ans;
   	cin>>n>>chefP;
   	ll p[n];
   	for(int i=0;i<n;i++)
   	{
   		cin>>p[i];
           //checking every instance of array and comparing it with chefP number
   		if(p[i]<=chefP)
   		{
               //checking if if the number is divisible by the value in array p.
   			if(chefP%p[i]==0)
   			{  
   				ll k=chefP/p[i];
                //finding k 
   				if(k<mi)
   				{
   					mi=k;
   					ans=p[i];
   				}
   			}
   		}
   		
   	}
    //if mi doesnt exist means the value is not changed and we print out the ans variable found
   	if(mi==INT_MAX)
   	cout<<"-1\n";
   	else
   	{
   		cout<<ans<<"\n";
   	}
   }
}