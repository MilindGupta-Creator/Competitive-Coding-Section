#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
ll t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    ll i;
    if(s.size()%2==1){
        cout<<"NO"<<endl;
    }
    else{
        string p="";
        string q="";
        for(i=0;i<s.size()/2;i++){
            p+=s[i];
        }
        for(i=(s.size()/2);i<s.size();i++){
            q+=s[i];
        }
        if(p==q){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
       // cout<<p<<" "<<q<<endl;
    }
}
}
