/*
Kadane's Algorithm for maximum subarray sum
Time Complexity= O(n)
Author: Adarsh
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={-1,0,5,6,-2,8,3,-5,-1,0,6,-2,-8,3,-5};

    int maxSum=arr[0],currentSum=0;

    for(int i=0;i<15;i++)
    {
        if(currentSum+arr[i]>0)
        {
          currentSum+=arr[i];   //Keeps tack of sum of current subarray 
        }
        else{
            currentSum=0;
        }
        maxSum=max(maxSum,currentSum);  //Update maximum sum

    }
    cout<<maxSum<<endl;
}
/*
Quick Explaination
Problem: given an array of integers find the max sum of subarray
=> Initialize current sum variable as 0(if all elements are less than zero, then 
maximum sum will be of empty subarray ).
=> Now while sum of subarray is grater then zero keep adding the elements and after each iteration
update value of maxSum variable, this will provide you final answer.
*/