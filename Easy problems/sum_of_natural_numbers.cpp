#include<bits/stdc++.h>
using namespace std;
int sumofnatural(int n){
	if(n==1){
		return 1;
	}
	return n + sumofnatural(n-1);
}
int main(){
	int m;cin>>m;
	cout<<sumofnatural(m);
}
