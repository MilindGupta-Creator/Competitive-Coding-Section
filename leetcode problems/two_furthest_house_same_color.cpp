class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0,j=n-1;
        if(colors[i]!=colors[j])
            return j-i;
        int maxm=0;
        j=0;
        for(int i=n-1;i>=0;i--)
        {
            if(colors[i]!=colors[j])
            {
                maxm=max(maxm,i-j);
                break;
            }
        }
        j=n-1;
        for(int i=0;i<n;i++)
        {
            if(colors[i]!=colors[j])
            {
                maxm=max(maxm,j-i);
                break;
            }
        }
        return maxm;
        
    }
};