class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxm=0,year;
        for(int i=1950;i<=2050;i++)
        {
            int ctr=0;
            for(int j=0;j<logs.size();j++)
            {
                if(i>=logs[j][0] && i<logs[j][1])
                    ctr++;
            }
            if(ctr>maxm)
            {
                maxm=ctr;
                year=i;
            }
        }
        return year;
    }
};