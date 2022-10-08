#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
using namespace std;
unsigned countBits(unsigned int number)
{   
   
    
    return (int)log2(number)+1;
}
int main(){
     ios_base::sync_with_stdio(false);
   ll tt;
   cin>>tt;
   while(tt--){
       ll n;
       cin>>n;
       n--;
       ll i;
       set<ll>s,p;
       vector<ll>vvv;
       ll pppp;
       char cc;
       char tttt;
       ll k=countBits(n);
       s.insert(n);
       for(i=n;i>0;i--){
           if(countBits(i)==k){
               s.insert(i);
           }
           else{
               p.insert(i);
           }
       }
       for(auto it=p.begin();it!=p.end();it++){
           cout<<*it<<" ";
       }
       cout<<0<<" ";
       for(auto it=s.begin();it!=s.end();it++){
           cout<<*it<<" ";
       }
       string uu;
       cout<<"\n";
       
   }
}
   



