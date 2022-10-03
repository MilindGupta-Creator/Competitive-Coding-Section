class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,string> mp;
        int ctr=0;
        for(int i=1;i<rings.length();i+=2)
        {
            int num=rings[i]-'0';
            if(mp.find(num)==mp.end())
                mp[num]+=rings[i-1];
            else
            {
                string str=mp[num];
                int flag=0;
                for(int j=0;j<str.length();j++)
                {
                    if(str[j]==rings[i-1])
                    {
                        flag=1;
                        break;
                    }
                    
                        
                }
                if(flag==0)
                    {
                        str+=rings[i-1];
                        mp[num]=str;
                    }
            }
                
        }
        for(int i=0;i<=9;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                if(mp[i].length()==3)
                    ctr++;
            }
        }
        return ctr;
    }
};