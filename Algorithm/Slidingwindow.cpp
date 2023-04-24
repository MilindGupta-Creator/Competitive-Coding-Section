/*
Test Case 1:
Input : s = "abcabcbb"
Output: 3
Explaination: here longest substring without repeating character is "abc" so answer is 3
Test Case 2: 
Input : s = "bbbbb"
Output : 1
Explaination : here longest substring without repeating character is "b" only
*/
//Solution here

#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxm=0;
        while(j<s.length())
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                maxm=max(maxm,j-i+1);
                j++;
                //in case the window size is equal to map size this window maybe a possible 
                //candidate for answer
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    /*if the map size is smaller it means that any character is repeating 
                    in the window so we have to remove that value until it becomes to
                    equal to the window size*/
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        //in case it become zero it means it has no use now
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxm;
    }
   int main()
   {
     string t;
     cin>>t;
     cout<<"The length of longest substring is : "<<lengthOfLongestSubstring(t);
