#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e;
    cin>>e;
    while (e--){
        int n , k, b , s;
        cin>>n>>k>>b>>s;
        int z=s-(b*k);
        if(s/k==b){
            for(int i=0;i<n-1;i++){
                cout<<0<<" ";
            }
            cout<<s<<endl;
        }
        else if(s/k<b)cm;
        else if((k-1)*n<z)cm;
        else{
            int a[n]={0};
            a[n-1]=b*k;
            for(int i=n-1; i>=0; i--){
                if(z>k-1){
                    a[i]+=k-1;
                    z-=(k-1);
                }
                else{
                    if(z!=0){
                        a[i]+=z;
                        z=0;
                    }
                }
            }
            for(int i=0;i<n;i++)cout<<a[i]<<" ";
            cout << endl;
        }
    }
    return 0;
}