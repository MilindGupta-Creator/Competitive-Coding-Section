#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

void LCS(string X, string Y, int m, int n){
	//create table
	int t[m+1][n+1];

	//initialize table. 1st row and columns with 0 rest with -1
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j){
			if(i==0 || j==0){
				t[i][j]=0;
			}
			else{
				t[i][j]=-1;
			}
		}
	}


	cout<<"Before DP"<<endl;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	
	for (int i = 1; i < m+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if(X[i-1]==Y[j-1]){ 
				//if char at pos X[i-1]==Y[j-1], increase the count 
				t[i][j] = 1+ t[i-1][j-1];
			}
	
			else{
				//if it is not same see for both by decreasing size of each and choosing the max 
				t[i][j] = max(t[i-1][j],t[i][j-1]);
			}
		}
	}

	cout<<"After DP"<<endl;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Longest subsequence = "<< t[m][n];	
	return;
}

int main(){
	string X="abceh";
	int m=X.length();
	string Y="abdefhr";
	int n=Y.length();
	LCS(X,Y,m,n);
}