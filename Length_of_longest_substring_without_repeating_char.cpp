int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
       unordered_map<int,int>mp;
        int max2=0;
        while(i<s.length()&&j<s.length()){
            if(mp[s[j]]==0)
            {
                mp[s[j]]++;
                max2=max(max2,j-i+1);
                j++;
            }
            else
            {
                mp[s[i]]--;
                i++;
            }
        }
        
        return max2;
        
    }
