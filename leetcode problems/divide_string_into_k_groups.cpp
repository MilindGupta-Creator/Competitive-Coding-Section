class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> vect;
        int ctr=0;
        string str="";
        for(int i=0;i<s.length();i++)
        {
            str+=s[i];
            ctr++;
            if(ctr==k)
            {
                vect.push_back(str);
                str="";
                ctr=0;
            }
        }
        while(ctr<k && ctr!=0)
        {
            str+=fill;
            ctr++;
        }
         if(ctr!=0)  
        vect.push_back(str);
        return vect;
        
    }
};