bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=i;
            else 
            {
                int letter = s[i]-'a';
                if(distance[letter]!=(i-mp[s[i]]-1))
                    return false;
            }
        }
        return true;
    }