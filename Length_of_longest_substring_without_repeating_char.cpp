/*
Firstly I will check wether element is first occur or it is occured befor already
Then if it is occured first time then i will stor it in map and change max2 accordingly 
else if is occured earlier then i will remove it from map and increase my second pointer and after that i will that element again as my first pointer remians same in this case
*/
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
