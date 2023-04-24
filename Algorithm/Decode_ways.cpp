//LEETCODE
//MEDIUM
//91

/*A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/


class Solution {
    private: 
     int memo[101];
public:
    int numDecodings(string s) {
        memset(memo,-1,sizeof(int)*101);
        return fun(s,0);
    }
    int fun(string s,int index)
    {
        // Base Case
        if(index==s.size())
            return 1;
        
        // Using Memoization
        if(memo[index]!=-1)
            return memo[index];

        int ans=0;
        
        // Recursive Call
           // You have two choices 
                 // 1. Choose one digit
                // 2. Choose two digit
         
        // 1. Choose one digit
            if(s[index]!='0')
                ans+=fun(s,index+1);
        
        // 2. Choose two digit
            if(index+1<s.size())
            if(s[index]!='0')
            {
                int num=s[index]-'0';
                 num*=10;
                num+=s[index+1]-'0';
                if(num<=26)
                    ans+=fun(s,index+2);
            }
        return memo[index]=ans;
    }
};

// credits leetcode
//username-yash_107
