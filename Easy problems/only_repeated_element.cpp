// In this problem we need to find , the only repeated element in the given array.
// for ex:  a[] = { 3 , 4 , 12 , 25 , 4 , 10 } , Ans : 4 (occurs two times)

#include<bits/stdc++.h>
using namespace std;

int findOnlyRepeated(int a[] , int size)
{
	int count[10000];
	memset(count , 0 , sizeof(count));
	
	for(int i=0 ; i < size ; i++)
	{
		count[a[i]] += 1;
	}
	
	int ans;
	for(int i=0 ; i < 10000 ; i++)
	{
		if(count[i] == 2)
		{
			ans = i;
		}
	}
	
	return ans;
}

int main()
{
	int a[] = { 3 , 4 , 12 , 25 , 4 , 10 };
	
	int ans =  findOnlyRepeated(a , 6);
	
	cout<<ans;
	
	return 0;
}
