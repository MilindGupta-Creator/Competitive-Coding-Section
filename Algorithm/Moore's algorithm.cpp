//*************MOORE'S ALGORITHM*************
//Solution by  Atharva kulkarni

//Question : find the majority element in an array with an occurence of more than n/2 times(given such element always exists)
//question link : https://leetcode.com/problems/majority-element/

//DESCRIPTION : The crucks of this (moore's) algorithm is if an element is occuring more than (n/2) times i.e. it is occuring in majority we reduce count
//of such element even if the count gets equal to zero at start it will be positive at the end . For better understanding do some dry runs.

//Time complexities: O(n)

//IP1 : 3 2 3
//OP1 : 3(count=2)

//IP2 : 7 7 5 7 5 1 5 7 5 5 7 7 5 5 5 5
//OP2 : 5(count=9)

#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	int count = 0;
	int element = 0;
	for (int i = 0; i < n; i++) {
		if (count == 0) element = nums[i];
		if (element == nums[i]) count++;
		else count--;
	}
	cout << element;
	return 0;
}