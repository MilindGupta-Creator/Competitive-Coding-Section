#include<bits/stdc++.h>
using namespace std;   
int firstMissingPositive(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]+=1;
    for(int i=1;;i++){
        if(mp.find(i)==mp.end())
            return i;
	}
    return INT_MAX;
}
int main(void){
	int n;//size of array
	cin>>n
	vector<int> nums(n,0);
	for(int i=0;i<n;i++) cin>>nums[i];
	cout<<firstMissingPositive(nums);
	 
}
