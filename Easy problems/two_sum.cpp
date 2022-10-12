class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            if(mp.find(val)!=mp.end())
            {
                auto it=mp.find(val);
                
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};