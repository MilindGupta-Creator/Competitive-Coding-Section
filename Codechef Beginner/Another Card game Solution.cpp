//August Long Challenge 2020
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 
int main()
{
  int i,j;
  int t;
  //taking test input
  cin>>t;
 while(t--)
  {
    int ans;
  int  n,k;
    cin>>n>>k;
int  count = (n == 0) ? 1  : (log10(n) + 1);
 int count1 = (k == 0) ? 1  : (log10(k) + 1);
if((n-k>0 && n-k<9 )||( k-n>0 && k-n<9) )
{
   ans=1;
    cout<<ans<<" "<<(k/9)+1<<endl;
   
}
  else if(n-k>=9)
  {
    ans=1;
    if(k%9==0)
    cout<<ans<<" "<<(k/9)<<endl;
    else
    cout<<ans<<" "<<(k/9)+1<<endl;
    
  }
else if(k-n>=9) 
{
  ans=0;
  
    if(n%9==0 )
    cout<<ans<<" "<<(n/9)<<endl;
    else
    cout<<ans<<" "<<(n/9)+1<<endl;

}
  }

}
