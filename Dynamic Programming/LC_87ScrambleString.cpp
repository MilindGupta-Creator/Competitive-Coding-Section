
// So we have 2 strings s1 and s2 and we need to check if they are scrambled strings are not
// For that we can follow the MCM pattern of dividing the string into 2 parts at every possible point
// So we can do 2 possible things at a point
// 1. leave the string as it is
// 2. swap it!
// Let us assume you are at index 1 and you want to leave the string as it is then it would be true if and only if (0,1) of s1 == (0,1) of s2 (AND) (1,n) of s1 == (1,n) of s2
// Now for swap case let us assume we are at index 1 and now we will check if (0,1) of s1 == (n-1,1) of s2 (AND) (1,n) of s1 == (0,n-1) of s2
// (Here 's1==s2' doesn't mean we are comparing both the string it represent whether s1 and s2 are scrambled strings or not)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rec(string s1, string s2, unordered_map<string, int> &um)
    {
        int n = s1.size();
        if (s1 == s2)
        {
            return 1;
        }
        if (n == 1)
        {
            return 0;
        }
        int flag = 0;
        if (um.find(s1 + " " + s2) != um.end())
        {
            return um[s1 + " " + s2];
        }
        for (int k = 1; k < n; k++)
        {
            if (rec(s1.substr(0, k), s2.substr(0, k), um) && rec(s1.substr(k), s2.substr(k), um))
            {
                flag = 1;
            }
            if (flag == 1)
            {
                return true;
            }
            if (rec(s1.substr(0, k), s2.substr(n - k), um) && rec(s1.substr(k), s2.substr(0, n - k), um))
            {
                flag = 1;
            }
            if (flag == 1)
            {
                return true;
            }
        }
        return um[s1 + " " + s2] = flag;
    }
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, int> um;
        return rec(s1, s2, um);
    }
};